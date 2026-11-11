
/*
Problem:
Given a string s, return the length of the longest palindrome
that can be built using its characters.

Intuition:
A palindrome contains pairs of the same characters.
If any character has an odd frequency, one occurrence of that
character can be placed in the center.

Approach:
1. Use an unordered_map to count the frequency of each character.
2. For every character, take the largest even number of occurrences.
3. Add these pairs to the answer.
4. If any character has an odd frequency, add one character
   to the center.
5. Return the final count.

Example:
Input: s = "abccccdd"
Output: 7

Explanation:
We can build "dccaccd", which has length 7.

Time Complexity: O(n)
Space Complexity: O(k)
where k is the number of distinct characters.
*/

class Solution {
public:
    int longestPalindrome(string s) {
         
         unordered_map<char,int> mp;
         int count = 0;
         bool odd = false;

         for(char ch : s) {
              mp[ch]++;
         }

         for(auto it : mp) {
              if(it.second >= 2) {
                 int x = it.second / 2;
                 count += (x * 2);
              }

              if(it.second % 2 != 0) {
                  odd = true;
              }
         }

         if(odd) count++;

         return count;
    }
};
