using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class Bullet : MonoBehaviour

{
    public float speed = 250.0f;
    public Rigidbody rbody;

    
	void Start()
    {
        rbody.AddForce(transform.forward * speed);
        Destroy(gameObject, 3.0f);
    }
	
}
