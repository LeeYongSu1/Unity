using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class CameraController : MonoBehaviour

{

    public Transform target;       
    [SerializeField]
    private Transform tr;   //카메라 자기 자신
    public float dist = 10f;    //카메라와 타겟의 거리
    public float height = 5f;    //카메라의 높이
    public float SmoothRotate = 3f; //카메라 회전 부드러운 정도
    

    void Start()
    {
        tr = GetComponent<Transform>();
        
    }

	void LateUpdate()
    {
        float angle = Mathf.LerpAngle(tr.eulerAngles.y, target.eulerAngles.y, SmoothRotate * Time.deltaTime); //Mathf =수학공식을 모아 놓은 클래스

        Quaternion rot = Quaternion.Euler(0.0f, angle, 0f);

        tr.position = target.position - (rot * Vector3.forward * dist) + (Vector3.up * height);
        /* tr.position = new Vector3(target.position.x - 0.52f, tr.position.y , target.position.z - 6.0f);*/
        tr.LookAt(target);
        
        
    }

    private void FollowPlayer()
    {

    }
}
