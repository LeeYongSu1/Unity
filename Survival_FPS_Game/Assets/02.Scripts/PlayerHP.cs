using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerHP : MonoBehaviour

{
    public Image hpbar;
    private int hp = 100;
    private int hpInit = 100;
    private int dmg = 10;
    public Text hptext;
    public static bool IsPlayerDie = false;
    public Image bloodScreen;

    void Start()
    {
        hpbar.color = Color.blue;
        IsPlayerDie = false;
        bloodScreen.enabled = false;
}

	void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "PUNCH")
        {
            HpManager();
            StartCoroutine(ShowBloodScreen());
            if (hp <= 0)
            {
                PlayerDie();
            }
        }
        else if (other.gameObject.tag == "SWORD")
        {
            HpManager();
            StartCoroutine(ShowBloodScreen());
            if (hp <= 0)
            {
                PlayerDie();
            }
        }
    }

    void HpManager()
    {
        hp -= dmg;
        hpbar.fillAmount = (float)hp / (float)hpInit;
        if (hpbar.fillAmount <= 0.3f)
            hpbar.color = Color.red;
        else if (hpbar.fillAmount >= 0.5f)
            hpbar.color = Color.yellow;
        hptext.text = "Player HP : " + hp.ToString();
        if (hpbar.fillAmount <= 0.0f)
            hptext.text = "HP: 0";
    }

    void PlayerDie()
    {
        //Debug.Log("죽었다");
        IsPlayerDie = true;
        print("die!!" + hp.ToString());
        Invoke("WaitSecond", 5.0f);
        
    }

    void WaitSecond()
    {
        SceneManager.LoadScene("EndScene");
    }

    IEnumerator ShowBloodScreen()
    {
        bloodScreen.color = new Color(1, 0f, 0f, Random.Range(0.2f, 0.3f));
        yield return new WaitForSeconds(0.1f);
        bloodScreen.color = Color.clear;
    }
}
