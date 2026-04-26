class Solution {
public:
    vector<vector<int>>result;
    void helper(vector<int>&temp,int &n , int &k,int idx){
        // base case
        if(temp.size() == k){
            result.push_back(temp);
        }

        for(int i = idx;i<=n;i++){
            // do
            temp.push_back(i);
            // explore
            helper(temp,n,k,i+1);
            // backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        int idx = 1;
        vector<int>temp;
        helper(temp,n,k,idx);
        return result;
    }
};
