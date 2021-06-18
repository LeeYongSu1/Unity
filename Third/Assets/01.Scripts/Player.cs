using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    [SerializeField]
    //ㄴ 속성(Attribute)
    private Transform tr;
    [SerializeField]
    private Animation ani;
    private Rigidbody rbody;

    float h, v;
    public float movespeed = 10.0f;
    public float rotspeed = 100.0f;
    private bool jumpstatus = false;
    private Transform jumppos;

    // Start is called before the first frame update
    void Start()
    {
        tr = this.GetComponent<Transform>();
        ani = this.GetComponent<Animation>();
        rbody = this.GetComponent<Rigidbody>();
        ani.Play("idle");
        jumppos = tr;
    }

    // Update is called once per frame
    void Update()
    {
        PlayerControl();
        PlayerAnimation();
    
    }

    void PlayerControl()
    {

        h = Input.GetAxis("Horizontal");
        v = Input.GetAxis("Vertical");

        //tr.Translate(Vector3.right * h * movespeed * Time.deltaTime);
        //tr.Translate(Vector3.forward * v * movespeed * Time.deltaTime);

        Vector3 moveDir = (Vector3.forward * v) + (Vector3.right * h);
        tr.Translate(moveDir.normalized * movespeed * Time.deltaTime, Space.Self);
        //(Vector3).nomalized : 벡터 정규화
        //Space.Self : 상대 좌표 이용
        //Space.World : 절대 좌표 이용

        tr.Rotate(Vector3.up * Input.GetAxis("Mouse X") * rotspeed * Time.deltaTime);

        if (Input.GetKeyDown(KeyCode.Space) && !jumpstatus)
        {
            jumpstatus = true;
            rbody.AddForce(Vector3.up * 400, ForceMode.Impulse);
        }

        if(Input.GetKeyDown(KeyCode.F))
        {
            Instantiate(Resources.Load<GameObject>("Barrel"), tr.position + (tr.forward * 5), Quaternion.identity);
        }

    }

    void PlayerAnimation()
    {
        if (h > 0.01f)
        {
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
        {
            ani.CrossFade("idle", 0.3f);
        }
        //(Animation).CrossFade(대상 애니메이션, 시간)
        //: 시간동안 지연후 애니메이션, 부드러운 전환을 위해
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("GROUND"))
        {
            jumpstatus = false;
        }
    }
}
