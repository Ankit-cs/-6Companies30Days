 /*
*Prerequisite: A solid competitive programming background is required to fully grasp the solution.
*DP with Sorting: A simple dynamic programming approach with sorting will likely lead to Time Limit Exceeded (TLE) errors.
Common Interview Question: This problem is frequently asked in top tech companies, including FAANG.
*LIS Approach: Although the Longest Increasing Subsequence (LIS) approach is optimal, TLE can still occur without efficient implementation.
*Optimal Strategy:
1-Sort the envelopes by width in ascending order.
2-For envelopes with the same width, sort by height in descending order.
3-Apply LIS on the heights to get the result efficiently.
*/
#define ii int

class Solution {
public:
    int maxEnvelopes(vector<vector<ii>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<ii>& a, const vector<ii>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        vector<ii> heights;
        for (auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        return lengthOfLIS(heights);
    }

private:
    int lengthOfLIS(vector<ii>& heights) {
        vector<ii> dp;
        for (ii h : heights) {
            auto it = lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) {
                dp.push_back(h);
            } else {
                *it = h;
            }
        }
        return dp.size();
    }
};
