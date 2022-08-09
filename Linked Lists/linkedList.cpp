#include <iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput_Better(){ // time complexity - O(n)
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

Node* takeInput(){ // time complexity - O(n^2)
    int data;
    cin>>data;
    Node *head = NULL;

    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
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

int main()
{
    Node *head = takeInput_Better();
    print(head);




    /*
    // Statically
    Node n1(1);
    Node *head = &n1;   // head is an pointer not an object  
    
    Node n2(2);

    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head); 

    */



    /*
    // Dynamically
    Node *n3 = new Node(10);
    Node *head = n3;

    Node *n4 = new Node(20);
    n3->next = n4;
    */


}