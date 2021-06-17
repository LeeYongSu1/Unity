using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Slope : MonoBehaviour
{
    [SerializeField]
    private AudioClip hitsound;

    void Start()
    {
        hitsound = Resources.Load<AudioClip>("hit");
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(gameObject.transform.tag == "BULLET")
        {
            GameManager.gmr.PlayeSfx(collision.transform.position, hitsound);
        }
    }


}
