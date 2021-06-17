using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LightObjectPool : MonoBehaviour
{
    public GameObject Light_1;
    public GameObject Light_2;
    public GameObject ParentLightObj;
    public List<GameObject> LightPool = new List<GameObject>();

    private void Awake()
    {
        
    }

    private void Start()
    {
        for (int i = 0; i< 1; i++)
        {
            GameObject lightobj1 = (GameObject)Instantiate(Light_1);
            GameObject lightobj2 = (GameObject)Instantiate(Light_2);
            lightobj1.transform.parent = ParentLightObj.transform;
            lightobj2.transform.parent = ParentLightObj.transform;
            lightobj1.transform.localPosition = new Vector3(-3.577f, -0.221f, 25.652f);
            lightobj2.transform.localPosition = new Vector3(-3.577f, -0.221f, 22.652f);
            LightPool.Add(lightobj1);
            LightPool.Add(lightobj2);
        }
    }

    public void LightObjectPoolManager()
    {

    }
}
