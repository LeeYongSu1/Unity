using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class StairLight : MonoBehaviour

{
    public Light s_light;
    public AudioSource Source;
    public AudioClip lightSound;
    //유니티 지원 함수 istrigger 체크시 충돌감지하는 함수
    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "Player")
        {
            s_light.enabled = true;
            Source.PlayOneShot(lightSound, 1.0f);
        }
        
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            s_light.enabled = false;
            Source.PlayOneShot(lightSound, 1.0f);
        }
    }
}
