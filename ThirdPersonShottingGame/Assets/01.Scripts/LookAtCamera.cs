using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LookAtCamera : MonoBehaviour
{
    [SerializeField]
    private Transform mainCam;
    private Transform player;
    private Transform thisCanvas;


    void Start()
    {
        mainCam = Camera.main.GetComponent<Transform>();
        player = GameObject.FindWithTag("Player").GetComponent<Transform>();
        thisCanvas = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        thisCanvas.LookAt(mainCam);
    }
}
