#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class DoubleLinkedList
{
private:
	Node<T>* start;
	Node<T>* end;
	int count;
public:
	DoubleLinkedList() : start(nullptr), end(nullptr), count(0) {}

	~DoubleLinkedList()
	{
		while (start)
		{
			Node<T>* next = start->urm;
			delete start;
			start = next;
		}
		this->count = 0;
	}

	int GetCount() const
	{
		return this->count;
	}

	void PushOnFront(const T& value)
	{
		Node<T>* new_node = new Node<T>(value);
		if (!start)
		{
			start = new_node;
			end = new_node;
		}
		else
		{
			new_node->urm = start;
			start->prev = new_node;
			start = new_node;
		}
		this->count++;
	}

	void PushOnBack(const T& value)
	{
		Node<T>* new_node = new Node<T>(value);
		if (!start)
		{
			start = new_node;
			end = new_node;
		}
		else
		{
			new_node->prev = end;
			end->urm = new_node;
			end = new_node;
		}
		this->count++;
	}
	T  PopFromBack()
	{
		if (!end)
		{
			return 0;
		}
		Node<T>* node_to_remove = end;
		end = end->prev;
		if (end)
		{
			end->urm = nullptr;
		}
		else
		{
			start = nullptr;
		}
		T n = node_to_remove->info;
		delete node_to_remove;
		this->count--;
		return n;
	}
	void PrintAll(void (*func)(const T&))
	{
		Node<T>* temp = start;
		if (temp != nullptr)std::cout << "Elements: " << count << " => ";
		while (temp != nullptr)
		{
			func(temp->info);
			temp = temp->urm;
		}
		std::cout << std::endl;
	}

};
