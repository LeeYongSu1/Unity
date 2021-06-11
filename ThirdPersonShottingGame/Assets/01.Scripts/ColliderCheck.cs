using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColliderCheck : MonoBehaviour
{
    [SerializeField]
    private GameObject player;
    [SerializeField]
    private HelgiController helgi;

    void Start()
    {
        player = GameObject.FindWithTag("Player").gameObject;
        helgi = transform.parent.GetComponent<HelgiController>();
        //자기 자신의 부모 컴퍼넌트에 HelgiController를 찾는다.
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            player.SetActive(false);
            helgi.IsGetIn = true;
            Camera.main.transform.GetComponent<CameraController>().target = this.transform;
        }
    }

    void Update()
    {
        GetOutHellgi();
    }
    public void GetOutHellgi()
    {
        if (Input.GetKeyDown(KeyCode.F)&&helgi.IsGround)
        {
            player.SetActive(true);
            helgi.IsGetIn = false;
            Camera.main.transform.GetComponent<CameraController>().target = player.transform;
            player.transform.position = new Vector3(helgi.transform.position.x + 10f, helgi.transform.position.y, helgi.transform.position.z);

            GetComponent<Rigidbody>().useGravity = true;
            GetComponent<Rigidbody>().mass = 100;
        }
    }
}
