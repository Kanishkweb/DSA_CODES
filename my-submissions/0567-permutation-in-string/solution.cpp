class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int a = s1.length();
        int n = s2.length();

        if (a > n)
            return false;

        vector<int> freq1(26,0), freq2(26,0);
        // fill the freq1 
        for(char &ch : s1){
            freq1[ch - 'a']++;
        }
        // fill the first window
        for(int i = 0;i<a;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1 == freq2) return true;
        for(int i = a;i<n;i++){
            freq2[s2[i] - 'a']++;
            freq2[s2[i-a] - 'a']--;
            if(freq1 == freq2) return true;
        }
        return false;
    }
};
