
/*
Problem: 189. Rotate Array
Platform: LeetCode
Topic: Arrays
Language: C++

Algorithm Intuition:
First, normalize k using k = k % n.

Then reverse the entire array.
Next, reverse the first k elements.
Finally, reverse the remaining n - k elements.

These three reversals rotate the array to the
right by k positions without using an extra array.

Time Complexity: O(n)
The three reversal operations together take
linear time.

Space Complexity: O(1)
The algorithm modifies the original array in place
and uses only a constant amount of extra space.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        int i = 0, j = n - 1;

        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        i = 0, j = k - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        i = n - (n - k), j = n - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
