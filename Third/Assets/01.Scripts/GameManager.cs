using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    //1. 적 프리팹  2. 태어날 위치   3. 최대 스폰 수  4. 스폰 시간
    [Header("Enemy")]
    [SerializeField]
    private GameObject monsterPrefab;
    public List<GameObject> monsterPool = new List<GameObject>();
            //List<자료형> : 어떤 자료형이든 다 담을 수 있다.
            //몬스터 prefab을 미리 생성해 저장할 리스트 자료형
    [SerializeField]
    private Transform[] spawnPoints;
    [SerializeField]
    private int spawnMaxCount;
    [SerializeField]
    private float spawnTime;
    public bool isGameOver;

    //싱글턴 패턴을 위한 인스턴스 변수 선언
    public static GameManager gmr;
    //싱글턴: 빈번하게 접근하는 클래스에 대표 변수를 선언해서 접근을 간편하게

    [Header("SoundManager")]
    public float sfxVomunm = 1.0f;
    public bool isSfxMute = false;

    private void Awake() //Start()보다 먼저 호출된다.
    {
        gmr = this;
    }

    //호출순서 Awake -> OnEnable -> Start -> -> FixedUpdate -> on Trigger -> on Collision -> Update -> LateUpdate -> OnDisable


    // Start is called before the first frame update
    void Start()
    {
        monsterPrefab = Resources.Load<GameObject>("monster");
        spawnPoints = GameObject.Find("SpawnPoints").GetComponentsInChildren<Transform>();
        spawnMaxCount = 10;
        spawnTime = 3.0f;
        isGameOver = false;

        for(int i=0;i<spawnMaxCount;i++)
        {
            GameObject monster = (GameObject)Instantiate(monsterPrefab);    //prefab생성
            monster.name = "monster_" + i.ToString();                       //이름 변경
            monster.SetActive(false);                                       //비활성화
            monsterPool.Add(monster);                                       //pool에 추가
        }

        if (spawnPoints.Length > 0)
        {
            StartCoroutine(CreateMonster());
        }
    }  

    IEnumerator CreateMonster()
    {
        while(!isGameOver)
        {
            yield return new WaitForSeconds(Random.Range(spawnTime - 1.0f, spawnTime + 1.0f));
            if (isGameOver) yield break;
            foreach(GameObject _monster in monsterPool)
            {
                if(!_monster.activeSelf) // ().activeSelf: 활성화 여부 반환
                {
                    int idx = Random.Range(1, spawnPoints.Length);
                    _monster.transform.position = spawnPoints[idx].position;
                    _monster.SetActive(true);
                    break;
                    //오브젝트 풀에서 prefab을 하나 활성화 후에 break한다.
                }
            }




            //yield return new WaitForSeconds(Random.Range(spawnTime - 0.5f, spawnTime + 0.5f));
            //if ((int)GameObject.FindGameObjectsWithTag("Monster").Length < spawnMaxCount)
            //{
            //    int idx = Random.Range(1, spawnPoints.Length);
            //    Instantiate(monsterPrefab, spawnPoints[idx].position, spawnPoints[idx].rotation);
            //}
            //yield return null;
        }
    }

    //사운드 공용 함수 동적으로 생성 되었다가 사라진다.
    public void PlaySfx(Vector3 pos, AudioClip sfx)
    {
        if (isSfxMute) return;

        GameObject soundObj = new GameObject("sfx");
        soundObj.transform.position = pos;

        AudioSource audioSource = soundObj.AddComponent<AudioSource>();
        audioSource.clip = sfx;
        audioSource.minDistance = 10.0f;
        audioSource.maxDistance = 30.0f;
        audioSource.volume = sfxVomunm;
        audioSource.Play();

        Destroy(soundObj, sfx.length);
    }

}
