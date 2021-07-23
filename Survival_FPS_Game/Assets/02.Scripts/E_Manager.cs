using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class E_Manager : MonoBehaviour

{
    //1. 태어날 위치 2. 태어날 오브젝트
    public Transform[] points;
    public Transform s_points;
    public Transform[] stone_points;
    public GameObject zombiePrefab;
    public GameObject skeletonPrefab;
    public GameObject stonePrefab;
    
   
    private float timePrev;
    private float s_timePrev; //과거시
    private float stone_time;
    private int maxcount = 10;
    private int s_maxcount = 3;
    private int spawncount = 0;
    private int s_spawncount = 0;
    private int ston_count = 0;

	void Start()
    {
        timePrev = Time.time;
        s_timePrev = Time.time;//현재 시간
        stone_time = Time.time;

        

        for (int i = 0; i < s_maxcount; i++)
        {
           
           /* GameObject skel = Instantiate(skeletonPrefab);
            skel.name = "skeleton" + i.ToString();*/
        }
    }


	void Update()
    {
        if (Time.time - timePrev >= 3.0f)
        {
            spawncount = GameObject.FindGameObjectsWithTag("ENEMY").Length;
           
            if (maxcount > spawncount)
            {
                //CreateZomBie();
                //StartCoroutine(Zombie());
                StartCoroutine(Zombie());
                timePrev = Time.time;
            }
            
        }

        if (Time.time - s_timePrev >= 3.0f)
        {
            s_spawncount = GameObject.FindGameObjectsWithTag("SKELETON").Length;
            if (s_maxcount > s_spawncount)
            {
                CreateSkeleton();
                s_timePrev = Time.time;
            }
            
        }

        if (Time.time - stone_time >= 3.0f)
        {
            ston_count = GameObject.FindGameObjectsWithTag("STONE").Length;
            if (maxcount > ston_count)
            {
                CreateStone();
                stone_time = Time.time;
            }

        }

    }

    void CreateZomBie()
    {
        int idx = Random.Range(1, 5);
        //Instantiate(zombiePrefab, points[idx].position, points[idx].rotation);
    }

    void CreateSkeleton()
    {
        //int idx = Random.Range(1, points.Length);
       // Instantiate(skeletonPrefab, s_points.position, s_points.rotation);
    }

    void CreateStone()
    {
        int idx = Random.Range(6, stone_points.Length);
        Instantiate(stonePrefab, stone_points[idx].position, stone_points[idx].rotation);
    }

    IEnumerator Zombie()
    {
        yield return new WaitForSeconds(2.0f);
        int idx = Random.Range(0, points.Length);
        var zombie = ObjectPool.GetObject();
        zombie.transform.position = points[idx].position;
        zombie.gameObject.SetActive(true);
    }
}
