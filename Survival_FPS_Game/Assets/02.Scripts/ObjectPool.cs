using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObjectPool : MonoBehaviour
{
    public static ObjectPool Instance;

    [SerializeField]
    private GameObject zombiePre;
    public E_Manager _manager;
    public Queue<ZomBie> zombieQue = new Queue<ZomBie>();



    private void Awake()
    {
        Instance = this;
        Initialize(10);


    }
    private void Start()
    {

    }

    private ZomBie CreatNewObject()
    {
        var newObj = Instantiate(zombiePre).GetComponent<ZomBie>();
        newObj.gameObject.SetActive(false);

        return newObj;
    }

    private void Initialize(int count)
    {
        for (int i = 0; i < count; i++)
        {
            zombieQue.Enqueue(CreatNewObject());
        }
    }

    public static ZomBie GetObject()
    {
        if (Instance.zombieQue.Count > 0)
        {
            var obj = Instance.zombieQue.Dequeue();
            obj.transform.SetParent(null);
            obj.gameObject.SetActive(true);
            return obj;
        }
        else
        {
            var newObj = Instance.CreatNewObject();
            newObj.transform.SetParent(null);
            newObj.gameObject.SetActive(true);
            return newObj;
        }
        /*foreach (ZomBie zom in Instance.zombieQue)
        {
            int idx = Random.Range(1, 5);
            zom.transform.position = _manager.points[idx].position;
        }*/

    }

    public static void ReturnObject(ZomBie zomBie)
    {

        zomBie.transform.SetParent(Instance.transform);
        Instance.zombieQue.Enqueue(zomBie);
    }

}
