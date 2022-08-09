#include <iostream>
using namespace std;
#include "BinaryTreeNodeClass.h"
#include "InputPrtintFunc.h"

void elementsInRange(BinaryTreeNode<int>* root, int min, int max){
    if(root == NULL){
        return;
    }
    

    if(root->data > min){
        elementsInRange(root->left, min, max);
    }
    if(min <= root->data && root->data <= max){
        cout<<root->data<<" ";
    }
    
    if(root->data < max){
        elementsInRange(root->right, min, max);
    }

}


int main(){

    BinaryTreeNode<int>* root = takeInput();
    int m, n;
    cout<<"Enter min: ";
    cin>>m;
    cout<<"Enter max: ";
    cin>>n;

    elementsInRange(root, m, n);





    


}
