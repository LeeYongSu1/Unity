using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotor : MonoBehaviour
{
    public float rotSpeed = 20.0f;
    void Start()
    {
        
    }

  
    void Update()
    {
        transform.Rotate(0.0f, 0.0f, rotSpeed);
    }
}
