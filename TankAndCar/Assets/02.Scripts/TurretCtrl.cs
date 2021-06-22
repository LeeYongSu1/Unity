using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TurretCtrl : MonoBehaviour
{
    //ScreenPointToRay() = 스크린에 보이는 2d 좌표를 3d 좌표로 바꾸어준다.
    Transform tr;
    RaycastHit hit;//광선에 맞은 위치 및 물체 뽑아오기
    Ray ray;//광선 자료형
    public float rotSpeed = 5.0f;   //터렛 회전 속도

    void Start()
    {
        tr = GetComponent<Transform>();
    }

    
    void Update()
    {
        ray = Camera.main.ScreenPointToRay(Input.mousePosition);//메인 카메라에서 마우스 커서 위치로 레이 발사
        Debug.DrawRay(ray.origin, ray.direction * 100f, Color.blue);

        if(Physics.Raycast(ray, out hit, Mathf.Infinity, 1<<10))
        {
            Vector3 relative = tr.InverseTransformPoint(hit.point);//자기 자신에서 레이저 맞은 위치를 3차원 좌표로 넘긴다
            float angle = Mathf.Atan2(relative.x, relative.z) * Mathf.Rad2Deg;//역 탄젠트 함수 = 두 점간의 각도를 계산
            tr.Rotate(0.0f, angle * Time.deltaTime * rotSpeed, 0f);
        }
    }
}
