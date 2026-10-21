
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;

        vector<int> prefix(n);
        vector<int> suffix(n);

        // Calculate maximum height from the left
        prefix[0] = height[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        // Calculate maximum height from the right
        suffix[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        // Calculate trapped water
        for (int i = 0; i < n; i++) {
            int leftMax = prefix[i];
            int rightMax = suffix[i];

            total += min(leftMax, rightMax) - height[i];
        }

        return total;
    }
};
