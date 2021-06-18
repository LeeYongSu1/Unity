using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.UI;

public enum MonsterState { idle, trace, attack, die };

public class MonsterCtrl : MonoBehaviour
{
    //몬스터의 현재 상태정보를 저장할 enum 변수
    public MonsterState monsterstate = MonsterState.idle;

    [Header("Component")]
    [SerializeField]
    private Transform monsterTr;
    [SerializeField]
    private Transform playerTr;
    [SerializeField]
    private Rigidbody rbody;
    [SerializeField]
    private NavMeshAgent navi;
    [SerializeField]
    private Animator ani;
    [SerializeField]
    private GameObject effect;
    [SerializeField]
    private AudioSource asource;
    [SerializeField]
    private AudioClip dieSound;

    [Header("Distance")]
    public float tracedist = 25.0f;
    public float attackdist = 2.5f;
    private float dist;

    [Header("Status")]
    private bool isDie;
    private int Hp = 100;
    private int curHp;
    public int damage = 15;
    private BulletCtrl bullet;
    [SerializeField]
    private GameObject bloodDecal;

    [Header("UI")]
    [SerializeField]
    private Image hpBar;
    [SerializeField]
    private Text hpText;
    [SerializeField]
    private Canvas hudCanvas;


    private void Awake()
    {
        playerTr = GameObject.FindWithTag("Player").transform;
        monsterTr = GetComponent<Transform>();
        rbody = GetComponent<Rigidbody>();
        navi = GetComponent<NavMeshAgent>();
        ani = GetComponent<Animator>();
        effect = Resources.Load<GameObject>("blood1");
        asource = GetComponent<AudioSource>();
        dieSound = Resources.Load<AudioClip>("player_killed_1");

        hpBar = transform.GetChild(14).GetChild(0).GetChild(0).GetComponent<Image>();
        hpText = transform.GetChild(14).GetChild(0).GetChild(1).GetComponent<Text>();
        hudCanvas = transform.GetChild(14).GetComponent<Canvas>();

        bloodDecal = Resources.Load<GameObject>("Effects/BloodDecal");

        isDie = false;
        navi.destination = playerTr.position;
        //damage = 20;
    }

    private void OnEnable() //활성화될때 Start보다 빠르게 호출된다
    {
        curHp = Hp;
        hpBar.fillAmount = (float)curHp / Hp;
        hpBar.color = Color.green;
        hpText.text = "HP: " + curHp.ToString();

        StartCoroutine(CheckMonsterState());
        StartCoroutine(MonsterAction());
    }


    // Start is called before the first frame update
    void Start()
    {

    }

    IEnumerator CheckMonsterState()
    {
        while (!isDie)
        {
            yield return new WaitForSeconds(0.2f);
            dist = Vector3.Distance(playerTr.position, monsterTr.position);
            if (dist<attackdist)
            {
                monsterstate = MonsterState.attack;
            }
            else if(dist<tracedist)
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
        while (!isDie)
        {
            switch (monsterstate)
            {
                case MonsterState.idle:
                    navi.isStopped = true;
                    ani.SetBool("isTrace", false);
                    break;
                case MonsterState.trace:
                    navi.isStopped = false;
                    navi.destination = playerTr.position;
                    ani.SetBool("isTrace", true);
                    ani.SetBool("isAttack", false);
                    break;
                case MonsterState.attack:
                    navi.isStopped = true;
                    ani.SetBool("isAttack", true);
                    break;
            }
            yield return null;
        }
    }

    //private void OnCollisionEnter(Collision collision)
    //{
    //    if(collision.gameObject.CompareTag("BULLET"))
    //    {
    //        ani.SetTrigger("isHit");
    //        Destroy(collision.gameObject);
    //        //GameObject eff = Instantiate(effect, collision.transform.position, Quaternion.Euler(90, 90, 0f));
    //        //Destroy(eff, 0.5f);
    //        curHp -= damage;
    //        Damage(collision.gameObject.GetComponent<BulletCtrl>().damage);
    //    }
    //}

    public void Damage(int damage)
    {
        curHp -= damage;
        hpBar.fillAmount = (float)curHp / Hp;
        hpText.text = "HP: " + curHp.ToString();
        CreateBlood();
        if (hpBar.fillAmount <= 0.3f)
        {
            hpBar.color = Color.red;
        }
        else if (hpBar.fillAmount <= 0.5f)
        {
            hpBar.color = Color.yellow;
        }
        if (curHp <= 0)
            Die();
    }

    public void OnDamage(object[] _params)
    {
        ani.SetTrigger("isHit");
        Damage((int)_params[1]);
    }

    void Die()
    {
        StopAllCoroutines();
        isDie = true;
        navi.isStopped = true;
        ani.SetTrigger("isDie");
        asource.PlayOneShot(dieSound, 1.0f);
        GetComponent<CapsuleCollider>().enabled = false;
        rbody.collisionDetectionMode = CollisionDetectionMode.Discrete;
        rbody.isKinematic = true;
        hudCanvas.enabled = false;
        PlayerUI.pui.DisplayKillCount();
        foreach (Collider col in GetComponentsInChildren<SphereCollider>())
        {
            col.enabled = false;
        }
        StartCoroutine(PushObjectPool());
    }

    IEnumerator PushObjectPool()
    {
        yield return new WaitForSeconds(3.0f);
        isDie = false;
        navi.isStopped = false;
        GetComponent<CapsuleCollider>().enabled = true;
        rbody.isKinematic = false;
        rbody.collisionDetectionMode = CollisionDetectionMode.ContinuousDynamic;
        hudCanvas.enabled = true;
        foreach (Collider col in GetComponentsInChildren<SphereCollider>())
        {
            col.enabled = true;
        }
        gameObject.SetActive(false);
    }

    void CreateBlood()
    {
        Vector3 decalPos = monsterTr.position + (Vector3.up * 0.08f);
        Quaternion decalRot = Quaternion.Euler(90.0f, 0, Random.Range(0, 360));
        float _scale = Random.Range(1.5f, 3.5f);
        GameObject blooddecal = Instantiate(bloodDecal, decalPos, decalRot);
        blooddecal.transform.localScale = Vector3.one * _scale;
        Destroy(blooddecal, 1.0f);
    }
}
