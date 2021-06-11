using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.UI;
//1.컴퍼넌트 2.추적 거리 공격거리 idle 거리 3. 플레이어와 스켈레톤의 거리
public enum MonsterState
{
    idle, trace, attack, die
}

public class Skeleton : MonoBehaviour

{
    [SerializeField]
    private NavMeshAgent navi;
    private Animator ani;
    private Transform playerTr;
    private Transform skeletonTr;
    private CapsuleCollider capcol;
    private Rigidbody rbody;
    public float tracedist = 25.0f;
    public float attackdist = 10.0f;
    public int hp = 500;
    private int _hp = 500;
    public int dmg = 25;
    private bool isDie;
    [Header("UI")]
    public Image hpbar;
    public Canvas canvas;
    public MonsterState monsterState;
    //public Text hptext;

    private void Awake()
    {
        skeletonTr = GetComponent<Transform>();
        playerTr = GameObject.FindWithTag("Player").GetComponent<Transform>();
        navi = GetComponent<NavMeshAgent>();
        ani = GetComponent<Animator>();
        rbody = GetComponent<Rigidbody>();
        capcol = GetComponent<CapsuleCollider>();
        //하이라키에 Player태그를 가진 게임 오브젝트안에 트랜스폼을 넘긴다.
        hpbar.color = Color.green;
        monsterState = MonsterState.idle;
        isDie = false;
    }

    private void OnEnable()//활성화때 스타트 함수보다 먼저 호출된다
    {
        StartCoroutine(checkmonsterState());
        StartCoroutine(MonsterAction());
        PlayerDie();
    }

    void Start()
    {
        
        
    }
    IEnumerator checkmonsterState()
    {
        while (!isDie)
        {
            yield return new WaitForSeconds(0.2f);
            float dist = Vector3.Distance(playerTr.position, skeletonTr.position);
            if (dist <= attackdist)
            {
                monsterState = MonsterState.attack;
            }
            else if (dist <= tracedist)
            {
                monsterState = MonsterState.trace;
            }
            else
            {
                monsterState = MonsterState.idle;
            }
        }
    }

    IEnumerator MonsterAction()
    {
        while (!isDie)
        {
            switch (monsterState)
            {
                case MonsterState.trace:
                    navi.isStopped = false;
                    navi.destination = playerTr.position;
                    ani.SetBool("IsTrace", true);
                    ani.SetBool("IsAttack", false);
                    break;
                case MonsterState.attack:
                    navi.isStopped = true;
                    ani.SetBool("IsAttack", true);
                    break;
                case MonsterState.idle:
                    navi.isStopped = true;
                    ani.SetBool("IsTrace", false);
                    break;
                default:
                    break;
            }
            yield return null;
        }
    }

    /*void Update()
    {
        if (isDie) { return; }//true가 되는 순가 하위 코드로 내려가지 않는다.

        float dist = Vector3.Distance(playerTr.position, skeletonTr.position);

        if (dist <= attackdist)
        {
            navi.isStopped = true;
            ani.SetBool("IsAttack", true);
        }
        else if (dist <= tracedist)
        {
            navi.isStopped = false;
            navi.destination = playerTr.position;
            ani.SetBool("IsAttack", false);
            ani.SetBool("IsTrace", true);

        }
        else
        {
            navi.isStopped = true;
            ani.SetBool("IsTrace", false);

        }
        PlayerDie();

    }*/
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "BULLET")
        {
            Destroy(collision.gameObject);
            ani.SetTrigger("IsHit");
            SkeletonHpManager();
            if (hp <= 0)
                Die();
        }
    }

    void Die()
    {
        ani.SetTrigger("IsDie");
        this.GetComponent<CapsuleCollider>().enabled = false;
        this.GetComponent<CapsuleCollider>().enabled = false;

        isDie = true;
        U_Manager.umanager.KillCount(1);
        Destroy(this.gameObject, 5.0f);
    }

    void SkeletonHpManager()
    {
        hp -= dmg;
        hpbar.fillAmount = (float)hp / (float)_hp;
        if (hpbar.fillAmount <= 0.3f)
            hpbar.color = Color.red;
        else if (hpbar.fillAmount >= 0.5f)
            hpbar.color = Color.yellow;
    }
    void PlayerDie()
    {
        if (PlayerHP.IsPlayerDie == true)
            ani.SetTrigger("IsPlayerDie");
    }
}
