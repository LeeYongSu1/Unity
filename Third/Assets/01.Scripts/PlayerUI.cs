using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerUI : MonoBehaviour
{
    [SerializeField]
    private Text killCountText;
    public int killCount;
    public static PlayerUI pui;

    private void Awake()
    {
        pui = this;
    }

    // Start is called before the first frame update
    void Start()
    {
        killCountText = GameObject.Find("Canvas-UI").transform.GetChild(1).GetChild(0).GetComponent<Text>();
        killCountText.text = "Kill : 0";
        killCount = 0;
    }

    public void DisplayKillCount()
    {
        killCountText.text = "Kill : <color=#ff0000>" + (++killCount).ToString() + "</color>";
    }
}
