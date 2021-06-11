using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Scene_Manager : MonoBehaviour

{
    
    public Canvas endcanvas;

	void Start()
    {
        Cursor.visible = true;

        Cursor.lockState = CursorLockMode.None; //마우스 커서 움직이게

       
    }
    
	public void PlayGame()
    {
        SceneManager.LoadScene("BattleScene");
    }

    public void QuitGame()
    {
        Application.Quit();
    }
}
