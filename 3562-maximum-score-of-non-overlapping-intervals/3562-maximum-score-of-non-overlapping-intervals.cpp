class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {end, start, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][1],
                intervals[i][0],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][0];

        // prev[i] = number of intervals before i
        // whose ending point is strictly less than a[i]'s start
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] = lower_bound(
                ends.begin(),
                ends.begin() + i,
                a[i][1]
            ) - ends.begin();
        }

        // dp[i][k] = best answer using first i intervals
        // and choosing at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for (int i = 1; i <= n; i++) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: don't take this interval
                auto skip = dp[i - 1][k];

                // Option 2: take this interval
                auto take = dp[prev[i - 1]][k - 1];

                take.first += a[i - 1][2];
                take.second.push_back(a[i - 1][3]);

                sort(take.second.begin(), take.second.end());

                // Choose better score
                // If equal, choose lexicographically smaller indices
                if (take.first > skip.first ||
                    (take.first == skip.first &&
                     take.second < skip.second)) {
                    dp[i][k] = take;
                }
                else {
                    dp[i][k] = skip;
                }
            }
        }

        return dp[n][4].second;
    }
};