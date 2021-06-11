using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;


public class ColliderHit : MonoBehaviour

{
    public AudioSource source;
    public AudioClip hitsound;
    public GameObject effect;
    

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "BULLET")
        {
            Destroy(collision.gameObject);
            source.PlayOneShot(hitsound, 1.0f);
            GameObject eff = Instantiate(effect, collision.transform.position/*맞은 위치*/, Quaternion.identity/*회전 안하게*/);
            //지역 변수를 준 이유 effect가 사라지면 본체가 사라져서 이펙트 생성이 안됨
            Destroy(eff, 5.0f);
        }
    }
}
