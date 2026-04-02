#pragma once
#include<iostream>
#include"clsQueueArr.h"
using namespace std;

template<class T>
class clsStackArr : public clsQueueArr<T> {

public:
	void push(T data)
	{
		clsQueueArr<T>::_queueArr.InsertAtBeginning(data);
	}
	void pop()
	{
		clsQueueArr<T>::_queueArr.deleteFirstItem();
	}
	T top()
	{
		return clsQueueArr<T>::front();
	}
	T bottom()
	{
		return clsQueueArr<T>::back();
	}

};

