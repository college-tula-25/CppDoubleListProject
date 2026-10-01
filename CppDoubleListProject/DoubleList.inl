#pragma once
#include "DoubleList.h"

template<typename T>
void PushBack(DoubleList<T>& list, T value)
{
	Node<T>* node{ new Node<T> };
	node->value = value;
	list.size++;

	if (!list.tail)
	{
		list.tail = list.head = node;	
		return;
	}

	node->prev = list.tail;
	list.tail->next = node;
	list.tail = node;
}

template<typename T>
void PushFront(DoubleList<T>& list, T value)
{
	Node<T>* node{ new Node<T> };
	node->value = value;
	list.size++;

	if (!list.head)
	{
		list.head = list.tail = node;
		return;
	}

	node->next = list.head;
	list.head->prev = node;
	list.head = node;
}

template<typename T>
inline void InsertAfter(DoubleList<T>& list, Node<T>* node, T value)
{
	if (node == list.tail)
	{
		PushBack(list, value);
		return;
	}

	Node<T>* nodeNew{ new Node<T> };
	nodeNew->value = value;
	nodeNew->prev = node;
	nodeNew->next = node->next;

	node->next = nodeNew;
	nodeNew->next->prev = nodeNew;

	list.size++;
}

template<typename T>
inline void InsertBefore(DoubleList<T>& list, Node<T>* node, T value)
{
	if (node == list.head)
	{
		PushFront(list, value);
		return;
	}

	Node<T>* nodeNew{ new Node<T> };
	nodeNew->value = value;
	nodeNew->prev = node->prev;
	nodeNew->next = node;

	nodeNew->prev->next = nodeNew;
	node->prev = nodeNew;

	list.size++;
}

template<typename T>
inline Node<T>* Find(DoubleList<T> list, T value)
{
	while (list.head)
	{
		if (list.head->value == value)
			return list.head;
		list.head = list.head->next;
	}
	return nullptr;
}


template<typename T>
void PrintForward(DoubleList<T> list)
{
	while (list.head)
	{
		std::cout << list.head->value << " ";
		list.head = list.head->next;
	}
	std::cout << "\n";
}