using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Menu : MonoBehaviour
{
    public RectTransform PauseImage;
    public RectTransform PauseMenu;
    public RectTransform SoundMenu;
    public RectTransform ScreenMenu;
    public GameObject directLight;

    GameObject player;

    private void Awake()
    {
        player = GameObject.Find("unitychan").gameObject;
        //PauseImage.gameObject.SetActive(false);
        //ScreenMenu.gameObject.SetActive(false);
        player.transform.position = new Vector3(PlayerPrefs.GetFloat("x"), PlayerPrefs.GetFloat("y"), PlayerPrefs.GetFloat("z")); //PlayerPrefs = 계속 저장시켜주는 로직
        player.transform.eulerAngles = new Vector3(0f, PlayerPrefs.GetFloat("Cam_y"), 0f);
        //플레이어의 y축 회전 값을 저장save하기 위해 회전값을 문자열로 얻어온다.
    }
    
    void Update()
    {
        if (Application.platform == RuntimePlatform.Android)
        {
            if(Input.GetKeyDown(KeyCode.Escape))
                Pause();
        }
        if (Application.platform == RuntimePlatform.WindowsEditor)
        {
            if (Input.GetKeyDown(KeyCode.Escape))
                Pause();
        }
        if(Application.platform == RuntimePlatform.IPhonePlayer)
        {
            if (Input.GetKeyDown(KeyCode.Escape))
                Pause();
        }
    }

    public void Pause()
    {
        if(PauseImage.gameObject.activeInHierarchy == false)
        {
            if(PauseMenu.gameObject.activeInHierarchy == false)
            {
                PauseMenu.gameObject.SetActive(true);
                SoundMenu.gameObject.SetActive(false);
                ScreenMenu.gameObject.SetActive(false);
            }
            PauseImage.gameObject.SetActive(true);
            Time.timeScale = 0f;
            player.SetActive(false);
        }
        else
        {
            PauseMenu.gameObject.SetActive(false);
            PauseImage.gameObject.SetActive(false);
            SoundMenu.gameObject.SetActive(false);
            ScreenMenu.gameObject.SetActive(false);
            Time.timeScale = 1f;
            player.SetActive(true);
        }
    }

    public void Sounds(bool open)
    {
        if(open)
        {
            SoundMenu.gameObject.SetActive(true);
            PauseMenu.gameObject.SetActive(false);
            ScreenMenu.gameObject.SetActive(false);
        }

        if(!open)
        {
            SoundMenu.gameObject.SetActive(false);
            PauseMenu.gameObject.SetActive(true);
            ScreenMenu.gameObject.SetActive(false);
        }
    }

    public void Screen(bool open)
    {
        if (open)
        {
            SoundMenu.gameObject.SetActive(false);
            PauseMenu.gameObject.SetActive(false);
            ScreenMenu.gameObject.SetActive(true);
        }

        if (!open)
        {
            SoundMenu.gameObject.SetActive(false);
            PauseMenu.gameObject.SetActive(true);
            ScreenMenu.gameObject.SetActive(false);
        }
    }

    public void SaveSetting(bool isQuit)
    {   //실행 시 위에서 등록한 키값을 찾아서 save
        PlayerPrefs.SetFloat("x", player.transform.position.x);
        PlayerPrefs.SetFloat("y", player.transform.position.y);
        PlayerPrefs.SetFloat("z", player.transform.position.z);
        PlayerPrefs.SetFloat("Cam_y", player.transform.eulerAngles.y);//y축 회전값 저장

        if (isQuit)
        {
            Time.timeScale = 0f;
            SceneManager.LoadScene("StartScene");
            
        }
    }

    public void PlayeScene()
    {
        SceneManager.LoadScene("TestScene");
        Time.timeScale = 1.0f;
    }
}
