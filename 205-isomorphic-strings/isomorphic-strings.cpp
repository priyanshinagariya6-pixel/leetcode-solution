class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false ;
        }
        unordered_map<char,char> sTot ;
        unordered_map<char,char> tTos;

        for(int i=0 ;i< s.size() ; i++){
            char a = s[i];
            char b = t[i];

            if(sTot.count(a) && sTot[a] !=b){
                return false;
            }
            if(tTos.count(b) && tTos[b] !=a){
                return false ;
            }
            sTot[a] = b;
            tTos[b] = a;
        }
        return true;
    }
};