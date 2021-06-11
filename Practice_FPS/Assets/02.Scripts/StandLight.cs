using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class StandLight : MonoBehaviour

{
    public Light whitelight;
    public Light redlight;
    public Light yellolight;
    
	void Start()
    {
        TuenLightOn();
    }


	void Update()
    {
        
    }

    void TuenLightOn()
    {
        StartCoroutine(changelight());
    }

    IEnumerator changelight()
    {
        whitelight.enabled = true;
        redlight.enabled = false;
        yellolight.enabled = false;
        yield return new WaitForSeconds(3.0f);

        whitelight.enabled = false;
        redlight.enabled = true;
        yellolight.enabled = false;
        yield return new WaitForSeconds(3.0f);

        whitelight.enabled = false;
        redlight.enabled = false;
        yellolight.enabled = true;
        yield return new WaitForSeconds(3.0f);

        whitelight.enabled = true;
        redlight.enabled = true;
        yellolight.enabled = true;
        yield return new WaitForSeconds(3.0f);
        TuenLightOn();
    }
}
