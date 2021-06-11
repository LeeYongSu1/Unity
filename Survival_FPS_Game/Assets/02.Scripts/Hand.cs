using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class Hand : MonoBehaviour

{
    public Animation ani;
    public SkinnedMeshRenderer spas12;
    public MeshRenderer[] Ak47;
    public MeshRenderer[] M4a1;
    public static bool ishavem4a1 = false;
    public static bool isrun = false;
    
	void Start()
    {
        
    }
	void Update()
    {
        HandAni();
        WeaponChange();
    }

    void HandAni()
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
            for(int i=0; i<3; i++)
            {
                Ak47[i].enabled = true;
                M4a1[i].enabled = false;
            }
            spas12.enabled = false;
            ani.Play("draw");
            ishavem4a1 = false;
        }
        else if (Input.GetKeyDown(KeyCode.Alpha2))
        {
            for (int i = 0; i < 3; i++)
            {
                Ak47[i].enabled = false;
                M4a1[i].enabled = false;
            }
            spas12.enabled = true;
            ani.Play("draw");
            ishavem4a1 = false;
        }
        else if (Input.GetKeyDown(KeyCode.Alpha3))
        {
            for (int i = 0; i< 3; i++)
            {
                Ak47[i].enabled = false;
                M4a1[i].enabled = true;
            }
            spas12.enabled = false;
            ani.Play("draw");
            ishavem4a1 = true;
        }

            
    }
}
