using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletCtrl : MonoBehaviour
{
    private Rigidbody rbody;
    public float speed = 50.0f;
    public int damage = 20;

    // Start is called before the first frame update
    void Start()
    {
        rbody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        rbody.AddForce(transform.forward * speed, ForceMode.Impulse);
        //(Rigidbody).AddForce(Vector3좌표, /Forcemode/)
        //Forcemode.
        Destroy(this.gameObject, 3.0f);
    }
}
