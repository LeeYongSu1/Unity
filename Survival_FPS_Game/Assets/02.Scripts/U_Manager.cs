using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityStandardAssets.Characters.FirstPerson;

public class U_Manager : MonoBehaviour

{
    public Text killtxt;
    
    //UI매니저라는 곳에 다른 클래스가 쉽게 접근 하기 위해서
    //대표 변수를 선언
    public static U_Manager umanager;
    public static int total = 0;

    void Start()
    {
        umanager = this;
    }

	void Update()
    {
        if (PlayerHP.IsPlayerDie)
        {
            GameObject.FindWithTag("Player").GetComponent<FirstPersonController>().enabled = false;
            //하이라키에서 Player태그를 가진 오브젝트를 찾아서 끈다.
        }
    }

    public void KillCount(int killcount)
    {
        total += killcount;
        killtxt.text = "Kill Count : "+ total.ToString();
    }
}
