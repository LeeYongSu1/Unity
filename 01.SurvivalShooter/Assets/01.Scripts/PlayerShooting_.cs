using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerShooting_ : MonoBehaviour
{
    public int damagePerShot = 20;
    public float timeBetweenBullets = 0.15f;
    public float range = 100f;

    private float timer;
    private Ray shootRay = new Ray();
    private RaycastHit shootHit;
    private int shootableMask;
    private ParticleSystem gunParticles;
    private LineRenderer gunLine;
    private AudioSource gunAudio;
    private Light gunLight;
    private float effectsDisplayTime = 0.2f;

    private void Awake()
    {
        shootableMask = LayerMask.GetMask("Shootable");
        gunParticles = GetComponent<ParticleSystem>();
        gunLine = GetComponent<LineRenderer>();
        gunAudio = GetComponent<AudioSource>();
        gunLight = GetComponent<Light>();
    }


    void Update()
    {
        timer += Time.deltaTime;

        //마우스 좌측버튼 or 키보드 Ctrl버튼 사용
        if(Input.GetButton("Fire1") && timer >= timeBetweenBullets && Time.timeScale != 0)
        {
            Shoot();
        }

        if(timer>= timeBetweenBullets * effectsDisplayTime)
        {
            DisableEffects();
        }
    }
    //광원효과 해제
    public void DisableEffects()
    {
        gunLine.enabled = false;
        gunLight.enabled = false;
    }

    //공격과 데미지 적용
    void Shoot()
    {
        timer = 0f;
        gunAudio.Play();
        gunLight.enabled = true;

        gunParticles.Stop();
        gunParticles.Play();

        gunLine.enabled = true;
        gunLine.SetPosition(0, transform.position);

        shootRay.origin = transform.position;//레이가 시작되는 지점
        shootRay.direction = transform.forward;//레이의 방향

        if(Physics.Raycast(shootRay, out shootHit, range, shootableMask))
        {
            EnemyHealth_ enemyHealth_ = shootHit.collider.GetComponent<EnemyHealth_>();
            if(enemyHealth_ != null)
            {
                enemyHealth_.TakeDamage(damagePerShot, shootHit.point);
                Debug.Log(enemyHealth_.currnetHealth);
            }
            gunLine.SetPosition(1, shootHit.point);
        }
        else
        {
            gunLine.SetPosition(1, shootRay.origin + shootRay.direction * range);
        }
    }
}
