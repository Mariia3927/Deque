#include "pch.h"
#include <iostream>

int main()
{
	Deque<int> deque;
	deque.PushFront(1);
	std::cout << deque.Front() << "; size - " << deque.Size() << '\n';

	deque.PushBack(2);
	std::cout << deque.Back() <<"; size - "<< deque.Size() << '\n';

	deque.PushBack(3);
	std::cout << deque.Back() << "; size - " << deque.Size() << '\n';

	deque.PopFront();

	deque.PopBack();
	deque.PopBack();

	std::cout << "Size - " << deque.Size() << '\n';

	for (int i = 0; i < 20; i++)
	{
		deque.PushFront(i);
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << deque.Front() << "; size - " << deque.Size() << '\n';
		deque.PopFront();
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << deque.Back() << "; size - " << deque.Size() << '\n';
		deque.PopBack();
	}

	std::cout <<"Is deque empty - "<< deque.Empty() << '\n';
	deque.PopBack();
	deque.PopFront();

	std::cout << "Deque size = " << deque.Size() << '\n';

	Deque<std::string> stringDeque;
	stringDeque.PushBack("I");
	stringDeque.PushBack(" ");
	stringDeque.PushBack("love");
	stringDeque.PushBack(" ");
	stringDeque.PushBack("C++");
	stringDeque.PushBack("!");

	Deque<std::string> copiedDeque(stringDeque);
	std::cout << "Copied deque size = " << copiedDeque.Size() << '\n';

	while (copiedDeque.Size() != 0)
	{
		std::cout << copiedDeque.Front();
		copiedDeque.PopFront();
	}
	std::cout << '\n';

	stringDeque.Clear();

	Deque<std::string> anotherStringDeque;
	anotherStringDeque.PushBack("I");
	anotherStringDeque.PushBack(" ");
	anotherStringDeque.PushBack("love");
	anotherStringDeque.PushBack(" ");
	anotherStringDeque.PushBack("Swift");
	anotherStringDeque.PushBack("!");

	Deque<std::string> movedDeque(std::move(anotherStringDeque));

	Deque<std::string> assignedDeque;

	assignedDeque = movedDeque;

	while (assignedDeque.Size() != 0)
	{
		std::cout << assignedDeque.Front();
		assignedDeque.PopFront();
	}
	std::cout << '\n';
}

