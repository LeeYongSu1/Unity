using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Barrel : MonoBehaviour
{
    [SerializeField]
    private GameObject hiteffect;
    [SerializeField]
    private GameObject boomEff;

    [SerializeField]
    private AudioSource source;
    [SerializeField]
    private AudioClip a_clip;

    public int hitcount = 0;
    private Transform tr;
    public Texture[] textures;

    void Start()
    {
        hiteffect = Resources.Load<GameObject>("Effects/Flare");
        boomEff = Resources.Load<GameObject>("Effects/Exp");
        source = GetComponent<AudioSource>();
        a_clip = Resources.Load<AudioClip>("missile_explosion");
        tr = GetComponent<Transform>();
        textures = Resources.LoadAll<Texture>("Textrue");

        /*int idx = Random.Range(0, 2);
        GetComponentInChildren<MeshRenderer>().material.mainTexture = textures[idx];*/
        //자기자신 하위에 자식 오브젝트의 메쉬랜더러 컴퍼넌트
    }
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag=="BULLET")
        {
            Destroy(collision.gameObject);
            GameObject eff = Instantiate(hiteffect, collision.transform.position, Quaternion.identity);
            Destroy(eff, 3.0f);
            hitcount++;
            if (hitcount>=3)
            {
                Explosion();
                Destroy(gameObject, 1.0f);
            }
        }
    }

    void Explosion()
    {
        GameObject boom = Instantiate(boomEff, transform.position, Quaternion.identity);
        Destroy(boom, 2.0f);
        source.PlayOneShot(a_clip, 1.0f);

        Collider[] colls = Physics.OverlapSphere(transform.position, 25f);
        //25반경안에서 스피어가 겹치는 리지드바디나 콜라이더를 달고있는 오브젝트를 찾아서 colls에 넣어준다.
        foreach(Collider col in colls)
        {
            Rigidbody r_body = col.GetComponent<Rigidbody>();
            if (r_body != null)//리지디바디를 가지고 있다면
            {
                if(col.gameObject.tag != "Player")
                {
                    r_body.mass = 1f;
                    //폭파력/위치/반경/위로 솟구치는 힘
                    r_body.AddExplosionForce(1000f, transform.position, 25f, 650f);
                    
                }
                
            }
        }
    }

}
