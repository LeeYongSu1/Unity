using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//[RequireComponent (typeof(AudioSource))]
////반드시 필요한 컴포넌트를 명시하고 해당 컴포넌트가 삭제되는것을 방지하는 Attribute

public class WallCtrl : MonoBehaviour
{
    [Header("Wall Hit Effect")]
    [SerializeField]
    private GameObject hiteffect;
    [SerializeField]
    private AudioClip hitsound;

    // Start is called before the first frame update
    void Start()
    {
        hiteffect = Resources.Load<GameObject>("Effects/MetalHit/Flare");
        hitsound = Resources.Load<AudioClip>("Effects/MetalHit/hit");
        
    }

    //private void OnCollisionEnter(Collision collision)
    //{
    //    if(collision.gameObject.tag == "BULLET")
    //    {
    //        Destroy(collision.gameObject);
    //        GameManager.gmr.PlaySfx(collision.transform.position, hitsound);
    //        GameObject eff = Instantiate(hiteffect, collision.transform.position, Quaternion.identity);
    //        Destroy(eff, 0.1f);
    //    }
    //}

    void OnDamage(object[] _params)
    {
        Vector3 hitpos = (Vector3)_params[0];
        GameManager.gmr.PlaySfx(hitpos, hitsound);
        GameObject eff = Instantiate(hiteffect, hitpos, Quaternion.identity);
        Destroy(eff, 0.1f);
    }
}
