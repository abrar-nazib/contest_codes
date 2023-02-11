# A. One and Two 
 
 link: https://codeforces.com/contest/1788/problem/0 
 
 A. One and Twotime limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputYou are given a sequence $$$a\_1, a\_2, \ldots, a\_n$$$. Each element of $$$a$$$ is $$$1$$$ or $$$2$$$.

Find out if an integer $$$k$$$ exists so that the following conditions are met. 

* $$$1 \leq k \leq n-1$$$, and
* $$$a\_1 \cdot a\_2 \cdot \ldots \cdot a\_k = a\_{k+1} \cdot a\_{k+2} \cdot \ldots \cdot a\_n$$$.

If there exist multiple $$$k$$$ that satisfy the given condition, print the smallest.

InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 100$$$). Description of the test cases follows.

The first line of each test case contains one integer $$$n$$$ ($$$2 \leq n \leq 1000$$$).

The second line of each test case contains $$$n$$$ integers $$$a\_1, a\_2, \ldots, a\_n$$$ ($$$1 \leq a\_i \leq 2$$$).

OutputFor each test case, if there is no such $$$k$$$, print $$$-1$$$.

Otherwise, print the smallest possible $$$k$$$.

ExampleInputCopy
```
362 2 1 2 1 231 2 141 1 1 1
```
OutputCopy
```
2
-1
1

```
NoteFor the first test case, $$$k=2$$$ satisfies the condition since $$$a\_1 \cdot a\_2 = a\_3 \cdot a\_4 \cdot a\_5 \cdot a\_6 = 4$$$. $$$k=3$$$ also satisfies the given condition, but the smallest should be printed.

For the second test case, there is no $$$k$$$ that satisfies $$$a\_1 \cdot a\_2 \cdot \ldots \cdot a\_k = a\_{k+1} \cdot a\_{k+2} \cdot \ldots \cdot a\_n$$$

For the third test case, $$$k=1$$$, $$$2$$$, and $$$3$$$ satisfy the given condition, so the answer is $$$1$$$.

