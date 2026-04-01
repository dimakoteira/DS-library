#pragma once
#include<iostream>
using namespace std;
template<class T>
class clsDbLinkedList
{
protected:
	int length = 0;
public:
	class Node {
	public:
		T data;
		Node* next;
		Node* prev;
	};
	Node* head = nullptr;
	void InsertAtBeginning(T value)
	{
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = head;
		newNode->prev = nullptr;
		if (head != nullptr)
			head->prev = newNode;
		head = newNode;
		length++;
	}

	void InsertAtEnd(T value)
	{
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = nullptr;
		Node* curr = head;
		if (head == nullptr)
		{
			InsertAtBeginning(value);
			return;
		}
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = newNode;
		newNode->prev = curr;
		length++;

	}

	void InsertAfter(Node* prevNode, T value)
	{
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = prevNode->next;
		newNode->prev = prevNode;
		prevNode->next = newNode;
		if (newNode->next != nullptr)
			newNode->next->prev = newNode;
		length++;
	}

	Node* FindNode(T value)
	{
		if (head == nullptr)
			return nullptr;
		if (head->data == value)
			return head;
		Node* curr = head;
		while (curr != nullptr)
		{
			if (curr->data == value)
				return curr;
			curr = curr->next;
		}
		return nullptr;
	}

	void deleteNode(Node*& n)
	{
		if (n == nullptr || head == nullptr)
			return;
		Node* curr = n;
		if (curr == head)
			head = curr->next;
		if (curr->next != nullptr)
			curr->next->prev = curr->prev;
		if (curr->prev != nullptr)
			curr->prev->next = curr->next;
		delete(curr);
		length--;
	}

	void deleteFirst()
	{
		if (head == nullptr)
			return;
		Node* curr = head;
		head = curr->next;
		if (head != nullptr)
			head->prev = nullptr;
		delete(curr);
		length--;
	}

	void deleteLast()
	{
		if (head == nullptr)
			return;
		Node* curr = head;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		if (curr->prev != nullptr)
			curr->prev->next = nullptr;
		else
			head = nullptr;
		delete(curr);
		length--;
	}

	void printList()
	{
		Node* curr = head;
		while (curr != nullptr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}

	int size()
	{
		return length;
	}
	bool isEmpty()
	{
		return size() == 0;
	}
	void clear()
	{
		while (length > 0)
			deleteFirst();
	}
	void reverse()
	{
		Node* curr = head;
		Node* temp = nullptr;
		while (curr != nullptr)
		{
			temp = curr->prev;
			curr->prev = curr->next;//swap prev and next
			curr->next = temp;
			curr = curr->prev;
		}
		if (temp != nullptr)
			head = temp->prev;
	}
	Node* getNode(int index)
	{
		if (index >= length || index < 0)
			return nullptr;
		int pos = 0;
		Node* curr = head;
		while (curr != nullptr && pos != index)
		{
			curr = curr->next;
			pos++;
		}
		return curr;

	}

	T getItem(int index)
	{
		Node* n = getNode(index);
		if (n == nullptr)
			return NULL;
		return n->data;
	}
	bool updateItem(int index, T value)
	{
		Node* item = getNode(index);
		if (item != nullptr)
		{
			item->data = value;
			return true;
		}
		else
			return false;
	}
	bool InsertAfter(int index, T value)
	{
		Node* item = getNode(index);
		if (item != nullptr)
		{
			InsertAfter(item, value);
			return true;
		}
		return false;
	}
};
