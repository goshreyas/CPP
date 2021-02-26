

#include <bits/stdc++.h>
using namespace std;

---------------------------------------------------------------------------------------------------
Tips#1:
Find max of k num:
    m = max({n1, n2, n3, ... nk});
    Ref: 


#include<algorithm>
   vector <int> v;
 - int smallest_element = *min_element(v.begin(),v.end());
 - int largest_element  = *max_element(v.begin(),v.end());
Ref: https://leetcode.com/problems/count-square-submatrices-with-all-ones/

---------------------------------------------------------------------------------------------------
Tips#2:
auto it = find()
    
---------------------------------------------------------------------------------------------------
Tips#3:
Fast I/O for Competitive Programming
1: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
2: https://leetcode.com/problems/range-sum-of-bst/submissions/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // To decrease computation time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

---------------------------------------------------------------------------------------------------
Tips#4:
Define mySort() inside the class:
- https://leetcode.com/problems/course-schedule-iii/submissions/
- https://leetcode.com/problems/reorder-data-in-log-files/submissions/
- https://leetcode.com/submissions/detail/429993485/
- https://leetcode.com/submissions/detail/433754238/

Use lambda function in custom sorting:
- https://leetcode.com/problems/top-k-frequent-words/submissions/
- https://leetcode.com/problems/set-intersection-size-at-least-two/

---------------------------------------------------------------------------------------------------
Tips#5:
keep "vector<vector<int>> next_land{{-1,0}, {0,-1}, {0, 1}, {1,0}};" inside class
Ref:
- https://leetcode.com/problems/number-of-islands/
- https://leetcode.com/submissions/detail/433668870/

---------------------------------------------------------------------------------------------------
Tips#5:
Overflow

int overflow = (INT_MAX / 10) * 10 + 7; // INT_MAX = +2147483647 , INT_MIN = -2147483648
int overflow = INT_MAX; // NOTE

Ref: https://leetcode.com/problems/reverse-integer/

Overflow Check
if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))

Ref: https://leetcode.com/problems/string-to-integer-atoi/

Value of INT_MAX is +2147483647
Value of INT_MIN is -2147483648
    
int modulo = 1e9+7; // 1000000007  == 1𝑒9+7

---------------------------------------------------------------------------------------------------

nth_element(): http://www.cplusplus.com/reference/algorithm/nth_element/
https://leetcode.com/problems/kth-largest-element-in-an-array/



---------------------------------------------------------------------------------------------------

Log:
 - Length of the base 10 num: log10(N)+1
 - Length of the base 2 num: log2(N)+1
Ref: https://leetcode.com/problems/armstrong-number/

---------------------------------------------------------------------------------------------------



---------------------------------------------------------------------------------------------------




---------------------------------------------------------------------------------------------------
