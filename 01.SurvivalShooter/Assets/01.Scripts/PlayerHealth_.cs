using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class PlayerHealth_ : MonoBehaviour
{
    public int startingHealth = 100;
    public int currentHealth;
    public Slider healthSlider;
    public Image damageImage;
    public AudioClip deathClip;
    public float flashspeed = 5f;
    public Color flashColor = new Color(1f, 0f, 0f, 0.1f);

    private Animator anim;
    private AudioSource playerAudio;
    private PlayerMovement playerMovement;
    private PlayerShooting_ playerShooting;

    private bool isDead;
    private bool damaged;


    private void Awake()
    {
        anim = GetComponent<Animator>();
        playerAudio = GetComponent<AudioSource>();
        playerMovement = GetComponent<PlayerMovement>();
        playerShooting = GetComponentInChildren<PlayerShooting_>();
        currentHealth = startingHealth;
    }


    void Update()
    {
        if(damaged)
        {
            //데미지를 입으면 붉은색 화면
            damageImage.color = flashColor;
        }
        else
        {
            //원래 화면으로 돌아옴
            damageImage.color = Color.Lerp(damageImage.color, Color.clear, flashspeed * Time.deltaTime);
        }
        damaged = false;
    }

    public void TakeDamage(int amount)
    {
        damaged = true;
        currentHealth -= amount;
        healthSlider.value = currentHealth;
        playerAudio.Play();

        if(currentHealth <= 0 && !isDead)
        {
            Death();
        }
    }

    void Death()
    {
        isDead = true;
        playerShooting.DisableEffects();
        anim.SetTrigger("Die");
        playerAudio.clip = deathClip;
        playerAudio.Play();

        playerMovement.enabled = false;
        playerShooting.enabled = false; //공격불가
    }

    //게임 재실행(첫 번째 씬으로 돌아옴)
    public void RestartLevel()
    {
        SceneManager.LoadScene(0);
    }
}
