#pragma once

template<typename T>

struct Node
{
	T info;
	Node<T>* urm;
	Node<T>* prev;
	Node(T info)
	{
		this->info = info;
		this->urm = nullptr;
		this->prev = nullptr;
	}
};