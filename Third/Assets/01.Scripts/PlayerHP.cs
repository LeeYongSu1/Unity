using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerHP : MonoBehaviour
{
    private int hp = 100;
    private int curHp;
    public int damage = 15;
    private Image hpBar;
    private Text hpText;
    // Start is called before the first frame update
    void Start()
    {
        hpBar = GameObject.Find("Canvas-UI").transform.GetChild(0).GetChild(0).GetComponent<Image>();
        hpText = GameObject.Find("Canvas-UI").transform.GetChild(0).GetChild(1).GetComponent<Text>();
        hpBar.color = Color.green;
        curHp = hp;
        hpText.text = curHp.ToString() + " / " + hp.ToString();
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.CompareTag("PUNCH"))
        {
            //Damage(15);
            Damage(other.transform.parent.parent.parent.parent.parent.GetComponent<MonsterCtrl>().damage);
        }
    }

    void Damage(int damage)
    {
        curHp -= damage;
        hpBar.fillAmount = (float)curHp / hp;
        hpText.text = curHp.ToString() + " / " + hp.ToString();
        if(hpBar.fillAmount <= 0.3f)
        {
            hpBar.color = Color.red;
        }
        else if(hpBar.fillAmount<=0.5f)
        {
            hpBar.color = Color.yellow;
        }

        if(hp<=0)
        {
            Die();
        }
    }

    void Die()
    {
        GameManager.gmr.isGameOver = true;
    }

}
