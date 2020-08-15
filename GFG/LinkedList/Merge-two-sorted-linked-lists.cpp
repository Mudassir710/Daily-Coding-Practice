/*
Mohammed Mudassir Mohiuddin

Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,]
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.
Your Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N, M <= 104
1 <= Node's data <= 105
*/

// { Driver Code Starts
#include<iostream>
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

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
Node* mergeUtil(Node* head1, Node* head2)
{
    if(!head1->next)
    {
        head1->next = head2;
        return head1;
    }
    Node* curr1 = head1 , *next1 = head1->next;
    Node* curr2 = head2 , *next2 = head2->next;
    
    while(next1 && curr2)
    {
        if ((curr2->data) >= (curr1->data) && (curr2->data) <= (next1->data)) 
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            if(next1->next)
            {
                curr1 = next1;
                next1 = next1->next;
            }
            else
            {
                next1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}
Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    // code here
    if(!head_A) return head_B;
    if(!head_B) return head_A;
    if(head_A->data < head_B->data)
        return mergeUtil(head_A, head_B);
    else
        return mergeUtil(head_B ,head_A);
}  
