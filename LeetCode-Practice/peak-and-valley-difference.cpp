
/*
LeetCode: Peak and Valley Difference
Contest: Biweekly Contest
Topic: Arrays
Difficulty: Contest Problem

Problem Statement:
Calculate the sum of all peak elements and the sum of all
valley elements in the array. Return the difference between
the peak sum and the valley sum.

Approach:
Traverse the array from index 1 to n-2.
- A peak is greater than both its adjacent elements.
- A valley is smaller than both its adjacent elements.
Add peak values to peaksum and valley values to valleysum.
Finally, return peaksum - valleysum.

Algorithm Intuition:
An element can be a peak or a valley only if it has
elements on both sides. Therefore, we skip the first and
last elements.

For every middle element:
1. If it is greater than both neighbours, add it to peaksum.
2. Otherwise, if it is smaller than both neighbours,
   add it to valleysum.
3. Ignore elements that are neither peaks nor valleys.

Example:
nums = [1, 3, 2, 4, 1]

Peak elements: 3, 4
Valley element: 2

peaksum = 3 + 4 = 7
valleysum = 2

Answer = 7 - 2 = 5

Time Complexity: O(n)
Each array element is checked at most once.

Space Complexity: O(1)
Only a few integer variables are used.

Key Takeaway:
An element is a peak or valley based on comparisons
with its immediate neighbours.
*/

class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peaksum = 0;
        int valleysum = 0;
        int n = nums.size();

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] &&
                nums[i] > nums[i + 1]) {
                peaksum += nums[i];
            }
            else {
                if (nums[i] < nums[i - 1] &&
                    nums[i] < nums[i + 1]) {
                    valleysum += nums[i];
                }
            }
        }

        return peaksum - valleysum;
    }
};
