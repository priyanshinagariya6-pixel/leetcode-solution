
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> st;

        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            int curr = asteroids[i];
            bool alive = true;

            while (!st.empty() && st.back() > 0 && curr < 0) {
                if (st.back() < abs(curr)) {
                    st.pop_back();
                }
                else if (st.back() == abs(curr)) {
                    st.pop_back();
                    alive = false;
                    break;
                }
                else {
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push_back(curr);
            }
        }

        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
