using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameOverManager_ : MonoBehaviour
{
    public PlayerHealth_ PlayerHealth_;
    private Animator anim;


    private void Awake()
    {
        PlayerHealth_ = GameObject.Find("Player").transform.GetComponent<PlayerHealth_>();
        anim = GetComponent<Animator>();
    }


    void Update()
    {
        //플레이어 사망시 gameover문구 보여줌
        if(PlayerHealth_.currentHealth <= 0)
        {
            anim.SetTrigger("GameOver");
        }
    }
}
