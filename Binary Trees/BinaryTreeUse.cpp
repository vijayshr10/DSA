#include <iostream>
using namespace std;
#include "BinaryTreeNodeClass.h"

void printTree(BinaryTreeNode<int> * root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<< "L" <<root->left->data;
    }
    if(root->right != NULL){
        cout<< " R" <<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;

    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;

    return root;
}


#include <queue>
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;  
}

void printTreeLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<": ";

        if(front->left != NULL){
            cout<<"L"<<front->left->data;
            pendingNodes.push(front->left);

        }
        if(front->right != NULL){
            cout<< " R" <<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }  

}

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}

bool isNodePresent(BinaryTreeNode<int>* root, int num){
    if(root == NULL){
        return false;
    }
    if(root->data == num){
        return true;
    }

    return isNodePresent(root->left, num) || isNodePresent(root->right, num);    
}

int getHeight(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int leftH = getHeight(root->left);
    int  rightH = getHeight(root->right);

    if(leftH > rightH){
        return leftH + 1;
    }
    else{
        return rightH + 1;
    }
}

void mirrorBinaryTree(BinaryTreeNode<int>* root){
    if (root == NULL)
    {
        return;
    }

    BinaryTreeNode<int>* temp = root->left;

    root->left = root->right;
    root->right = temp;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);    
}


void inOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}
// ===========================================================================================

// Code: Construct Tree from Preorder and Inorder

// ===========================================================================================
BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE || preS > preE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS; //left inorder start
	int lInE = rootIndex - 1;//left inorder end
	int lPreS = preS + 1;//left preorder start
	int lPreE = lInE - lInS + lPreS;//left preorder end
    
	int rPreS = lPreE + 1;//right preorder start
	int rPreE = preE;//right preorder end
	int rInS = rootIndex + 1;//right inorder start
	int rInE = inE;//right inorder end
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
  
    return buildTreeHelper(inorder,preorder,0,inLength-1,0,preLength-1);
}


// =====================================================================================================
// Construct Tree from Postorder and Inorder
// =====================================================================================================

BinaryTreeNode<int>* tree(int *postorder, int *inorder,int ps,int pe, int is, int ie)
{
    if(ps>pe)
        return NULL;
    
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(postorder[pe]);
    
     int k = 0; 
    for(int i = is; i <= ie; i++)
    { if(postorder[pe] == inorder[i])
        { k = i; break; } 
    }
    
    int lps=ps;    //left prestart
    int lis=is;  //left instart
    int  lie=k-1;   //left inend
    int lpe= lie-lis+lps; //left  pre end
    
    int rps=lpe+1; //right prestart
    int rpe=pe-1;//  right preend
    int ris=k+1;  //right instart
    int rie=ie;   //right inend
    
    root->left=tree(postorder,inorder,lps,lpe,lis,lie);
    root->right=tree(postorder,inorder,rps,rpe,ris,rie);
    
    return root;   
}
BinaryTreeNode<int>* buildTree2(int *postorder, int postLength, int *inorder, int inLength) {
    return tree (postorder,inorder,0,postLength-1,0,inLength-1);
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}


//    1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    
    /*
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;



    */
    // BinaryTreeNode<int>* root = takeInputLevelWise();
    // printTreeLevelWise(root);

    // cout<<"Num of nodes : "<<numNodes(root)<<endl;


    // int num;
    // cout<<"find: ";
    // cin>>num;

    // isNodePresent(root, num) ? cout<<"true" : cout<<"false";
    // cout<<endl;
    
    // cout<<"Height : "<<getHeight(root);

    // mirrorBinaryTree(root);
    // cout<<"reverse"<<endl;
    // printTreeLevelWise(root);

    // INorder Traversal
    // cout<<"Inorder: ";
    // inOrder(root);

    // // preOrder Traversal
    // cout<<"preOrder: ";
    // preOrder(root);

    
    // // postOrder Traversal
    // cout<<"postOrder: ";
    // postOrder(root);

    // Code: Construct Tree from Preorder and Inorder
    // cout<<"Size: ";
    // int size;
    // cin >> size;
    // int *pre = new int[size];
    // int *in = new int[size];
    // for (int i = 0; i < size; i++) cin >> pre[i];
    // for (int i = 0; i < size; i++) cin >> in[i];
    // BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    // printTreeLevelWise(root);

// =====================================================================================

    // Construct Tree from Postorder and Inorder

    // cout<<"Size: ";
    // int size;
    // cin >> size;
    // int *post = new int[size];
    // int *in = new int[size];
    // for (int i = 0; i < size; i++) cin >> post[i];
    // for (int i = 0; i < size; i++) cin >> in[i];
    // BinaryTreeNode<int> *root = buildTree2(post, size, in, size);
    // printTreeLevelWise(root);

    // =====================================================================================

    // Diameter of Binary Tree - Better Approach


    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout<<endl;
    pair<int, int> p = heightDiameter(root);
    cout<<"Height: "<<p.first<<endl;
    cout<<"Diameter: "<<p.second<<endl;

















    delete root;
    
}