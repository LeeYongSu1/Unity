using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    //1.적 프리펩 2. 태어날 위치 3. 몇마리 태어날 것인지? 4.태어날 시간 간격
    [SerializeField]
    private GameObject monsterPre;
    [SerializeField]
    private Transform[] points;
    private bool IsGameOver;
    public int maxcount;
    [SerializeField]
    private int count;
    //싱글톤 패턴을 위한 인스턴스 변수 선언
    public static GameManager gmr;
    void Start()
    {
        maxcount = 10;
        IsGameOver = false;
        points = GameObject.Find("SpawnPoints").GetComponentsInChildren<Transform>();
        monsterPre = Resources.Load<GameObject>("monster");
        
        if (points.Length > 0)
            StartCoroutine(CreateMonster());
       
    }
    IEnumerator CreateMonster()
    {
        while(!IsGameOver)
        {
            int monstercount = GameObject.FindGameObjectsWithTag("MONSTER").Length;
            if(monstercount<maxcount)
            {
                yield return new WaitForSeconds(Random.Range(2.5f, 4.5f));
                int idx = Random.Range(1, points.Length);
                Instantiate(monsterPre, points[idx].position, points[idx].rotation);
            }
            else
            {
                yield return null;
            }
            
        }
    }
}
