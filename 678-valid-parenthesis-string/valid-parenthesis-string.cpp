class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open.push(i);
            }
            else if (s[i] == '*') {
                star.push(i);
            }
            else { // s[i] == ')'

                if (!open.empty()) {
                    open.pop();          // Match with '('
                }
                else if (!star.empty()) {
                    star.pop();          // Use '*' as '('
                }
                else {
                    return false;        // No '(' or '*' available
                }
            }
        }

        // Match remaining '(' with '*' acting as ')'
        while (!open.empty() && !star.empty()) {

            if (open.top() < star.top()) {
                open.pop();
                star.pop();
            }
            else {
                return false; // '*' came before '('
            }
        }

        return open.empty();
    }
};