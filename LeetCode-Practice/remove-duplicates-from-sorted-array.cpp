
/*
Problem: 26. Remove Duplicates from Sorted Array
Platform: LeetCode
Topic: Arrays, Two Pointers
Language: C++

Algorithm Intuition:
Use two pointers to remove duplicates in-place.
The j pointer traverses the array, while i points
to the position where the next unique element
should be stored.

If nums[j] differs from nums[i - 1], store it
at nums[i] and increment i.

Finally, return i, the number of unique elements.

Time Complexity: O(n)
The array is traversed once.

Space Complexity: O(1)
Only a constant amount of extra space is used.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1;

        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i - 1]) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};
