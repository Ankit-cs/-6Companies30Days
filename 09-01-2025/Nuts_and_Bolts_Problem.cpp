/*
Most INTUTIVE: I just think by using constraints 

*Create a helper function to perform binary search on the predefined order.
*Use this binary search to map each nut to its corresponding bolt.
*Sort both nuts and bolts arrays based on their positions in the predefined order.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

   void matchPairs(int n, char nuts[], char bolts[]) {
        vector<char> order = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        
        auto binarySearch = [&](char key) {
            int low = 0, high = order.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (order[mid] == key) return mid;
                else if (order[mid] < key) low = mid + 1;
                else high = mid - 1;
            }
            return -1;
        };

        sort(nuts, nuts + n, [&](char a, char b) {
            return binarySearch(a) < binarySearch(b);
        });

        sort(bolts, bolts + n, [&](char a, char b) {
            return binarySearch(a) < binarySearch(b);
        });
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends
