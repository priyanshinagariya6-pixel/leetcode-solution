class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();

        vector<pair<int,int>> athletes;

        // Store {score, original index}
        for(int i = 0; i < n; i++) {
            athletes.push_back({score[i], i});
        }

        // Sort by score in descending order
        sort(athletes.begin(), athletes.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.first > b.first;
             });

        vector<string> answer(n);

        // Assign ranks
        for(int rank = 0; rank < n; rank++) {

            int originalIndex = athletes[rank].second;

            if(rank == 0) {
                answer[originalIndex] = "Gold Medal";
            }
            else if(rank == 1) {
                answer[originalIndex] = "Silver Medal";
            }
            else if(rank == 2) {
                answer[originalIndex] = "Bronze Medal";
            }
            else {
                answer[originalIndex] = to_string(rank + 1);
            }
        }

        return answer;
    }
};