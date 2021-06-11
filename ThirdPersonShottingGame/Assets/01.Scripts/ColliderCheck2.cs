using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColliderCheck2 : MonoBehaviour
{
    [SerializeField]
    private GameObject player;
    [SerializeField]
    private ApachCtl apach;

    void Start()
    {
        player = GameObject.FindWithTag("Player").gameObject;
        apach = transform.parent.GetComponent<ApachCtl>();
    }
    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "Player")
        {
            player.SetActive(false);
            apach.IsGetIn = true;
            Camera.main.transform.GetComponent<CameraController>().target = transform.parent.GetComponent<Transform>();
        }
    }

    void Update()
    {
        GetOutHellgi();
    }

    public void GetOutHellgi()
    {
        if(Input.GetKeyDown(KeyCode.F) && apach.IsGround==true)
        {
            player.SetActive(true);
            apach.IsGetIn = false;
            Camera.main.transform.GetComponent<CameraController>().target = player.transform;
            player.transform.position = 
                new Vector3(apach.transform.position.x+10f, apach.transform.position.y,apach.transform.position.z);

            apach.GetComponent<Rigidbody>().useGravity = true;
            apach.GetComponent<Rigidbody>().mass = 100;
        }
    }
}
