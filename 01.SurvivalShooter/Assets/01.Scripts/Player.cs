using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float speed = 6.0f;
    private Animator anim;
    private Rigidbody rigidBody;
    private Vector3 movement;   //플레이어의 위치
    private float camRayLength = 100.0f;//카메라 레이캐스트 거리
    int floorMask;  //레이어

    void Start()
    {
        anim = GetComponent<Animator>();
        rigidBody = GetComponent<Rigidbody>();

    }

   //키 매핑
    void Update()
    {
        //키보드의 입력값을 받아와서 세팅
        float h = Input.GetAxisRaw("Horizontal");   //좌우값
        float v = Input.GetAxisRaw("Vertical");//상하값

        Move(h,v);
        Turning();
    }

    //이동을 처리하는 함수
    private void Move(float h, float v)
    {
        //Vector.set(x, y, z) : 벡터값을 세팅
        movement.Set(h, 0, v);
        movement = movement.normalized * speed * Time.deltaTime;
        //MovePosition : rigidbody를 이용하여 물체를 이동시킴
        //transform.position: 이 스크립트 객체의 포지션
        rigidBody.MovePosition(transform.position + movement);
    }
    //회전을 처리하는 함수
    private void Turning()
    {
        //마우스 위치로 Ray를 만듬
        //ScreenPointToRay : 2d화면을 클릭했을 때 3d 좌표계로 계산
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        //레이캐스팅 -> 만들어진 레이를 발사해서 충돌되는 객체가 있는지 판단
        RaycastHit hitinfo;
        //레이의 시작위치, 레이충돌 반환, 레이길이, 충돌한 레이어
        if (Physics.Raycast(ray, out hitinfo, camRayLength, floorMask))
        {
            //캐릭터의 방향 계산
            Vector3 playerToMouse = hitinfo.point - transform.position;
            playerToMouse.y = 0;
        }
    }
}
