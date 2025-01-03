/*
Brute Force:
Outer Loop: Iterates through the array to select subarray start index.
Inner Loop: Forms subarrays and counts odd numbers.
Condition Check: If odd count equals ==k 
Time: O(n^2)
Space:O(1)
*/
/*
Optimal better than Brute :
Code Breakdown:
- **Initialization**: 
  - `unordered_map mp` stores cumulative odd sums.
  - `cnt` counts valid subarrays, and `sum` tracks odd counts.
- **For Loop**:
  - Iterates through `nums`, updates `sum` for odd numbers, and checks how many times `sum - k` has occurred in `mp`.
Operations:
Each map operation (insertion/lookup) takes \( O(1) \).
Updates for `sum` and `cnt` are \( O(1) \).

Complexity:
Time:( O(n)
Space:O(n) 
*/
/*
More optimal using constant space by Sliding Window techniue:
### Approach:
Use the **two-pointer (sliding window)** technique to solve the problem in \( O(n) \) time and \( O(1) \) space.

### Key Steps:
1. Use `left` and `right` pointers to define the window.
2. Count odd numbers within the window.
3. Adjust `left` pointer when odd count exceeds \( k \).
4. Track valid subarrays using `count`.

### Explanation:
- **Two Pointers**: `left` reduces the window size when oddCount = \( k \); `right` expands the window.
- **Odd Count**: Tracks the number of odd numbers in the window.
- **Prefix**: Counts valid subarrays for each window with exactly \( k \) odd numbers.
- **Count**: Adds `prefix` to total count of valid subarrays.

### Complexity:
- **Time**: \( O(n) \) (Each element is processed at most twice).
- **Space**: \( O(1) \) (Only a few integer variables).

*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, totalSubarrays = 0, oddCount = 0, validSubarrays = 0;

        while (right < nums.size()) {
            if (nums[right] % 2 != 0) {
                oddCount++;
                validSubarrays = 0;
            }

            while (oddCount == k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                validSubarrays++;
                left++;
            }

            totalSubarrays += validSubarrays;
            right++;
        }

        return totalSubarrays;
    }
};