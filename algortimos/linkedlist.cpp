#include <iostream>
using namespace std;

#define SIZE 10

class Stack{
    //propiedades
    int *arr;
    int top;
    int capacity;
    //declaracion de los metodos
    public:
        Stack(int size = SIZE);
        void push(int);
        int pop();
        int peek();
        int size();
        bool isEmpty();
        bool isFull();
        void printStack();
};  

Stack::Stack(int size){
    capacity = size;
    arr = new int[capacity];    
    top = -1;
}   

void Stack::push(int value){
    if (isFull()){
        cout << "Stack overflow" << endl;
    }
    else {
        cout << "Inserting value " << value << endl;
        top++;
        arr[top] = value;
    }
    
}

int Stack::pop(){
    if (isEmpty()){
        cout << "Stack underflow" << endl;
    }
    else {
        cout << "Removing value " << peek() << endl;
        top--;
        return arr[top];
    }
}

int Stack::peek(){
    if (!isEmpty()){
        return arr[top];
    }
}

int Stack::size(){
    cout << "Size is " << top + 1 << endl;
    return top + 1;
}

bool Stack::isEmpty(){
    return top == -1;
}

bool Stack::isFull(){
    return top == capacity - 1;
}

void Stack::printStack() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } 
    else {
        cout << "Stack elements:" << endl;
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}


int main(){
    Stack stack;

    stack.push(1);
    stack.push(10);
    stack.push(4);

    stack.pop();

    stack.size();
    cout << "Peek value " << stack.peek() << endl;

    stack.printStack();
    return 0;
    
}