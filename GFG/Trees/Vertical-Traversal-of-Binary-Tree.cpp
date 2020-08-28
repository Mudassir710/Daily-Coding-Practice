/*Mohammed Mudassir Mohiuddin*/ 
/*
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
     2
      \
       3
      /
     4
Output: 2 4 3

Example 2:

Input:
       1
    /    \
   2      3
 /   \      \
4     5      6
Output: 4 2 1 5 3 6

Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N log N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 5000
*/ 


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

vector <int> verticalOrder(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
    	Node* root = buildTree(s);
    	
    	vector <int> res = verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

void generateVerticalOrder(Node* root, int hd, map<int,vector<int>> &mp)
{
    if(!root) return;
    
    mp[hd].push_back(root->data);
     
    generateVerticalOrder(root->left, hd-1, mp);
    
    generateVerticalOrder(root->right, hd+1, mp);
}

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
    if(!root) return {};
    map<int,vector<int>> mp;
    int horizontalDistance = 0;
    
    queue<pair<Node*,int>> q;
    q.push(make_pair(root, horizontalDistance));
    
    while(!q.empty()) 
    { 
        pair<Node *,int> temp = q.front(); 
        q.pop(); 
        horizontalDistance = temp.second; 
        Node* node = temp.first; 
        mp[horizontalDistance].push_back(node->data); 
        if (node->left != NULL) 
            q.push(make_pair(node->left, horizontalDistance-1)); 
        if (node->right != NULL) 
            q.push(make_pair(node->right, horizontalDistance+1)); 
    } 
  
    map<int, vector<int>> :: iterator it;
    vector<int> res;
    for(it = mp.begin(); it!=mp.end(); ++it)
    {
        for(int i=0; i<it->second.size(); ++i)
            res.push_back(it->second[i]);
    }
    return res;
}

