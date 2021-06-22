using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TankMove : MonoBehaviour
{
    public float moveSpeed = 20.0f;
    public float F_moveSpeed = 25.0f;
    public float rotSpeed = 50.0f;
    public float F_rotSpeed = 55.0f;
    Rigidbody rbody;
    Transform tr;
    float h, v;

    void Start()
    {
        rbody = GetComponent<Rigidbody>();
        tr = GetComponent<Transform>();
        rbody.centerOfMass = new Vector3(0.0f, -0.5f, 0.0f);//무게중심을 y축을 -0.5로 잡혀 있어야 넘어지지 않는다
    }

    
    void FixedUpdate()
    {
        TankMoceCtrl();
        FastMove();
    }

    void TankMoceCtrl()
    {
        h = Input.GetAxis("Horizontal");
        v = Input.GetAxis("Vertical");

        tr.Translate(Vector3.forward * v * F_moveSpeed * Time.deltaTime);//포지션 이동 함수
        tr.Rotate(Vector3.up * h * F_rotSpeed * Time.deltaTime);  //회전 함수
    }

    void FastMove()
    {
        if(Input.GetKey(KeyCode.LeftShift))
        {
            h = Input.GetAxis("Horizontal");
            v = Input.GetAxis("Vertical");

            tr.Translate(Vector3.forward * v * F_moveSpeed * Time.deltaTime);//포지션 이동 함수
            tr.Rotate(Vector3.up * h * F_rotSpeed * Time.deltaTime);  //회전 함수
        }
    }
}
