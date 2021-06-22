using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireCannon : MonoBehaviour
{
    [SerializeField]
    GameObject cannonPre = null;
    [SerializeField]
    Transform firePos;
    [SerializeField]
    AudioSource _audioSource;
    [SerializeField]
    AudioClip _clip;
    
    void Start()
    {
        cannonPre = Resources.Load<GameObject>("Cannon");
        firePos = transform.GetChild(4).GetChild(1).GetChild(1).GetComponent<Transform>();
        _audioSource = GetComponent<AudioSource>();
        _audioSource.clip = Resources.Load<AudioClip>("Sound/CannonFire") as AudioClip;
    }
    
    void Update()
    {
        Fire();
    }

    void Fire()
    {
        if(Input.GetMouseButtonDown(0))
        {
            Instantiate(cannonPre, firePos.position, firePos.rotation);
            _clip = _audioSource.clip;
            _audioSource.PlayOneShot(_clip);
        }
    }
}
