/*
INTUTION:

- **Sliding Window Technique**: 
  - Two pointers (`left` and `right`) are used to maintain a window of size `k`.
  
- **Expanding and Shrinking Window**:
  - The `right` pointer expands the window by moving right.
  - The `left` pointer shrinks the window when duplicates are found to maintain uniqueness.

- **Maintaining Sum**:
  - The sum of the elements in the window is updated as the `right` pointer moves.
  
- **Checking Subarray Size**:
  - When the window size reaches `k`, the sum is considered for the maximum sum.
  
- **Efficient Time Complexity**:
  - The approach runs in **O(n)** time since each element is added and removed from the window only once.
  
- **No Duplicate Elements**:
  - The sliding window ensures that no elements are repeated within the window using a set for tracking unique elements.

- **Optimal Solution**:
  - Avoids recalculating sums for overlapping parts of subarrays, providing an optimal solution.*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
   
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;
    int current_max = -1;

    for (int i = 0; i < k; i++) {
        current_max = max(current_max, arr[i]);
    }
    result.push_back(current_max);

    for (int i = k; i < n; i++) {
        if (arr[i - k] == current_max) {
            current_max = *max_element(arr.begin() + i - k + 1, arr.begin() + i + 1);
        } else {
            current_max = max(current_max, arr[i]);
        }
        result.push_back(current_max);
    }

    return result;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends