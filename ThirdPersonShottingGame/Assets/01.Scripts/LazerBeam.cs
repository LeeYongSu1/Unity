using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LazerBeam : MonoBehaviour
{
    private Transform tr;
    private LineRenderer line;
    private Ray ray;//광선 자료형(구조체)
    private RaycastHit hit;
    void Start()
    {
        tr = GetComponent<Transform>();
        line = GetComponent<LineRenderer>();
        line.useWorldSpace = false;
        line.enabled = false;
        line.SetWidth(0.3f, 0.01f); //라인 시작과 종료 폭 설정
    }

    
    void Update()
    {
        ray = new Ray(tr.position + (Vector3.up * 0.02f), tr.forward);
        Debug.DrawRay(ray.origin, ray.direction * 100f, Color.red);

        if (Input.GetMouseButtonDown(0))
        {
            
            line.SetPosition(0, tr.InverseTransformPoint(ray.origin)); //Inverse = //2차원 좌표를 3차원 좌표로 바꾼다.
            //라인렌더러 첫번째 점의 위치 설정
            if(Physics.Raycast(ray, out hit, 100f))//레이를 쐈는데 맞았다면
            {
                line.SetPosition(1, tr.InverseTransformPoint(hit.point));//맞은 지점이 끝점 혹은 두번째 지점
            }
            else
            {
                line.SetPosition(1, tr.InverseTransformPoint(ray.GetPoint(100.0f)));
            }
            StartCoroutine(ShowLazerBeam());
        }
    }


    IEnumerator ShowLazerBeam()
    {
        line.enabled = true;
        yield return new WaitForSeconds(Random.Range(0.01f, 0.2f));
        line.enabled = false;
    }
    IEnumerator ShowLazerBeamAuto()
    {
        while(true)
        {
            line.enabled = true;
            yield return new WaitForSeconds(0.35f);
            line.enabled = false;
            yield return new WaitForSeconds(0.35f);
            line.enabled = true;
            yield return new WaitForSeconds(0.35f);
            line.enabled = false;

        }
        
    }
}
