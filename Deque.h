#pragma once
#include "pch.h"

template <typename T>
class Deque
{
public:
	Deque(Deque<T>&& deque) : m_list(std::move(deque.m_list)) { }
	~Deque() { m_list.~List(); }

	Deque<T>& operator=(const Deque<T>& deque) { m_list.operator=(deque.m_list); return *this; }
	Deque<T>& operator=(Deque<T>&& deque) { m_list.operator=(deque.m_list); return *this; }

	void PushFront(const T& data) { m_list.PushFront(data); }
	void PushBack(const T& data) { m_list.PushBack(data); }

	void PopFront() { m_list.PopFront(); }
	void PopBack() { m_list.PopBack(); }

	const T& Front() const { return m_list.Front(); }
	T& Front() { return m_list.Front(); }
	const T& Back() const { return m_list.Back(); }
	T& Back() { return m_list.Back(); }
	
	bool Empty() const { return m_list.Empty(); }
	int Size() const { return m_list.Size(); }

	void Clear() { m_list.Clear(); }
private:
	List<T> m_list;
};




