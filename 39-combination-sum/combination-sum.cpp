class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int idx, vector<int>& candidates, int target) {
        // Found a valid combination
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Out of bounds
        if (idx == candidates.size())
            return;

        // Take current element
        if (candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            solve(idx, candidates, target - candidates[idx]); // same index
            temp.pop_back();
        }

        // Skip current element
        solve(idx + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};