# E. Negatives and Positives 
 
 link: https://codeforces.com/contest/1791/problem/E 
 
 E. Negatives and Positivestime limit per test2 secondsmemory limit per test256 megabytesinputstandard inputoutputstandard outputGiven an array $$$a$$$ consisting of $$$n$$$ elements, find the maximum possible sum the array can have after performing the following operation any number of times: 

* Choose $$$2$$$ adjacent elements and flip both of their signs. In other words choose an index $$$i$$$ such that $$$1 \leq i \leq n - 1$$$ and assign $$$a\_i = -a\_i$$$ and $$$a\_{i+1} = -a\_{i+1}$$$.
InputThe input consists of multiple test cases. The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 1000$$$) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains an integer $$$n$$$ ($$$2 \leq n \leq 2\cdot10^5$$$) — the length of the array.

The following line contains $$$n$$$ space-separated integers $$$a\_1,a\_2,\dots,a\_n$$$ ($$$-10^9 \leq a\_i \leq 10^9$$$).

It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2\cdot10^5$$$.

OutputFor each test case, output the maximum possible sum the array can have after performing the described operation any number of times.

ExampleInputCopy
```
53-1 -1 -151 5 -5 0 231 2 36-1 10 9 8 7 62-1 -1
```
OutputCopy
```
1
13
6
39
2

```
NoteFor the first test case, by performing the operation on the first two elements, we can change the array from $$$[-1, -1, -1]$$$ to $$$[1, 1, -1]$$$, and it can be proven this array obtains the maximum possible sum which is $$$1 + 1 + (-1) = 1$$$.

For the second test case, by performing the operation on $$$-5$$$ and $$$0$$$, we change the array from $$$[1, 5, -5, 0, 2]$$$ to $$$[1, 5, -(-5), -0, 2] = [1, 5, 5, 0, 2]$$$, which has the maximum sum since all elements are non-negative. So, the answer is $$$1 + 5 + 5 + 0 + 2 = 13$$$.

For the third test case, the array already contains only positive numbers, so performing operations is unnecessary. The answer is just the sum of the whole array, which is $$$1 + 2 + 3 = 6$$$.

