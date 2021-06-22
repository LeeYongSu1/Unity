using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WheelAni : MonoBehaviour
{
    float scrollSpeed = 0.1f;
    Renderer _renderer;

    void Start()
    {
        _renderer = GetComponent<Renderer>();
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        float offset = Time.time * scrollSpeed * Input.GetAxisRaw("Vertical");//즉시성 GetAxis보다 빠르게 반응한다.
        _renderer.material.SetTextureOffset("_MainTex", new Vector2(0f, offset));//기본 텍스처의 y오프셋 값 변경
        _renderer.material.SetTextureOffset("_BumpMap", new Vector2(0f, offset));//노말 텍스처의 y오프셋 값 변경
    }
}
