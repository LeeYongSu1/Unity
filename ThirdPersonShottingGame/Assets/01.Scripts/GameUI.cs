using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameUI : MonoBehaviour
{
    [SerializeField]
    private Text txtscore;
    private int count;
    void Start()
    {
        txtscore = GameObject.Find("Canvas-hp").transform.GetChild(1).transform.GetChild(0).GetComponent<Text>();
        DisplayScore(0);
    }
    public void DisplayScore(int _count)
    {
        count += _count;
        txtscore.text = "Kill Count: <color=#ff0000>" + count.ToString() + "</color>";
    }

    
}
