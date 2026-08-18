class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char ,string> charToword;
         unordered_map<string , char> wordTochar;
         stringstream ss(s);
         string word ;
         int i = 0 ;
         while(ss >> word){
            if( i >= pattern.size()){
                return false ;
            }
            char ch = pattern[i];
            if(charToword.count(ch) && charToword[ch] != word){
                return false ;
            }
            if(wordTochar.count(word) && wordTochar[word] != ch){
                return false ;
            }
            charToword[ch] = word ;
            wordTochar[word] = ch ;      
            
            i++; }

            if( i != pattern.size())
            return false ;
             
             return true ;
        
    
    }
};