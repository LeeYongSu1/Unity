using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LookAtCamera : MonoBehaviour
{
    private Transform tr;
    private Transform mtr;


    void Start()
    {
        tr = GetComponent<Transform>();
        mtr = Camera.main.transform;
    }

    // Update is called once per frame
    void Update()
    {
        tr.LookAt(mtr.transform);
    }
}
