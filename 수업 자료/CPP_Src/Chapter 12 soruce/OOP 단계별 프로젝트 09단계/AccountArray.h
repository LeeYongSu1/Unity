/*
 * 파일이름: AccountArray.h
 * 작성자: 윤성우
 * 업데이트 정보: [2010, 02, 01] 파일버전 0.1
 */

#ifndef __ACCOUN_ARRAY_H__
#include "Account.h"

template <typename T>
class BoundCheckAccountPtrArray 
{
private:
	T* arr;
	int arrlen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) { }
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) { }

public:
	BoundCheckAccountPtrArray(int len=100);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};

template <typename T>
BoundCheckAccountPtrArray<T>::BoundCheckAccountPtrArray(int len) :arrlen(len)
{
	arr = new T[len];
}

template <typename T>
T& BoundCheckAccountPtrArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckAccountPtrArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
int BoundCheckAccountPtrArray<T>::GetArrLen() const
{
	return arrlen;
}

template <typename T>
BoundCheckAccountPtrArray<T>::~BoundCheckAccountPtrArray()
{
	delete[]arr;
}
#endif