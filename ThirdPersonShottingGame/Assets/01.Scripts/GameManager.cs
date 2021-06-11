using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    //1.적 프리펩 2. 태어날 위치 3. 몇마리 태어날 것인지? 4.태어날 시간 간격
    [SerializeField]
    private GameObject monsterPre;
    public List<GameObject> monsterPool = new List<GameObject>();
    [SerializeField]
    private Transform[] points;
    public bool IsGameOver;
    public int maxcount;
    [SerializeField]
    private int count;
    //싱글톤 패턴을 위한 인스턴스 변수 선언
    public static GameManager gmr;  //게임 매니저에 쉽게 접근하기 위해 대표 변수 선언
    private void Awake()
    {
        //밑에 스타트 함수보다 먼저 호출되는 함수
        //객체 생성
        gmr = this;
    }
    void Start()
    {
        maxcount = 10;
        IsGameOver = false;
        points = GameObject.Find("SpawnPoints").GetComponentsInChildren<Transform>();
        monsterPre = Resources.Load<GameObject>("monster");

        for(int i=0; i<maxcount; i++)
        {   //몬스터 프리펩 생성
            GameObject monster = (GameObject)Instantiate(monsterPre);
            //생선한 몬스터의 이름 설정
            monster.name = "monster_" + i.ToString();
            //생성한 몬스터 비활성화
            monster.SetActive(false);
            //생성한 몬스터를 오브젝트 풀에 추가
            monsterPool.Add(monster);
        }
        
        if (points.Length > 0)
            StartCoroutine(CreateMonster());
       
    }
    IEnumerator CreateMonster()
    {
        while(!IsGameOver)
        {
            /*int monstercount = GameObject.FindGameObjectsWithTag("MONSTER").Length;
            if(monstercount<maxcount)
            {
                yield return new WaitForSeconds(Random.Range(2.5f, 4.5f));
                //int idx = Random.Range(1, points.Length);
                //Instantiate(monsterPre, points[idx].position, points[idx].rotation);ㅠ
            }
            else
            {
                yield return null;
            }*/
            yield return new WaitForSeconds(3.0f);
            if (IsGameOver) yield break;
            foreach(GameObject _monster in monsterPool)
            {       //activeSlef = 활성화 비활성화 여부 알려줌
                if (!_monster.activeSelf)
                {
                    int idx = Random.Range(1, points.Length);
                    _monster.transform.position = points[idx].position;
                    _monster.SetActive(true);
                    break;
                    //오브젝트 풀에서 몬스터 프리팹을 하나 활성화하면 빠져나감
                }
            }
            
        }
    }
}
