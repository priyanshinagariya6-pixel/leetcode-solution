class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = INT_MAX;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 == 1) {
                smallestOdd = min(smallestOdd, x);
            }
        }

        // Case 1: All numbers are already even
        if (smallestOdd == INT_MAX) {
            return true;
        }

        // Case 2: Try to make everything odd
        for (int x : nums1) {
            if (x % 2 == 0) {
                // Need a smaller odd number
                if (x <= smallestOdd) {
                    return false;
                }
            }
        }

        return true;
    }
};