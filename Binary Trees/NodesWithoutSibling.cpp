#include <iostream>
using namespace std;
#include "BinaryTreeNodeClass.h"
#include "inputPrint.h"

void printNodesWithoutSibling(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    if(root->left != NULL && root->right != NULL){
        printNodesWithoutSibling(root->left);
        printNodesWithoutSibling(root->right);
    }
    else if(root->left != NULL){
        cout<<root->left->data<<" ";
        printNodesWithoutSibling(root->left);
    }
    else if(root->right != NULL){
        cout<<root->right->data<<" ";
        printNodesWithoutSibling(root->right);
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printNodesWithoutSibling(root);
}