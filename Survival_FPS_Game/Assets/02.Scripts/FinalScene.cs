﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class FinalScene : MonoBehaviour

{
    public Text finalkilltxt;

	void Start()
    {
        finalkilltxt.text = " Total Kill : " + U_Manager.total.ToString();
    }

	
}
