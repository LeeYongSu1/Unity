using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ApachCtl : MonoBehaviour
{
    [SerializeField]
    private Transform tr;
    float h, v, ud, rot;
    public float speed = 10.0f;
    public float rotSpeed = 100.0f;
    public bool IsGetIn;
    public bool IsGround;
    [SerializeField]
    private Rigidbody rbody;

    void Start()
    {
        tr = GetComponent<Transform>();
        rbody = GetComponent<Rigidbody>();
        IsGround = true;
        IsGetIn = false;
    }

    
    void Update()
    {
        ApachController();
    }

    void ApachController()
    {
        if(IsGetIn==true)
        {
            rbody.useGravity = false;
            rbody.mass = 1;
            h = Input.GetAxis("Horizontal");
            v = Input.GetAxis("Vertical");
            ud = Input.GetAxis("UpDown");

            Vector3 moveDir = (Vector3.forward * v) + (Vector3.right * h) + (Vector3.up * ud);
            tr.Translate(moveDir.normalized * Time.deltaTime * speed, Space.Self);

            tr.Rotate(Vector3.up * Input.GetAxis("Mouse X") * rotSpeed * Time.deltaTime);
        }
        
    }
}
