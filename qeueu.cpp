#include <iostream>
using namespace std;
template <class elementTypnode>
class node{
    public:
    elementTypnode data;
    node*next;
    node(){
        next= nullptr;
    }
};
template <class elementType>
class Queue{
public:
    int length;
node<elementType>*front;
    node<elementType>*rear;
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
        node<elementType>*newnode=new node<elementType>();
        newnode->data=element;

        if(isEmpty()){
            front=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
        length++;

    }
    void print(){
        node<elementType>*temp=front;
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
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
            node<elementType>*delpr=front;
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
        while(!isEmpty()){
            dequeue();
        }
    }
};
