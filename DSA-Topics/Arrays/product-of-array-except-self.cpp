
/*
=========================================================
LeetCode 238: Product of Array Except Self
Topic: Arrays
=========================================================

PROBLEM STATEMENT:
Given an integer array nums, return an array answer such
that answer[i] is equal to the product of all the elements
of nums except nums[i].

The solution must not use division, and the problem expects
O(n) time complexity.

Example:
Input:  nums = [1, 2, 3, 4]
Output: [24, 12, 8, 6]


=========================================================
APPROACH 1: TOTAL PRODUCT + ZERO COUNT
=========================================================

APPROACH:
Calculate the product of all non-zero elements and count
the number of zeros. Then decide the result based on the
zero count.

ALGORITHM INTUITION:
1. Multiply all non-zero elements into prod.
2. Count the zeros in the array.
3. If there is exactly one zero:
   - The answer at the zero's position is prod.
   - All other positions are zero.
4. If there are more than one zero, every answer is zero.
5. If there are no zeros, divide prod by each element to
   obtain the product except that element.

TIME COMPLEXITY: O(n)
We traverse the array a constant number of times.

SPACE COMPLEXITY: O(1) AUXILIARY SPACE
Excluding the output array, only a few variables are used.
The output array itself requires O(n) space.

IMPORTANT:
This approach uses division, so it does not satisfy
LeetCode 238's no-division requirement. It is included
as a learning approach, not a valid submission for the
original problem constraints.


=========================================================
APPROACH 2: PREFIX ARRAY + SUFFIX ARRAY
=========================================================

APPROACH:
Build two arrays:
- prefix[i] stores the product of elements before i.
- suffix[i] stores the product of elements after i.

Then multiply prefix[i] by suffix[i].

ALGORITHM INTUITION:
For nums = [1, 2, 3, 4]:

prefix = [1, 1, 2, 6]
suffix = [24, 12, 4, 1]

answer[i] = prefix[i] * suffix[i]

answer = [24, 12, 8, 6]

The prefix product excludes nums[i] by stopping before i.
The suffix product excludes nums[i] by starting after i.

TIME COMPLEXITY: O(n)
Building prefix, building suffix, and creating the answer
each take linear time.

SPACE COMPLEXITY: O(n) AUXILIARY SPACE
The prefix and suffix arrays each require O(n) space.
The output array also requires O(n) space.


=========================================================
APPROACH 3: PREFIX + RUNNING SUFFIX (OPTIMIZED)
=========================================================

APPROACH:
Use the answer array to store prefix products first.
Then traverse from right to left using one suffix variable.

ALGORITHM INTUITION:
For nums = [1, 2, 3, 4]:

After the prefix pass:
ans = [1, 1, 2, 6]

Now traverse from right to left with suffix = 1.

At index 3:
ans[3] = 6 * 1 = 6
suffix = 1 * 4 = 4

At index 2:
ans[2] = 2 * 4 = 8
suffix = 4 * 3 = 12

At index 1:
ans[1] = 1 * 12 = 12
suffix = 12 * 2 = 24

At index 0:
ans[0] = 1 * 24 = 24

Final answer = [24, 12, 8, 6]

TIME COMPLEXITY: O(n)
Two linear passes are performed.

SPACE COMPLEXITY: O(1) AUXILIARY SPACE
Only one suffix variable is used beyond the output array.
The output array itself requires O(n) space.

=========================================================
COMPARISON
=========================================================

Approach 1:
Time: O(n)
Extra auxiliary space: O(1)
Uses division; violates the original problem requirement.

Approach 2:
Time: O(n)
Extra auxiliary space: O(n)
Uses separate prefix and suffix arrays.

Approach 3:
Time: O(n)
Extra auxiliary space: O(1)
Avoids division and does not need separate prefix/suffix
arrays. This is the most space-efficient valid approach.

=========================================================
*/


// APPROACH 1: TOTAL PRODUCT + ZERO COUNT

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1, zerocount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                prod *= nums[i];
            } else {
                zerocount++;
            }
        }

        vector<int> ans;

        if (zerocount == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0) {
                    ans.push_back(0);
                } else {
                    ans.push_back(prod);
                }
            }
        } else if (zerocount > 1) {
            for (int i = 0; i < n; i++) {
                ans.push_back(0);
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans.push_back(prod / nums[i]);
            }
        }

        return ans;
    }
};


// APPROACH 2: PREFIX ARRAY + SUFFIX ARRAY

/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> ans;

        // Prefix products
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Suffix products
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Combine prefix and suffix products
        for (int i = 0; i < n; i++) {
            ans.push_back(prefix[i] * suffix[i]);
        }

        return ans;
    }
};
*/


// APPROACH 3: PREFIX + RUNNING SUFFIX

/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Store prefix products in ans
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Multiply each prefix product by the suffix product
        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
*/
