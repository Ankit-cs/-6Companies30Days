/*INTUTION:
### Intuition for the Code:

The problem is to calculate the total number of friend requests sent, based on specific age constraints. Here's the step-by-step intuition behind the code:

1. **Understanding the Problem**:
   - A person `x` sends a friend request to person `y` if:
     - `age[y] > 0.5 * age[x] + 7` (age of `y` is not too small compared to `x`).
     - `age[y] <= age[x]` (age of `y` is not greater than `x`).
     - `age[y] <= 100 || age[x] >= 100` (special case for ages above 100).

2. **Frequency Array**:
   - To efficiently handle repeated ages in the input, the code uses a frequency array `count` of size `121` (since ages range from 1 to 120). 
   - `count[age]` stores the number of people with that particular age.

3. **Double Loop for Pairs of Ages**:
   - Two nested loops are used to iterate over all possible age pairs `(ageX, ageY)`.
   - For each pair, we check if the friend request conditions are satisfied:
     - `ageY > 0.5 * ageX + 7`
     - `ageY <= ageX`
   - If the conditions are satisfied, the number of friend requests between these two ages is calculated as `count[ageX] * count[ageY]`.

4. **Handling Same Ages**:
   - If `ageX == ageY`, we adjust the calculation to avoid overcounting:
     - Subtract `count[ageX]` from the total because a person cannot send a request to themselves.

5. **Result**:
   - The total number of valid friend requests is accumulated in `totalRequests`.

### Key Optimizations:
- Using a frequency array (`count`) ensures we do not process the same age multiple times, reducing redundant computations.
- The double loop only iterates over the range of valid ages (1 to 120), keeping the algorithm efficient.

This approach is both intuitive and efficient for handling the constraints of the problem.*/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (int age : ages) {
            count[age]++;
        }

        int totalRequests = 0;

        for (int ageX = 1; ageX <= 120; ageX++) {
            if (count[ageX] == 0) continue;

            for (int ageY = 1; ageY <= 120; ageY++) {
                if (count[ageY] == 0) continue;

                if (ageY <= 0.5 * ageX + 7) continue;
                if (ageY > ageX) continue;

                totalRequests += count[ageX] * count[ageY];
                if (ageX == ageY) {
                    totalRequests -= count[ageX];
                }
            }
        }

        return totalRequests;
    }
};
