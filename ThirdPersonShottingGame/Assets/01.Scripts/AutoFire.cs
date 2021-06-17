using System.Collections;
using System.Collections.Generic;
using UnityEngine;
[RequireComponent(typeof(AudioSource))]
public class AutoFire : MonoBehaviour
{
    [Header("BulletFire")]
    [SerializeField]
    private GameObject bullet;
    [SerializeField]
    private Transform firepos;
    [SerializeField]
    private MeshRenderer muzzleFlash;
    [SerializeField]
    private AudioSource source;
    [SerializeField]
    private AudioClip gunSound;

    public float currentfirelate;
    public float currentgun;

    public FireMode mode;

    public enum FireMode
    {
        OneShot = 1,
        ThreeShot = 2,
        AutoShot = 3,
    }

    void Start()
    {
        source = GetComponent<AudioSource>();
        gunSound = Resources.Load<AudioClip>("gun");
        firepos = GetComponent<Transform>();
        bullet = Resources.Load<GameObject>("Bullet");
        currentfirelate = 0;
        muzzleFlash = GetComponentInChildren<MeshRenderer>();
        mode = FireMode.OneShot;
        
    }


    void Update()
    {
        /*if (Input.GetMouseButtonDown(0))
        {
            Fire();
        }*/

        /*else if (Input.GetKey(KeyCode.Mouse0))
        {
            StartCoroutine("FireAuto");
        }*/                 //시작 위치//방향 * 거리=velocity//색
        //Debug.DrawRay(firepos.position, firepos.forward * 20f, Color.red);
        FireModeChange();
        FireRateCalc();
        TryFire();

    }

    void TryFire()
    {
        if (Input.GetKey(KeyCode.Mouse0))
        {
            if (currentfirelate <= 0)
            {
                currentfirelate = 0.2f;
                if (mode == FireMode.AutoShot)
                {
                    Fire();
                }
                
            }

        }
        if (mode == FireMode.OneShot && Input.GetKeyDown(KeyCode.Mouse0))
        {
            Fire();
                
        }
        else if ( mode == FireMode.ThreeShot && Input.GetKeyDown(KeyCode.Mouse0))
        {
                StartCoroutine( FastShotFire());
        }

    }
    void Fire()
    {
        //프로젝타일 무부먼트 방식
        //Instantiate(bullet, firepos.position, firepos.rotation);
        RaycastHit hit; //광선을 발사해서 오브젝트에 맞으면 맞은 위치를 충돌감지하는 구조체 
        if(Physics.Raycast(firepos.position, firepos.forward, out hit, 40.0f))
        {
            if(hit.collider.tag == "MONSTER")
            {
                //모든 클래스의 부모 혹은 조상 클래스 루트 클래스
                object[] _params = new object[2];
                _params[0] = hit.point; //첫번째 배열에 Ray에 맞은 위치 전달
                _params[1] = 20;//몬스터에 입힐 데미지 값을 전달
                hit.collider.gameObject.SendMessage("OnDamaged", _params);//다른 오브젝트의 함수 호출 가능
            }

            if(hit.collider.tag=="WALL")
            {
                object[] _params = new object[2];
                _params[0] = hit.point; //첫번째 배열에 Ray에 맞은 위치 전달
                _params[1] = 20;
                hit.collider.gameObject.SendMessage("OnDamage", _params);
            }

            if(hit.collider.tag == "BARREL")
            {
                object[] _params = new object[2];
                _params[0] = hit.point; //첫번째 배열에 Ray에 맞은 위치 전달
                _params[1] = firepos.position;  //발사 위치
                hit.collider.gameObject.SendMessage("OnDamage", _params);
            }
        }

        source.PlayOneShot(gunSound, 1.0f);

        StartCoroutine(ShowMuzzleFlash());
    }
    void FireRateCalc()
    {
        if (currentfirelate > 0)
        {
            currentfirelate -= Time.deltaTime;
        }
    }
    IEnumerator FastShotFire()
    {
        
        Fire();
        yield return new WaitForSeconds(0.25f);
        Fire();
        yield return new WaitForSeconds(0.25f);
        Fire();
    }
    IEnumerator ShowMuzzleFlash()
    {
        muzzleFlash.enabled = true;
        yield return new WaitForSeconds(Random.Range(0.05f, 0.15f));
        muzzleFlash.enabled = false;
    }

    /*IEnumerator FireAuto()
    {
            while(true)
            {
               
                yield return new WaitForSeconds(0.3f);
                //Fire();

            if (Input.GetMouseButton(0) != true) { break; }
            }
    }*/
    

    FireMode FireModeChange()
    {
        if (Input.GetKeyDown(KeyCode.B))
        {
            if (mode == FireMode.OneShot)
            {
                this.mode = FireMode.ThreeShot;
                Debug.Log("점사모드");
            }
            else if (mode == FireMode.ThreeShot)
            {
                this.mode = FireMode.AutoShot;
                Debug.Log("연사모드");
            }
            else
            {
                this.mode = FireMode.OneShot;
                Debug.Log("단발모드");
            }
               


        }
        return mode;

    }


}
