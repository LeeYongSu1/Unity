using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class Fire2 : MonoBehaviour

{
    public string weaponName;
    public int bulletsPerMag;       // 탄창 당 장탄 수
    public int bulletsTotal;        // 전체 가지고 있는 총탄 수
    public int currentBullets;      // 현재 탄창에 남아있는 총탄 수
    public float range;				// 사정거리
    public float fireRate;			// 연사속도
    public float damage;            // 데미지

    private float fireTimer;		// 총탄과 총탄 사이의 발사 간격 설정

    public Transform shootPoint;        // 총탄이 실제 발사되는 지점

    void Start()
    {
        currentBullets = bulletsPerMag;
    }


	void Update()
    {
        if (Input.GetMouseButton(0))
        {
            if (currentBullets > 0)
            {
                Fire();
            }
            if (fireTimer < fireRate)
            {
                fireTimer += Time.deltaTime;
            }
        }
    }

    private void Fire()
    {
        if (fireTimer < fireRate) return;
        RaycastHit hit;
        if (Physics.Raycast(shootPoint.position, shootPoint.transform.forward, out hit, range))
        {
            Debug.LogWarning(hit.transform.name);
        }
        currentBullets--;
        fireTimer = 0.0f;
    }
}
