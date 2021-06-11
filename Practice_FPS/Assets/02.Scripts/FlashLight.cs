using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class FlashLight : MonoBehaviour

{
    public Light flashlight;
    public AudioSource a_source;
    public AudioClip a_clip;

	void Start()
    {
        
    }


	void Update()
    {
        if (Input.GetKeyDown(KeyCode.F))
        {
            flashlight.enabled = !flashlight.enabled;
            a_source.PlayOneShot(a_clip, 1.0f);
        }
    }
}
