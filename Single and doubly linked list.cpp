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
			cout << "Invalid index" << endl;
		}
		else if (index > linkedListSize())
		{
			cout << "Index out of range" << endl;
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
			cout << "Invalid index" << endl;
		}
		else if (index >= linkedListSize())
		{
			cout << "Index out of range" << endl;
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

// This is the Node of doubly linked list
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
			SNode<T>* temp = first->next;
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
		DNode<T>* temp = NULL;
		DNode<T>* current = head;
		while (current != NULL)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp != NULL)
		{
			head = temp->prev;
		}
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
	/*list.removeAtTail();
	list.removeAtTail();
	list.removeAtTail();
	list.removeAtTail();*/
	list.forwardTraversal();
	list.backwardTraversal();
	list.clear();
	cout << "----------------------------------------" << endl;
	
}

	
//int main()
//{
//	// give me test cases for all the methods with different data types and different scenarios
//	// for example, if the list is empty, if the list has one element, if the list has more than one element
//	// if the index is out of range, if the index is in range, if the element is not in the list, if the element is in the list
//	
//	SingleLinkedList<int> list;
//	cout << "Inserting at head" << endl;
//	list.insertAtHead(1);
//	list.insertAtHead(2);
//	list.insertAtHead(3);
//	list.insertAtHead(4);
//	list.insertAtHead(5);
//	list.print();
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "Inserting at tail" << endl;
//	list.insertAtTail(1);
//	list.insertAtTail(2);
//	list.insertAtTail(3);
//	list.insertAtTail(4);
//	list.insertAtTail(5);
//	list.print();
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "Inserting at index" << endl;
//	list.insertAt(1, 0);
//	list.insertAt(2, 1);
//	list.insertAt(3, 2);
//	list.insertAt(4, 3);
//	list.insertAt(5, 4);
//	list.print();
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "Deleting at head" << endl;
//	list.insertAt(1, 0);
//	list.insertAt(2, 1);
//	list.insertAt(3, 2);
//	list.insertAt(4, 3);
//	list.insertAt(5, 4);
//	list.print();
//	list.removeAtHead();
//	list.removeAtHead();
//	list.removeAtHead();
//	list.removeAtHead();
//	list.removeAtHead();
//	list.print();
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "Deleting at tail" << endl;
//	list.insertAt(1, 0);
//	list.insertAt(2, 1);
//	list.insertAt(3, 2);
//	list.insertAt(4, 3);
//	list.insertAt(5, 4);
//	list.print();
//	list.removeAtTail();
//	list.removeAtTail();
//	list.removeAtTail();
//	list.removeAtTail();
//	list.removeAtTail();
//	list.print();
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "Deleting at index" << endl;
//	list.insertAtTail(1);
//	list.insertAtTail(2);
//	list.insertAtTail(3);
//	list.insertAtTail(4);
//	list.insertAtTail(5);
//	list.print();
//	list.removeAt(4);
//	list.removeAt(4);
//	list.removeAt(4);
//	list.removeAt(4);
//	list.removeAt(4);
//	list.print();
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "Retrieve at index" << endl;
//	list.insertAt(1, 0);
//	list.insertAt(2, 1);
//	list.insertAt(3, 2);
//	list.insertAt(4, 3);
//	list.insertAt(5, 4);
//	list.print();
//	cout << list.retrieveAt(3) << endl;
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "Replace at index" << endl;
//	list.insertAt(1, 0);
//	list.insertAt(2, 1);
//	list.insertAt(3, 2);
//	list.insertAt(4, 3);
//	list.insertAt(5, 4);
//	list.print();
//	list.replaceAt(6, 3);
//	list.print();
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "is Exist" << endl;
//	list.insertAt(1, 0);
//	list.insertAt(2, 1);
//	list.insertAt(3, 2);
//	list.insertAt(4, 3);
//	list.insertAt(5, 4);
//	list.print();
//	cout << list.isExist(3) << endl;
//	cout << list.isExist(6) << endl;
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "Item at equal" << endl;
//	list.insertAt(1, 0);
//	list.insertAt(2, 1);
//	list.insertAt(3, 2);
//	list.insertAt(4, 3);
//	list.insertAt(5, 4);
//	list.print();
//	cout << list.isItemAtEqual(3 , 2) << endl;
//	cout << list.isItemAtEqual(3, 3) << endl;
//	list.clear();
//	cout << "----------------------------------------" << endl;
//	cout << "Swap" << endl;
//	list.insertAt(1, 0);
//	list.insertAt(2, 1);
//	list.insertAt(3, 2);
//	list.insertAt(4, 3);
//	list.insertAt(5, 4);
//	list.print();
//	list.swap(3, 4);
//	list.print();
//	list.clear();
//	cout << "----------------------------------------" << endl;	
//}
