using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class FirePos : MonoBehaviour

{
    public AudioSource source;
    public AudioClip firesound;
    public GameObject bulletprefab;
    public Transform fire_pos;
    public Animation ani;

	void Start()
    {
        
    }

	void Update()
    {
       if (Input.GetMouseButtonDown(0))
        {
            if (Hand.isrun == false)
            {
                Fire();
            }
            else
                return;

            if (Hand.ishaveAK47 == true || Hand.ishaveUMP == true)
            {
                StartCoroutine(FaseShotFire());
            }
        }

       
    }

    void Fire()
    {
        Instantiate(bulletprefab, fire_pos.position, fire_pos.rotation);
        source.PlayOneShot(firesound, 1.0f);

        if (Hand.ishaveAK47 || Hand.ishaveUMP)
        {
            ani.Play("aimFire");
        }
        else
            ani.Play("fire");
    }

    IEnumerator FaseShotFire()
    {
        Fire();
        yield return new WaitForSeconds(0.25f);
        Fire();
        yield return new WaitForSeconds(0.25f);
        Fire();
        yield return new WaitForSeconds(0.25f);
    }
}
