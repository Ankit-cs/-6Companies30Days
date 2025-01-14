/*
Intution : DIrectly going to the intution :
The intuition behind the solution is to use the **sliding window** technique to maintain a valid subarray where the frequency of each element is less than or equal to `k`. 

1. **Expand the Window**: Move the `end` pointer to include new elements in the subarray.
2. **Track Frequencies**: Use a hashmap to keep track of how many times each element appears within the window.
3. **Shrink the Window**: If any element's frequency exceeds `k`, move the `start` pointer to reduce the window size until all frequencies are valid.
4. **Update Maximum Length**: After each valid window, calculate its length and update the result.

By continuously adjusting the window, we efficiently find the longest valid subarray.*/
code:
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len=0;
        unordered_map<int,int>count;
        int start=0,end=0,n=nums.size();
        while(end<n){
          count[nums[end]]++;
          while(count[nums[end]]>k){
            count[nums[start]]--;
            start++;
          }
          len=max(len,end-start+1);
          end++;
        }
        return len;
    }
};