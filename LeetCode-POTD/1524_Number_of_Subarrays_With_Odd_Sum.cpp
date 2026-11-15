```cpp
/*
    LeetCode POTD 1524: Number of Sub-arrays With Odd Sum

    Problem:
    Given an array of integers, count the number of subarrays
    whose sum is odd.

    Return the answer modulo 10^9 + 7.

    Intuition:
    We use Prefix Sum and the concept of odd and even numbers.

    Important observation:
    - Even + Even = Even
    - Odd + Odd = Even
    - Even + Odd = Odd

    If the current prefix sum is even, we need a previous
    odd prefix sum to get an odd subarray sum.

    If the current prefix sum is odd, we need a previous
    even prefix sum to get an odd subarray sum.

    Approach:
    1. Initialize oddcnt = 0 and evencnt = 1.
       evencnt starts at 1 because the initial prefix sum
       is 0, which is even.

    2. Calculate the prefix sum for every element.

    3. If the prefix sum is even:
       - Add oddcnt to count.
       - Increase evencnt.

    4. If the prefix sum is odd:
       - Add evencnt to count.
       - Increase oddcnt.

    5. Apply modulo 10^9 + 7 to avoid overflow.

    6. Return count.

    Time Complexity: O(n)
    - We traverse the array only once.

    Space Complexity: O(1)
    - Only a constant number of variables are used.
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int oddcnt = 0, evencnt = 1;
        int count = 0, prefixsum = 0;

        const int MOD = 1e9 + 7;

        for (int num : arr) {

            prefixsum += num;

            if (prefixsum % 2 == 0) {

                count += oddcnt;
                evencnt++;

            } else {

                count += evencnt;
                oddcnt++;
            }

            count %= MOD;
        }

        return count;
    }
};
```
