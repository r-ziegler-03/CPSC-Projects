/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: P5 Lazy BST
*/

/*
Overview:
This file creates the BST which holds a collection of data
This data is sorted and can be modified through different methods
This BST self balances if its height difference becomes too large
*/
#ifndef LAZY_BST_H
#define LAZY_BST_H

#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

template <typename T>
class LazyBST{
    public:
    // Constructor 
        LazyBST();
    // Destructor
        virtual ~LazyBST();
    // returns the size of the BST
        int getSize();
    // inserts data into the BST of type T
        void insert(T data);
    // removes data from the BST of type T
        void remove(T data);
    // returns a bool if the BST contains data of type T
        bool contains(T data);
    // prints the entire tree in ascending order
        void printTreeInOrder();
    // prints the entire tree in descending order
        void printTreePostOrder();
    // gets the min value in the BST
        T getMin();
    // gets the max value in the BST
        T getMax();
    // searches the BST for a node and returns that node
        TreeNode<T>* search(T key);
    // prints the BST to a text file
        void printToFile(std::string oFS);
    private:
    // the output file stream variable
        std::ofstream m_outFS;
    // stores the root node of the BST
        TreeNode<T>* m_root;
    // store the size of the BST
        int m_size;
    // stores the current index 
        int m_currIdx;
    // stores the fill counters
        int m_fillCounter;
    // stores the size of the array
        int m_arrSize;
    // stores the array pointer
        T* m_orderedArr;
    // Helper for the insert method
        void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
    // Helper for the contains method
        bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
    // helper for the print in ascending order method
        void printTreeInOrderHelper(TreeNode<T>* subTreeRoot);
    // helper for the print in descending order method
        void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);
    // helper for the get min method
        T getMinHelper(TreeNode<T>* subTreeRoot);
    // helper for the get max method
        T getMaxHelper(TreeNode<T>* subTreeRoot);
    // helper method
        void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
    // gets the next successor for the BSt
        TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);
    // gets the max depth starting from the given node
        int getMaxDepth(TreeNode<T>* subTreeRoot);
    // checks to see if the BST needs to be balanced
        void checkForBalance();
    // balances the BST
        void balance();
    // fills an array with the nodes from the BST
        void fillArrayHelper(TreeNode<T>* subTreeRoot, T* arr);
    // fills the tree back with the nodes in a balanced order
        void fillTreeHelper(TreeNode<T>* subTreeRoot, TreeNode<T>*& parent, T* arr, int low, int high, bool isLeftChild);
    // clears the tree of all of its nodes besides the root
        void clearTree();
    // helper for the search method
        TreeNode<T>* searchHelper(TreeNode<T>* subTreeRoot, T key);
    // helper for the print to file method
        void printToFileHelper(TreeNode<T>* subTreeRoot);
};
template <typename T>
LazyBST<T>::LazyBST(){
    m_root = NULL;
    m_size = 0;
}
template <typename T>
LazyBST<T>::~LazyBST(){
    if(m_root != NULL){
        delete m_root;
    }
}
template <typename T>
int LazyBST<T>::getSize(){
    return m_size;
}
template <typename T>
void LazyBST<T>::insert(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    insertHelper(m_root, newNode);
    ++m_size;
    checkForBalance();
}
template <typename T>
void LazyBST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        subTreeRoot = newNode; //pointer swap
    }else if(newNode->m_data < subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_left, newNode);
    }else if(newNode->m_data > subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_right, newNode);
    }
}
template <typename T>
bool LazyBST<T>::contains(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    return containsHelper(m_root, newNode);
}
template <typename T>
bool LazyBST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        return false;
    }else if(newNode->m_data == subTreeRoot->m_data){
        return true;
    }else if(newNode->m_data < subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_left, newNode);
    }else{
        return containsHelper(subTreeRoot->m_right, newNode);
    }
}
template <typename T>
void LazyBST<T>::printTreeInOrder(){
    printTreeInOrderHelper(m_root);
}
template <typename T>
void LazyBST<T>::printTreeInOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printTreeInOrderHelper(subTreeRoot -> m_left);
        std::cout << subTreeRoot->m_data << std::endl;
        printTreeInOrderHelper(subTreeRoot -> m_right);
    }
}
template <typename T>
void LazyBST<T>::printTreePostOrder(){
    printTreePostOrderHelper(m_root);
}
template <typename T>
void LazyBST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printTreePostOrderHelper(subTreeRoot->m_left);
        printTreePostOrderHelper(subTreeRoot->m_right);
        std::cout << subTreeRoot->m_data << std::endl;
    }
}
template <typename T>
T LazyBST<T>::getMin(){
    //check if empty
    if (m_size == 0){
        throw std::out_of_range("Empty");
    }
    return getMinHelper(m_root);
}
template <typename T>
T LazyBST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_left == NULL){
        return subTreeRoot->m_data;
    }else{
        return getMinHelper(subTreeRoot->m_left);
    }
}
template <typename T>
T LazyBST<T>::getMax(){
    if (m_size == 0){
        throw std::out_of_range("Empty");
    }
    return getMaxHelper(m_root);
}
template <typename T>
T LazyBST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_right == NULL){
        return subTreeRoot->m_data;
    }else{
        return getMaxHelper(subTreeRoot->m_right);
    }
}
template <typename T>
void LazyBST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
    while(target != NULL && target->m_data != key){
        parent = target;
        if(key < target->m_data){
            target = target->m_left;
        }else{
            target = target->m_right;
        }
    }
}
template <typename T>
TreeNode<T>* LazyBST<T>::getSuccessor(TreeNode<T>* rightChild){
    while(rightChild->m_left != NULL){
        rightChild = rightChild->m_left;
    }
    return rightChild;
}
template <typename T>
void LazyBST<T>::remove(T d){
    if (m_size == 0){
        return;
    }
    TreeNode<T>* target = NULL;
    TreeNode<T>* parent = NULL;
    target = m_root;
    findTarget(d,target, parent);
    if(target == NULL){ //not in the tree, nothing to do
        return;
    }
    if(target->m_left == NULL && target->m_right == NULL){ //no children, it's a leaf
        if(target == m_root){
            m_root = NULL;
        }else{ //it's not the root
            if(target == parent->m_left){
                parent->m_left = NULL;
            }else{
                parent->m_right = NULL;
            }
        }
    }else if(target->m_left != NULL && target->m_right !=NULL){ // 2 child case
        TreeNode<T>* suc = getSuccessor(target->m_right);
        T value = suc->m_data;
        remove(value);
        target->m_data = value;
    }else{ // 1 child case
        TreeNode<T>* child;
        if(target->m_left != NULL){
            child = target->m_left;
        }else{
            child = target->m_right;
        }
        if(target == m_root){
            m_root = child;
        }else{
            if(target == parent->m_left){
                parent->m_left = child;
            }else{
                parent->m_right = child;
            }
        }
    }
    --m_size;
}
template <typename T>
int LazyBST<T>::getMaxDepth(TreeNode<T>* subTreeRoot){
    if (subTreeRoot == NULL) {
        return 0;
    }
    int leftHeight = getMaxDepth(subTreeRoot->m_left);
    int rightHeight = getMaxDepth(subTreeRoot->m_right);
    if (leftHeight > rightHeight){
        return 1 + leftHeight;
    }
    else {
        return 1 + rightHeight;
    }
}
template <typename T>
void LazyBST<T>::checkForBalance(){
    double leftHeight = getMaxDepth(m_root->m_left);
    double rightHeight = getMaxDepth(m_root->m_right);
    if (m_size > 2){
        if (m_root->m_left == NULL && rightHeight >= 2){
            balance();
        }
        else if (m_root->m_right == NULL && leftHeight >= 2){
            balance();
        }
        else if ((leftHeight / rightHeight) > 1.5 || (rightHeight / leftHeight > 1.5)){
            balance();
        }
    }
}
template <typename T>
void LazyBST<T>::balance(){
    m_orderedArr = new T[m_size];
    m_currIdx = 0;
    fillArrayHelper(m_root, m_orderedArr);
    clearTree();
    m_fillCounter = 0;
    fillTreeHelper(m_root, m_root, m_orderedArr, 0, m_arrSize - 1, false);
    m_size = m_arrSize;
    delete[] m_orderedArr;
}
template <typename T>
void LazyBST<T>::fillArrayHelper(TreeNode<T>* subTreeRoot, T* arr){
    if(subTreeRoot != NULL){
        fillArrayHelper(subTreeRoot->m_left, arr);
        arr[m_currIdx++] = subTreeRoot->m_data;
        fillArrayHelper(subTreeRoot->m_right, arr);
    }
}
template <typename T>
void LazyBST<T>::fillTreeHelper(TreeNode<T>* subTreeRoot, TreeNode<T>*& parent, T* arr, int low, int high, bool isLeftChild){
    if (m_fillCounter < m_arrSize){  //makes sure that not all elements in the array have been used
        if (low > high){ //if this part of the array has been fully searched already
            return;
        }
        int midpoint = low + (high - low) / 2;
        if (subTreeRoot == NULL){    //anything but the root (since the tree has been cleard) --> we have to add a node
            subTreeRoot = new TreeNode<T>(arr[midpoint]);
            if (isLeftChild){
                parent->m_left = subTreeRoot;
            }
            else {
                parent->m_right = subTreeRoot;
            }
            m_fillCounter++;
        }
        else {  //only applies to the root
            subTreeRoot->m_data = arr[midpoint];
            m_fillCounter++;
        }
        fillTreeHelper(subTreeRoot->m_left, subTreeRoot, arr, low, midpoint - 1, true);
        fillTreeHelper(subTreeRoot->m_right, subTreeRoot, arr, midpoint + 1, high, false);
    }
}
template <typename T>
void LazyBST<T>::clearTree(){
    m_arrSize = m_size;
    for (int i = 0; i < m_arrSize; i++){
        if (m_orderedArr[i] != m_root->m_data){
            remove(m_orderedArr[i]);
        }
    }
}
template <typename T>
TreeNode<T>* LazyBST<T>::search(T key){
    return searchHelper(m_root, key);
}
template <typename T>
TreeNode<T>* LazyBST<T>::searchHelper(TreeNode<T>* subTreeRoot,T key){
    if (subTreeRoot == NULL || subTreeRoot->m_data == key){
        return subTreeRoot;
    }
    if (key > subTreeRoot->m_data){
        return searchHelper(subTreeRoot->m_right, key);
    }
    return searchHelper(subTreeRoot->m_left, key);
}

template <typename T>
void LazyBST<T>::printToFile(std::string fileName){
    m_outFS.open(fileName);
    printToFileHelper(m_root);
    m_outFS.close();
}
template <typename T>
void LazyBST<T>::printToFileHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printToFileHelper(subTreeRoot -> m_left);
        m_outFS << subTreeRoot->m_data << std::endl;
        printToFileHelper(subTreeRoot -> m_right);
    }
}
#endif
