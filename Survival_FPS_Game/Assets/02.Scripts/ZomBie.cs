using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.UI;
public class ZomBie : MonoBehaviour
{
    [Header("Component")]
    public NavMeshAgent navi; //플레이어를 추적하는 네비 컴퍼넌트
    private Transform playerTr;
    public Transform zombieTr;
    public Animator ani;
    [Header("Distance")]
    public float tracedist = 25.0f;//추적 범위
    public float attackdist = 2.5f; //공격범위 
    [Header("Stat")]
    public int hp = 100;
    private int _hp = 100;

    private bool isDie = false;
    
    [Header("UI")]
    public Image hpbar;
    public Canvas canvas;
    public Text hptext;

    void Start()
    {
        playerTr = GameObject.FindWithTag("Player").GetComponent<Transform>();
        //하이라키에 있는 오브젝트중 Player라는 태그를 가진 것을 찾음
        hpbar.color = Color.green;
    }
    void Update()
    {
        if (isDie == true) { return; }//true가 되는 순가 하위 코드로 내려가지 않는다.

        float dist = Vector3.Distance(playerTr.position, zombieTr.position);
        //3차원 에서 거리를 구하는 함수 

        if (dist <= attackdist)
        {   //네비 추적 중지 
            navi.isStopped = false;
            ani.SetBool("IsAttack", true);
        }
        else if (dist <= tracedist)
        {
            navi.isStopped = false;
            //네비 추적 = 플레이어 포지션
            navi.destination = playerTr.position;
            ani.SetBool("IsAttack", false);
            ani.SetBool("IsTrace", true);
        }
        else
        {
            navi.isStopped = false;
            ani.SetBool("IsTrace", false);
        }

    }
    /*private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "BULLET")
        {
            Destroy(collision.gameObject);
            ani.SetTrigger("IsHit");
            HPManager();

            if (hp <= 0)
                Die();
        }
    }*/

    void OnDamage(object[] _object)
    {
        ani.SetTrigger("IsHit");
        HPManager(_object);

        if (hp <= 0)
            Die();
    }

    void HPManager(object[] _object)
    {
        hp -= (int)_object[1];
        hpbar.fillAmount = (float)hp / (float)_hp;
        if (hpbar.fillAmount <= 0.3f)
            hpbar.color = Color.red;
        else if (hpbar.fillAmount >= 0.5f)
            hpbar.color = Color.yellow;
        hptext.text = "HP: " + hp.ToString();
        if (hpbar.fillAmount <= 0.0f)
            hptext.text = "HP: 0";
    }

    void Die()
    {
        ani.SetTrigger("IsDie");
        this.GetComponent<CapsuleCollider>().enabled = false;
        isDie = true;
        navi.isStopped = true;
        canvas.enabled = false;
        hpbar.fillAmount = 1.0f;
        hpbar.color = Color.green;
        gameObject.SetActive(false);
        Invoke("DestroyZombie", 3f);
        U_Manager.umanager.KillCount(1);
        foreach (Collider col in GetComponentsInChildren<SphereCollider>())
        {
            col.enabled = false;
        }

    }

    private void DestroyZombie()
    {
        ObjectPool.ReturnObject(this);
    }

}