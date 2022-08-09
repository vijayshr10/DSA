#include <iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput(){ // time complexity - O(n)
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;  //or tail = newNode;
        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// length --> Iterative method
int length(Node *head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

void printIthNode(Node *head, int i){
    Node *temp = head;
    int count = 0;
    while(temp){
        if(count == i){
            cout<<temp->data<<endl;
            return;
        }
        count++;
        temp = temp->next;
    }
}

// Insert Node at ith position
Node* insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if(i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(temp != NULL && count < i-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        Node *temp2 = temp->next;
        temp->next = newNode;
        newNode->next = temp2;
    }
    return head;
}

// Delete Node
Node* deleteNode(Node *head, int i){
    Node *temp = head;
    Node *temp2 = NULL;

    if(i<0 || i>length(head)){
        return head;
    }
    else if(i==0){
        head = temp->next;
        delete temp;
    }
    else{
        for(int j = 0; j<i && temp!=NULL; j++){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        delete temp;
        }
    return head;   
}

// length --> Recusrive method
int lengthRecusive(Node *head){
    if(head == NULL){
        return 0;
    }
    return 1 + lengthRecusive(head->next);
}

// Insert Node Recusively
Node* insertNodeRecusive(Node *head, int pos, int data){
    if(head == NULL || pos<0){
        return head;
    }
    if (pos == 0){
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head; 
    }
    head->next = insertNodeRecusive(head->next, pos-1, data);
    return head;
}

Node* deleteNodeRecursive(Node *head, int pos){
    if(head == NULL || pos<0){
        return head;
    }
    if(pos == 0){
        Node *temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    head->next = deleteNodeRecursive(head->next, pos-1);
    return head;
}


int main()
{
    Node *head = takeInput();
    print(head);

    cout<<"Iterative : "<<length(head)<<endl;
    cout<<"Recursive : "<<lengthRecusive(head)<<endl;

    // int i;
    // cin>>i;
    // cout<<"ith node ";
    // printIthNode(head, i);

    // int i,data;
    // cin>>i;
    // cin>>data;
    // head = insertNode(head, i , data);
    
    // int i;
    // cin>>i;
    // head = deleteNode(head , i);
    
    // print(head);

    // int i,data;
    // cin>>i;
    // cin>>data;
    // head = insertNodeRecusive(head, i , data);
    // print(head);

    int i;
    cin>>i;
    head = deleteNodeRecursive(head , i);
    
    print(head);





   

}