using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class PlayerHP : MonoBehaviour
{
    [SerializeField]
    private Image hpbar;
    private Text hptxt;
    public int hp = 100;
    public int hpinit;


    void Start()
    {
        hpinit = hp;
        hpbar = GameObject.Find("Canvas-hp").transform.GetChild(0).transform.GetChild(0).GetComponent<Image>();
        hpbar.color = Color.green;
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.tag =="PUNCH")
        {
            hp -= other.gameObject.GetComponent<Monster>().damage;
            hpbar.fillAmount = (float)hp / (float)hpinit;
            hptxt.text = "HP: " + hp.ToString();
        }
    }
}
