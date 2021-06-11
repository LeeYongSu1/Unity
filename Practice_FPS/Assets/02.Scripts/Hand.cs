using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class Hand : MonoBehaviour

{
    public Animation ani;
    public SkinnedMeshRenderer spas12;
    public MeshRenderer[] AK47;
    public MeshRenderer[] UMP;
    public static bool ishaveUMP = false;
    public static bool ishaveAK47 = false;
    
    public static bool isrun = false;
    
	void Start()
    {
        spas12.enabled = false;
    }


	void Update()
    {
        Handani();
        WeaponChange();
    }

    void Handani()
    {
        if (Input.GetKey(KeyCode.LeftShift) && Input.GetKey(KeyCode.W))
        {
            ani.Play("running");
            isrun = true;
        }
        else if (Input.GetKeyUp(KeyCode.LeftShift))
        {
            ani.Play("runStop");
            isrun = false;
        }
    }
    void WeaponChange()
    {
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            for(int i = 0;i < 3; i++)
            {
                AK47[i].enabled = true;
                
            }
            for (int i = 0; i<2; i++)
            {
                UMP[i].enabled = false;
            }
            ishaveAK47 = true;
            spas12.enabled = false;
            ani.Play("draw");
            ishaveUMP = false;
        }
        else if (Input.GetKeyDown(KeyCode.Alpha2))
        {
            for (int i = 0; i< 3; i++)
            {
                AK47[i].enabled = false;
            }
            for (int i = 0; i < 2; i++)
            {
                UMP[i].enabled = false;
            }
            spas12.enabled = true;
            ani.Play("draw");
            ishaveAK47 = false;
            ishaveUMP = false;
        }
        else if (Input.GetKeyDown(KeyCode.Alpha3))
        {
            for (int i = 0; i < 3; i++)
            {
                AK47[i].enabled = false;
            }
            for (int i = 0; i < 2; i++)
            {
                UMP[i].enabled = true;
            }
            spas12.enabled = false;
            ani.Play("draw");
            ishaveAK47 = false;
            ishaveUMP = true;
        }
    }

}
