using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FirePos : MonoBehaviour
{
    [Header("BulletFire")]
    [SerializeField]
    private GameObject bullet;
    [SerializeField]
    private Transform firepos;
    [SerializeField]
    private MeshRenderer muzzleFlash;

    public float currentfirelate;
    public float currentgun;

    

    void Start()
    {
        firepos = GetComponent<Transform>();
        bullet = Resources.Load<GameObject>("Bullet");
        currentfirelate = 0;
        muzzleFlash = GetComponentInChildren<MeshRenderer>();
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
        }*/
        FireRateCalc();
        TryFire();
        
    }

    void TryFire()
    {
        if(Input.GetKey(KeyCode.Mouse0))
        {
            if(currentfirelate <=0)
            {
                currentfirelate = 0.2f;
                Fire();
            }
            
            
        }
        
    }
    void Fire()
    {
        Instantiate(bullet, firepos.position, firepos.rotation);
        StartCoroutine(ShowMuzzleFlash());
    }
    IEnumerator ShowMuzzleFlash()
    {
        float _scale = Random.Range(1.0f, 2.0f);
        muzzleFlash.transform.localScale = Vector3.one * _scale;
        Quaternion rot = Quaternion.Euler(0f, 0f, Random.Range(0, 360));
        //Quaternion.Euler= 정수나 실수를 Quaternion회전값으로 변경시켜준다.
        muzzleFlash.transform.localRotation = rot;
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
    void FireRateCalc()
    {
        if(currentfirelate > 0)
        {
            currentfirelate -= Time.deltaTime;
        }
    }
}
