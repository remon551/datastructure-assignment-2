#include<bits/stdc++.h>

using namespace std;

template<class T>
class SNode
{
public:
	T data;
	SNode* next;
};

template<class T>
class SingleLinkedList
{
public:
	SNode<T>* head;
	SNode<T>* tail;
	SingleLinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void insertAtHead(T element)
	{
		SNode<T>* newNode = new SNode<T>;
		newNode->data = element;
		newNode->next = NULL;
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtTail(T element)
	{
		SNode<T>* newNode = new SNode<T>;
		newNode->data = element;
		newNode->next = NULL;
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	void insertAt(T element, int index)
	{
		SNode<T>* newNode = new SNode<T>;
		newNode->data = element;
		newNode->next = NULL;
		if (index < 0)
		{
			throw std::out_of_range("Index is out of range!");
		}
		else if (index > linkedListSize())
		{
			throw std::out_of_range("Index is out of range!");
		}
		else if (index == 0)
		{
			insertAtHead(element);
		}
		else if (index == linkedListSize())
		{
			insertAtTail(element);
		}
		else
		{
			SNode<T>* temp = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	void removeAtHead()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			if (linkedListSize() == 1)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				SNode<T>* temp = head;
				head = head->next;
				delete temp;
			}
		}
	}

	void removeAtTail()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			if (linkedListSize() == 1)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				SNode<T>* temp = head;
				while (temp->next != tail)
				{
					temp = temp->next;
				}
				delete tail;
				tail = temp;
				tail->next = NULL;
			}
		}
	}

	void removeAt(int index)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else if (index < 0)
		{
			throw std::out_of_range("Index is out of range!");
		}
		else if (index >= linkedListSize())
		{
			throw std::out_of_range("Index is out of range!");
		}
		else if (index == 0)
		{
			removeAtHead();
		}
		else if (index == linkedListSize() - 1)
		{
			removeAtTail();
		}
		else
		{
			SNode<T>* temp = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			SNode<T>* temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}
	}

	T retrieveAt(int index)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else if (index < 0)
		{
			throw std::out_of_range("Index is out of range!");
		}
		else if (index >= linkedListSize())
		{
			throw std::out_of_range("Index is out of range!");
		}
		else
		{
			SNode<T>* temp = head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			return temp->data;
		}
	}

	void replaceAt(T element, int index)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else if (index < 0)
		{
			throw std::out_of_range("Index is out of range!");
		}
		else if (index >= linkedListSize())
		{
			throw std::out_of_range("Index is out of range!");
		}
		else
		{
			SNode<T>* temp = head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			temp->data = element;
		}
	}

	bool isExist(T element)
	{
		if (head == NULL)
		{
			return false;
		}
		else
		{
			SNode<T>* temp = head;
			while (temp != NULL)
			{
				if (temp->data == element)
				{
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
	}

	bool isItemAtEqual(T element, int index)
	{
		if (head == NULL)
		{
			return false;
		}
		else if (index < 0)
		{
			throw std::out_of_range("Index is out of range!");
		}
		else if (index >= linkedListSize())
		{
			throw std::out_of_range("Index is out of range!");
		}
		else
		{
			SNode<T>* temp = head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			if (temp->data == element)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	void swap(int firstindex, int secondindex)
	{
		if (firstindex >= 0 && firstindex < linkedListSize() && secondindex >= 0 && secondindex < linkedListSize())
		{
			if (firstindex == secondindex)
			{
				return;
			}
			SNode<T>* first = head;
			SNode<T>* prevfirst = NULL;
			SNode<T>* second = head;
			SNode<T>* prevsecond = NULL;
			for (int i = 0; i < firstindex && first != NULL; i++)
			{
				prevfirst = first;
				first = first->next;
			}
			for (int i = 0; i < secondindex && second != NULL; i++)
			{
				prevsecond = second;
				second = second->next;
			}
			if (first == NULL || second == NULL)
			{
				return;
			}
			if (prevfirst != NULL)
			{
				prevfirst->next = second;
			}
			else
			{
				head = second;
			}
			if (prevsecond != NULL)
			{
				prevsecond->next = first;
			}
			else
			{
				head = first;
			}
			SNode<T>* temp = first->next;
			first->next = second->next;
			second->next = temp;
		}
		else
		{
			throw std::out_of_range("Index is out of range!");
		}

		
	}
	bool isEmpty()
	{
		return head == NULL;
	}

	int linkedListSize()
	{
		int size = 0;
		SNode<T>* temp = head;
		while (temp != NULL)
		{
			size++;
			temp = temp->next;
		}
		return size;
	}

	void clear()
	{
		SNode<T>* temp = head;
		while (temp != NULL)
		{
			SNode<T>* temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
		head = NULL;
		tail = NULL;
	}

	void print()
	{
		SNode<T>* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << '\t';
			temp = temp->next;
		}
		cout << endl;
	}
};
