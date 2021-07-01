using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyManager_ : MonoBehaviour
{
    PlayerHealth_ playerHealth;
    [SerializeField]
    GameObject enemy;
    public float spawnTime = 3f;
    [SerializeField]
    Transform[] spawnPoints;
    

    void Start()
    {
        playerHealth = GameObject.Find("Player").transform.GetComponent<PlayerHealth_>();
        enemy = Resources.Load<GameObject>("Zombunny");
        spawnPoints = gameObject.transform.GetComponentsInChildren<Transform>();
        InvokeRepeating("Spawn", spawnTime, spawnTime);
    }
    void Spawn()
    {
        //플레이어가 사망시 적 캐릭터 소환 x
        if(playerHealth.currentHealth <=0f)
        {
            return;
        }

        int spawnPointIndex = Random.Range(0, spawnPoints.Length);

        Instantiate(enemy, spawnPoints[spawnPointIndex].position, spawnPoints[spawnPointIndex].rotation);
    }
    
    void Update()
    {
        
    }
}
