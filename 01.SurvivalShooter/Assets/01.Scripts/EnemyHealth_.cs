using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class EnemyHealth_ : MonoBehaviour
{
    public int startingHealth = 100;
    public int currnetHealth;
    public float sinkSpeed = 2.5f;
    public int scoreValue = 10;
    public AudioClip deathClip;

    [SerializeField]
    private Animator anim;
    private AudioSource enemyAudio;
    private ParticleSystem hitParticles;
    private CapsuleCollider capsuleCollider;
    private bool isDead;
    private bool isSinking;

    private void Awake()
    {
        anim = GetComponent<Animator>();
        enemyAudio = GetComponent<AudioSource>();
        hitParticles = GetComponentInChildren<ParticleSystem>();
        capsuleCollider = GetComponent<CapsuleCollider>();

        currnetHealth = startingHealth;
    }


    void Update()
    {
        if(isSinking)
        {
            //바닥으로 내려가는 효과
            transform.Translate(-Vector3.up * sinkSpeed * Time.deltaTime);
        }
    }

    public void TakeDamage(int amount, Vector3 hitPoint)
    {
        if (isDead)
            return;

        enemyAudio.Play();
        currnetHealth -= amount;
        hitParticles.transform.position = hitPoint;
        hitParticles.Play();

        if(currnetHealth <= 0)
        {
           Death();
        }
    }
    
    void Death()
    {
        isDead = true;

        capsuleCollider.isTrigger = true;
        anim.SetTrigger("Dead");

        enemyAudio.clip = deathClip;
        enemyAudio.Play();

        
    }

    //사망시 싱크효과 후 오브젝트 삭제

    public void StartSinking()
    {
        GetComponent<NavMeshAgent>().enabled = false;
        GetComponent<Rigidbody>().isKinematic = true;
        isSinking = true;

        Destroy(gameObject, 2f);
    }
}
