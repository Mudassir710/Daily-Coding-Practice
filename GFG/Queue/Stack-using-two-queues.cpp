/*Mohammed Mudassir Mohiuddin*/ 
/*
Implement a Stack using two queues q1 and q2
*/ 
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
/*Method 1*/
/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    q1.push(-100);
    int ans = -1;
    while(1)
    {
        int x = q1.front();
        q1.pop();
        if(q1.front() == -100)
        {
            ans = x;
            break;
        }
        else q1.push(x);
    }
    q1.pop();
    return ans;
}

/*Method 2*/

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q;
        q = q1;
        q1 = q2;
        q2 = q;
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    int res = q1.front();
    q1.pop();
    return res;
}

