class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.",
            "--.","....","..",".---","-.-",".-..",
            "--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-",
            "-.--","--.."
        };

        unordered_set<string> st;

        for (string word : words) {

            string transformation = "";

            for (char c : word) {
                transformation += morse[c - 'a'];
            }

            st.insert(transformation);
        }

        return st.size();
    }
};