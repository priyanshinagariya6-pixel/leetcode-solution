class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int > st (nums.begin() , nums.end());
        int longest = 0 ;
        for(int x : st ){
            if(st.count(x - 1) == 0){
                int current = x ;
                int length = 1 ;
                while(st.count(current + 1)){
                    current++ ;
                    length++ ;

                }
                longest = max(longest , length );

            }
        }
        return longest ;
        
    }
};