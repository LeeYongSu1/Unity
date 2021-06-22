using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cannon : MonoBehaviour
{
    public float Speed = 6000f;
    [SerializeField]
    GameObject expEffect;
    private Collider _collider;
    private Rigidbody rbody;
    [SerializeField]
    AudioSource _audioSource;
    AudioClip _clip;

    void Start()
    {
        expEffect = Resources.Load<GameObject>("D-Wide");
        _collider = GetComponent<CapsuleCollider>();
        rbody = GetComponent<Rigidbody>();
        rbody.AddForce(transform.forward * Speed);
        StartCoroutine(ExplosionCannon(3.0f)); //3초 후 자동 폭파
        _audioSource = GetComponent<AudioSource>();
        _audioSource.clip = Resources.Load<AudioClip>("Sound/NearExplosionA") as AudioClip;
    }

    private void OnTriggerEnter(Collider other)
    {
        StartCoroutine(ExplosionCannon(0.0f));//땅에 닿으면 바로 폭발
        _clip = _audioSource.clip;
        _audioSource.PlayOneShot(_clip, 1.0f);
    }

    IEnumerator ExplosionCannon(float _time)
    {
        yield return new WaitForSeconds(_time);
        _collider.enabled = false;
        rbody.isKinematic = true; //물리 영향을 받지 않음

        GameObject obj = (GameObject)Instantiate(expEffect, transform.position, Quaternion.identity);
        Destroy(obj, 3.0f);
        Destroy(this.gameObject, 1.0f);
    }

}
