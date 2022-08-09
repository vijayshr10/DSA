#include <iostream>
using namespace std;
#include "BinaryTreeNodeClass.h"
#include "inputPrint.h"

template <typename T>
class Node {
	public:
	T data;
	Node<T> *next;
	Node(T data) {
    	this->data=data;
    	this->next=NULL;
	}
};

#include <vector>
#include <queue>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int>* root){
    vector<Node<int>*> arr;
    if(root == NULL){
        return arr;
    }

    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);

    int currentLevelRemaining = 1;
    int nextLevelCount = 0;


    Node<int> * head = NULL;
    Node<int> *tail = NULL;

    while(pending.size() != 0){
        BinaryTreeNode<int>* front = pending.front();
        pending.pop();
        
        Node<int>* newNode = new Node<int>(front->data);

        if(head == NULL){
            head = newNode;
            tail = newNode; 
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }

        if(front->left != NULL){
            pending.push(front->left);
            nextLevelCount++;
        }
        if(front->right != NULL){
            pending.push(front->right);
            nextLevelCount++;
        }
        currentLevelRemaining--;

        if(currentLevelRemaining == 0){
            arr.push_back(head);
            head = NULL;
            tail = NULL;
            currentLevelRemaining = nextLevelCount;
            nextLevelCount = 0;
        }
        
    }


    return arr;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}