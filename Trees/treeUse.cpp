#include <iostream>
#include <queue>
#include "treeNodeClass.h"
using namespace std;

/*
TreeNode<int>* takeInput(){
    int roorData;
    cout<<"Enter data "<<endl;
    cin>>roorData;

    TreeNode<int>* root = new TreeNode<int>(roorData);

    int n;
    cout<<"Number of children of "<<roorData<<endl;
    cin>>n;
    
    for(int i=0; i<n; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
*/

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data "<<endl;
    cin>>rootData;                  // taking root input

    TreeNode<int>* root = new TreeNode<int>(rootData);      // making a root node of tree from rootData

    queue<TreeNode<int>*> pendingNodes;  // queue of TreeNode integer pointers
    pendingNodes.push(root);            //pushing first node in queue

    while(pendingNodes.size() != 0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter num of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;

        for(int i=0; i<numChild; i++){
            int childData;
            cout<<"Enter "<<i<<" th child of "<<front->data<<endl;
            cin>>childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}


void printTree(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";

    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}



void printTreeLevelWise(TreeNode<int>* root){
    if(root == NULL){
        return;
    }

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<": ";

        for(int i=0; i < front->children.size(); i++)
        {
            if(i == front->children.size()-1){
                cout<<front->children[i]->data;
            }
            else{
                cout<<front->children[i]->data<<", ";

            }
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}


// Numeber of NOdes in tree -----------------===============
int countNodes(TreeNode<int>* root){
    int ans = 1;
    for(int i=0; i<root->children.size(); i++){
        ans += countNodes(root->children[i]);
    }
    return ans;
}


// Sum of all NOdes -----------------------------
int sumNodes(TreeNode<int>* root){
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++){
        countNodes(root->children[i]);
        sum += root->data;
    }
    return sum;
}


// Maximum data NOde ---------------------------
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int> *max=new TreeNode<int>(root->data);
    
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int> *child=maxDataNode(root->children[i]);
        if(child->data > max->data)
              max=child;
    }
    
    return max;
}


// height of tree ---------------------============
int getHeight(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans = 0;

    for(int i=0; i<root->children.size(); i++){
        int childHeight = getHeight(root->children[i]);
        if(childHeight > ans){
            ans = childHeight;
        }
    }
    return ans + 1;
}

// Nodes at depth k ================
void printAtLevelK(TreeNode<int>* root, int  k){
    if(root == NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k-1);
    }   
}


// Count leaf Nodes ==============================

int countLeafNodes(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    if(root->children.size() == 0){
        return 1;
    }

    int ans =0;
    for(int i=0; i<root->children.size(); i++){
        ans += countLeafNodes(root->children[i]);
    }

    return ans;
}


// preoder transversing =================================
void preOrder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";

    for(int i=0; i<root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

//  postOrder Tranversing ==========================
void postOrder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }

    for(int i=0; i<root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
        cout<<root->data<<" ";
}



int main()
{
    

    // 1 3 2 3 4 2 5 6 2 7 8  0 0 0 0 1 9 0
    /*
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    */

    TreeNode<int> * root = takeInputLevelWise();
    printTreeLevelWise(root);

    // cout<<"Count Nodes: "<<countNodes(root);

    // cout<<"Sum Nodes: "<<sumNodes(root);


    // int k;
    // cout<<"Nodes at level k = ";
    // cin>>k;
    // printAtLevelK(root, k);


    // cout<<"Leaf Nodes : "<<countLeafNodes(root)<<endl;

    cout<<"preOrder : "<<endl;
    preOrder(root);


    cout<<endl<<"postOrder : "<<endl;
    postOrder(root);    


    













}