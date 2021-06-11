using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class E_Manager : MonoBehaviour

{
    public Transform[] points;
    public GameObject stonePrefab;
    private float timePrev;
    private float past_time;
    private float stoneTime;
    private int maxcount = 10;
    private int stone_count = 0;

    void Start()
    {
        timePrev = Time.time;
        past_time = Time.time;
        stoneTime = Time.time;
    }

	void Update()
    {
        if (Time.time - timePrev>= 3.0f)
        {
            stone_count = GameObject.FindGameObjectsWithTag("STONE").Length;

            if (maxcount > stone_count)
            {
                CreateStone();
                timePrev = Time.time;
            }
        }
    }

    void CreateStone()
    {
        int idx = Random.Range(1, 5);
        Instantiate(stonePrefab, points[idx].position, points[idx].rotation);
    }
}
