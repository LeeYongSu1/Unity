using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    //1.적 프리펩 2. 태어날 위치 3. 몇마리 태어날 것인지? 4.태어날 시간 간격
    [SerializeField]
    private GameObject monsterPre;
    [SerializeField]
    private Transform[] points;

    void Start()
    {
        points = GameObject.Find("SpawnPoints").GetComponentsInChildren<Transform>();
    }

    
    void Update()
    {
        
    }
}
