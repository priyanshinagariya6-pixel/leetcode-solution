
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        // Step 1: Count frequency of each number
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets based on frequency
        vector<vector<int>> bucket(n + 1);

        for (auto it : freq) {
            int number = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(number);
        }

        // Step 3: Collect k most frequent elements
        vector<int> ans;

        for (int i = n; i >= 1; i--) {

            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
