class Solution {
public:

    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;

        vector<int> temp;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        // Remaining left part
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        // Remaining right part
        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }

        // Copy back
        for (int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {

        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        // Sort left half
        mergeSort(nums, left, mid);

        // Sort right half
        mergeSort(nums, mid + 1, right);

        // Merge both halves
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};