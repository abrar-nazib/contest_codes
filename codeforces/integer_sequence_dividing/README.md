# A. Integer Sequence Dividing 
 
 link: https://codeforces.com/contest/1102/problem/A 
 
 A. Integer Sequence Dividingtime limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputYou are given an integer sequence 1,2,…,n1, 2, \dots, n. You have to divide it into two sets AA and BB in such a way that each element belongs to exactly one set and |sum(A)−sum(B)||sum(A) - sum(B)| is minimum possible.

The value |x||x| is the absolute value of xx and sum(S)sum(S) is the sum of elements of the set SS.

InputThe first line of the input contains one integer nn (1≤n≤2⋅1091 \le n \le 2 \cdot 10^9).

OutputPrint one integer — the minimum possible value of |sum(A)−sum(B)||sum(A) - sum(B)| if you divide the initial sequence 1,2,…,n1, 2, \dots, n into two sets AA and BB.

ExamplesInputCopy
```
3

```
OutputCopy
```
0

```
InputCopy
```
5

```
OutputCopy
```
1

```
InputCopy
```
6

```
OutputCopy
```
1

```
NoteSome (not all) possible answers to examples:

In the first example you can divide the initial sequence into sets A={1,2}A = \{1, 2\} and B={3}B = \{3\} so the answer is 00.

In the second example you can divide the initial sequence into sets A={1,3,4}A = \{1, 3, 4\} and B={2,5}B = \{2, 5\} so the answer is 11.

In the third example you can divide the initial sequence into sets A={1,4,5}A = \{1, 4, 5\} and B={2,3,6}B = \{2, 3, 6\} so the answer is 11.

