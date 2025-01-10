/*
INTUTION:
The **Matrix Chain Multiplication** problem aims to find the most efficient order to multiply a chain of matrices to minimize scalar multiplications. The process involves:

- **Key Insight**:
  - Matrix multiplication is **associative** but not **commutative**, meaning the order of multiplication affects the cost.
  
- **Recursive Approach**:
  - For a given sequence of matrices, try all possible splits between matrices `i` and `j` at index `k`.
  - The subproblem is divided into two parts: multiplying matrices from `i` to `k` and from `k+1` to `j`.
  - The cost of the split is the sum of the costs of the two subproblems plus the cost of multiplying the two resulting matrices.

- **Memoization**:
  - To avoid redundant calculations, store results of subproblems in a table:
    - `dp[i][j]` stores the minimum cost for multiplying matrices from `i` to `j`.
    - `brackets[i][j]` stores the optimal parenthesization (order of multiplication).

- **Base Case**:
  - When `i == j`, the cost is zero because only one matrix is involved and no multiplication is needed.

- **Final Result**:
  - The minimum multiplication cost for matrices from `1` to `n-1` is in `dp[1][n-1]`.
  - The optimal multiplication order is stored in `brackets[1][n-1]`.

This dynamic programming approach reduces the time complexity from exponential to polynomial by reusing previously computed results.*/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<string>> brackets(n, vector<string>(n, ""));
        return solve(arr, 1, n - 1, dp, brackets);
    }

  private:
    string solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp, vector<vector<string>> &brackets) {
        if (i == j) {
            return string(1, 'A' + i - 1);
        }

        if (dp[i][j] != -1) {
            return brackets[i][j];
        }

        int minCost = INT_MAX;
        string optimalParenthesization;

        for (int k = i; k < j; k++) {
            string left = solve(arr, i, k, dp, brackets);
            string right = solve(arr, k + 1, j, dp, brackets);
            int cost = (dp[i][k] != -1 ? dp[i][k] : 0) +
                       (dp[k + 1][j] != -1 ? dp[k + 1][j] : 0) +
                       arr[i - 1] * arr[k] * arr[j];

            if (cost < minCost) {
                minCost = cost;
                optimalParenthesization = "(" + left + right + ")";
            }
        }

        dp[i][j] = minCost;
        brackets[i][j] = optimalParenthesization;

        return optimalParenthesization;
    }
};


//{ Driver Code Starts.

int get(vector<int> &p, int n) {
    int m[n][n], ans = 1e9;
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            m[i][i + L - 1] = INT_MAX;
            for (int k = i; k <= i + L - 2; k++) {
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i - 1] * p[k] * p[i + L - 1];
                if (q < m[i][i + L - 1]) {
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int find(string s, vector<int> &p) {
    vector<pair<int, int>> arr;
    int ans = 0;
    for (auto t : s) {
        if (t == '(') {
            arr.push_back({-1, -1});
        } else if (t == ')') {
            pair<int, int> b = arr.back();
            arr.pop_back();
            pair<int, int> a = arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first, b.second});
            ans += a.first * a.second * b.second;
        } else {
            arr.push_back({p[int(t - 'A')], p[int(t - 'A') + 1]});
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> p;
        int x;
        while (ss >> x) {
            p.push_back(x);
        }
        Solution ob;
        string result = ob.matrixChainOrder(p);
        if (find(result, p) == get(p, p.size())) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}
// } Driver Code Ends