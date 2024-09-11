/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: P5 Lazy BST
*/

/*
Overview:
This file creates Tree Node which holds data at a node and points to a left node and right node
*/
#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class TreeNode{
public:
  TreeNode(T d);
  virtual ~TreeNode();
  T getData();

  template <typename S>
  friend class LazyBST;
  T m_data;
  TreeNode<T>* m_left;
  TreeNode<T>* m_right;

};

// Constructor ; initializes the data to d of type T ; initializes left and right to null
template <typename T>
TreeNode<T>::TreeNode(T d){
  m_data = d;
  m_left = NULL;
  m_right = NULL;
}

// Destructor ; deletes the nodes from memory
template <typename T>
TreeNode<T>::~TreeNode(){
  if(m_left != NULL){
    delete m_left;
  }
  if(m_right != NULL){
    delete m_right;
  }
}

// Gets the data at the node
template <typename T>
T TreeNode<T>::getData(){
  return m_data;
}

#endif