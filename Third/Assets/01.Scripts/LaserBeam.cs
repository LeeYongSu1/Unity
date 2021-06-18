using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LaserBeam : MonoBehaviour
{
    private Transform tr;
    private LineRenderer line;
    private Ray ray;
    private RaycastHit hit;

    // Start is called before the first frame update
    void Start()
    {
        tr = GetComponent<Transform>();
        line = GetComponent<LineRenderer>();
        line.useWorldSpace = false;
        line.enabled = false;
        //라인 시작폭, 종료폭
        line.startWidth = 0.3f;
        line.endWidth = 0.01f;

    }

    // Update is called once per frame
    void Update()
    {
        ray = new Ray(tr.position+(Vector3.up*0.02f), tr.forward);
        Debug.DrawRay(ray.origin, ray.direction * 100f, Color.blue);

        if(Input.GetMouseButtonDown(0))
        {
            line.SetPosition(0, tr.InverseTransformPoint(ray.origin));
            //InverseTransformPoint(): 2차원 좌표를 3차원좌표로 변환

            if(Physics.Raycast(ray, out hit, 100))
            //광선을 발사해서 어떤 오브젝트에 맞았다면
            {
                line.SetPosition(1, tr.InverseTransformPoint(hit.point));
                //맞은 지점이 끝 점 혹은 두번째 지점
            }
            else
            {
                line.SetPosition(1, tr.InverseTransformPoint(ray.GetPoint(100.0f)));
            }

            StartCoroutine(ShowLaserBeam());

        }
    }

    IEnumerator ShowLaserBeam()
    {
        line.enabled = true;
        yield return new WaitForSeconds(Random.Range(0.01f, 0.1f));
        line.enabled = false;
    }
}
