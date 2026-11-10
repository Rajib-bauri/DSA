
/*
    Problem: 3693. Climbing Stairs II

    Intuition:
    From the current stair, we can jump either 1, 2, or 3 steps.
    Each jump has a cost consisting of:
    1. The cost of reaching the destination stair.
    2. The square of the jump length.

    We need to find the minimum total cost to reach stair n.

    Approach: Recursion + Memoization

    1. Start from stair 0.
    2. Try three possible jumps: 1, 2, and 3.
    3. Calculate the cost of each valid jump.
    4. Recursively calculate the minimum cost from the
       destination stair.
    5. Choose the minimum among all three possibilities.
    6. Store the result in memo to avoid repeated calculations.

    Base Case:
    If i == n, return 0 because we have reached the destination.

    Time Complexity: O(n)
    Space Complexity: O(n)
    - Memoization array and recursion stack.
*/

class Solution {
public:
    vector<int> memo;

    int solve(int i, int n, vector<int>& costs) {

        if (i == n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int cost = INT_MAX;

        int j = i + 1;

        if(j <= n)
            cost = solve(j, n, costs) + costs[j - 1]
                   + (j - i) * (j - i);

        j = i + 2;

        if (j <= n)
            cost = min(cost, solve(j, n, costs) + costs[j - 1]
                        + (j - i) * (j - i));

        j = i + 3;

        if (j <= n)
            cost = min(cost, solve(j, n, costs) + costs[j - 1]
                        + (j - i) * (j - i));

        return memo[i] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {

        memo.assign(n + 1, -1);

        return solve(0, n, costs);
    }
};
