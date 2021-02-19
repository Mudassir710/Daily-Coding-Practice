class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        stack<char> st;
        
        for(int i=0; i<S.size(); i++){
            char ch = S[i];
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else st.push(ch);
        }
        
        if(st.empty()) return "";
        while(!st.empty())
        {
           res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};