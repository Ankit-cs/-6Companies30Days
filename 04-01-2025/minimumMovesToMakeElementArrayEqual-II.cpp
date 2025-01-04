/*
Brute Force :
From the constraints it is clear that the question need to be solve in O(n)/O(nlogn)
So need to go to the O(n^2) solution which only waste of  timr only 

INTUTION: for O( nlogn)*


- The problem requires making all array elements equal using the minimum number of moves.  
- After sorting, the target value for all elements should ideally be a central tendency (mean, median, or mode).  

---

### **Key Observations**  
1. **Choice of Target Value:**
   - The most optimal target is the **median**, as it minimizes the total number of moves.
   - For even-sized arrays, any number between the two middle values can act as the median without affecting the result.

2. **Reason for Median:**
   - If we set the target to a number outside the range of the two middle values, the total steps required increase.
   - This can be observed by focusing on pairs of elements from the left and right sides of the sorted array:  
     \( \text{nums[0]} \leq \text{median} \leq \text{nums[n-1]} \).

3. **Median Calculation:**
   - For odd-sized arrays: The median is the middle element.
   - For even-sized arrays: Any value between the two middle elements is valid.

4. **Steps to Equalize Elements:**
   - The steps needed for each element to reach the target value are the absolute differences: \( \text{abs(nums[i] - median)} \).

5. **Conclusion:**
   - The problem boils down to:
     1. Finding the **median** of the array.
     2. Calculating the sum of absolute differences of each element from the median.  

Note:
- For even-sized arrays, taking the mean of the two middle values is unnecessary because all numbers in the range of the two middle values yield the same result.  
- Each step involves incrementing or decrementing by 1, which simplifies to the absolute difference calculation.*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int steps=0;int n=nums.size();
       int median=nums[n/2];
       for(int i=0;i<n;i++){
        steps+=abs(nums[i]-median);
       } 
       return steps;
    }
};




