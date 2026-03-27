class Solution {
public:
    bool isAlphanumeric(char ch){
        if(tolower(ch) <= 'z' && tolower(ch) >= 'a'){
            return true;
        } else if(ch <= '9' && ch >= '0'){
            return true;
        }else{
            return false;
        }
    }
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start <= end){
            if(!isAlphanumeric(s[start])){
                start++;
                continue;
            }
            if(!isAlphanumeric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            } else{
                start++;
                end--;
            }

        }
        return true;
    }
};
