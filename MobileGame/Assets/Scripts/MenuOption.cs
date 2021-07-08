using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MenuOption : MonoBehaviour
{
    public Transform dropDown;
    public GameObject Light;

    
    void Update()
    {
        if(dropDown.GetComponent<Dropdown>().value == 0)
        {
            Light.GetComponent<Light>().shadows = LightShadows.Soft;
        }
        if (dropDown.GetComponent<Dropdown>().value == 1)
        {
            Light.GetComponent<Light>().shadows = LightShadows.Hard;
        }
        if (dropDown.GetComponent<Dropdown>().value == 2)
        {
            Light.GetComponent<Light>().shadows = LightShadows.None;
        }
    }
}
