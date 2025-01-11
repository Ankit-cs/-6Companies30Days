/*
Brute Force:
The intuition behind the \( O(n^2) \) solution is as follows:

- For each element in `arr1`, we want to check if there is any element in `arr2` that is within a distance `d`.
- To do this, we iterate over every element in `arr1` and compare it with every element in `arr2`.
- If we find an element in `arr2` that is within distance `d` of the current element from `arr1`, we mark the current element as invalid.
- If no such element exists for a given element in `arr1`, we consider it valid and increment the count.
- This leads to two nested loops, giving an \( O(n^2) \) time complexity.
*/

/*
INTUTION:
### Summary of Intuition

The problem is to count elements in `arr1` that do not have any elements in `arr2` within a distance \( d \). 

1. **Sort `arr2`**: Sorting enables efficient range queries using binary search.
2. **Binary Search**: For each element in `arr1`, use binary search to find the range in `arr2` where elements fall within \([num - d, num + d]\).
3. **Non-Conflicting Check**: If no elements in `arr2` lie within this range (i.e., `left == right`), count the element in `arr1`.
4. **Efficiency**: Sorting takes \( O(n_2 \log n_2) \), and binary search for each element in `arr1` takes \( O(\log n_2) \), leading to an overall complexity of \( O(n_1 \log n_2 + n_2 \log n_2) \). 

This approach is much faster than brute force and suitable for larger input sizes.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int res = 0;

        auto binarySearch = [](const string& mode, const vector<int>& arr, int target) -> int {
            int left = 0, right = arr.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (mode == "left") {
                    if (arr[mid] < target)
                        left = mid + 1;
                    else
                        right = mid;
                } else if (mode == "right") {
                    if (arr[mid] <= target)
                        left = mid + 1;
                    else
                        right = mid;
                }
            }
            return left;
        };

        for (int num : arr1) {
            int left = binarySearch("left", arr2, num - d);
            int right = binarySearch("right", arr2, num + d);
            if (left == right) {
                res++;
            }
        }

        return res;
    }
};
