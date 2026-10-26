
/*
LeetCode 3619: Count Islands
Topic: Graph, BFS, Matrix
Difficulty: Medium
Problem Link: https://leetcode.com/problems/count-islands/

Problem Statement:
Given a grid of positive and non-positive values and an integer k,
find the number of connected components consisting of positive
cells whose total sum is divisible by k.

Approach:
Use BFS to explore every connected component of positive cells.

1. Traverse every cell in the grid.
2. If a cell is positive, start BFS from that cell.
3. Add the values of all connected positive cells to sum.
4. Mark each visited cell as 0 to avoid visiting it again.
5. If sum % k == 0, increment count.

Algorithm Intuition:
Every connected group of positive cells represents an island.
BFS visits all cells connected horizontally or vertically.

During traversal, we calculate the total value of that island.
After BFS finishes, check whether its sum is divisible by k.
If it is, that island contributes 1 to the answer.

Example:
Suppose an island contains the values [1, 2, 3]
and k = 3.

Island sum = 1 + 2 + 3 = 6
6 % 3 == 0

This island contributes 1 to the answer.

Time Complexity: O(m * n)
Every cell is visited at most once.

Space Complexity: O(m * n)
The BFS queue can contain up to O(m * n) cells in the
worst case. The directions array uses constant space.

Key Takeaway:
BFS finds an entire connected component. Summing its values
lets us determine whether that component satisfies the
divisibility condition.
*/

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    long long bfs(int i, int j, vector<vector<int>>& grid) {
        long long sum = grid[i][j];
        grid[i][j] = 0;

        queue<pair<int, int>> que;
        que.push({i, j});

        while (!que.empty()) {
            auto [r, c] = que.front();
            que.pop();

            for (vector<int>& dir : directions) {
                int i_ = r + dir[0];
                int j_ = c + dir[1];

                if (i_ >= 0 && i_ < m &&
                    j_ >= 0 && j_ < n &&
                    grid[i_][j_] > 0) {

                    sum += grid[i_][j_];
                    grid[i_][j_] = 0;
                    que.push({i_, j_});
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = bfs(i, j, grid);

                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};
