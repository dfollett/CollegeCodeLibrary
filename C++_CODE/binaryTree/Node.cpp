/*------------------------------------------------------------------------------
 * Author: Dustin Follett
 * File: Node.cpp
 * Description: Node class implementation.
 *
 -----------------------------------------------------------------------------*/

#include "Node.h"

// NULL is defined for use in constructor and destructor
#define NULL 0;

//constructor
Node::Node(int val){
  value = val;
  left = NULL;
  right = NULL;
}
//destructor
Node::~Node(){
  left = NULL;
  right = NULL;
}
//function prototypes
int Node::getValue(){
  return value;
}
Node* Node::getLeft(){
  return left;
}
Node* Node::getRight(){
  return right;
}
void Node::setLeft(Node* l){
  left = l;
}
void Node::setRight(Node* r){
  right = r;
}
