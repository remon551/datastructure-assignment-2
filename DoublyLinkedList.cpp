#include <bits/stdc++.h>
using namespace std;


template <class T>
class DNode
{
public:
	T data;
	DNode<T>* next;
	DNode<T>* prev;
};


template <class T>
class DoublyLinkedList
{
public:
	DNode<T>* head;
	DNode<T>* tail;
	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void insertAtHead(T element)
	{
		DNode<T>* newNode = new DNode<T>;
		newNode->data = element;
		newNode->next = head;
		newNode->prev = NULL;
		if (head != NULL)
		{
			head->prev = newNode;
		}
		head = newNode;
		if (tail == NULL)
		{
			tail = newNode;
		}
	}
	void insertAtTail(T element)
	{
		DNode<T>* newNode = new DNode<T>;
		newNode->data = element;
		newNode->next = NULL;
		newNode->prev = tail;
		if (tail != NULL)
		{
			tail->next = newNode;
		}
		tail = newNode;
		if (head == NULL)
		{
			head = newNode;
		}
	}

	void insertAt(T element, int index)
	{
		if (index == 0)
		{
			insertAtHead(element);
		}
		else if (index == doubleLinkedListSize())
		{
			insertAtTail(element);
		}
		else if (index > doubleLinkedListSize())
		{
			cout << "Index out of range" << endl;
		}
		else if (index < 0)
		{
			cout << "Invalid, index should be positive" << endl;
		}
		else
		{
			DNode<T>* newNode = new DNode<T>;
			newNode->data = element;
			DNode<T>* temp = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next = newNode;
			if (newNode->next != NULL)
			{
				newNode->next->prev = newNode;
			}
			else
			{
				tail = newNode;
			}
		}
	}

	void insertAfter(DNode<T>* prev_node, T element)
	{
		if (prev_node == NULL)
		{
			cout << "Previous node cannot be null" << endl;
			return;
		}
		DNode<T>* newNode = new DNode<T>;
		newNode->data = element;
		newNode->next = prev_node->next;
		newNode->prev = prev_node;
		prev_node->next = newNode;
		if (newNode->next != NULL)
		{
			newNode->next->prev = newNode;
		}
		else
		{
			tail = newNode;
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
			DNode<T>* temp = head;
			head = head->next;
			if (head != NULL)
			{
				head->prev = NULL;
			}
			else
			{
				tail = NULL;
				head = NULL;
			}
			delete temp;
		}
	}
	void removeAtTail()
	{
		if (tail == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			DNode<T>* temp = tail;
			tail = tail->prev;
			if (tail != NULL)
			{
				tail->next = NULL;
			}
			else
			{
				head = NULL;
				tail = NULL;
			}
			delete temp;
		}
	}
	void removeAt(int index)
	{
		if (index == 0)
		{
			removeAtHead();
		}
		else if (index == doubleLinkedListSize() - 1)
		{
			removeAtTail();
		}
		else if (index > doubleLinkedListSize() - 1)
		{
			cout << "Index out of range" << endl;
		}
		else if (index < 0)
		{
			cout << "Invalid, index should be positive" << endl;
		}
		else
		{
			DNode<T>* temp = head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			else
			{
				tail = temp->prev;
			}
			delete temp;
		}
	}

	T retrieveAt(int index)
	{
		if (index >= 0 && index < doubleLinkedListSize())
		{
			DNode<T>* temp = head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			return temp->data;
		}
		else
		{
			cout << "Index out of range" << endl;
			return NULL;
		}
	}

	void replaceAt(T element, int index)
	{
		if (index >= 0 && index < doubleLinkedListSize())
		{
			DNode<T>* temp = head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			temp->data = element;
		}
		else
		{
			cout << "Index out of range" << endl;
		}
	}

	bool isExist(T element)
	{
		DNode<T>* temp = head;
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

	bool isItemAtEqual(T element, int index)
	{
		if (index >= 0 && index < doubleLinkedListSize())
		{
			DNode<T>* temp = head;
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
		else
		{
			cout << "Index out of range" << endl;
			return false;
		}
	}

	void swap(int firstindex, int secondindex)
	{
		if (firstindex >= 0 && firstindex < doubleLinkedListSize() && secondindex >= 0 && secondindex < doubleLinkedListSize())
		{
			DNode<T>* first = head;
			for (int i = 0; i < firstindex; i++)
			{
				first = first->next;
			}
			DNode<T>* second = head;
			for (int i = 0; i < secondindex; i++)
			{
				second = second->next;
			}
			if (first == NULL || second == NULL)
			{
				return;
			}
			if (first->prev != NULL)
			{
				first->prev->next = second;
			}
			else
			{
				head = second;
			}
			if (second->prev != NULL)
			{
				second->prev->next = first;
			}
			else
			{
				head = first;
			}
			DNode<T>* temp = first->next;
			first->next = second->next;
			second->next = temp;

		}
		else
		{
			cout << "Index out of range" << endl;
		}
	}
	// this will be changed
	void reverse()
	{
		DNode<T>* current = head;
		DNode<T>* Next = current->next;
		current->next = NULL;
		current->prev = Next;
		while (Next != NULL)
		{
			Next->prev = Next->next;
			Next->next = current;
			current = Next;
			Next = Next->prev;
		}
		tail = head;
		head = current;
	}

	bool isEmpty()
	{
		return (head == NULL);
	}
	void clear()
	{
		DNode<T>* temp = head;
		while (temp != NULL)
		{
			DNode<T>* next = temp->next;
			delete temp;
			temp = next;
		}
		head = NULL;
		tail = NULL;
	}

	void forwardTraversal()
	{
		DNode<T>* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << '\t';
			temp = temp->next;
		}
		cout << endl;
	}

	void backwardTraversal()
	{
		DNode<T>* temp = tail;
		while (temp != NULL)
		{
			cout << temp->data << '\t';
			temp = temp->prev;
		}
		cout << endl;
	}
	int doubleLinkedListSize()
	{
		int size = 0;
		DNode<T>* temp = head;
		while (temp != NULL)
		{
			size++;
			temp = temp->next;
		}
		return size;
	}
};


int main()
{
	DoublyLinkedList<int> list;
	cout << "Insert at head" << endl;
	list.insertAtHead(1);
	list.insertAtHead(2);
	list.insertAtHead(3);
	list.insertAtHead(4);
	list.insertAtHead(5);
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Insert at tail" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Insert at index" << endl;
	list.insertAt(1, 0);
	list.insertAt(2, 1);
	list.insertAt(3, 2);
	list.insertAt(4, 3);
	list.insertAt(5, 4);
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Insert After" << endl;
	list.insertAt(1, 0);
	list.insertAt(2, 1);
	list.insertAt(3, 2);
	list.insertAt(4, 3);
	list.insertAt(5, 4);
	list.forwardTraversal();
	list.backwardTraversal();
	list.insertAfter(list.head, 0);
	list.insertAfter(list.head->next, 1);
	list.insertAfter(list.head->next->next, 2);
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Remove at head" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.forwardTraversal();
	list.backwardTraversal();
	list.removeAtHead();
	list.removeAtHead();
	list.removeAtHead();
	list.removeAtHead();
	list.removeAtHead();
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Remove at tail" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.forwardTraversal();
	list.backwardTraversal();
	list.removeAtTail();
	list.removeAtTail();
	list.removeAtTail();
	list.removeAtTail();
	list.removeAtTail();
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Remove at index" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.forwardTraversal();
	list.backwardTraversal();
	list.removeAt(0);
	list.removeAt(1);
	list.removeAt(2);
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Retrieve at" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.forwardTraversal();
	list.backwardTraversal();
	cout << list.retrieveAt(2) << endl;
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Replace at" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.forwardTraversal();
	list.backwardTraversal();
	list.replaceAt(0, 0);
	list.replaceAt(1, 1);
	list.replaceAt(2, 2);
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "is Exist" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	cout << list.isExist(1) << endl;
	cout << list.isExist(8) << endl;
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "is item at equal" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	cout << list.isItemAtEqual(1, 0) << endl;
	cout << list.isItemAtEqual(2, 4) << endl;
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Swap" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.forwardTraversal();
	list.backwardTraversal();
	list.swap(0, 4);
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	cout << "Reverse" << endl;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.forwardTraversal();
	list.backwardTraversal();
	list.reverse();
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
}
