using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCam : MonoBehaviour
{
    [SerializeField]
    private Transform target;
    [SerializeField]
    private Transform tr;
    [SerializeField]
    private float Distance = 20.0f;
    [SerializeField]
    private float Height = 15.0f;
    [SerializeField]
    private float angle;

    void Start()
    {
        target = GameObject.FindWithTag("TANK").GetComponent<Transform>();
        tr = GetComponent<Transform>();
    }


    private void LateUpdate()
    {   //타겟과 카메라가 y축으로 부드럽게 움직이기 위한 로직
        angle = Mathf.LerpAngle(target.eulerAngles.y, tr.eulerAngles.y, Time.deltaTime * 3.0f);
        Quaternion rot = Quaternion.Euler(0.0f, angle, 0.0f);
        //앞의 angle float값을 쿼터니언 회전값으로 변환

        tr.position = target.position - (Vector3.forward * Distance) + (Vector3.up * Height);
        //카메라 포지션 = 타겟 포지션 뒤에 배치 - 
        tr.LookAt(target.transform);
    }
}
