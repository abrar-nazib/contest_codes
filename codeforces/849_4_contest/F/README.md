# F. Range Update Point Query 
 
 link: https://codeforces.com/contest/1791/problem/F 
 
 F. Range Update Point Querytime limit per test2 secondsmemory limit per test256 megabytesinputstandard inputoutputstandard outputGiven an array $$$a\_1, a\_2, \dots, a\_n$$$, you need to handle a total of $$$q$$$ updates and queries of two types:

* $$$1$$$ $$$l$$$ $$$r$$$ — for each index $$$i$$$ with $$$l \leq i \leq r$$$, update the value of $$$a\_i$$$ to the sum of the digits of $$$a\_i$$$.
* $$$2$$$ $$$x$$$ — output $$$a\_x$$$.
InputThe first line of the input contains an integer $$$t$$$ ($$$1 \leq t \leq 1000$$$) — the number of testcases.

The first line of each test case contains two integers $$$n$$$ and $$$q$$$ ($$$1 \le n, q \le 2 \cdot 10^5$$$) — the size of the array and the number of queries, respectively.

The second line of each test case contains $$$n$$$ integers $$$a\_1, a\_2, \dots, a\_n$$$ ($$$1 \le a\_i \le 10^9$$$).

The next $$$q$$$ lines of each test case are of two forms:

* $$$1$$$ $$$l$$$ $$$r$$$ ($$$1 \leq l \leq r \leq n$$$) — it means, for each index $$$i$$$ with $$$l \leq i \leq r$$$, you should update the value of $$$a\_i$$$ to the sum of its digits.
* $$$2$$$ $$$x$$$ ($$$1 \leq x \leq n$$$) — it means you should output $$$a\_x$$$.

There is at least one query of the second type.

The sum of $$$n$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$.

The sum of $$$q$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$.

OutputFor each test case, output the answers of queries of the second type, in the order they are given.

ExampleInputCopy
```
35 81 420 69 1434 20231 2 32 22 32 41 2 52 12 32 52 39999 10001 1 22 12 21 112 1
```
OutputCopy
```
6
15
1434
1
6
7
36
1
1

```
NoteIn the first test case, the following process occurs: 

* Initially, $$$a = [1, 420, 69, 1434, 2023]$$$.
* The operation is performed for $$$l=2$$$, $$$r=3$$$, yielding $$$[1, \color{red}{6}, \color{red}{15}, 1434, 2023]$$$.
* We are queried for $$$x=2$$$, $$$x=3$$$, and $$$x=4$$$, and output $$$6$$$, $$$15$$$, and $$$1434$$$.
* The operation is performed for $$$l=2$$$, $$$r=5$$$, yielding $$$[1, \color{red}{6}, \color{red}{6}, \color{red}{12}, \color{red}{7}]$$$.
* We are queried for $$$x=1$$$, $$$x=3$$$, and $$$x=5$$$, and output $$$1$$$, $$$6$$$, and $$$7$$$.
