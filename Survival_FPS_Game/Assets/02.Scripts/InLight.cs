using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class InLight : MonoBehaviour

{
    public Light light_in;
    public AudioSource a_source;
    public AudioClip a_clip;

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "Player")
        {
            light_in.enabled = true;
            a_source.PlayOneShot(a_clip, 1.0f);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            light_in.enabled = false;
            a_source.PlayOneShot(a_clip, 1.0f);
        }
    }


}
