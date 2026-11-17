#pragma once
#include "Node.h"
#include <iostream>


using namespace std;

template <typename T>
class Deck
{
private:
	Node<T>* top;
    int count;

public:
	Deck() : top(nullptr), count(0) {}

	Deck(Deck& other) = delete;
	Deck& operator=(Deck& other) = delete;

	~Deck()
	{
		while (!isEmpty())
		{
			Node<T>* temp = top;
			top = top->next;
			delete temp;
		}
	}

	//getters
	int size() const
	{
		return count;
	}

	//predicates
	bool isEmpty() const
	{
		return top == nullptr;
	}

	//methods
	void putOnTop(const T& card)
	{
		Node<T>* node = new Node<T>(card);
		node->next = top;
		top = node;
		count++;
	}

	bool draw(T& card)
	{
		if (isEmpty())
		{
			cout << "Колода пуста!" << endl;
			return false;
		}

		card = top->data;
		Node<T>* temp = top;
		top = top->next;
		delete temp;
		count--;
		return true;
	}

	void show() const
	{
		for (Node<T>* current = top; current != nullptr; current = current->next)
		{
			cout << current->data << "  ";
		}
		cout << endl;
	}
};


