#pragma once
#include<iostream>
#include"clsDbLinkedList.h"
using namespace std;
template<class T>
class clsMyQueue {
protected:
	clsDbLinkedList<T> dll;
public:
	void push(T data)
	{
		dll.InsertAtEnd(data);
	}
	int size()
	{
		return dll.size();
	}
	T front()
	{
		return dll.getItem(0);
	}
	T back()
	{
		return dll.getItem(dll.size() - 1);
	}
	void pop()
	{
		dll.deleteFirst();
	}
	void print()
	{
		dll.printList();
	}
	bool isEmpty()
	{
		return dll.isEmpty();
	}
	T getItem(int index)
	{
		return dll.getItem(index);
	}
	void reverse()
	{
		dll.reverse();
	}
	void updateItem(int index, T value)
	{
		dll.updateItem(index, value);
	}
	void InsertAfter(int index, T value)
	{
		dll.InsertAfter(index, value);
	}
	void InsertAtFront(T value)
	{
		dll.InsertAtBeginning(value);
	}
	void InsertAtBack(T value)
	{
		dll.InsertAtEnd(value);
	}
	void clear()
	{
		dll.clear();
	}
};
