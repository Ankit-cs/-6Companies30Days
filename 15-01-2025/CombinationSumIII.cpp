/*
Simple recursive apporahcc works well as its constraints ar too much loose can be practice DP approach */
Code:

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(k, n, 1, current, result);
        return result;
    }

private:
    void backtrack(int k, int n, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k && n == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i <= 9; ++i) {
            if (n - i < 0) break;
            current.push_back(i);
            backtrack(k, n - i, i + 1, current, result);
            current.pop_back();
        }
    }
};
