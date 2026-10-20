class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        // Find next greater element for every number in nums2
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        // Elements remaining in stack have no next greater element
        vector<int> ans;

        for (int num : nums1) {
            if (mp.find(num) != mp.end()) {
                ans.push_back(mp[num]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};