class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(); // row
        int n = boxGrid[0].size(); // col

        for(int i = 0;i<m;i++){
            int cell = n-1;
            for(int j = n-1;j>=0;j--){
                if(boxGrid[i][j] == '*'){
                    cell = j-1;
                } else if(boxGrid[i][j] == '#'){
                    boxGrid[i][j] = '.';
                    boxGrid[i][cell] = '#';
                    cell--;
                }
            }
        }
        vector<vector<char>>ans(n,vector<char>(m));
        // rotate the box
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans[i][j] = boxGrid[m-1-j][i];
            }
        }
        return ans;
    }
};
