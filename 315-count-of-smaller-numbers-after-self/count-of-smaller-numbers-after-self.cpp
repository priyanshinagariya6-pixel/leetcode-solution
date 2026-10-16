
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> indices(n);

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        mergeSort(nums, indices, ans, 0, n - 1);
        return ans;
    }

    void mergeSort(vector<int>& nums, vector<int>& indices,
                   vector<int>& ans, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, indices, ans, left, mid);
        mergeSort(nums, indices, ans, mid + 1, right);

        vector<int> temp;
        int i = left, j = mid + 1;
        int smaller = 0;

        while (i <= mid && j <= right) {
            if (nums[indices[j]] < nums[indices[i]]) {
                temp.push_back(indices[j]);
                smaller++;
                j++;
            } else {
                ans[indices[i]] += smaller;
                temp.push_back(indices[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[indices[i]] += smaller;
            temp.push_back(indices[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(indices[j]);
            j++;
        }

        for (int k = left; k <= right; k++) {
            indices[k] = temp[k - left];
        }
    }
};
