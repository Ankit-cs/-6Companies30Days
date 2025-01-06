/*
INTUTION:

*Identify the peak: A peak is an element greater than both its neighbors.
*Expand left while the sequence is increasing.
*Expand right while the sequence is decreasing.
*Track the longest mountain by calculating the length from left to right boundaries.
*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        vector<int> prefix(n, 0), suffix(n, 0);

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                prefix[i] = prefix[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                suffix[i] = suffix[i + 1] + 1;
            }
        }

        int longest = 0;

        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                if (prefix[i] > 0 && suffix[i] > 0) {
                    longest = max(longest, prefix[i] + suffix[i] + 1);
                }
            }
        }

        return longest;
    }
};
