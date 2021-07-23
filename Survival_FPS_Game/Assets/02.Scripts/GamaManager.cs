using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class GamaManager : MonoBehaviour
{
    private bool isPause;
    public Image minimap;
    private float timePrev;

    private void Awake()
    {
        isPause = false;
    }
    private void Start()
    {
        timePrev = Time.time;
    }

    private void Update()
    {
        if(Time.time - timePrev > 0.5f)
        {
            minimap.enabled = !minimap.enabled;
            timePrev = Time.time;
        }
        
    }

    public void Pause()
    {
        isPause = !isPause;
        Time.timeScale = (isPause) ? 0 : 1;
    }
}
