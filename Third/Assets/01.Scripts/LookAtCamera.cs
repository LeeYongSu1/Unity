using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LookAtCamera : MonoBehaviour
{
    //private Transform mainCam;
    //private Transform thistran;

    // Start is called before the first frame update
    void Start()
    {
        //mainCam = Camera.main.GetComponent<Transform>();
        //thistran = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        //thistran.LookAt(mainCam);
        transform.LookAt(Camera.main.transform.position);
    }
}
