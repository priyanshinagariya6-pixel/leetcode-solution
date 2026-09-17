
class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        
        // Count frequency of each number
        for (int x : nums) {
            freq[x]++;
        }
        
        int ans = 0;
        
        // Check every number
        for (auto it : freq) {
            int x = it.first;
            
            if (freq.find(x + 1) != freq.end()) {
                ans = max(ans, freq[x] + freq[x + 1]);
            }
        }
        
        return ans;
    }
};

