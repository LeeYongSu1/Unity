using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TouchPad : MonoBehaviour
{
    [SerializeField]
    private RectTransform touchpad;
    [SerializeField]
    private PlayerMovement playerMovement;
    private int _touchid = -1;//터치 했는지 판단
    private Vector3 _startPos = Vector3.zero;//터치패드 시작지점
    public float _dragRadius = 90f;
    private bool _buttonPressed = false; //눌렀는지 안눌렀는지 판단
    

    void Start()
    {
        touchpad = GetComponent<RectTransform>();
        playerMovement = GameObject.Find("blade_girl").GetComponent<PlayerMovement>();
        _startPos = touchpad.position;
    }

    public void ButtonDown()
    {
        _buttonPressed = true;
    }

    public void ButtonUp()
    {
        _buttonPressed = false;
        //HandleInput(_startPos);
    }

    void HandleTouchInput() //모바일 터치 함수
    {
        int i = 0;
        if(Input.touchCount > 0)//몇 번 카운트 되는 지 자동으로 카운트 된다.
        {
            foreach(Touch _touch in Input.touches)//터치 카운트 모아놓은 배열
            {
                i++;
                Vector3 touchPos = new Vector3(_touch.position.x, _touch.position.y);
                if(_touch.phase == TouchPhase.Began)//터치 유형이 시작과 같다면
                {
                    if(_touch.position.x <= (_startPos.x + _dragRadius)) //현재 터치 위치가 터치 패드 범위 안에 있다면
                    {
                        _touchid = i;
                    }
                    if (_touch.position.y <= (_startPos.y + _dragRadius)) //현재 터치 위치가 터치 패드 범위 안에 있다면
                    {
                        _touchid = i;
                    }
                }
                if(_touch.phase == TouchPhase.Moved || _touch.phase == TouchPhase.Stationary)//터치유형이 움직이고 있거나 멈춰있다면
                {
                    if(_touchid == i)
                    {
                        HandleInput(touchPos);
                    }
                }
                if(_touch.phase == TouchPhase.Ended) //터치가 끝나면
                {
                    if(_touchid == i)
                    {
                        _touchid = -1;
                    }
                }
            }
        }
    }

    void HandleInput(Vector3 input)//마우스 클릭으로 터치 하는 함수
    {
        if(_buttonPressed == true)
        {
            Vector3 diffVector = (input - _startPos);
            if(diffVector.sqrMagnitude > _dragRadius * _dragRadius)//터치 지점이 원의 넓이를 넘어갔다면
            {
                diffVector.Normalize();
                touchpad.position = _startPos + diffVector * _dragRadius;
                //방향은 유지하고 범위를 벗어나지 않도록
                Debug.Log(_startPos + diffVector);
            }
            else
            {
                touchpad.position = input;
            }
        }
        else
        {
            touchpad.position = _startPos;
        }
        Vector3 diff = touchpad.position - _startPos;
        Vector3 normalDiff = new Vector3(diff.x / _dragRadius, diff.y / _dragRadius);//거리 값에 원의 반지름을 나누면 방향벡터가 구해짐

        if(playerMovement != null)
        {
            playerMovement.OnStickChanged(normalDiff);
        }
    }

    void Update()
    {
        if(Application.platform == RuntimePlatform.Android)
        {
            HandleTouchInput();
        }
        if(Application.platform == RuntimePlatform.WindowsEditor)
        {
            HandleInput(Input.mousePosition);
        }
    }
}
