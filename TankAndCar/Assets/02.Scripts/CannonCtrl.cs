using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CannonCtrl : MonoBehaviour
{
    Transform tr;
    public float rotSpeed = 300f;
    public float CurrentRotate = 0f; //현재 회전값
    public float UpperAngle = -30.0f;//최하 제한 값
    public float DownAngle = 30f;//최상 제한 값

    void Start()
    {
        tr = GetComponent<Transform>();   
    }

    
    void Update()
    {
        /*float angle = -Input.GetAxis("Mouse ScrollWheel") * Time.deltaTime * rotSpeed;
        tr.Rotate(angle, 0.0f, 0.0f);*/

        float Wheel = Input.GetAxis("Mouse ScrollWheel");
        float angle = Time.deltaTime * Wheel * rotSpeed;
        /*
            마우스 휠 업 다운 시 양수와 음수로 변경된다.
        다른 Axis(Horizontal)과 같이 -1 +1을 리턴하지 않기 때문에 양수 음수를 판단하여 각도를 제한 해야 한다.
         */
        if(Wheel <= -0.01f) //포신을 올릴 때
        {
            CurrentRotate += angle;
            if(CurrentRotate > UpperAngle)
            {
                tr.Rotate(angle, 0f, 0f);
            }
            else
            {
                CurrentRotate = UpperAngle;
            }
        }
        else
        {
            CurrentRotate += angle;
            if (CurrentRotate < DownAngle)
            {
                tr.Rotate(angle, 0f, 0f);
            }
            else
            {
                CurrentRotate = DownAngle;
            }
        }
    }

    /*void CannonMove()
    {
        if()
        float Wheel = Input.GetAxis("Mouse ScrollWheel");
        float angle = Time.deltaTime * Wheel * rotSpeed;
    }*/
}
