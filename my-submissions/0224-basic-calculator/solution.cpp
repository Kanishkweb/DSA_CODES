class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int result = 0;
        int sign = 1;
        stack<int> st;
        // traverse for the loop
        for (char ch : s) {
            if (ch == '+') {
                result = result + (num * sign);
                num = 0;
                sign = 1;
            } else if (ch == '-') {
                result = result + (num * sign);
                num = 0;
                sign = -1;
            } else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result = result + (num * sign);
                num = 0;
                sign = 1;
                int stSign = st.top();
                st.pop();
                int stRes = st.top();
                st.pop();
                result = stRes + (stSign * result);
            } else if(ch == ' '){
                continue;
            } else {
                num = (num * 10) + (ch - '0');
            }
        }
        result += (num * sign);
        return result;
    }
};
