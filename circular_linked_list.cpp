#include<iostream>
using namespace std;

template <class elementType>
class node
{
public:
    elementType value;
    node* link;
    node()
    {
        value = 0;
        link = NULL;
    }
};

template <class elementType>
class circular_linked_list
{
    private:
        node<elementType>* head;
        node<elementType>* tail;
        int size;
    public:
        circular_linked_list()
        {
            head = tail = NULL;
            size = 0;
        }
        void insertAtHead(elementType element)
        {
            node<elementType>* newnode = new node<elementType>();
            newnode->value=element;
            newnode->link=NULL;
            if(isEmpty())
            {
                head = tail = newnode;
                newnode->link = newnode;
            }
            else
            {
                newnode->link=head;
                head = newnode;
                tail->link = newnode;
            }
            size++;
        }
        void insertAtEnd(elementType element)
        {
            node<elementType>* newnode = new node<elementType>();
            newnode->value=element;
            newnode->link=NULL;
            if(isEmpty())
            {
                head = tail = newnode;
                newnode->link = newnode;
            }
            else
            {
                tail->link = newnode;
                newnode->link = head;
                tail = newnode;
            }
            size++;
        }
        void insertAt(elementType element, int index)
        {
            if(index < 0 || index > size)
            {
                cout << "invalid index\n";
            }
            else if(index == 0)
            {
                insertAtHead(element);
            }
            else if(index == size)
            {
                insertAtEnd(element);
            }
            else
            {
                node<elementType>* newnode = new node<elementType>(), *current = head;
                newnode->value = element;
                for(int i = 0; i < index-1; i++)
                {
                    current = current->link;
                }
                newnode->link = current->link;
                current->link = newnode;
                size++;
            }
        }
        void removeAtHead()
        {
            if(!isEmpty())
            {
                node<elementType>* temp = head;
                head = head->link;
                tail->link = head;
                temp->link = NULL;
                delete temp;
                size--;
                if(size == 0)
                {
                    head = tail = NULL;
                }
            }
            else
            {
                cout << "list is empty\n";
            }
        }
        void removeAtEnd()
        {
            if(!isEmpty())
            {
                node<elementType> *temp = tail, *current = head;
                while(current->link != tail)
                {
                    current = current->link;
                }
                tail = current;
                tail->link = head;
                delete temp;
                size--;
                if(size == 0)
                {
                    head = tail = NULL;
                }
            }
            else
            {
                cout << "list is empty\n";
            }
        }
        void removeAt (int index)
        {
            if(index < 0 || index > size)
            {
                cout << "invalid index\n";
            }
            else if(index == 0)
            {
                removeAtHead();
            }
            else if(index == size)
            {
                removeAtEnd();
            }
            else
            {
                node<elementType> *current = head;
                for (int i = 0; i < index-1; i++)
                {
                    current = current->link;
                }
                node<elementType> *temp = current->link;
                current->link = current->link->link;
                temp->link = NULL;
                delete temp;
                size--;
            }
        }
        elementType retrieveAt(int index)
        {
            node<elementType> *current = new node<elementType>();
            if(index < 0 || index > size)
            {
                cout << "invalid index\n";
            }
            else
            {
                current = head;
                for (int i = 0; i < index; i++)
                {
                    current = current->link;
                }
            }
            return current->value;
        }
        void replaceAt(elementType newElement, int index)
        {
            if(index < 0 || index > size)
            {
                cout << "invalid index\n";
            }
            else
            {
                node<elementType> *current = head;
                for (int i = 0; i < index; i++)
                {
                    current = current->link;
                }
                current->value = newElement;
            }
        }
        bool isExist(elementType element)
        {
            bool b = false;
            node<elementType> *current = head;
            for (int i = 0; i < size; i++)
            {
                if(current->value == element)
                {
                    b = true;
                    break;
                }
                current = current->link;
            }
            return b;
        }
        bool isItemAtEqual (elementType element, int index)
        {
            bool b = false;
            if(index < 0 || index > size)
            {
                cout << "invalid index\n";
            }
            else
            {
                node<elementType> *current = head;
                for (int i = 0; i < index; i++)
                {
                    current = current->link;
                }
                b = (current->value == element);
            }
            return b;
        }
        void swap(int firstItemIdx, int secondItemIdx)
        {
            if(firstItemIdx >= 0 && firstItemIdx < size && secondItemIdx >= 0 && secondItemIdx < size && firstItemIdx != secondItemIdx)
            {
                tail->link = NULL;
                if(secondItemIdx < firstItemIdx)
                {
                    int temp = firstItemIdx;
                    firstItemIdx = secondItemIdx;
                    secondItemIdx = temp;
                }
                node<elementType> *prev_first = NULL, *first = head, *prev_second = NULL, *second = head;
                for (int i = 0; i < firstItemIdx; i++)
                {
                    prev_first = first;
                    first = first->link;
                }
                
                for (int i = 0; i < secondItemIdx; i++)
                {
                    prev_second = second;
                    second = second->link;
                }

                if (prev_first != NULL)
                {
                    prev_first->link = second;
                }
                else
                {
                    head = second;
                }

                if (prev_second != NULL)
                {
                    prev_second->link = first;
                }
                else
                {
                    head = first;
                }

                node<elementType>* temp = second->link;
                second->link = first->link;
                first->link = temp;

                node<elementType>* cur = head;
                while(cur->link != NULL)
                {
                    cur = cur->link;
                }
                tail = cur;

                tail->link = head;

            }
            else if(!(firstItemIdx >= 0 && firstItemIdx < size && secondItemIdx >= 0 && secondItemIdx < size))
            {
                cout << "invalid indices\n";
            }
            else
            {
                cout << "the indices are the same\n";
            }
        }
        bool isEmpty()
        {
            return(size == 0);
        }
        int circularLinkedListSize()
        {
            return size;
        }
        void clear()
        {
            node<elementType> *temp;
            while(size)
            {
                temp = head;
                head = head->link;
                delete temp;
                size--;
            }
            head = tail = NULL;
        }
        void print()
        {
            if(!isEmpty())
            {
                node<elementType>* current = head;
                cout << '[';
                for (int i = 0; i < 2*size-1; i++)
                {
                    cout << current->value << ", ";
                    current = current->link;
                }
                cout << current->value << ']';
                cout << '\n';
            }
            else
            {
                cout << "list is empty\n";
            }
        }
};

/*int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            circular_linked_list<int> c;
            c.insertAtEnd(0);
            c.insertAtEnd(1);
            c.insertAtEnd(2);
            c.insertAtEnd(3);
            c.insertAtEnd(4);
            c.swap(i,j);
            cout << "for " << i << ' ' << j << '\n';
            c.print();
        }   
    }
    while(c.circularLinkedListSize())
    {
        c.removeAtHead();
        cout << "after head\n";
        c.print();
        c.removeAtEnd();
        cout << "after end\n";
        c.print();
    }
}*/