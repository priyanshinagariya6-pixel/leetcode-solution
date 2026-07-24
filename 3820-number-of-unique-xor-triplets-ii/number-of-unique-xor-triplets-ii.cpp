class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        vector<bool> ans(MAXX, false);

        // Triplets with repeated indices contribute only original values.
        for (int x : nums)
            ans[x] = true;

        // DP for XOR of three distinct elements.
        for (int v : nums) {
            for (int k = 2; k >= 0; k--) {
                for (int x = 0; x < MAXX; x++) {
                    if (dp[k][x])
                        dp[k + 1][x ^ v] = true;
                }
            }
        }

        for (int x = 0; x < MAXX; x++)
            if (dp[3][x])
                ans[x] = true;

        int cnt = 0;
        for (bool b : ans)
            if (b) cnt++;

        return cnt;
    }
};