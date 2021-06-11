using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class OutLight1 : MonoBehaviour

{
    public Light YelloLight;
    public Light PinkLight;
    public Light blueLight;
    
	void Start()
    {
        TurnOn();
    }
	void TurnOn()
    {
        StartCoroutine(LightChange());
    }

    IEnumerator LightChange()
    {
        YelloLight.enabled = true;
        PinkLight.enabled = false;
        blueLight.enabled = false;
        yield return new WaitForSeconds(1.0f);

        YelloLight.enabled = false;
        PinkLight.enabled = true;
        blueLight.enabled = false;
        yield return new WaitForSeconds(1.0f);

        YelloLight.enabled = false;
        PinkLight.enabled = false;
        blueLight.enabled = true;
        yield return new WaitForSeconds(1.0f);
        TurnOn();
    }
}
