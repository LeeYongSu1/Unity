using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BarrelCtrl : MonoBehaviour
{
    public int hitcount = 3;
    [Header("Gameobject")]
    [SerializeField]
    private GameObject hiteffect;
    [SerializeField]
    private GameObject expeffect;
    [Header("Component")]
    [SerializeField]
    private AudioClip hitsound;
    [SerializeField]
    private AudioClip expsound;
    private Rigidbody rbody;
    private Transform tr;
    public Texture[] textures;
    public int damage;


    // Start is called before the first frame update
    void Start()
    {
        hiteffect = Resources.Load<GameObject>("Effects/MetalHit/Flare");
        hitsound = Resources.Load<AudioClip>("Effects/MetalHit/hit");
        expeffect = Resources.Load<GameObject>("Effects/Explosion/Explosion");
        expsound = Resources.Load<AudioClip>("Effects/Explosion/explosion");
        rbody = GetComponent<Rigidbody>();
        tr = GetComponent<Transform>();

        textures = Resources.LoadAll<Texture>("Textures");
        damage = 100;

        int idx = Random.Range(0, textures.Length);
        GetComponentInChildren<MeshRenderer>().material.mainTexture = textures[idx];
        //자신의 하위 오브젝트의 MeshRenderer.material.mainTexture를 변경
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    //private void OnCollisionEnter(Collision collision)
    //{
    //    if(collision.gameObject.tag == "BULLET")
    //    {
    //        Destroy(collision.gameObject);
    //        GameManager.gmr.PlaySfx(collision.transform.position, hitsound);
    //        GameObject eff = Instantiate(hiteffect, collision.transform.position, Quaternion.identity);
    //        Destroy(eff, 0.2f);
    //        hitcount -= 1;
    //        if(hitcount <= 0)
    //        {
    //            Explosion();
    //        }
    //    }
    //}

    void OnDamage(object[] _params)
    {
        Vector3 hitpos = (Vector3)_params[0];
        Vector3 firepos = (Vector3)_params[1];
        
        Vector3 incomeVector = hitpos - firepos;
        //입사벡터 (Ray의 각도)
        incomeVector = incomeVector.normalized;
        rbody.AddForceAtPosition(incomeVector * 1000f, hitpos);


        GameManager.gmr.PlaySfx(hitpos, hitsound);
        GameObject eff = Instantiate(hiteffect, hitpos, Quaternion.identity);
        Destroy(eff, 0.2f);
        hitcount -= 1;
        if (hitcount <= 0)
        {
            Explosion();
        }
    }

    void Explosion()
    {
        GameManager.gmr.PlaySfx(transform.position, expsound);
        GameObject eff = Instantiate(expeffect, this.transform.position, Quaternion.identity);
        Destroy(eff, 1.0f);
        //rbody.AddForce(Vector3.up * 1000, ForceMode.Impulse);

        Collider[] colls = Physics.OverlapSphere(transform.position, 25.0f);
        //25반경 안에서 rigidbody나 collider를 달고 있는 오브젝트를 찾아서
        //colls라는 Collider배열에 넣는다.

        foreach(Collider col in colls) // colls배열의 col을 하나씩 꺼내고 배열 끝까지 반복한다
        {
            Rigidbody rb = col.GetComponent<Rigidbody>();
            if (rb!=null) //rigidbody가 있다면
            {
                if(col.gameObject.tag != "Player")
                    rb.AddExplosionForce(100000f, transform.position, 25.0f);
                //(rigidbody).AddExplosionForce(폭파력, 위치, 폭파반경)

                if (col.gameObject.tag == "Monster")
                    col.GetComponent<MonsterCtrl>().Damage(damage);
            }
        }
        Destroy(gameObject, 6.0f);

    }


}
