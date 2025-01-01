
/*
Brute Force :

The goal is to reorder the array to satisfy the pattern: nums[0] < nums[1] > nums[2] < nums[3] > nums[4] < nums[5] and so on.

Alternating conditions:

*For even indices (i.e., 0, 2, 4, ...), the element should be less than the next one: nums[i] < nums[i+1].
*For odd indices (i.e., 1, 3, 5, ...), the element should be greater than the next one: nums[i] > nums[i+1].
Approach:

Iterate through the array and check the conditions at each index.
For even indices:
*If nums[i] > nums[i+1], swap them to satisfy nums[i] < nums[i+1].
For odd indices:
*If nums[i] < nums[i+1], swap them to satisfy nums[i] > nums[i+1].
Repeat the process until the entire array satisfies the zigzag pattern.

The idea is to correctly place the elements at each step by swapping adjacent elements where necessary.





*/
/*
OPTIMAL:
*Count how many times each number appears:
*First, we tally up how many times each number appears in the array. This allows us to keep track of all elements, especially the duplicates, so that we can place them correctly later.

*Place the larger numbers at the "peak" positions:
*We start with the largest numbers and place them at the odd indices (1, 3, 5, ...). These positions will represent the peaks of our wiggle pattern, so we need the biggest numbers here. It’s like filling the high points on a mountain range.

*Place the smaller numbers at the "valley" positions:
*Once the peaks are filled, we move to the even indices (0, 2, 4, ...) and place the smaller numbers there. These positions form the valleys, where smaller numbers naturally go, making the wiggle effect complete.



*/



class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 5000;
        vector<int> frequency(maxVal + 1, 0);

        for (int num : nums) {
            frequency[num]++;
        }

        int index = maxVal;
        for (int i = 1; i < n; i += 2) {
            while (frequency[index] == 0) {
                index--;
            }
            nums[i] = index;
            frequency[index]--;
        }

        for (int i = 0; i < n; i += 2) {
            while (frequency[index] == 0) {
                index--;
            }
            nums[i] = index;
            frequency[index]--;
        }
    }
};
