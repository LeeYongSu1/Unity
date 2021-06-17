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
    [SerializeField]
    AudioSource a_source;
   

    public float tracedist = 15.0f;
    public float attackdist = 2.5f;
    private bool IsDie;
    
    [Header("UI")]
    private Image HPbar;
    private Text hp;
    public int _hp = 100;
    public int hpinit;
    [SerializeField]
    private Canvas hudCanvas;
    [SerializeField]
    private GameObject bloodDecal;
    [SerializeField]
    private GameUI gameUI;
    private void Awake()
    {
        hpinit = _hp;
        monster = GetComponent<Transform>();
        rbody = GetComponent<Rigidbody>();
        anim = GetComponent<Animator>();
        nav = GetComponent<NavMeshAgent>();
        a_source = GetComponent<AudioSource>();
        a_source.clip = Resources.Load<AudioClip>("player_killed_1") as AudioClip;
        player = GameObject.FindWithTag("Player").GetComponent<Transform>();
        hudCanvas = gameObject.transform.GetChild(14).GetComponent<Canvas>();
        HPbar = gameObject.transform.GetChild(14).transform.GetChild(0).transform.GetChild(0).GetComponent<Image>();
        hp = gameObject.transform.GetChild(14).transform.GetChild(0).transform.GetChild(1).GetComponent<Text>();
        bloodDecal = Resources.Load<GameObject>("Effects/BloodDecal");
        gameUI = GameObject.Find("GameManager").GetComponent<GameUI>();
        nav.destination = player.position;
        IsDie = false;
        HPbar.color = Color.green;
        
    }

    private void OnEnable() //활성화 될 때 스타트 함수보다 빨리 호출됨
    {
        StartCoroutine(checkmonsterState());
        StartCoroutine(MonsterAction());
    }
    void Start()
    {
        
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

    /*private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "BULLET")
        {
            Destroy(collision.gameObject);
            anim.SetTrigger("IsHit");
            _hp -= collision.transform.GetComponent<Bullet>().damage;
            HPbar.fillAmount = (float)_hp / (float)hpinit;
            hp.text = "Hp : " + _hp.ToString();
            CreateBlood();
            if (_hp <= 0)
            {
                MonsterDie();


            }
        }
    }*/
    void MonsterDie()
    {
        StopAllCoroutines(); //모든 코루틴 중지
        nav.isStopped = true;
        IsDie = true;
        GetComponent<CapsuleCollider>().enabled = false;
        hudCanvas.enabled = false;
        anim.SetTrigger("IsDie");
        rbody.isKinematic = true;

        foreach (Collider col in GetComponentsInChildren<SphereCollider>())
        {
            col.enabled = false;
        }
        gameUI.DisplayScore(1);
        a_source.PlayOneShot(a_source.clip);
        StartCoroutine(PushObjectPool());
    }
    IEnumerator PushObjectPool()
    {
        yield return new WaitForSeconds(3.0f);
        nav.isStopped = false;
        IsDie = false;
        _hp = 100;
        HPbar.fillAmount = 1.0f;
        HPbar.color = Color.green;
        GetComponent<CapsuleCollider>().enabled = true;
        hudCanvas.enabled = true;
        //anim.SetTrigger("IsDie");

        rbody.isKinematic = false;

        foreach (Collider col in GetComponentsInChildren<SphereCollider>())
        {
            col.enabled = true;
        }
        //gameUI.DisplayScore(1);
        a_source.PlayOneShot(a_source.clip);
    }

    public void OnDamaged(object[] _params)
    {
        anim.SetTrigger("IsHit");
        _hp -= (int)_params[1];
        HPbar.fillAmount = (float)_hp / (float)hpinit;
        hp.text = "Hp : " + _hp.ToString();
        CreateBlood();
        if (_hp <= 0)
        {
            MonsterDie();

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
}
