using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

[System.Serializable] // Attribute(속성)
public class AnimationWizard
{
    public AnimationClip idle;
    public AnimationClip walk;
    public AnimationClip run;
    public AnimationClip jump;
    public AnimationClip attack;
}

public class WizardCtrl : MonoBehaviour
{
    private Transform thistr;
    //public AnimationWizard wizardAni;
    public AnimationWizard wizardAni;
    private Animation ani;
    private NavMeshAgent navi;
    private RaycastHit hit; // 광선에 맞으면 충돌감지하는 구조체
    private Ray ray;        // 광선 그 자체 구조체
    private Vector3 target = Vector3.zero;
    private bool isMoving;
    private bool isAttacking;
    private bool isLanding;
    private bool isIdle;
    // Start is called before the first frame update
    void Start()
    {
        thistr = GetComponent<Transform>();
        ani = GetComponent<Animation>();
        navi = GetComponent<NavMeshAgent>();
        ani.clip = wizardAni.idle;
        ani.Play();
        isMoving = false;
        isAttacking = false;
        isLanding = false;
        isIdle = true;
        //애니메이션 클립 지정
    }
    private void OnCollisionEnter(Collision collision)
    {
        isLanding = true;
    }

    // Update is called once per frame
    void Update()
    {
        ClickMove();
        ClickAttack();
        jump();
    }

    void ClickMove()
    {           //광선을 카메라에서 마우스 포인터 지점으로 발사
                //화면에서 보는 좌표와 실제 좌표를 맞춰준다.
        ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        Debug.DrawRay(ray.origin, ray.direction * 100, Color.yellow);
        if (!isAttacking)
        {
            if (Input.GetMouseButton(0))
            {
                if (Physics.Raycast(ray, out hit, Mathf.Infinity, 1 << 12))
                {
                    navi.isStopped = false;
                    target = hit.point;
                    navi.SetDestination(target);
                    isMoving = true;
                    isIdle = false;
                    ani.CrossFade(wizardAni.walk.name, 0.3f);

                    
                }
                
            }

            if (isMoving)
            {
                float dist = Vector3.Distance(thistr.position, target);
                if (dist < 0.3f)
                {
                    ani.CrossFade(wizardAni.idle.name, 0.3f);
                    isMoving = false;
                    isIdle = true;
                }
            }
        }
    }

    void ClickAttack()
    {
       
        if (Input.GetMouseButton(1))
        {
            navi.isStopped = true;
            isIdle = false;
            ani.Play(wizardAni.attack.name);
            //StartCoroutine(AttackStop());
        }

        if(Input.GetMouseButtonUp(1))
        {
            navi.isStopped = false;
            isIdle = true;
        }
    }
    void jump()
    {
        
        if(Input.GetKeyDown(KeyCode.Space))
        {
            if (isIdle == true)
                return;
            else
                isLanding = false;
                ani.Play(wizardAni.jump.name);
                Invoke("JumpDeley", 1.0f);
        }
    }
    void JumpDeley()
    {
        if(ani.isPlaying)
        {
            ani.Stop(wizardAni.jump.name);
            ani.PlayQueued(wizardAni.run.name);
        }
    }

    //IEnumerator AttackStop()
    //{
    //    yield return new WaitForSeconds(wizardAni.attack.length);
    //    navi.isStopped = false;
    //}
}
