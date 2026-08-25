class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        vector<pair<int , string>>words ;
        string word ;
        while(ss >> word){
            int pos = word.back() - '0';
            word.pop_back() ;
            words.push_back({pos, word});
        }
        sort(words.begin(), words.end());
        string ans ="";
        for( auto &p : words){
            ans += p.second ;
            ans += " " ;
        }
        ans.pop_back();
        return ans ;
    }
};