#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput(){
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
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    Node*temp = head;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int length(Node *head){
    if(head == NULL){
        return 0;
    }
    return 1 + length(head->next);
}


//  Find a Node in Linked List

int findNode(Node *head, int n){
    Node *temp = head;
    int count = 0;

    while (head != NULL)
    {
        if(head->data == n){
            return count;
        }
        else{
            head = head->next;
            count++;
        }
    }
    return -1;
}

// Append last N TO FIRST
Node* AppendLastNToFirst(Node* head, int n){
    if(n ==0 || head == NULL){
        return head;
    }

    Node *fast = head;
    Node *slow = head;
    Node *initialHead = head;

    for(int i=0; i<n; i++){
        fast = fast->next;
    }
    while(fast->next != NULL){
        slow= slow->next;
        fast = fast->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    fast->next = initialHead;
    head = temp;

    return head;
}

// Eliminate duplicates from sorted linked list
Node* eliminateDuplicates(Node *head){
    if(head == NULL){
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

// Print Reverse LinkedList

void printReverse(Node *head){
    if(head==NULL){
        return;
    }
    printReverse(head->next);
    cout<<head->data<<" ";
}

Node* reverse(Node *head)
{
    Node *current = head;
    Node *prev = NULL;

    while(current != NULL){
        Node *temp = current->next;
        current->next = prev;

        prev = current;
        current = temp;        
    }

    return prev;
}

Node* reverseRecursive(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node *newhead = reverseRecursive(head->next);
    Node *headNext = head->next;
    headNext->next = head;
    head->next = NULL;
    return newhead;
}

bool isPalindrome(Node *head){
    if(head == NULL || head->next == NULL){
        return true;
    }

    // Find centre od list
    Node *fast = head;
    Node *slow = head;

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *secondHead = slow->next;
    slow->next == NULL;
    secondHead = reverse(secondHead);

    // Comparing the two list;
    Node *firstSubList = head;
    Node *secondSubList = secondHead;


    bool ans = true;

    while(secondSubList !=  NULL){
        if(firstSubList->data != secondSubList->data){
            ans = false;
            break;
        }
        firstSubList = firstSubList->next;
        secondSubList = secondSubList->next;
    }

    return ans;

}






int main(){

    Node *head = takeInput();
    print(head);
    cout<<"length : "<<length(head)<<endl;;

    // Question ---------------
    // Find a Node in Linked List

    // int n;
    // cin>>n;
    // cout<<findNode(head, n);


    // Question ---------------
    // AppendLastNToFirst

    // int n;
    // cin>>n;
    // head = AppendLastNToFirst(head, n);
    // print(head);


    // Question ---------------------
    // Eliminate duplicates from sorted linked list

    // head = eliminateDuplicates(head);
    // print(head);


    // Question ---------------------
    // Print Reverse LinkedList

    // printReverse(head);


    // Reverse a linked list
    // head = reverse(head);
    // print(head);

    // head = reverseRecursive(head);
    // print(head);


    // Question ---------------------------
    // Palindrome LinkedList

    bool ans = isPalindrome(head);
    if (ans) cout << "true";
    else cout << "false";












}