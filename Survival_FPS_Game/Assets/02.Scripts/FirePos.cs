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
    public FireMode mode;
    public int magazine = 3;
    public int bulletcount = 30;
    public int nowbulletcount;

    public enum FireMode
    {
        automatic,
        three,
        one
    }

	void Start()
    {
        
    }

	void Update()
    {       //마우스 왼쪽 버튼을 눌렀다면 0왼쪽 1 오른쪽 2휠버튼
        mode = FireMode.one;
        if (Input.GetKeyDown(KeyCode.B))
        {
            this.mode = FireModeChange();
        }
        
        if (mode==FireMode.one && Input.GetMouseButtonDown(0))
        {
            if (Hand.isrun == false)
            {
                nowbulletcount = bulletcount;
                magazine = 3;
                if (nowbulletcount >= 0 && magazine != 0)
                {
                    Fire();
                }
                else if (nowbulletcount <= 0 && magazine != 0)
                {
                    MagazineChange();
                }
                else
                    return;
                
                
                if (Hand.ishavem4a1 == true)
                {
                    StartCoroutine(FastShotFire());

                }
            }
        }
        else if (mode == FireMode.three && Input.GetMouseButtonDown(0))
        {
            if (Hand.isrun == false)
            {
                StartCoroutine(FastShotFire());

                if (Hand.ishavem4a1 == true)
                {
                    StartCoroutine(FastShotFire());
                }
            }
        }
        else if (mode == FireMode.automatic && Input.GetMouseButtonDown(0))
        {
            if (Hand.isrun == false)
            {
                StartCoroutine(FastShotFireAuto());

                if (Hand.ishavem4a1 == true)
                {
                    StartCoroutine(FastShotFireAuto());

                }
            }
        }
    }
    
    void Fire()
    {
        {
            Instantiate(bulletprefab, fire_pos.position, fire_pos.rotation);
            //동적 생성 함수 : 오브젝트를 필요할 때 생성시키는 함수
            source.PlayOneShot(firesound, 1.0f);
            if (Hand.ishavem4a1)
            {
                ani.Play("aimFire");
            }
            else
                ani.Play("fire");
        }
        nowbulletcount--;
        
    }
    IEnumerator FastShotFire()
    {
        Fire();
        yield return new WaitForSeconds(0.25f);
        Fire();
        yield return new WaitForSeconds(0.25f);
        Fire();
        yield return new WaitForSeconds(0.25f);
        Fire();
    }
    IEnumerator FastShotFireAuto()
    {
        while(true)
        {
            Fire();
            yield return new WaitForSeconds(0.50f);

            if (Input.GetMouseButtonUp(0))
            {
                yield break;
            }
}
        }

    FireMode FireModeChange()
    {
        if (mode == FireMode.one)
        {
            this.mode = FireMode.three;
        }
        else if (mode == FireMode.three)
        {
            this.mode = FireMode.automatic;
        }
        else
            this.mode = FireMode.one;

        return mode;

    }

    void MagazineChange()
    {
        magazine -= 1;
        ani.Play("reloadStart");
    }
}
