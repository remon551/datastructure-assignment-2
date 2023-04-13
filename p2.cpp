#include <iostream>
#include "SingleLinkedList.cpp"
using namespace std;
int main()
{
    //first example
    /*************************************input*****************************************/
    SingleLinkedList<SingleLinkedList<int>*> lists;
    SingleLinkedList<int> result;
    int k;
    cout << "enter the number of lists: ";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        lists.insertAtTail(new SingleLinkedList<int>);
        int size;
        cout << "enter the size of list: ";
        cin >> size;
        cout << "enter the elements of lists: ";
        while(size--)
        {
            int x;
            cin >> x;
            lists.retrieveAt(i)->insertAtTail(x);
        }
    }
    while(lists.linkedListSize())
    {
        int index_of_the_smallest = 0;
        for (int i = 1; i < k; i++)
        {
            if(lists.retrieveAt(i)->retrieveAt(0) < lists.retrieveAt(index_of_the_smallest)->retrieveAt(0))
            {
                index_of_the_smallest = i;
            }
        }

        result.insertAtTail(lists.retrieveAt(index_of_the_smallest)->retrieveAt(0));
        lists.retrieveAt(index_of_the_smallest)->removeAtHead();
        if(lists.retrieveAt(index_of_the_smallest)->linkedListSize() == 0)
        {
            lists.removeAt(index_of_the_smallest);
            k--;
        }
    }
    result.print();
}

/*
first example
3
3
1 4 5
3
1 3 4
2
2 6
result: [1, 1, 2, 3, 4, 4, 5, 6]

second example
3
4
1 3 5 7
4
2 4 6 8
3
0 9 10
result: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

third example
5
7
1 15 18 69 100 101 102
3
68 71 82
4
1 2 3 4
1
1000
2
-1 0
*/