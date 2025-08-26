class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // now we will traverse the s string;
        int n = s.length();
        if (n <= 1)
            return false;
        for (char c : s) {
            if(st.size() == 0){
                st.push(c);
                continue;
            }
            // our three conditions;
            if (st.top() == '(' && c == ')') {
                st.pop();
            } else if (st.top() == '{' && c == '}') {
                st.pop();
            } else if (st.top() == '[' && c == ']') {
                st.pop();
            } else {
                st.push(c);
            }
        }
        if (st.size() == 0)
            return true;
        else
            return false;
    }
};
