/*
Mohammed Mudassir Mohiuddin
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
*/

// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
//int diff
int getLen(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        ++len;
        temp = temp->next;
    }
    return len;
}
int _intersectPoint(Node* head1, Node* head2, int diff)
{
    while(diff--)
    {
        if(!head1) return -1;
        head1 = head1->next;    
    }
    while (head1 && head2)
    {
        if(head1 == head2) return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len1 = getLen(head1), len2 = getLen(head2);
    int diff = abs(len1 - len2);
    if(len1 > len2)
        return _intersectPoint(head1,head2,diff);
    else
        return _intersectPoint(head2,head1,diff);
    return -1;
}

