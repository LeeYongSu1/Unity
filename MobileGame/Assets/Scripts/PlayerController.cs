using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    [SerializeField]
    Animator anim;
    VirtualJoystick joystick;
    public float lastAttackTime;
    public bool isAttack;
    GameObject go;

    void Start()
    {
        anim = GetComponent<Animator>();
        joystick = GameObject.Find("Canvas").transform.GetComponentInChildren<VirtualJoystick>();
        go = GameObject.Find("unitychan").gameObject;
    }
    
    void Update()
    {
        Animation();
    }

    private void Animation()
    {
        if(joystick.isTouch == true)
        {
            anim.SetBool("Walk", true);
            
        }
        else
        {
            anim.SetBool("Walk", false);
        }
    }

    public void AttackDown()
    {
        isAttack = true;
        StartCoroutine(StartAttack());
    }

    public void AttackUp()
    {
        isAttack = false;
        anim.SetBool("Attack", false);
        anim.speed = 1f;
    }

    public void Slide()
    {
        if(!isAttack)
        {
            anim.SetTrigger("Slide");
        }
    }

    public void Skill()
    {
      if(!isAttack)
        {
            anim.SetTrigger("Skill");
        }
    }

    IEnumerator StartAttack()
    {
        if (Time.time - lastAttackTime > 0.7f)
        {
            lastAttackTime = Time.time;
            while (isAttack == true)
            {
                anim.SetBool("Attack", true);
                anim.speed = 2.5f;
                yield return new WaitForSeconds(1f);
            }
        }
    }


}
