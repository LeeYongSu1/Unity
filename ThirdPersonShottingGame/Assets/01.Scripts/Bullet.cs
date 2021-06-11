using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    [SerializeField]
    private Rigidbody rbody;
    public float speed = 50f;
    public int damage = 20;
    
    

    void Start()
    {
        rbody = GetComponent<Rigidbody>();

        rbody.AddForce(transform.forward * speed, ForceMode.Impulse);
        Destroy(gameObject, 3.0f);
    }

    
}
