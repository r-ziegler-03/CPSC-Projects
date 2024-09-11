/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA3 Do You See What I See?
*/

/*
Overview:
This file creates the templated class, monostack. 
It behaves similar to a stack, except it can be in increasing or decreasing order
*/
#ifndef MONO_STACK_H
#define MONO_STACK_H
template <typename T>
class MonoStack{
    public:
        MonoStack(int iSize, char o); // Param: take an initial size for the array, take a char for increasing or decreasing order
        ~MonoStack(); // deletes the stack array from memory
        void push(T c); // add c to the top of the stack, behavior in which it is added depends on increasing or decreasing order
        T pop(); // remove from top so no args, and return what we remove
        T peek(); // returns the top element of the stack without removing it
        bool isFull(); // returns true or false for whether the stack is full or not full
        bool isEmpty(); // returns true or false for whether the stack is empty or not
        int size(); // returns an integer for what the size of the stack array is
    private:
        T* stackArr; // the stack array member variable
        int count; // number of items currently in the array
        int maxSize; // will start off as the isize from the constructor
        int top; // the index of the current top of the stack
        bool isIncreasing; // true if is increasing and false if decreasing
};

/*
Initializes the stack array to be of the size given in the parameter
Sets the bool isIncreasing to be true if the char parameter is 'i' and false otherwise
*/
template <typename T>
MonoStack<T>::MonoStack(int iSize, char o){
    stackArr = new T[iSize];
    maxSize = iSize;
    count = 0;
    top = -1;
    if (o == 'i'){
        isIncreasing = true;
    } else {
        isIncreasing = false;
    }
}
/*
deletes the stack array from memory
*/
template <typename T>
MonoStack<T>::~MonoStack(){
    delete[] stackArr;
}
/*
returns a boolean, true if the count equals the maxsize, and otherwise false
*/
template <typename T>
bool MonoStack<T>::isFull(){
    return (count == maxSize);
}
/*
returns a boolean, true if the count equals 0 and otherwise false
*/
template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count == 0);
}
/*
returns an integer, the count of the stack array
*/
template <typename T>
int MonoStack<T>::size(){
    return count;
}
/*
is a void return type
pushes the T data type into the stack array
if the stack array is full the array is resized
if the stack array is increasing, if the top is greater than c, the top is popped
if the stack array is decreasing, if the top is less than c, the top is popped
*/
template <typename T>
void MonoStack<T>::push(T c){
    if (isFull()){
        T* temp = new T[2*maxSize];
        for (int i = 0; i < maxSize; i++){
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;
    }
    if (isIncreasing){
            while (stackArr[top] > c && !isEmpty()){
                pop();
            }
    } else {
            while (stackArr[top] < c && !isEmpty()){
                pop();
            }
    }
    stackArr[++top] = c;
    count++;
}

/*
Returns T data type
pops the value at the top of the stack array
*/
template <typename T>
T MonoStack<T>::pop(){
    --count;
    return stackArr[top--];
}

/*
Returns the value at the top of the stack array
*/
template <typename T>
T MonoStack<T>::peek(){
    return stackArr[top];
}

#endif