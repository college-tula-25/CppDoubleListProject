#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T value;
	Node<T>* next{};
	Node<T>* prev{};
};

template<typename T>
struct DoubleList
{
	Node<T>* head{};
	Node<T>* tail{};
	size_t size{};
};


template<typename T>
void PushBack(DoubleList<T>& list, T value);
template<typename T>
void PushFront(DoubleList<T>& list, T value);
template<typename T>
void InsertAfter(DoubleList<T>& list, Node<T>* node, T value);
template<typename T>
void InsertBefore(DoubleList<T>& list, Node<T>* node, T value);

template<typename T>
Node<T>* Find(DoubleList<T> list, T value);

template<typename T>
T PopBack(DoubleList<T>& list);
template<typename T>
T PopFront(DoubleList<T>& list);
template<typename T>
T Remove(DoubleList<T>& list, Node<T>* node);


template<typename T>
void PrintForward(DoubleList<T> list);
template<typename T>
void PrintBackward(DoubleList<T> list);


#include "DoubleList.inl"