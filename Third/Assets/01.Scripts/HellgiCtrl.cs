using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HellgiCtrl : MonoBehaviour
{
    private float h, v, ud, rot;
    public float movespeed = 15.0f, rotspeed = 100.0f;
    public bool isGetin;
    public bool isGround;
    public Rigidbody rbody;

    // Start is called before the first frame update
    void Start()
    {
        isGetin = false;
        isGround = true;
        rbody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        HellgiContol();
    }

    void HellgiContol()
    {
        if (isGetin)
        {
            rbody.useGravity = false;
            h = Input.GetAxis("Horizontal");
            v = Input.GetAxis("Vertical");
            ud = Input.GetAxis("Updown");
            rot = Input.GetAxis("Mouse X");
            Vector3 moveDir = (Vector3.right * h) + (Vector3.forward * v) + (Vector3.up * ud);
            transform.Translate(moveDir.normalized * movespeed * Time.deltaTime);
            transform.Rotate(0f, rot * rotspeed * Time.deltaTime, 0f);
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("GROUND"))
            isGround = true;
    }

    private void OnCollisionExit(Collision collision)
    {
        if (collision.gameObject.CompareTag("GROUND"))
            isGround = false;
    }
}
