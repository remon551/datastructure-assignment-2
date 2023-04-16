#include <iostream>
using namespace std;
template <class elementTypqeueuNode>
class qeueuNode{
    public:
    elementTypqeueuNode data;
    qeueuNode*next;
    qeueuNode(){
        next= nullptr;
    }
};
template <class elementType>
class Queue{
public:
    int length;
    qeueuNode<elementType>*front;
    qeueuNode<elementType>*rear;
    Queue()
    {   length=0;
        front=rear=nullptr;
    }
    bool isEmpty(){
        if(front== nullptr&&rear== nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue (elementType element){
        qeueuNode<elementType>*newqeueuNode=new qeueuNode<elementType>();
        newqeueuNode->data=element;

        if(isEmpty()){
            front=rear=newqeueuNode;
        }
        else{
            rear->next=newqeueuNode;
            rear=newqeueuNode;
        }
        length++;

    }
    void print(){
        qeueuNode<elementType>*temp=front;
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout << endl;
    }

    elementType dequeue (){
        elementType value;
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
        }
        else if (front==rear){
            value=front->data;
        delete front;
        front=rear= nullptr;
        length--;
        }
        else{
            qeueuNode<elementType>*delpr=front;
            value=delpr->data;
            front=front->next;
            delete delpr;
            length--;
        }
        return value;

    }
    elementType first(){
        return front->data;
    }
    int queueSize(){
        return length;

    }
    void clear(){
        while(!isEmpty())
        {
            dequeue();
        }
    }
};
