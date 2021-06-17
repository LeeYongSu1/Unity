using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//[RequireComponent (typeof(AudioSource))] //반드시 필요한 컴퍼넌트를 명시해서 해당 컴퍼넌트가 삭제 되지 않도록 방지한다
public class WallCtrl : MonoBehaviour
{
    [Header("Wall Hit Effect")]
    [SerializeField]
    private GameObject hiteffect;
    [SerializeField]
    private AudioClip hitsound;

    void Start()
    {
        hiteffect = Resources.Load<GameObject>("Effects/Flare");
        hitsound = Resources.Load<AudioClip>("hit");
    }


    /*private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "BULLET")
        {
            Destroy(collision.gameObject);
            GameObject eff = Instantiate(hiteffect, collision.transform.position*//*맞은 위치*//*, Quaternion.identity*//*회전 안하게*//*);
            GameManager.gmr.PlayeSfx(collision.transform.position, hitsound);
            //지역 변수를 준 이유 effect가 사라지면 본체가 사라져서 이펙트 생성이 안됨
            Destroy(eff, 2f);
        }
    }*/

    void OnDamage(object[] _params)
    {
        Vector3 hitpos = (Vector3)_params[0];
        GameManager.gmr.PlayeSfx(hitpos, hitsound);
        GameObject eff = Instantiate(hiteffect, hitpos, Quaternion.identity);

        //지역 변수를 준 이유 effect가 사라지면 본체가 사라져서 이펙트 생성이 안됨
        Destroy(eff, 2f);
    }
}
