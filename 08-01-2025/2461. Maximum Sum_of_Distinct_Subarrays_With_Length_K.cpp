/*
INRURION:

1. **Sliding Window**: We maintain a window of size `k` using two pointers (`i` and `j`). The window slides through the array from left to right.

2. **Set for Distinct Elements**: We use a set to ensure that all elements in the window are distinct. If a duplicate is encountered, we shrink the window by moving the left pointer `i` until all elements in the window are unique.

3. **Subarray Sum Calculation**: As we expand the window by moving `j`, we add the current element to the sum. If the window reaches size `k`, we check if the sum is the maximum sum found so far.

4. **Efficient Updates**: Whenever we encounter a duplicate and shrink the window, we adjust the sum by removing the element at the left pointer `i` and updating the set.

5. **Result**: The maximum sum of any valid subarray of length `k` with distinct elements is returned.
.*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long result = 0, sum = 0;
        set<int> st;
        int i = 0, j = 0;
        
        while (j < n) {
            // Shrink the window from the left if there are duplicates
            while (st.count(nums[j])) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            
            // Add the current element to the sum and the set
            sum += nums[j];
            st.insert(nums[j]);
            
            // When the window size reaches k, check the sum
            if (j - i + 1 == k) {
                result = max(result, sum);
                
                // Move the left pointer to shrink the window
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        
        return result;
    }
};
