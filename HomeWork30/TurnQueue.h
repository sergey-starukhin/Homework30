#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class TurnQueue
{
private:
	Node<T>* head;
	Node<T>* tail;
	int count;

public:
	TurnQueue() : head(nullptr), tail(nullptr), count(0) {}

	TurnQueue(TurnQueue&) = delete;
	TurnQueue& operator = (TurnQueue&) = delete;

	~TurnQueue()
	{
		while (removeCurrent())
		{
		}
	}

	//getters
	int size() const
	{
		return count;
	}

	T& current()
	{
		return head->data;
	}

	//predicates
	bool isEmpty() const
	{
		return head == nullptr;
	}

	//methods
	bool removeCurrent()
	{
		if (isEmpty())
			return false;

		Node<T>* temp = head;
		head = head->next;
		if (head == nullptr)
			tail = nullptr;
		delete temp;
		count--;
		return true;
	}

	void enqueue(const T& value)
	{
		Node<T>* temp = new Node<T>(value);

		if (isEmpty())
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		count++;
	}

	void nextTurn()
	{
		if (count < 2)
			return;

		Node<T>* temp = head;
		head = head->next;
		tail->next = temp;
		tail = temp;
		tail->next = nullptr;
	}

	void show() const
	{
		for (Node<T>* node = head; node != nullptr; node = node->next)
			cout << node->data << endl;
	}
};

