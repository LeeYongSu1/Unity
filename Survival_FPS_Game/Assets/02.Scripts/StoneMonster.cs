using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class StoneMonster : MonoBehaviour
    //1.컴퍼넌느 2. 추적 거리 공격 거리 idle 3.플레이어와 스켈레톤의 거리
{
    public NavMeshAgent navi;
    public Animation ani;
    public Transform playerTr;
    public Transform stoneTr;
    public SphereCollider spcol;
    public Rigidbody rbody;
    public float tracedist = 25.0f;
    public float attackdist = 2.8f;
    private int hp = 100;
    private int dmg = 35;
    private bool isDie = false;


	void Start()
    {
        playerTr = GameObject.FindWithTag("Player").GetComponent<Transform>();
    }

	void Update()
    {
        if (isDie) { return; }

        float dist = Vector3.Distance(playerTr.position, stoneTr.position);

        if (dist <= attackdist)
        {
            navi.isStopped = true;
            ani.Play("Anim_Attack");
        }
        else if (dist <= tracedist)
        {
            navi.isStopped = false;
            navi.destination = playerTr.position;
            ani.Play("Anim_Run");
        }
        else
        {
            navi.isStopped = true;
            ani.Play("Anim_Idle");
        }
            
        

    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag=="BULLET")
        {
            Destroy(collision.gameObject);
            ani.Play("Anim_Damage");
            hp -= dmg;
            if (hp <= 0)
                Die();
        }
    }
    void Die()
    {
        ani.Play("Anim_Death");
        this.GetComponent<SphereCollider>().enabled = false;
        isDie = true;
        Destroy(this.gameObject, 3.0f);

    }
}
