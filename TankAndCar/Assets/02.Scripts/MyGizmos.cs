using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MyGizmos : MonoBehaviour
{
    public float _radius = 0.5f;
    public Color _color = Color.red;

    void Start()
    {
        
    }

    private void OnDrawGizmos() //기즈모 좌표에 색이나 선을 입히는 함수
    {
        Gizmos.color = _color;
        Gizmos.DrawSphere(transform.position, _radius);
    }

}
