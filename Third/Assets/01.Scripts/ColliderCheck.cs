using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColliderCheck : MonoBehaviour
{
    private GameObject player;
    private HellgiCtrl hellgictrl;

    // Start is called before the first frame update
    void Start()
    {
        player = GameObject.FindWithTag("Player").gameObject;
        hellgictrl = GetComponentInParent<HellgiCtrl>();        
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.CompareTag("Player"))
        {
            hellgictrl.isGetin = true;
            player.SetActive(false);
            Camera.main.GetComponent<FollowCamera>().target = this.transform;
        }
    }

    // Update is called once per frame
    void Update()
    {
        ExitHellgi();
    }

    void ExitHellgi()
    {
        if((hellgictrl.isGetin&&hellgictrl.isGround)&&Input.GetKeyDown(KeyCode.F))
        {
            hellgictrl.isGetin = false;
            Camera.main.GetComponent<FollowCamera>().target = player.transform;
            player.transform.Translate(transform.position + new Vector3(7, 0, 0));
            player.transform.rotation = transform.rotation;
            player.SetActive(true);
            hellgictrl.rbody.useGravity = true;
        }
    }
}
