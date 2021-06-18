using System.Collections;
using System.Collections.Generic;
using UnityEngine;
[RequireComponent(typeof(AudioSource))]

public class FireCtrl : MonoBehaviour
{
    [Header("BulletFire")]
    [SerializeField]
    private GameObject bulletprefab;
    [SerializeField]
    private Transform thisTr;
    [SerializeField]
    private MeshRenderer muzzleflash;
    [SerializeField]
    AudioSource source;
    [SerializeField]
    AudioClip gunSound;

    // Start is called before the first frame update
    void Start()
    {
        thisTr = GetComponent<Transform>();
        bulletprefab = Resources.Load<GameObject>("Bullet");
        //Resources 폴더에서 Bullet 게임오브젝트를 가져온다.
        muzzleflash = GetComponentInChildren<MeshRenderer>();
        //GetComponenInChildren<컴포넌트>()
        //:자식 게임오브젝트에서 컴포넌트를 가져온다.
        source = GetComponent<AudioSource>();
        gunSound = Resources.Load<AudioClip>("gun");
    }

    // Update is called once per frame
    void Update()
    {
        Debug.DrawRay(thisTr.position, thisTr.forward*100.0f, Color.green);
        //Debug.DrawRay(시작위치, 발사방향, 색깔): 시작위치에서 발사방향으로 색깔 광선을 발사

        if (Input.GetMouseButtonDown(0))
        {
            Fire();
        }

        //if (Input.GetMouseButtonDown(0))
        //{
        //    Fire();
        //}
    }

    void Fire()
    {
        //Instantiate(bulletprefab, thisTr.transform.position, thisTr.transform.rotation);
        //Projectile movement방식

        RaycastHit hit;
        //Raycast방식: 광선을 발사해서 오브젝트에 맞으면 맞은 위치를 감지
        if(Physics.Raycast(thisTr.position,thisTr.forward,out hit,Mathf.Infinity))
        {
            if (hit.collider.CompareTag("Monster"))
            {
                object[] _params = new object[2];
                //모든 클래스의 부모 혹은 조상 클래스, 루트 클래스
                _params[0] = hit.point; // 첫번째 배열에 맞은 위치 전달
                _params[1] = 20;        // 몬스터에 입히는 대미지 값을 전달
                hit.collider.gameObject.SendMessage("OnDamage", _params);
                //SendMessage: 다른 오브젝트에 있는 함수 호출이 가능
            }
            if (hit.collider.CompareTag("WALL"))
            {
                object[] _params = new object[2];
                _params[0] = hit.point;
                _params[1] = 20;
                hit.collider.gameObject.SendMessage("OnDamage", _params);
            }
            if (hit.collider.CompareTag("BARREL"))
            {
                object[] _params = new object[2];
                _params[0] = hit.point;
                _params[1] = thisTr.position;
                hit.collider.gameObject.SendMessage("OnDamage", _params);
            }
        }

        source.PlayOneShot(gunSound, 1.0f);
        StartCoroutine(ShowMuzzleFlash());
    }

    IEnumerator ShowMuzzleFlash()
    {
        float _scale = Random.Range(1.0f, 2.0f);
        muzzleflash.transform.localScale = Vector3.one * _scale;
        //localScale : 자기 자신의 상대좌표
        //Vector3.one : (1, 1, 1)
        Quaternion rot = Quaternion.Euler(0f, 0f, Random.Range(0, 360f));
        muzzleflash.transform.localRotation = rot;
        muzzleflash.enabled = true;
        yield return new WaitForSeconds(0.05f);
        muzzleflash.enabled = false;
    }
}
