using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController1 : MonoBehaviour
{
    [SerializeField]
    Define.CameraMode _mode = Define.CameraMode.QuarterView;

    [SerializeField]
    Vector3 _delta = new Vector3(0.0f, 6.0f, -5.0f);

    [SerializeField]
    GameObject _player = null;
    private Transform tr;
    public Transform target;
    public float dist = 10f;    //카메라와 타겟의 거리
    public float height = 5f;    //카메라의 높이
    public float SmoothRotate = 3f; //카메라 회전 부드러운 정도

    void Start()
    {
        tr = GetComponent<Transform>();
    }

    void LateUpdate()
    { 
        if (_mode == Define.CameraMode.QuarterView)
        {
            RaycastHit hit;
            if (Physics.Raycast(_player.transform.position, _delta, out hit, _delta.magnitude, LayerMask.GetMask("Wall")))
            {
                float dist = (hit.point - _player.transform.position).magnitude * 0.8f;
                transform.position = _player.transform.position + _delta.normalized * dist;
            }
            else
            {
				transform.position = _player.transform.position + _delta;
				transform.LookAt(_player.transform);
			}
		}
        float angle = Mathf.LerpAngle(tr.eulerAngles.y, target.eulerAngles.y, SmoothRotate * Time.deltaTime); //Mathf =수학공식을 모아 놓은 클래스

        Quaternion rot = Quaternion.Euler(0.0f, angle, 0f);

        tr.position = target.position - (rot * Vector3.forward * dist) + (Vector3.up * height);
        /* tr.position = new Vector3(target.position.x - 0.52f, tr.position.y , target.position.z - 6.0f);*/
        tr.LookAt(target);

    }

    public void SetQuarterView(Vector3 delta)
    {
        _mode = Define.CameraMode.QuarterView;
        _delta = delta;
    }
}
