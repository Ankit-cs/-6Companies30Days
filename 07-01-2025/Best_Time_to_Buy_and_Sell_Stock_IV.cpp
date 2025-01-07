/*
* Brute Force: A reader might wonder why recursion is used. It's because we can explore loose constraints efficiently.
* Goal: Maximize profit with at most 𝑘 buy-sell transactions.
* Choices:
  1. If holding, either sell or skip.
  2. If not holding, either buy or skip.
* Recursive Steps: Explore all actions at each day while tracking:
  - *Current day (index).
  - *Remaining transactions (transactions_remaining).
  - *Stock status (holding).
* Base Case: Stop when:
  - *All days are processed.
  - *No transactions left.
* Profit Calculation:
  - *Sell: Current price + future profit.
  - *Buy: -Current price + future profit.
  - *Choose the maximum.
*/

/*
/*
OPTIMISED : Using a 3D DP 
* Goal: Maximize profit with at most k transactions.
* Key Idea:
  - *At each day, decide whether to buy, sell, or skip based on remaining transactions and profit.
* States to Track:
  - *day: Current day.
  - *transLeft: Transactions remaining.
  - *canBuy: Whether buying is allowed (1 = yes, 0 = no).
* Base Case: 
  - *Stop when all days are processed or no transactions are left.
* Logic:
  - *If buying is allowed, choose to buy or skip.
  - *If selling is allowed, choose to sell or skip.
  - *Use the maximum profit from these choices.
* Memoization: 
  - *Save results of already calculated states in a 3D array to avoid recalculating.
*/

*/

class Solution {
private:
    int findMaxProfit(int day, int transLeft, int canBuy, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
        if (day == n || transLeft == 0) return 0;
        
        if (dp[day][transLeft][canBuy] != -1) return dp[day][transLeft][canBuy];
        
        if (canBuy == 1) {
            dp[day][transLeft][canBuy] = max(
                -prices[day] + findMaxProfit(day + 1, transLeft, 0, prices, n, dp),
                findMaxProfit(day + 1, transLeft, 1, prices, n, dp)
            );
        } else {
            dp[day][transLeft][canBuy] = max(
                prices[day] + findMaxProfit(day + 1, transLeft - 1, 1, prices, n, dp),
                findMaxProfit(day + 1, transLeft, 0, prices, n, dp)
            );
        }
        
        return dp[day][transLeft][canBuy];
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return findMaxProfit(0, k, 1, prices, n, dp);
    }
};
