class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
          int n1 = nums[0];
        int n2 = nums[0];

        for( int num : nums){
            n1 = min(n1,num);
            n2 = max(n2,num);
        }



        return gcd(n1, n2);
    }
};

