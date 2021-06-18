using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCamera : MonoBehaviour
{
    //카메라가 플레이어를 쫓아다닌다
    public Transform target;
    [SerializeField]
    private Transform thisTr;
    public float dist = 10.0f;          //카메라와 대상의 거리
    public float height = 5.0f;         //카메라의 높이
    public float smoothRotate = 3.0f;   //회전할때 부드럽게
    public float maxdist = 23.0f;

    // Start is called before the first frame update
    void Start()
    {
        thisTr = GetComponent<Transform>();
    }

    // Update is called once per frame
    void LateUpdate()                   //Update()가 호출된 후 호출된다
    {
        float angle = Mathf.LerpAngle(thisTr.eulerAngles.y, target.eulerAngles.y, smoothRotate * Time.deltaTime);
                                        //Mathf : 수학공식만 모은 클래스
                                        //Lerp: 보간법

        Quaternion rot = Quaternion.Euler(0.0f, angle, 0.0f);
        //Quaternion : 회전 클래스
        //Quaternion.Euler : Euler 자료형을 Quaternion 자료형으로 바꾼다
        //if (thisTr.position.x >= maxdist)
        //{
        //    thisTr.position = new Vector3(maxdist, thisTr.position.y, thisTr.position.z);
        //}

        thisTr.position = target.position - (rot * Vector3.forward * dist) + (Vector3.up * height);
        thisTr.LookAt(target);
        //(transform).LookAt(대상) : 대상을 쳐다보게 한다

    }
}
