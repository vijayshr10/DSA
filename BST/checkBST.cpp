#include <iostream>
#include <climits>
using namespace std;
#include "BinaryTreeNodeClass.h"
#include "InputPrtintFunc.h"


// Approach 1
int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));    
}
int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
bool isBST(BinaryTreeNode<int>* root){
    if(root == NULL){
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;    
}




//    1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}