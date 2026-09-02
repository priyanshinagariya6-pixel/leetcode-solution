class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st ;
        for(char ch : jewels){
            st.insert(ch);
        }
        int count = 0 ;

        for(char ch : stones){
            if(st.count(ch)){
                count++ ;
            }
        }
        return count ;
    }
};