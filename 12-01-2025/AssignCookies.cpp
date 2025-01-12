/*
Simple Brute force will not work well as the question want us to tb think greedy
### Intuition Summary

- **Sort Arrays**: Sort greed factors (`g`) and cookie sizes (`s`) to prioritize smaller values.
- **Two Pointers**: Use one pointer for children (`sigma`) and another for cookies (`alpha`).
- **Greedy Pairing**: Assign the smallest cookie that satisfies the current child (`s[alpha] >= g[sigma]`). Move to the next child and cookie.
- **Stop Condition**: Stop when all children are satisfied or cookies are exhausted.
- **Optimal**: Maximizes satisfied children by efficiently using resources.*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int sigma = 0;
        int alpha = 0;
        
        while (sigma < g.size() && alpha < s.size()) {
            if (s[alpha] >= g[sigma]) {
                sigma++;
            }
            alpha++;
        }
        
        return sigma;
    }
};