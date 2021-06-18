using System.Collections;

using System.Collections.Generic;

using UnityEngine;


public class StairLight : MonoBehaviour

{
    public Light s_light;
    public AudioSource Source;
    public AudioClip lightSound;

    public static bool IsExit = false;  //라이트 근처인지 아닌지 판단
    public static int lightcount = 0;   //OnTrigger()함수 충돌 감지시 카운트
    LightObjectPool lightObjectPool;    //라이트를 오브젝트풀링하는 스크립트 연결

    //유니티 지원 함수 istrigger 체크시 충돌감지하는 함수

    private void Awake()
    {
        lightObjectPool = GameObject.Find("In_light").GetComponent<LightObjectPool>();
    }
    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "Player" || other.gameObject.tag=="ENEMY")
        {
            lightcount++;
            s_light.enabled = true;
            Source.PlayOneShot(lightSound, 1.0f);
            IsExit = false;
            lightObjectPool.LightObjectPoolManager();
        }
        
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Player" || other.gameObject.tag == "ENEMY")
        {
            s_light.enabled = false;
            Source.PlayOneShot(lightSound, 1.0f);
            IsExit = true;
        }
    }
}
