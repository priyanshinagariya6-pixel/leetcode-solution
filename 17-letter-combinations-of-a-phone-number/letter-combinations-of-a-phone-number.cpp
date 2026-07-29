class Solution {
public:
    vector<string> ans;

    void solve(int index, string &digits, string &curr,
               vector<string> &mp) {

        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            curr.push_back(ch);
            solve(index + 1, digits, curr, mp);
            curr.pop_back();     // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string curr = "";
        solve(0, digits, curr, mp);

        return ans;
    }
};