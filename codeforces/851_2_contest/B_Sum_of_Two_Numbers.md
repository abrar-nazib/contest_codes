# B. Sum of Two Numbers 
 
 link: https://codeforces.com/contest/1788/problem/B 
 
 B. Sum of Two Numberstime limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputThe sum of digits of a non-negative integer aa is the result of summing up its digits together when written in the decimal system. For example, the sum of digits of 123123 is 66 and the sum of digits of 1010 is 11. In a formal way, the sum of digits of a=∞∑i=0ai⋅10i\displaystyle a=\sum\_{i=0}^{\infty} a\_i \cdot 10^i, where 0≤ai≤90 \leq a\_i \leq 9, is defined as ∞∑i=0ai\displaystyle\sum\_{i=0}^{\infty}{a\_i}.

Given an integer nn, find two non-negative integers xx and yy which satisfy the following conditions.

* x+y=nx+y=n, and
* the sum of digits of xx and the sum of digits of yy differ by at most 11.

It can be shown that such xx and yy always exist.

InputEach test contains multiple test cases. The first line contains the number of test cases tt (1≤t≤100001 \le t \le 10\,000). 

Each test case consists of a single integer nn (1≤n≤1091 \leq n \leq 10^9)

OutputFor each test case, print two integers xx and yy.

If there are multiple answers, print any.

ExampleInputCopy
```
5
1
161
67
1206
19

```
OutputCopy
```
1 0
67 94
60 7
1138 68
14 5
```
NoteIn the second test case, the sum of digits of 6767 and the sum of digits of 9494 are both 1313.

In the third test case, the sum of digits of 6060 is 66, and the sum of digits of 77 is 77.

