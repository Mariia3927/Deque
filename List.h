#pragma once
#include "pch.h"


template <typename T>
class List
{
public:
	List() : m_size(0) {}
	List(const List<T>& list);
	List(List<T>&& list);
	~List() { Clear(); }

	List<T>& operator=(const List<T>& list);
	List<T>& operator=(List<T>&& list);

	void PushFront(const T& data);
	void PushBack(const T& data);
	
	void PopFront();
	void PopBack();

	const T& Front() const { return m_head->m_data; }
	T& Front() { return m_head->m_data; }
	const T& Back() const { return m_tail->m_data; }
	T& Back() { return m_tail->m_data; }

	int Size() const { return m_size; }
	bool Empty() const { return m_size == 0; }

	void Clear();

private:
	void ResetLastElement(std::shared_ptr<Node<T> >& lastElement);
	void CopyList(const List<T>& list);
	void MoveList(List<T>&& list);

private:
	std::shared_ptr<Node<T> > m_head, m_tail;
	int m_size;
};

template <typename T>
void List<T>::ResetLastElement(std::shared_ptr<Node<T> >& lastElement)
{
	if (m_size == 1)
	{
		lastElement.reset();
	}
}

template <typename T>
void List<T>::CopyList(const List<T>& list)
{
	Node<T> *ptr = list.m_head.get();
	while (ptr)
	{
		PushBack(ptr->m_data);
		ptr = ptr->m_next.get();
	}
}

template <typename T>
void List<T>::MoveList(List<T>&& list)
{
	m_head = std::move(list.m_head);
	m_tail = std::move(list.m_tail);
	m_size = list.m_size;
	list.m_size = 0;
}

template <typename T>
List<T>::List(const List<T>& list)
{
	CopyList(list);
}

template <typename T>
List<T>::List(List<T>&& list)
{
	MoveList(std::move(list));
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& list)
{
	if (this == &list) {
		return *this;
	}
	
	Clear();
	CopyList(list);

	return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& list)
{
	if (this == &list) {
		return *this;
	}

	MoveList(std::move(list));

	return *this;
}

template <typename T>
void List<T>::PopFront()
{
	if (m_size > 0)
	{
		m_head = m_head->m_next;
		if (m_head)
		{
			m_head->m_prev.reset();
		}
		ResetLastElement(m_tail);
		--m_size;
	}
}

template <typename T>
void List<T>::PopBack()
{ 
	if (m_size > 0)
	{
		m_tail = m_tail->m_prev.lock();
		if (m_tail)
		{
			m_tail->m_next.reset();
		}
		ResetLastElement(m_head);
		--m_size;
	}
}

template <typename T>
void List<T>::PushFront(const T& data)
{
	if (!m_head)
	{
		m_head = std::make_shared<Node<T> >(data);
	}
	else if (m_head && !m_tail)
	{
		m_tail = m_head;
		m_head = std::make_shared<Node<T> >(data);
		m_head->m_next = m_tail;
		m_tail->m_prev = m_head;
	}
	else 
	{
		std::shared_ptr<Node<T> > sharedPtr = std::make_shared<Node<T> >(data);
		sharedPtr->m_next = m_head;
		m_head->m_prev = sharedPtr;
		m_head = sharedPtr;
	}
	++m_size;
}

template <typename T>
void List<T>::PushBack(const T& data)
{
	if (!m_head)
	{
		m_head = std::make_shared<Node<T> >(data);
	}
	else if (m_head && !m_tail)
	{
		m_tail = std::make_shared<Node<T> >(data);
		m_head->m_next = m_tail;
		m_tail->m_prev = m_head;
	}
	else
	{
		std::shared_ptr<Node<T> > sharedPtr = std::make_shared<Node<T> >(data);
		sharedPtr->m_prev = m_tail;
		m_tail->m_next = sharedPtr;
		m_tail = sharedPtr;
	}
	++m_size;
}

template <typename T>
void List<T>::Clear()
{
	while (m_head)
	{
		PopFront();
	}
}

