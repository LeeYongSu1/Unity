using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Player : MonoBehaviour

{
    [SerializeField]
    private Transform tr;
    [SerializeField]
    private Animation ani;
    float h, v;
    public float speed = 10.0f;
    public float rotSpeed = 100.0f;

	void Start()
    {
        tr = this.GetComponent<Transform>();
        ani = this.GetComponent<Animation>();
        ani.Play("idle");
        
    }

	void Update()
    {
        PlayerController();
        PlayerAnimation();
    }

    void PlayerController()
    {
        h = Input.GetAxis("Horizontal");
        v = Input.GetAxis("Vertical");
        

        //tr.Translate(Vector3.right * h * speed * Time.deltaTime);
        //tr.Translate(Vector3.forward * v * speed * Time.deltaTime);
        Vector3 moveDir = (Vector3.forward * v) + (Vector3.right * h);
        tr.Translate(moveDir.normalized * Time.deltaTime * speed, Space.Self);

        tr.Rotate(Vector3.up * Input.GetAxis("Mouse X") * rotSpeed * Time.deltaTime);
        //tr.Rotate(Vector3.right * Input.GetAxis("Mouse Y") * rotSpeed * Time.deltaTime);
    }
    void PlayerAnimation()
    {
        if (h > 0.01f)
        {
            //CrossFade = 정해진 시간동안 겹치게 애니메이션을 불러와서 부드럽게 만든다.
            //조금 느려서 레거시를 아직 사용한다.
            ani.CrossFade("runRight", 0.3f);
        }
        else if (h < -0.01f)
        {
            ani.CrossFade("runLeft", 0.3f);
        }
        else if (v > 0.01f)
        {
            ani.CrossFade("runForward", 0.3f);
        }
        else if (v < -0.01f)
        {
            ani.CrossFade("runBackward", 0.3f);
        }
        else
            ani.CrossFade("idle", 0.3f);
    }
}
