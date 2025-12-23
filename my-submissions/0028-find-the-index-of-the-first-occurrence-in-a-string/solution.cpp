class Solution {
public:
    bool matchString(string haystack , string needle , int i,int j){
        int l = haystack.length()-1;
        int m = needle.length()-1;
        while(i <= l && j <= m){
            if(haystack[i] != needle[j]){
                return 0; // false;
            }
            i++;
            j++;
        }
        if(j <= m) return 0;
        return 1; //true
    }
    int strStr(string haystack, string needle) {
        vector<int>res;
        for(int i = 0;i<haystack.length();i++){
            if(needle[0] == haystack[i]){
                res.push_back(i);
            }
        }

        for(int i = 0;i<res.size();i++){
            int start = res[i];
            if(matchString(haystack,needle,start,0)){
                return start;
            }
        }
        return -1;
    }
};
