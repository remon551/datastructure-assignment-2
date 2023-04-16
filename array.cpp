#include <bits/stdc++.h>
using namespace std;
template <class elementType>
class ArrayBasedList {
private:
    int size;
    int length;
    elementType* item;
public:
    ArrayBasedList(int arsize) {
        size = arsize;
        length = 0;
        item = new elementType[size];
    }

/*
    void fill() {
        cout << "how many items do u need" << endl;
        int len;
        cin >> len;
        if (len > size) {
            cout << "cannot exceed arr size" << endl;
        }
        else {
            for (int i = 0; i < len; i++) {
                cin >> item[i];
                length++;
            }
        }

    }


        int search(t value) {
        int idx = -1;
        for (int i = 0; i < length; i++) {
            if (item[i] == value) {
                idx = i;
                break;
            }
        }
        return idx;
    }

        void enlarge(int newsize) {
        if (newsize <= size) {
            cout << "the new size must be greater than the old size" << endl;
        }
        else{
            size = newsize;
            int* old = item;
            item = new int[newsize];

            for (int i = 0; i < length; i++) {
                item[i] = old[i];
            }
            delete[]old;


        }

    }

    */
    void insert(elementType element) {
        if (length == size) {
            cout << "Array size is full" << endl;
            return;
        }
        else {

            item[length] = element;
            length++;
        }
    }


    void insertAt (elementType element, int index) {
        if (index >= 0 && index < size) {
            for (int i = length; i > index; i--) {
                item[i] = item[i - 1];
            }
            item[index] = element;
            length++;
        }
        else {
            cout << "index out of range"<<endl;
        }

    }
    elementType retrieveAt(int index) {
        return item[index];
    }

    void removeAt(int index){
        if (index >= 0 && index < size) {
            for (int i = index; i < length - 1; i++) {
                item[i] = item[i + 1];
            }
            length--;
        }
        else {
            cout << "index out of range" << endl;
        }

    }

    void replaceAt(elementType newElement, int index) {
        item[index] = newElement;
    }

    bool isItemAtEqual(elementType element, int index) {
        if (item[index] == element) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isEmpty() {
        if (length == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isFull() {
        if (length == size) {
            return true;
        }
        else {
            return false;
        }
    }
    int listSize() {
        return length;
    }
    int maxListSize(){

        return size;
    }
    void print() {
        if(isEmpty()){
            cout<<"array is empty"<<endl;
        }
        for (int i = 0; i < length; i++) {
            cout << item[i] << " ";

        }
        cout << endl;
    }
    void clear(){

        elementType* newdata = new elementType[length];
        delete[] item;
        item = newdata;
        newdata = nullptr;
        length = 0;
    }

};
