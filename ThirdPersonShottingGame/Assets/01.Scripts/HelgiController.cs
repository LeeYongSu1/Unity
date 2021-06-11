using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HelgiController : MonoBehaviour
{
    [SerializeField]
    Transform helgiTr;
    public float speed = 10f;
    public float rotspeed = 10f;
    float h, v, ud, rot;
    public bool IsGetIn;
    public bool IsGround;
    [SerializeField]
    private Rigidbody rbody;


    void Start()
    {
        helgiTr = GetComponent<Transform>();
        IsGetIn = false;
        rbody = GetComponent<Rigidbody>();
        IsGround = true;
    }


    void Update()
    {
        HelgiMove();
        
    }

    void HelgiMove()
    {
        if(IsGetIn == true)
        {
            rbody.useGravity = false;
            rbody.mass = 1;
            h = Input.GetAxis("Horizontal");
            v = Input.GetAxis("Vertical");
            ud = Input.GetAxis("UpDown");

            /*helgiTr.Translate(Vector3.left * v * speed * Time.deltaTime);
            helgiTr.Translate(Vector3.back * h * speed * Time.deltaTime);*/
            Vector3 moveDir = (Vector3.forward * v) + (Vector3.right * h) + (Vector3.up * ud);
            helgiTr.Translate(moveDir.normalized * Time.deltaTime * speed, Space.Self);
            helgiTr.Rotate(Vector3.up * Input.GetAxis("Mouse X") * rotspeed * Time.deltaTime);
        }
        
    }
    private void OnCollisionEnter(Collision collision)
    {
        IsGround = true;
    }
    private void OnCollisionExit(Collision collision)
    {
        IsGround = false;
    }

}
