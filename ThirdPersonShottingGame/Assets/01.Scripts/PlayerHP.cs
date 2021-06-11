using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class PlayerHP : MonoBehaviour
{
    [SerializeField]
    private Image hpbar;
    [SerializeField]
    private Text hptxt;
    public int hp = 100;
    public int hpinit;


    void Start()
    {
        hpinit = hp;
        hpbar = GameObject.Find("Canvas-hp").transform.GetChild(0).transform.GetChild(0).GetComponent<Image>();
        hpbar.color = Color.green;
        hptxt = GameObject.Find("Canvas-hp").transform.GetChild(0).transform.GetChild(1).GetComponent<Text>();
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.tag =="PUNCH")
        {
            hp -= 15;
            Debug.Log(hp);
            hpbar.fillAmount = (float)hp / (float)hpinit;
            hptxt.text = "HP: " + hp.ToString();
            if(hp<=0)
            {
                PlayerDie();
            }
        }
    }
    void PlayerDie()
    {

    }
}
