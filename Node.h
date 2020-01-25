#pragma once
#include "pch.h"

template <typename T>
struct Node
{
	Node() {}
	Node(const T& data) : m_data(data) { }
	Node(const T& data, const std::shared_ptr<Node<T> >& next, const std::weak_ptr<Node<T> >& prev) : m_data(data), m_next(next), m_prev(prev) { }
	Node(T&& data, const std::shared_ptr<Node<T> >& next, const std::weak_ptr<Node<T> >& prev) : m_data(std::move(data)), m_next(next), m_prev(prev) { }

	T m_data;
	std::shared_ptr<Node<T> > m_next;
	std::weak_ptr<Node<T> > m_prev;
};