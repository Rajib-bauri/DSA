
/*
Problem: LeetCode 344 - Reverse String

Problem Statement:
Given an array of characters s, reverse the array in-place.
Use O(1) extra memory.

Example 1:
Input:  s = ['h', 'e', 'l', 'l', 'o']
Output: ['o', 'l', 'l', 'e', 'h']

Example 2:
Input:  s = ['H', 'a', 'n', 'n', 'a', 'h']
Output: ['h', 'a', 'n', 'n', 'a', 'H']


Approach: Two Pointers

1. Initialize left = 0 and right = s.size() - 1.
2. Swap the characters at the left and right positions.
3. Increment left and decrement right.
4. Repeat until left >= right.
5. The array is reversed in-place.


Algorithm Intuition:

The idea is to swap characters from opposite ends of
the array.

For example:
['h', 'e', 'l', 'l', 'o']

First swap:
['o', 'e', 'l', 'l', 'h']

Second swap:
['o', 'l', 'l', 'e', 'h']

Now the pointers meet or cross, so we stop.
Each swap puts two characters in their correct positions.


Time Complexity: O(n)
We perform approximately n/2 swaps.
Ignoring constant factors, the time complexity is O(n).


Space Complexity: O(1)
We reverse the array in-place using only two pointers.
No additional array is required.


Key Takeaway:
The Two Pointers technique efficiently reverses an array
by swapping elements from both ends.
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

## 8. Key Takeaway

The Two Pointers technique is useful when processing elements from opposite ends of an array.

For reversing an array in-place, swapping the first and last elements repeatedly gives an efficient solution with **O(n) time and O(1) extra space**.
