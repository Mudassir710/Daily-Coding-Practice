/*Mohammed Mudassir Mohiuddin*/ 
/*
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)

Constraints:
1 <= N, M <= 5000
*/ 

// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
struct Node* reverse(struct Node* head)
{
    struct Node* curr = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
void print(struct Node* head)
{
    struct Node* tmp = head;
    while(tmp)
    {
        cout<<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "\n"; 
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
   first = reverse(first);
   second = reverse(second);

   struct Node* a = first;
   struct Node* b = second;
   struct Node* head = NULL;
   struct Node* temp = NULL;
   int carry = 0;
   while(a && b)
   {
       int sum = a->data + b->data + carry;
       carry = sum / 10;
       if(!temp) temp = new Node(sum%10);
       else 
       {
            temp->next = new Node(sum%10);
            temp = temp->next;
       } 
       if(!head) head = temp;
       a = a->next;
       b = b->next;
   }
   while(a){
       int sum = carry + a->data;
       carry = sum / 10;
       temp->next = new Node(sum%10);;
       temp = temp->next;
       a = a->next;
   }
   while(b){
       int sum = carry + b->data;
       carry = sum / 10;
       temp->next = new Node(sum%10);;
       temp = temp->next;
       b = b->next;
   }
   if(carry)
       temp->next = new Node(carry);
   //print(head);
   return reverse(head);
}


void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node *res =NULL, *prev = NULL, *temp;
    int carry = 0, sum;
    while(first !=NULL || second != NULL)
    {
        sum = carry + (first? first->data: 0) + (second? second->data: 0);
        carry = (sum>=10 ? 1:0);
        sum = sum%10;
        temp = new Node(sum);
        if(res == NULL)
            res =temp;
        else
            prev->next =temp;
        prev = temp;
        if(first) 
            first = first->next;
        if(second)
            second = second->next;
    }
    if(carry>0)
        temp->next = new Node(carry);
    return res;
}
