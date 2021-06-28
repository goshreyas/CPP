

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
- https://leetcode.com/problems/sort-array-by-increasing-frequency/discuss/1023983/C%2B%2B-beats-95
- https://leetcode.com/problems/sort-array-by-increasing-frequency/
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

random_shuffle()
https://leetcode.com/problems/guess-the-word/


next_permutation()
https://leetcode.com/problems/24-game/

---------------------------------------------------------------------------------------------------

Segment tree
https://leetcode.com/problems/range-sum-query-mutable/solution/
Fenwick Tree or Binary Indexed Tree:
https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

---------------------------------------------------------------------------------------------------

Circular Array of size N:
 - Next Idx: (num + 1 + N) % N;
 - Prev Idx: (num - 1 + N) % N;

Ref: https://leetcode.com/problems/open-the-lock/
https://leetcode.com/problems/design-circular-queue/
---------------------------------------------------------------------------------------------------
Array Initialization:

Zero initialization:
int dp[50001] = {[0 ... 50000] = INT_MIN};
int MEM[501][501] = {[0 ... 500][0 ... 500] = 0};

https://leetcode.com/submissions/detail/490143361/
Ref: https://leetcode.com/problems/stone-game-iii/discuss/564261/C%2B%2B-Top-Down-DP
---------------------------------------------------------------------------------------------------


unordered_map()
reserve()
https://leetcode.com/problems/smallest-sufficient-team/submissions/
---------------------------------------------------------------------------------------------------
use cout as sprintf()
https://leetcode.com/problems/ambiguous-coordinates/submissions/

---------------------------------------------------------------------------------------------------
priority_queue using tuple:
typedef tuple<int,int,int> ti;

https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/115541/JavaC%2B%2BPython-Priority-Queue-Solution


---------------------------------------------------------------------------------------------------
string_view()
https://leetcode.com/problems/distinct-echo-substrings/submissions/


---------------------------------------------------------------------------------------------------
new/delete
https://leetcode.com/problems/remove-linked-list-elements/submissions/

---------------------------------------------------------------------------------------------------

