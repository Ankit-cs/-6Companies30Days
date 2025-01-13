/*INTUTUION:
The intuition behind the code for the `maxRotateFunction` lies in optimizing the computation of the rotation function \( F(k) \) by leveraging its relationship with \( F(k-1) \).

1. **Understanding \( F(k) \):**
   - \( F(k) \) is the weighted sum of elements in the array after it has been rotated \( k \) times.
   - Direct computation of \( F(k) \) for every \( k \) would involve recalculating the weighted sum repeatedly, leading to an \( O(n^2) \) time complexity.

2. **Observation about \( F(k) \):**
   - There is a relationship between \( F(k) \) and \( F(k-1) \):
     \[
     F(k) = F(k-1) + \text{sum} - n \cdot \text{last rotated element}
     \]
   - Here, `sum` is the sum of all elements in the array, and `n` is the array length.
   - This formula allows us to compute \( F(k) \) from \( F(k-1) \) in \( O(1) \) time.

3. **Key steps in the algorithm:**
   - Compute \( F(0) \), the initial value of the rotation function, and the total sum of the array in one pass.
   - Iteratively calculate \( F(k) \) using the relationship with \( F(k-1) \).
   - Keep track of the maximum value of \( F(k) \) as we progress.

4. **Efficiency:**
   - By avoiding direct recalculation of the weighted sum for each \( k \), the algorithm achieves \( O(n) \) time complexity, which is a significant improvement over a naive approach. 

In summary, the code uses mathematical insights and efficient iteration to maximize \( F(k) \).*/
/*<--------CODE------>*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int sum = 0, F = 0;
        
        // Calculate F(0) and sum of the array
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }
        
        int maxF = F;
        
        // Calculate F(k) iteratively from F(k-1)
        for (int k = 1; k < n; k++) {
            F = F + sum - n * nums[n - k];
            maxF = max(maxF, F);
        }
        
        return maxF;
    }
};
