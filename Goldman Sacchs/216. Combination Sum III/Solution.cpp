class Solution {
public:
    vector<vector<int>> ans;
    void solve (int currSum, int target, int k, int i, vector<int> &temp ) {
        if ( k == temp.size() ) {
            if ( currSum == target ) ans.push_back(temp);
            return;
        }
        if ( i > 9 ) return;
        temp.push_back(i);
        solve( currSum + i, target, k, i+1, temp);
        temp.pop_back();
        solve( currSum, target, k, i+1, temp);
    }
    //Aditya Seth.
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(0, n, k, 1, temp);
        return ans;
    }
};