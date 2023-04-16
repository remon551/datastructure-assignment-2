#include<iostream>
using namespace std;

template<class elementType>
struct stackNode
{
    elementType value;
    stackNode* next;
};

template<class elementType>
class Stack
{
    private:
        stackNode<elementType>* head, *tail;
        int size;
    public:
        Stack()
        {
            head = tail = NULL;
            size = 0;
        }
        void push(elementType v)
        {
            stackNode<elementType>* new_stackNode = new stackNode<elementType>();
            new_stackNode->value = v;
            new_stackNode->next = NULL;
            if(size == 0)
            {
                head = tail = new_stackNode;
            }
            else
            {
                new_stackNode->next = head;
                head = new_stackNode;
            }
            size++;
        }
        elementType pop()
        {
            if(!isEmpty())
            {
                stackNode<elementType>* temp = head;
                head = head->next;
                temp->next = NULL;
                elementType x = temp->value;
                delete temp;
                size--;
                return x;
            }
            else
            {
                cout << "stack is empty\n";
            }
        }
        elementType top()
        {
            if(size)
            {
                return head->value;
            }
            else
            {
                cout << "stack is empty\n";
            }
        }
        bool isEmpty()
        {
            return (size == 0);
        }
        int stackSize()
        {
            return size;
        }
        void clear()/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        {

        }
        void print()
        {
            if(!isEmpty())
            {
                stackNode<elementType>* current = head;
                for (int i = 0; i < size-1; i++)
                {
                    cout << current->value << " ";
                    current = current->next;
                }
                cout << current->value;
                cout << '\n';
            }
            else
            {
                cout << "list is empty\n";
            }
        }
};