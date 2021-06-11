using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoFire : MonoBehaviour
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

    public FireMode mode;

    public enum FireMode
    {
        OneShot = 1,
        ThreeShot = 2,
        AutoShot = 3,
    }

    void Start()
    {
        
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
        }*/
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
        Instantiate(bullet, firepos.position, firepos.rotation);
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
