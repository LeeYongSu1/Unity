using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class OutLight : MonoBehaviour

{
    public Light green;
    public Light red;
    public Light blue;
    
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
        green.enabled = true;
        red.enabled = false;
        blue.enabled = false;
        //다음 리턴은 3초 후에
        yield return new WaitForSeconds(3.0f);
        green.enabled = false;
        red.enabled = true;
        blue.enabled = false;
        yield return new WaitForSeconds(3.0f);
        
        green.enabled = false;
        red.enabled = false;
        blue.enabled = true;
        yield return new WaitForSeconds(3.0f);
        TurnOn();
    }
}
