// Sum Of Nodes

#include <iostream>
using namespace std;
#include "BinaryTreeNodeClass.h"
#include "inputPrint.h"

int getSum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int sum = root->data;
    int leftSum = getSum(root->left);
    sum += leftSum;
    int rightSum = getSum(root->right);
    sum += rightSum;

    return sum;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout << getSum(root);

}
