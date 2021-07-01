using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class _EnemyMovement : MonoBehaviour
{
    private Transform player;
    private PlayerHealth_ PlayerHealth;
    private EnemyHealth_ enemyHealth;
    private NavMeshAgent nav;

    private void Awake()
    {
        player = GameObject.FindGameObjectWithTag("Player").transform;
        PlayerHealth = player.GetComponent<PlayerHealth_>();
        enemyHealth = GetComponent<EnemyHealth_>();

        nav = GetComponent<NavMeshAgent>();
    }


    void Update()
    {
        if(enemyHealth.currnetHealth > 0 && PlayerHealth.currentHealth >0)
        {
            nav.SetDestination(player.position);
        }
        else
        {
            nav.enabled = false;
        }
        
    }
}
