#include <iostream>
#include <queue>
#include "treeNodeClass.h"
using namespace std;



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


// contain x
bool isPresent(TreeNode<int>* root, int x) {
    if(root == NULL){
        return 0;
    }
    if(root->data == x){
        return true;
    }

    bool ans = false;
    for(int i=0; i < root->children.size(); i++){
        bool smallans = isPresent(root->children[i], x);
        if(smallans != ans && smallans == true){
            ans = true;
        }
    }

    return ans;
}


int getLargeNodeCount(TreeNode<int>* root, int x){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    if(root->data > x){
        count++;
    }
    for(int i=0; i<root->children.size(); i++){
        int smallans = getLargeNodeCount(root->children[i], x);
        count += smallans;
    }

    return count;
}


// Node with maximum child sum========================================================
////  created soluttion
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int>* ans =root;
    
    int sum=root->data; 
    for(int i=0;i<root->children.size();i++)    ///  sum for root node
    {
        sum+=root->children[i]->data;
    }
    
    
  for(int i=0;i<root->children.size();i++)
    {
         TreeNode<int>*childmax=maxSumNode(root->children[i]);  //get the max node using recursion
      
          int smallsum=childmax->data; 
          
         for(int i=0;i<childmax->children.size();i++)			// calculating sum for max node 
          {
              smallsum+=childmax->children[i]->data;
          }
      
         if(sum<=smallsum)             //comparision  update if necessary
         {
             ans=childmax;	
             sum=smallsum;                           
         }
    }
    return ans;
}


// // official Solution================
// #include <climits>
// template<typename T>
// class MaxNodePair{
//     public:
//     TreeNode<T> * node;
//     int sum;
// };

// MaxNodePair<int>* maxSumNodeHelper(TreeNode<int>* root) {
//     if(root == NULL){
//         MaxNodePair<int> *pair = new MaxNodePair<int>();
//         pair->node = NULL;
//         pair->sum = INT_MIN;
//         return pair;
//     }
//     int sum = root->data;

//     for (int i = 0; i < root->children.size(); i++)
//     {
//         sum += root->children[i]->data;
//     }
//     MaxNodePair<int>* ans = new MaxNodePair<int>();
//     ans->node = root;
//     ans->sum = sum;

//     for(int i=0; i<root->children.size(); i++)
//     {
//         MaxNodePair<int> *childAns = maxSumNodeHelper(root->children[i]);
//         if(childAns->sum > ans->sum){
//             ans = childAns;
//         }
//     }
//     return ans;
    
// }

// TreeNode<int>* maxSumNode(TreeNode<int>* root) {
//     return maxSumNodeHelper(root)->node;
// }




// Structurally identical ============================================
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
     if(root1->data != root2->data)
        return false;
    
    if(root1->children.size() != root2->children.size())
        return false;
    
    bool ans = true;
    for(int i=0; i<root1->children.size(); i++)
    {
        bool smallans = areIdentical(root1->children[i], root2->children[i]);
        if(smallans == false)
        {   ans=smallans;
            return ans;
        }
    }
    return ans;
}

// Next larger ==========================================================
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int n) {
    // Write your code here
    if(root==NULL)
        return NULL;		///edge case
  
    TreeNode<int>*max =NULL;
    
    if(root->data > n)
        max=root;
    
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>*childmax= getNextLargerElement(root->children[i], n);
        
        if(childmax==NULL)
        {continue;}
        
        else
        {
            if(max==NULL)
                max=childmax;
            else if(childmax->data > n  && childmax->data < max->data)
                max= childmax;
        }
    }
    
    return max;
}


// Second Largest Element In Tree    =================================================

void helper(TreeNode<int> *root,TreeNode<int> **first,TreeNode<int> **second){
    if(root==NULL)
    {
        return;
    
    }
    if(!(*first)){
        *first=root;
    }
    else if(root->data>(*first)->data){
        *second=*first;
        *first=root;
    }
    else if(!(*second)|| root->data>(*second)->data)
        *second=root;
    
    for(int i=0;i<root->children.size();i++)
        helper(root->children[i],first,second);
     
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int> *second=NULL;
    TreeNode<int> *first=NULL;
    helper(root,&first,&second);
        
        if(second==NULL)
            return NULL;
    if(first->data==second->data)
        return NULL;
    return second;
    
}

// Replace with depth ===================================
void help(TreeNode<int> *root, int depth)
{
    root->data=depth;
    for(int i=0;i<root->children.size();i++)
    {
        help(root->children[i] ,depth+1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root){    
   
    int depth=0;
 help(root,depth);
 }


int main(){

    // Contains x

    TreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);


    // int n;
    // cin>>n;
    // cout<<"res =  ";
    // cout<<isPresent(root, n);
    
    
    int x;
    cin >> x;
    cout<<"res =  ";
    cout << getLargeNodeCount(root, x);




}