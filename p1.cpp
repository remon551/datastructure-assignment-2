#include <iostream>
#include "SingleLinkedList.cpp"
using namespace std;
int main()
{
    //first example
    /*************************************input*****************************************/
    SingleLinkedList<int> nums, result;
    nums.insertAtTail(0);
    nums.insertAtTail(3);
    nums.insertAtTail(1);
    nums.insertAtTail(0);
    nums.insertAtTail(4);
    nums.insertAtTail(5);
    nums.insertAtTail(2);
    nums.insertAtTail(0);
    /***********************************solution****************************************/
    nums.removeAtHead();
    int sum = 0;
    while(nums.linkedListSize())
    {
        if(nums.retrieveAt(0) != 0)
        {
            sum += nums.retrieveAt(0);
            nums.removeAtHead();
        }
        else
        {
            result.insertAtTail(sum);
            sum = 0;
            nums.removeAtHead();
        }
    }
    cout << "first example answer:";
    result.print();



    //second example 0, 1, 0, 3, 0, 2, 2, 0],
    /*************************************input*****************************************/
    nums.clear();
    result.clear();
    nums.insertAtTail(0);
    nums.insertAtTail(1);
    nums.insertAtTail(0);
    nums.insertAtTail(3);
    nums.insertAtTail(0);
    nums.insertAtTail(2);
    nums.insertAtTail(2);
    nums.insertAtTail(0);
    /***********************************solution****************************************/
    nums.removeAtHead();
    sum = 0;
    while(nums.linkedListSize())
    {
        if(nums.retrieveAt(0) != 0)
        {
            sum += nums.retrieveAt(0);
            nums.removeAtHead();
        }
        else
        {
            result.insertAtTail(sum);
            sum = 0;
            nums.removeAtHead();
        }
    }
        cout << "second example answer:";

    result.print();


}
