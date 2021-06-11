using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class StoneMonster : MonoBehaviour

{
    public NavMeshAgent nav;
    public Animation ani;
    public Transform playerTr;
    public Transform stoneTr;
    public SphereCollider spcol;
    public Rigidbody rbody;
    public int hp = 100;
    public int dmg = 35;
    private bool isDie = false;

    public float tracedist = 25.0f;
    public float attackdist = 3.0f;


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
            nav.isStopped = true;
            ani.Play("Anim_Attack");
        }
        else if (dist <= tracedist)
        {
            nav.isStopped = false;
            nav.destination = playerTr.position;
            ani.Play("Anim_Run");
        }
        else
        {
            nav.isStopped = true;
            ani.Play("Anim_Idle");
        }



    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "BULLET")
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
        nav.isStopped = true;
    }
}