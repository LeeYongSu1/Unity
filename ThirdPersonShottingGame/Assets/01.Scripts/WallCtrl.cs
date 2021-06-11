using System.Collections;
using System.Collections.Generic;
using UnityEngine;
[RequireComponent (typeof(AudioSource))] //반드시 필요한 컴퍼넌트를 명시해서 해당 컴퍼넌트가 삭제 되지 않도록 방지한다
public class WallCtrl : MonoBehaviour
{
    [Header("Wall Hit Effect")]
    [SerializeField]
    private GameObject hiteffect;
    [SerializeField]
    private AudioSource source;
    [SerializeField]
    private AudioClip hitsound;

    void Start()
    {
        hiteffect = Resources.Load<GameObject>("Effects/Flare");
        source = GetComponent<AudioSource>();
        hitsound = Resources.Load<AudioClip>("hit");
    }


    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "BULLET")
        {
            Destroy(collision.gameObject);
            source.PlayOneShot(hitsound, 1.0f);
            GameObject eff = Instantiate(hiteffect, collision.transform.position/*맞은 위치*/, Quaternion.identity/*회전 안하게*/);
            //지역 변수를 준 이유 effect가 사라지면 본체가 사라져서 이펙트 생성이 안됨
            Destroy(eff, 2f);
        }
    }
}
