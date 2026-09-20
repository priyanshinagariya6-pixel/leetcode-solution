class Solution {
public:
    int reverseDegree(string s) {
        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            int reversePosition = 'z' - s[i] + 1;
            int sum = reversePosition * (i + 1);

            count += sum;
        }

        return count;
    }
};