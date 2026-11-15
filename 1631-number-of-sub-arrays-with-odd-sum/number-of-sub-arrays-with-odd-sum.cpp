class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        const int MOD = 1e9 + 7;

        long long odd = 0;
        long long even = 1;

        long long ans = 0;
        int sum = 0;

        for(int num : arr) {

            sum += num;

            if(sum % 2 == 1) {

                ans = (ans + even) % MOD;
                odd++;

            }
            else {

                ans = (ans + odd) % MOD;
                even++;

            }
        }

        return ans;
    }
};