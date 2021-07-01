using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public float speed = 6.0f; //플레이어 이동 속도

    private Animator anim;
    private Rigidbody rigidbody;
    private Vector3 movement;   //플레이어 위치
    private float camRayLength = 100.0f; //카멜라 레이캐스트 거리
    int floorMask;  //레이어
    private void Start()
    {
        anim = GetComponent<Animator>();
        rigidbody = GetComponent<Rigidbody>();
        floorMask = LayerMask.GetMask("Floor");
    }

    private void Update()
    {
        float h = Input.GetAxisRaw("Horizontal");
        float v = Input.GetAxisRaw("Vertical");
        Move(h, v);
        Turning();
        Anim(h, v);
    }

    private void Move(float h, float v)
    {
        //Vector.set(x,y,x) 벡터값을 세팅
        movement.Set(h, 0, v);
        movement = movement.normalized * speed * Time.deltaTime;

        //MovePosition : rigidbody를 이용해서 물체를 이동시킴
        rigidbody.MovePosition(transform.position + movement);
    }

    private void Turning()
    {
        //마우스 위치로 Ray를 만듬
        //ScreenPointToRay : 2d 화면을 클릭 시 3d 좌표계로 계산
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        //RaycastHit hitInfo; =>만들어진 레이를 발사해서 충돌되는 객체가 있는지 판단
        RaycastHit hitInfo;

        //레이의 시작위치, 레이충돌 정보 반환, 레이 길이, 충돌한 레이어
        if(Physics.Raycast(ray, out hitInfo, camRayLength, floorMask))
        {
            //캐릭터의 방향 계산
            //목적지 위치 - 내 위치 = 방향
            Vector3 playerToMouse = hitInfo.point - transform.position;
            playerToMouse.y = 0;

            //방향으로 회전
            Quaternion rot = Quaternion.LookRotation(playerToMouse);

            //회전값 적용
            rigidbody.MoveRotation(rot);
        }

        //디버그 모드에서 레이를 그려줌
        //시작위치, 방향, 길이, 색깔, 유지시간
        Debug.DrawRay(ray.origin, ray.direction * camRayLength, Color.red, 0.1f);
    }

    //애니메이션 처리 함수
    private void Anim(float h, float v)
    {
        //h or v가 0이 아니면 걷는 애니메이션을 재생
        bool isWalking = (h !=0 || v != 0);
        anim.SetBool("IsWalking", isWalking);
    }
}
