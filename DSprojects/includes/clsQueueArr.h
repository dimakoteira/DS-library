#pragma once
#include<iostream>
#include"clsDynamicArray.h"
using namespace std;

template<class T>
class clsQueueArr {
protected:
	clsDynamicArray<T> _queueArr;//composition

public:
	void push(T data)
	{
		_queueArr.InsertAtEnd(data);
	}
	int size()
	{
		return _queueArr.size();
	}
	T front() 
	{
		return _queueArr.getItem(0);
	}
	T back()
	{
		return _queueArr.getItem(_queueArr.size() - 1);
	}
	void pop()
	{
		_queueArr.deleteFirstItem();
	}
	void print()
	{
		_queueArr.print();
	}
	bool isEmpty()
	{
		return _queueArr.isEmpty();
	}
	T getItem(int index)
	{
		return _queueArr.getItem(index);
	}
	void reverse()
	{
		_queueArr.reverse();
	}
	void updateItem(int index, T value)
	{
		_queueArr.updateItem(index, value);
	}
	void InsertAfter(int index, T value)
	{
		_queueArr.InsertAfter(index, value);
	}
	void InsertAtFront(T value)
	{
		_queueArr.InsertAtBeginning(value);
	}
	void InsertAtBack(T value)
	{
	    _queueArr.InsertAtEnd(value);
	}
	void clear()
	{
		_queueArr.clear();
	}
};