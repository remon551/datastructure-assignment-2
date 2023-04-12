#include<iostream>
using namespace std;

template<class elementType>
struct node
{
    elementType value;
    node* next;
};

template<class elementType>
class stack
{
    private:
        node<elementType>* head, *tail;
        int size;
    public:
        stack()
        {
            head = tail = NULL;
            size = 0;
        }
        void push(elementType v)
        {
            node<elementType>* new_node = new node<elementType>();
            new_node->value = v;
            new_node->next = NULL;
            if(size == 0)
            {
                head = tail = new_node;
            }
            else
            {
                new_node->next = head;
                head = new_node;
            }
            size++;
        }
        elementType pop()
        {
            if(!isEmpty())
            {
                node<elementType>* temp = head;
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
                node<elementType>* current = head;
                cout << '[';
                for (int i = 0; i < size-1; i++)
                {
                    cout << current->value << ", ";
                    current = current->next;
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
int main()
{
    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    while(!s.isEmpty())
    {
        cout << s.pop() << '\n';
        s.print();
    }
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.print();
}