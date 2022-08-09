#include <iostream>
using namespace std;
#include "BinaryTreeNodeClass.h"
#include "inputPrint.h"

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// solution
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        return NULL;
    }
    BinaryTreeNode<int>* rootLeft = removeLeafNodes(root->left);
    BinaryTreeNode<int>* rootRight = removeLeafNodes(root->right);

    root->left = rootLeft;
    root->right = rootRight;

    return root;

}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



void printLevelWise(BinaryTreeNode<int>* root)
{
    if(root == NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    pending.push(NULL);

    while(pending.size() != 0){
        BinaryTreeNode<int>* front = pending.front();
        pending.pop();

        if(front == NULL){
            if(pending.size() == 0)
            break;
            cout<<endl;
            pending.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left)
                pending.push(front->left);
            if(front->right)
                pending.push(front->right);
        }

    }

    
}
int main(){
    BinaryTreeNode<int>* root = takeInput();
    root = removeLeafNodes(root);
    printLevelWise(root);
}