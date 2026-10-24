
/*
=========================================================
LeetCode 122: Best Time to Buy and Sell Stock II
Topic: Array, Greedy
Difficulty: Medium

Problem Link:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/


PROBLEM STATEMENT:
You are given an array prices where prices[i] represents
the stock price on the ith day.

You can buy and sell the stock multiple times, but you
must sell the stock before buying again.

Return the maximum profit you can achieve.


EXAMPLE 1:
Input: prices = [7,1,5,3,6,4]
Output: 7

Explanation:
Buy at 1 and sell at 5: profit = 4.
Buy at 3 and sell at 6: profit = 3.
Total profit = 4 + 3 = 7.


EXAMPLE 2:
Input: prices = [1,2,3,4,5]
Output: 4

Explanation:
Buy at 1 and sell at 5: profit = 4.


EXAMPLE 3:
Input: prices = [7,6,4,3,1]
Output: 0

Explanation:
Prices only decrease, so no profitable transaction
is possible.


=========================================================
APPROACH: GREEDY
=========================================================

ALGORITHM INTUITION:

We compare each day's price with the previous day's price.

If today's price is greater than yesterday's price,
there is a positive price difference.

We add this difference to the total profit.

Why does this work?
Because multiple transactions are allowed, we can collect
every positive increase in price. This gives the same total
profit as buying before an increasing stretch and selling
at its end.

ALGORITHM:
1. Initialize profit = 0.
2. Start traversing from index 1.
3. Compare prices[i] with prices[i - 1].
4. If prices[i] > prices[i - 1], add their difference
   to profit.
5. Return the total profit.


DRY RUN:
prices = [7, 1, 5, 3, 6, 4]

i = 1: 1 < 7  -> profit = 0
i = 2: 5 > 1  -> profit = 4
i = 3: 3 < 5  -> profit = 4
i = 4: 6 > 3  -> profit = 7
i = 5: 4 < 6  -> profit = 7

Final answer = 7.


TIME COMPLEXITY: O(n)
We traverse the prices array once, performing constant-
time comparisons and additions at each index.

SPACE COMPLEXITY: O(1)
Only the variables n and profit are used. No additional
array or data structure is created.


KEY TAKEAWAY:
In this problem, every positive consecutive price increase
contributes to the maximum profit. The Greedy approach
collects these increases without explicitly storing
buying and selling days.
=========================================================
*/

class Solution {
public:
    int maxProfit(vector<int>& nums) {

        int n = nums.size();
        int profit = 0;

        for (int i = 1; i < n; i++) {

            if (nums[i] > nums[i - 1]) {
                profit += nums[i] - nums[i - 1];
            }
        }

        return profit;
    }
};
