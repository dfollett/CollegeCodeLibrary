/*------------------------------------------------------------------------------
 * Editor: Dustin Follett
 * File: BinaryTree.h
 * Description: class definitions for BinaryTree. I added a couple private
 * functions including: deleteNode,findMin, and findParent.
 *
 -----------------------------------------------------------------------------*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Node.h"

#include <iostream>

using namespace std;

class BinaryTree {
  public:
    BinaryTree();
    ~BinaryTree();

    void addNode(int value);
    void deleteNode(int value);
    Node *search(int value);
    void cleanupTree();
    void printTree(bool ascending);

  private:
    void cleanupTree(Node *leaf);
    void printTreeAscending(Node *leaf);
    void printTreeDescending(Node *leaf);
    void addNode(int value, Node *leaf);
    Node *search(int value, Node *leaf);
    void deleteNode(int value, Node *leaf);
    int findMax(Node *leaf);
    int findParent(int value, Node *leaf);
    //int parent;
    //int minVal;
    Node *root;
};

#endif
