using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyAttack_ : MonoBehaviour
{
    public float timeBetweenAttacks = 0.5f; //공격 대기 시간
    public int attackDamage = 10;//데미지

    private Animator anim;
    [SerializeField]
    private GameObject player;
    [SerializeField]
    private PlayerHealth_ playerHealth;
    private EnemyHealth_ enemyHealth;

    private bool playerInRange; //플레이어와 충돌중인지 유무
    private float timer; //타이머

    private void Awake()
    {
        player = GameObject.FindGameObjectWithTag("Player");
        playerHealth = GameObject.FindGameObjectWithTag("Player").transform.GetComponent<PlayerHealth_>();
        enemyHealth = GetComponent<EnemyHealth_>();
        anim = GetComponent<Animator>();
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject == player)
        {
            playerInRange = true;
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if(other.gameObject == player)
        {
            playerInRange = false;
        }
    }

    void Update()
    {
        timer += Time.deltaTime;

        if(timer >= timeBetweenAttacks && playerInRange && enemyHealth.currnetHealth > 0)
        {
            Attack();
        }

        if(playerHealth.currentHealth <= 0)
        {
            anim.SetTrigger("PlayerDead");
        }
    }

    void Attack()
    {
        timer = 0f;

        if(playerHealth.currentHealth > 0)
        {
            playerHealth.TakeDamage(attackDamage);
        }
    }
}
