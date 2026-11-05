
/*
    Problem: 1385. Find the Distance Value Between Two Arrays

    Intuition:
    An element from arr1 is valid if its absolute difference
    with every element in arr2 is strictly greater than d.

    Approach:
    1. Traverse each element x in arr1.
    2. Assume the element is valid by setting ok = true.
    3. Traverse every element y in arr2.
    4. Check whether abs(x - y) > d.
    5. If any difference is less than or equal to d,
       the element is not valid.
    6. Count all valid elements.

    Example:
    arr1 = [4, 5, 8]
    arr2 = [10, 9, 1, 8]
    d = 2

    4 -> Difference with 1 is 3, with 8 is 4,
         with 9 is 5, with 10 is 6. Valid.
    5 -> Difference with 1 is 4, with 8 is 3,
         with 9 is 4, with 10 is 5. Valid.
    8 -> Difference with 8 is 0. Not valid.

    Output: 2

    Time Complexity: O(n * m)
    - n = arr1.size()
    - m = arr2.size()

    Space Complexity: O(1)
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        int cnt = 0;

        for (auto& x : arr1) {
            bool ok = true;

            for (auto& y : arr2) {
                ok &= (abs(x - y) > d);
            }

            cnt += ok;
        }

        return cnt;
    }
};   

// 
