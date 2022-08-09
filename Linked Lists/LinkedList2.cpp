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
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;    
}

// Midpoint of LL
Node *midpointOfLL(Node *head){
    if(head == NULL && head->next == NULL){
        return head;
    }
    Node *fast = head->next;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


// Merge Two Sorted LL ----------- RECURSIVE
Node *mergeTwoSortedLinkedLists(Node *temp1, Node *temp2){

    Node *head = NULL;


    if (temp1 == NULL)
        return(temp2);
    else if (temp2 == NULL)
        return(temp1);

    
    if(temp1->data < temp2->data){
        head = temp1;
        head->next = mergeTwoSortedLinkedLists(temp1->next, temp2);
    }
    else{
        head = temp2;
        head->next = mergeTwoSortedLinkedLists(temp1, temp2->next);
    }
    
    return (head);

}


// Merge Two Sorted LL ----------- ITERATIVE
Node *mergeTwoSortedLL(Node *head1, Node *head2){

    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    Node *head = NULL;
    Node *tail = NULL;

    while(head1 != NULL && head2 != NULL){

        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1; 
            }
            else{
                tail->next = head1;
                tail = tail->next;
            }
            head1 = head1->next;
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2; 
            }
            else{
                tail->next = head2;
                tail = tail->next;
            }
            head2 = head2->next;
        }
    }

    if(head1 == NULL){
        tail->next = head2;
    }
    if (head2 == NULL){
        tail->next = head1;
    }
    return head;
}

// MERGE SORT--------------

Node* mergeSort(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node *part1 = head;

    Node *fast = head->next;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *part2 = slow->next;
    slow->next = NULL;

    part1 = mergeSort(part1);
    part2 = mergeSort(part2);

    Node *res = mergeTwoSortedLinkedLists(part1, part2);

    return res;
}


// Find a node in LL (recursive)=============

int findNodeRecursive(Node *head, int n){
    if(head == NULL){
        return -1;
    }
    if(head->data == n){
        return 0;
    }

    int x = findNodeRecursive(head->next, n);

    if(x == -1){
        return x;
    }
    else{
        return x+1;
    }
}

// Even after Odd LinkedList -------------------------+
Node *evenAfterOdd(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    if(head->data % 2 == 0){
        Node *temp = head;
        head = head->next;
        head = temp;
    }
    
    Node *temp2 = head->next;


    while(temp2 != NULL){
        if(temp2->data % 2 == 1){
            Node *temp3 = temp2;
            
        }
    }




}











int main()
{

    Node *head = takeInput();
    print(head);


    // Node *head1 = takeInput();
    // Node *head2 = takeInput();
    // print(head1);
    // print(head2);

    //  QUESTION -- Midpoint of LL
    // Node *mid = midpointOfLL(head);
    // if (mid != NULL){
	// 	cout << mid->data;
	// }
	// cout << endl;


    //  QUESTION -- Merge Two Sorted LL --------RECURSOVE AND ITERATIVE
    
    // Node *merged = mergeTwoSortedLL(head1, head2);
    // print(merged);


    // Question -- Merge Sort --------------
    // head = mergeSort(head);
    // print(head);



    // Question -------------
    // Find a node in LL (recursive)
    int n;
    cin>>n;
    cout<<"index : "<<findNodeRecursive(head, n);





}