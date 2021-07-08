using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class VirtualJoystick : MonoBehaviour,IPointerDownHandler,IPointerUpHandler, IDragHandler 
{
    [SerializeField]
    private RectTransform rect_Background;
    [SerializeField]
    private RectTransform rect_Joustick;
    [SerializeField]
    private GameObject go_Player;
    [SerializeField]
    private float moveSpeed;

    private float radius;
    public bool isTouch = false;
    private Vector3 movePosition;
    
    private void Start()
    {
        radius = rect_Background.rect.width * 0.5f;
        
    }
    private void Update()
    {
        if(isTouch)
        {
            go_Player.transform.position += movePosition;
        }
    }

    public void OnDrag(PointerEventData eventData)
    {
        Vector2 value = eventData.position - (Vector2)rect_Background.position;
        value = Vector2.ClampMagnitude(value, radius);
        rect_Joustick.localPosition = value;

        float distance = Vector2.Distance(rect_Background.position, rect_Joustick.position) / radius;
        value = value.normalized;
        movePosition = new Vector3(value.x * moveSpeed* distance * Time.deltaTime, 0f, value.y * moveSpeed* distance * Time.deltaTime);

        Vector3 dir = (go_Player.transform.position + movePosition) - go_Player.transform.position;
        go_Player.transform.rotation = Quaternion.LookRotation(new Vector3(movePosition.x, 0, movePosition.z));
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        isTouch = true;
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        rect_Joustick.localPosition = Vector3.zero;
        isTouch = false;
        movePosition = Vector3.zero;
    }

   
}
