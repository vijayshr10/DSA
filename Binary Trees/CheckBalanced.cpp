#include <iostream>
using namespace std;
#include "BinaryTreeNodeClass.h"
#include "inputPrint.h"


#include <cmath>

int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(BinaryTreeNode<int> *root){
    if(root == NULL){
        return true;
    }
    int l = height(root->left);
    int r = height(root->right);

    if(abs(l-r) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
        return true;
    }
    else{
        return false;
    }

}
int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");

}