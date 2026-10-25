
/*
LeetCode 1254: Number of Closed Islands
Topic: Graph, DFS, Matrix
Difficulty: Medium
Problem Link: https://leetcode.com/problems/number-of-closed-islands/

Problem Statement:
Given an m x n grid where 0 represents land and 1 represents
water, return the number of closed islands.

A closed island is a group of connected land cells completely
surrounded by water, meaning it does not touch the grid boundary.

Approach:
Use DFS to explore every connected component of land.

- If DFS goes outside the grid, return false because the island
  touches the boundary and is not closed.
- If a cell is water or already visited, return true.
- Mark each visited land cell as water.
- Explore left, right, up, and down.
- An island is closed only if all four DFS directions return true.

Algorithm Intuition:
A land cell belongs to a closed island only if its connected
region never reaches outside the grid.

DFS checks the entire connected region. If any path reaches
outside the boundary, false propagates back through the DFS calls.
Otherwise, the region is closed and contributes 1 to count.

Example:
grid = [
  [1,1,1,1,1,1,1],
  [1,0,0,0,0,0,1],
  [1,0,1,1,1,0,1],
  [1,0,0,0,0,0,1],
  [1,1,1,1,1,1,1]
]

The land region is completely surrounded by water.

Output: 1

Time Complexity: O(m * n)
Each cell is visited at most once.

Space Complexity: O(m * n)
The recursive DFS call stack can reach O(m * n)
in the worst case.

Key Takeaway:
DFS explores a whole connected land region. If any cell
leads outside the grid, that region is not a closed island.
*/

class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return false; // Not closed

        if (grid[r][c] == 1)
            return true; // Water or already visited

        grid[r][c] = 1;

        bool left  = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);
        bool up    = dfs(grid, r - 1, c);
        bool down  = dfs(grid, r + 1, c);

        return left && right && up && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count += dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};
