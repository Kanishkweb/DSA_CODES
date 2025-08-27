class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto ch : tokens) {
            if (ch == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int sum = a + b;
                st.push(sum);
                continue;
            } else if (ch == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int minus = b - a;
                st.push(minus);
            } else if (ch == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int multi = b * a;
                st.push(multi);
            } else if (ch == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int div = b / a; // truncated decimal;
                st.push(div);
            } else {
                st.push(stoi(ch));
            }
        }
        if (st.empty())
            return -1;
        return st.top();
    }
};
