using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterMove : MonoBehaviour
{
    [SerializeField]
    private Transform _Path;
    [SerializeField]
    Transform[] _PathTransforms;
    [SerializeField]
    List<Transform> nodes;
    [SerializeField]
    Transform tr;
    [SerializeField]
    public Transform target;
    [SerializeField]
    Animator anim;
    Rigidbody rbody;

    Vector3 movement;
    public int CurrnetNode = 0;
    public float speed = 6.0f;
    float time;
    float checkTime;
    public float H_Speed;
    bool isSurch = true;

    void Start()
    {
        rbody = GetComponent<Rigidbody>();
        _Path = GameObject.Find("Path").transform;
        _PathTransforms = _Path.transform.GetComponentsInChildren<Transform>();
        nodes = new List<Transform>();
        tr = gameObject.transform;
        anim = GetComponent<Animator>();
        for (int i = 0; i < _PathTransforms.Length; i++)
        {
            if (_PathTransforms[i] != _Path.transform)
            {
                nodes.Add(_PathTransforms[i]);
            }
        }
        CurrnetNode = 0;
        time = 0.0f;
        checkTime = 1.0f;
    }
    void FixedUpdate()
    {
        if (isSurch == true) //순찰중이면 왔다 갔다 함수 호출
        {
            CheckWayPointDistance();
            MonsterMoveCtr();
            TargetSurch();
        }
        else//아니면 공격
        {
            Attack();
        }

    }


    void MonsterMoveCtr()
    {
        //anim.SetTrigger("Walk");
        Vector3 arrivedist = nodes[CurrnetNode].position - tr.position;
        tr.rotation = Quaternion.Slerp(tr.rotation, Quaternion.LookRotation(arrivedist), Time.deltaTime * 2f);
        tr.Translate(Vector3.forward * Time.deltaTime * 2f);
        float dist = Vector3.Distance(tr.position, nodes[CurrnetNode].position);
    }

    void CheckWayPointDistance()
    {
        if (Vector3.Distance(tr.position, nodes[CurrnetNode].position) < 5.5f)
        {
            if (CurrnetNode == nodes.Count - 1)
            {
                CurrnetNode = 0;
            }
            else
            {
                CurrnetNode++;
            }
        }
    }

    void TargetSurch()
    {
        float distance = Vector3.Distance(transform.position, target.position);
        if (distance < 10.0f)
        {
            isSurch = false;

        }
    }
    void Attack()
    {
        Vector3 attackdist = target.position - tr.position;
        
        tr.rotation = Quaternion.Slerp(tr.rotation, Quaternion.LookRotation(attackdist), Time.deltaTime * 3.0f);

        float dist = Vector3.Distance(tr.position, target.position);
        if (dist > 50.0f)
        {
            isSurch = true;
        }

    }
}
