#pragma once
#include "Node.h"


template <typename T>
class GameLog
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	GameLog() : head(nullptr), tail(nullptr) {}

	GameLog(GameLog&) = delete;
	GameLog& operator=(GameLog&) = delete;

	~GameLog(){}

	//methods
	void addToTail(const T& value)
	{
		Node<T>* temp = new Node<T>(value);
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else 
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void show() const
	{
		for (Node<T>* node = head; node != nullptr; node = node->next)
		{
			cout << node->data << endl;
		}
	}

	void reverse()
	{
		Node<T>* previous = nullptr;
		Node<T>* current = head;
		tail = head;

		while (current != nullptr)
		{
			Node<T>* nextNode = current->next; 
			current->next = previous; 
			previous = current;
			current = nextNode;
		}

		head = previous;
	}
};

