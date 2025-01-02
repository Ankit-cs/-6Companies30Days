/*
Brute Force: excepted during Contest but not feasible for interviews

*Generate all possible subarrays using two nested loops.
*For each subarray, remove it from the original array to form the remaining array.
*Check if the remaining array is strictly increasing.
*Count how many such subarrays result in a strictly increasing remaining array and return the count.
*/
/*
Optimal Force: 2 pointer for solution in O(n)
*Initial Check for Single Element: If there is only one element, then the total count is 1 since there's only one subarray.

*Find the Left and Right Boundaries:

1-The i pointer finds the end of the longest increasing subsequence starting from the left.-
2-The j pointer finds the start of the longest decreasing subsequence starting from the right.
3-If the Entire Array is Increasing or Decreasing: If j <= i, the entire array is either strictly increasing or decreasing, and all possible subarrays are incremovable. The formula (1LL * n * (n + 1)) / 2 computes the total number of subarrays in this case.

*Calculate Valid Subarrays:

1-Count the valid incremovable subarrays starting from the left up to i and from j to the right.
2-For each i1 from 0 to i, use a pointer j1 to find valid subarrays that can be formed from the current left section without violating the increasing order.
3-Return the Total Count: The result is incremented by 1 to account for the empty subarray.
*/