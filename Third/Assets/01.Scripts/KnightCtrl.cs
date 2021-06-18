using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

[System.Serializable]
public class KnightAnimation
{
    public AnimationClip idle;
    public AnimationClip walk;
    public AnimationClip attack;
}

public class KnightCtrl : MonoBehaviour
{
    public KnightAnimation knightAniClip;
    private Animation ani;
    private Transform thisTr;
    private Vector3 target = Vector3.zero;
    private NavMeshAgent navi;
    private Ray ray;
    private RaycastHit hit;
    private bool isMoving;


    // Start is called before the first frame update
    void Start()
    {
        thisTr = GetComponent<Transform>();
        navi = GetComponent<NavMeshAgent>();
        ani = GetComponent<Animation>();
        ani.clip = knightAniClip.idle;
        ani.CrossFade(knightAniClip.idle.name,0.3f);
        isMoving = false;
    }

    // Update is called once per frame
    void Update()
    {
        ClickMove();
        ClickAttack();
    }

    void ClickMove()
    {
        ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        Debug.DrawRay(ray.origin, ray.direction * 100, Color.yellow);

        if (Input.GetMouseButton(0))
        {
            if (Physics.Raycast(ray, out hit, Mathf.Infinity, 1 << 12))
            {
                isMoving = true;
                navi.isStopped = false; ;
                target = hit.point;
                navi.SetDestination(target);
                ani.CrossFade(knightAniClip.walk.name, 0.3f);
            }
        }

        if (isMoving)
        {
            float dist = Vector3.Distance(thisTr.position, target);
            if (dist < 0.3f)
            {
                ani.CrossFade(knightAniClip.idle.name, 0.3f);
                isMoving = false;
            }
        }
    }

    void ClickAttack()
    {
        if (Input.GetMouseButton(1))
        {
            navi.isStopped = true;
            ani.Play(knightAniClip.attack.name);
        }

        if(Input.GetMouseButtonUp(1))
        {
            navi.isStopped = false;
        }
    }
}
