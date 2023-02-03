# A. Flip Flop Sum 
 
 link: https://codeforces.com/contest/1778/problem/0 
 
 A. Flip Flop Sumtime limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputYou are given an array of $$$n$$$ integers $$$a\_1, a\_2, \ldots, a\_n$$$. The integers are either $$$1$$$ or $$$-1$$$. You have to perform the following operation exactly once on the array $$$a$$$:

* Choose an index $$$i$$$ ($$$1 \leq i < n$$$) and flip the signs of $$$a\_i$$$ and $$$a\_{i+1}$$$. Here, flipping the sign means $$$-1$$$ will be $$$1$$$ and $$$1$$$ will be $$$-1$$$.

What is the maximum possible value of $$$a\_1 + a\_2 + \ldots + a\_n$$$ after applying the above operation?

InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 500$$$). Description of the test cases follows.

The first line of each test case contains a single integer $$$n$$$ ($$$2 \le n \le 10^5$$$), the length of the array $$$a$$$.

The next line contains $$$n$$$ integers $$$a\_1, a\_2, \ldots, a\_n$$$ ($$$a\_i = 1$$$ or $$$a\_i = -1$$$).

The sum of $$$n$$$ over all cases doesn't exceed $$$10^5$$$.

OutputFor each test case, print the maximum possible sum of the array $$$a$$$ you can get in a separate line.

ExampleInputCopy
```
45-1 1 1 -1 -151 1 -1 -1 -121 141 -1 -1 1
```
OutputCopy
```
3
3
-2
4

```
NoteIn the first case, we can choose index $$$4$$$ and flip the signs of $$$a\_4$$$ and $$$a\_5$$$. After this operation, the sum will be $$$-1+1+1+1+1 = 3$$$. We can't make the sum larger than this.

In the third case, the only option is to choose the index $$$1$$$.

