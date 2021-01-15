/*------------------------------------------------------------------------------
 * Author: Dustin Follett
 * File: BinaryTree.cpp
 * Description: this is the implementation of prototypes from BinaryTree.h.
 * this file does a bulk of the work on the BST. It allows addNode,deleteNode,
 * search, cleanupTree, and printTree which are all accessable by the user.
 *
 -----------------------------------------------------------------------------*/

#include "BinaryTree.h"

//constructor
  BinaryTree::BinaryTree(){
      root = NULL;
      cout<<"in BinaryTree constructor"<<endl;
  }

//destructor
  BinaryTree::~BinaryTree(){
    cout<<"in BinaryTree destructor"<<endl;
    cleanupTree();
  }

//this function calls the private deleteNode to kick off the recursion.
  void BinaryTree::deleteNode(int value){
    cout<<"deleting "<<value<<"..."<<endl;
    Node* temp = search(value);
      if (root){
        deleteNode(value,temp);
      }
  }

/*------------------------------------------------------------------------------
 *
 * Function: deleteNode
 * Description:This private function handles the recursion to in order to
 * delete a Node there are 3 cases that need to be handled in this function.
 * Also there are 2 helper functions to shorten code: findParent and findMin.
 * After hours of working on delete node everytime I make a break through
 * and test something else it breaks. So I have most of the parts and know
 * how to delete a node from a tree I just struggled on puting it in code.
 *
-----------------------------------------------------------------------------*/
  void BinaryTree::deleteNode(int value, Node *leaf){
    //case 1: no children.
    if (leaf->getLeft() == NULL && leaf->getRight() == NULL) {
      cout<<"no leafs"<<endl;
      delete leaf;
      //leaf = NULL;
    }
    //case 2: node with one leaf (no left leaf)
    else if (leaf->getLeft() == NULL){
      cout<<"no left"<<endl;
      Node* temp = leaf;
      delete leaf;
      //leaf = NULL;
    }
    //case 2: node with one leaf (no right leaf)
    else if (leaf->getRight() == NULL){
      cout<<"no right"<<endl;
      //findParent(value,root);
      //Node* temp = leaf;
      delete leaf;
      //leaf = NULL;
    }
    //case 3: node with both children
    else{
      delete leaf;
      //Node* temp = new Node(findMax(leaf->getRight()));
      //Node* parent = new Node(findParent(value, leaf));
      //cout<<temp->getValue()<<endl;
      //      cout<<temp->getLeft()<<endl;
      //            cout<<temp->getRight()<<endl;
      //cout<<leaf->getValue()<<endl;

      //parent->setLeft(leaf->getLeft());
      //parent->setRight(leaf->getRight());
      //cout<<temp->getValue()<<endl;
      //      cout<<temp->getLeft()->getValue()<<endl;
      //            cout<<temp->getRight()->getValue()<<endl;
      //delete(search(temp->getValue()));
      //delete leaf;
      //printTreeDescending(root);
      //leaf = temp;
      //delete leaf;
      //delete temp;
    }
  }

//helper function to delete node finds parent node
  int BinaryTree::findParent(int value, Node *leaf){

    if(leaf->getLeft() == NULL && leaf->getRight() == NULL){
      cout<<"root: "<<leaf->getValue()<<endl;
      //return NULL;
    }
    if ((leaf->getLeft() != NULL && leaf->getLeft()->getValue() == value) || (leaf->getRight() != NULL && leaf->getRight()->getValue() == value)){
      cout<<value<<" : value"<<endl;
      cout<<leaf->getValue()<<" : leaf value"<<endl;
      return leaf->getValue();
    }

    else if(leaf->getValue() > value){
       findParent(value,leaf->getLeft());
     }

    else if(leaf->getValue() < value){
       findParent(value,leaf->getRight());
     }
  }

//another helper function to find minimum value in tree
  int BinaryTree::findMax(Node *leaf) {
    while(leaf->getRight()!=NULL){
      leaf = leaf->getRight();
    }
    return leaf->getValue();
  }

//This function calls the private cleanupTree to kick off the recursion.
  void BinaryTree::cleanupTree(){
    cleanupTree(root);
  }

// Recursively deletes nodes from right to left.
  void BinaryTree::cleanupTree(Node *leaf){
    if (leaf == NULL) return;
    if (leaf!=NULL){
      cleanupTree(leaf->getRight());
      cout<<"cleaning node: "<<leaf->getValue()<<" "<<endl;
      //delete(leaf);
      cleanupTree(leaf->getLeft());
    }
  }

  // This function calls private functions printTreeAscending or printTreeDescending
  // depending on bool param passed in. uses recursion to print tree.
  void BinaryTree::printTree(bool ascending){
    if (ascending == 0){
      cout<<"printing tree ascending========================= "<<endl;
      printTreeAscending(root);
      cout<<"done printing tree."<<endl<<endl;
    }
    else{
      cout<<"printing tree Descending========================= "<<endl;
      printTreeDescending(root);
      cout<<"done printing tree."<<endl<<endl;
    }
  }

  //using recursion prints tree from low to high.
  void BinaryTree::printTreeAscending(Node *leaf){
    if (leaf!=NULL){
      //if(leaf->getValue()==0){
      //  return;
      //}
      printTreeAscending(leaf->getLeft());
      cout<<"value: "<<leaf->getValue()<<" "<<endl;
      printTreeAscending(leaf->getRight());
    }
  }

  //using recursion prints tree from high to low.
  void BinaryTree::printTreeDescending(Node *leaf){
    if (leaf!=NULL){
    //  if(leaf->getValue()==0){
    //    return;
    //  }
      printTreeDescending(leaf->getRight());
      cout<<"value: "<<leaf->getValue()<<" "<<endl;
      printTreeDescending(leaf->getLeft());
    }
  }

//this function calls the private addNode to kick off the recursion.
  void BinaryTree::addNode(int value){
    if (root) {
      cout<<"adding value: "<<value<<endl;
      addNode(value,root);
    }
    else if (root == NULL){
      cout<<"adding value: "<<value<<endl;
      root = new Node(value);
      cout<<"visiting node,left,right: "<<root->getValue()<<",NULL,NULL"<<endl;
    }
    else if (!root){
      cout<<"data.txt file was empty!  exiting."<<endl;
    }
  }

// adds the nodes recursively and prints a trace along the way.
  void BinaryTree::addNode(int value, Node *leaf){
    if (value == leaf->getValue()){
      return;
    }
    if (value < leaf->getValue()){
      if (leaf->getLeft()){
        addNode(value, leaf->getLeft());
      }
      else{
        leaf->setLeft(new Node(value));
      }

    }
    else{
      if (leaf->getRight()){
        addNode(value, leaf->getRight());
      }
      else{
        leaf->setRight(new Node(value));
      }
    }
    cout<<"visiting node,left,right: "<<leaf->getValue();
    if(leaf->getLeft() == NULL ){
      cout<<",NULL,";
    }
    else{
      cout<<","<<leaf->getLeft()->getValue()<<",";
    }
    if(leaf->getRight() == NULL){
      cout<<"NULL"<<endl;
    }
    else{
      cout<<leaf->getRight()->getValue()<<endl;
    }
  }

//this function calls the private search to kick off the recursion.
  Node* BinaryTree::search(int value){
    if (root) {
      cout<<"searching begins for "<<value<<endl;
      search(value,root);
    }
    else{
      return root;
    }
  }

// Recurses left and right side looking for matching value once found
// it returns the node it found.
  Node* BinaryTree::search(int value, Node *leaf){
    cout<<"searching(value,node): "<<value<<" , "<<leaf->getValue()<<endl;
    if (value < leaf->getValue()){
      if (leaf->getLeft()){
        search(value, leaf->getLeft());
      }
      else{
        cout<<value<<" not found :("<<endl;
      }

    }
    else if (value > leaf->getValue()){
      if (leaf->getRight()){
        search(value, leaf->getRight());
      }
      else{
        cout<<value<<" not found :("<<endl;
      }
    }
    else{
      cout<<value<<" found!"<<endl;
      return leaf;
    }
  }
