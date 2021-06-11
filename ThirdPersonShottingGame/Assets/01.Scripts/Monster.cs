using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.UI;

public enum MonsterState { idle,trace,attack,die};
public class Monster : MonoBehaviour
{
    //몬스터의 현재 상태정보를 저장 할 enum 변수
    public MonsterState monsterstate = MonsterState.idle;

    [Header("Component")]
    [SerializeField]
    Transform player;
    [SerializeField]
    Transform monster;
    [SerializeField]
    Rigidbody rbody;
    [SerializeField]
    Animator anim;
    [SerializeField]
    NavMeshAgent nav;
    
    public float tracedist = 15.0f;
    public float attackdist = 2.5f;
    private bool IsDie;

    [Header("UI")]
    private Image HPbar;
    private Text hp;
    public int _hp = 100;
    public int hpinit;

    [SerializeField]
    private GameObject bloodDecal;
    

    void Start()
    {
        hpinit = _hp;
        monster = GetComponent<Transform>();
        rbody = GetComponent<Rigidbody>();
        anim = GetComponent<Animator>();
        nav = GetComponent<NavMeshAgent>();
        player = GameObject.FindWithTag("Player").GetComponent<Transform>();
        nav.destination = player.position;
        IsDie = false;
        HPbar = gameObject.transform.GetChild(14).transform.GetChild(0).transform.GetChild(0).GetComponent<Image>();
        HPbar.color = Color.green;
        hp = gameObject.transform.GetChild(14).transform.GetChild(0).transform.GetChild(1).GetComponent<Text>();
        bloodDecal = Resources.Load<GameObject>("Effects/BloodDecal");


        StartCoroutine(checkmonsterState());
        StartCoroutine(MonsterAction());
        
    }
    IEnumerator checkmonsterState()
    {
        while(!IsDie)
        {
            yield return new WaitForSeconds(0.2f);
            float dist = Vector3.Distance(player.position, monster.position);
            if(dist <= attackdist)
            {
                monsterstate = MonsterState.attack;
            }
            else if(dist <=tracedist)
            {
                monsterstate = MonsterState.trace;
            }
            else
            {
                monsterstate = MonsterState.idle;
            }
        }
    }

    IEnumerator MonsterAction()
    {
        while (!IsDie)
        {
            switch (monsterstate)
            {
                case MonsterState.trace:
                    nav.isStopped = false;
                    nav.destination = player.position;
                    anim.SetBool("IsTrace", true);
                    anim.SetBool("IsAttack", false);
                    break;
                case MonsterState.attack:
                    nav.isStopped = true;
                    anim.SetBool("IsAttack", true);
                    break;
                case MonsterState.idle:
                    nav.isStopped = true;
                    anim.SetBool("IsTrace", false);
                    break;
                default:
                    break;
            }
            yield return null;
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.tag=="BULLET")
        {
            Destroy(collision.gameObject);
            anim.SetTrigger("IsHit");
            _hp -= collision.transform.GetComponent<Bullet>().damage;
            HPbar.fillAmount = (float)_hp / (float)hpinit;
            hp.text = "Hp : " + _hp.ToString();
            CreateBlood();
            if (_hp<=0)
            {
                MonsterDie();
            }
        }
    }
    void MonsterDie()
    {
        Debug.Log("다이");
    }

    void CreateBlood()
    {
        Vector3 decalPos = monster.position + (Vector3.up * 0.08f);
        Quaternion decalRot = Quaternion.Euler(90f, 0, Random.Range(1, 360));
        GameObject blooddecal = Instantiate(bloodDecal, decalPos, decalRot);
        float _scale = Random.Range(1.5f, 3.9f);
        blooddecal.transform.localScale = Vector3.one * _scale;
        Destroy(blooddecal, 5.0f);
    }
}
