using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    [SerializeField]
    Rigidbody rbody;
    [SerializeField]
    CapsuleCollider col;
    [SerializeField]
    AudioSource playerAudio;
    [SerializeField]
    AudioClip swordClip;
    [SerializeField]
    AudioClip[] footSteps;
    [SerializeField]
    Transform tr;
    [SerializeField]
    Animator anim;

    private float h = 0f, v = 0f;
    float lastAttackTime, lastSkillTime, lastDashTime, lastDashAttack;
    bool isAttack;
    bool dash;
    void Start()
    {
        isAttack = false;
        dash = false;
        rbody = GetComponent<Rigidbody>();
        col = GetComponent<CapsuleCollider>();
        playerAudio = GetComponent<AudioSource>();
        swordClip = Resources.Load<AudioClip>("coconut_throw");
        footSteps = Resources.LoadAll<AudioClip>("FootStep");
        tr = GetComponent<Transform>();
        anim = GetComponent<Animator>();
        
    }

    public void OnStickChanged(Vector2 stick)//조이스틱 움직임
    {
        h = stick.x;
        v = stick.y;
    }
    #region moving
    public void OnAttackDown()
    {
        isAttack = true;
        anim.SetBool("Combo", true);
        StartCoroutine(StartAttack());
    }

    public void OnAttackUp()
    {
        isAttack = false;
        anim.SetBool("Combo", false);
    }

    IEnumerator StartAttack()
    {
        if(Time.time - lastAttackTime > 0.7f)
        {
            lastAttackTime = Time.time;
            while(isAttack == true)
            {
                anim.SetBool("Combo", true);
                yield return new WaitForSeconds(1f);
            }
        }
    }

    public void OnSkillDown()
    {
        if(Time.time - lastSkillTime > 1.0f)
        {
            anim.SetBool("isSkill", true);
            lastSkillTime = Time.time;
        }
        
        if (!playerAudio.isPlaying)//오디오가 플레이중이 아니라면
        {
            playerAudio.clip = swordClip;
            playerAudio.PlayDelayed(0.5f);
            playerAudio.Play();

        }

    }

    public void OnSkillUp()
    {
        anim.SetBool("isSkill", false);
    }

    public void OnDashDown()
    {
        if(Time.time - lastDashTime > 1.0f)
        {
            lastDashTime = Time.time;
            dash = true;
            anim.SetBool("Dash", true);
        }
    }

    public void OnDashUp()
    {
        if (Time.time - lastDashTime > 1.0f)
        {
            lastDashTime = Time.time;
            dash = false;
            anim.SetBool("Dash", false);
        }
    }

    public void OnDashAttackDown()
    {
        if (Time.time - lastDashAttack > 1.0f)
        {
            lastDashAttack = Time.time;
            anim.SetTrigger("DashAttack");
        }
    }

    public void OnDashAttackUp()
    {
        
    }

    #endregion
    void FixedUpdate()
    {
        if(anim != null)
        {
            anim.SetFloat("Speed", (h * h + v * v));
            if(rbody != null)
            {
                Vector3 Speed = rbody.velocity;
                Speed.x = 4 * h;
                Speed.z = 4 * v;
                rbody.velocity = Speed;
                if(h != 0f && v != 0f) //터치패드의 움직임이 있다면
                {
                    if(anim.GetFloat("Speed") > 0.3)
                    {
                        if (!playerAudio.isPlaying)
                        {
                            playerAudio.pitch = 1.4f;
                            playerAudio.PlayOneShot(footSteps[Random.Range(0, 1)], 1.0f);
                        }
                    }
                    else
                    {
                        if (!playerAudio.isPlaying)
                        {
                            playerAudio.pitch = 1f;
                            playerAudio.PlayOneShot(footSteps[Random.Range(0, 1)], 1.0f);
                        }

                    }
                    tr.rotation = Quaternion.LookRotation(new Vector3(h, 0f, v));
                    
                        
                }
            }
        }
    }
}
