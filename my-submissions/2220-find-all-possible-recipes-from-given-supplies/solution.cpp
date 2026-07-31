class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> st; // set of supplies;
        vector<string> ans;
        for (auto& supply : supplies) {
            st.insert(supply);
        }
        unordered_set<int> visited;
        // now O(n^2) loop for check what we can made;
        for (int i = 0; i < recipes.size(); i++) {
            for (int j = 0; j < recipes.size(); j++) {
                if (visited.find(j) != visited.end())
                    continue;
                bool check = 1;
                for (auto& ingre : ingredients[j]) {
                    if (st.find(ingre) == st.end()) {
                        check = 0;
                    }
                }
                // if check is still true means we can make this recipe
                if (check) {
                    st.insert(recipes[j]);
                    ans.push_back(recipes[j]); // push the name of that recipe;
                    visited.insert(j);
                }
            }
        }
        return ans;
    }
};
