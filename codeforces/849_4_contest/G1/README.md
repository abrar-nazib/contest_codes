# G1. Teleporters (Easy Version) 
 
 link: https://codeforces.com/contest/1791/problem/G1 
 
 G1. Teleporters (Easy Version)time limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputThe only difference between the easy and hard versions are the locations you can teleport to.

Consider the points $$$0, 1, \dots, n$$$ on the number line. There is a teleporter located on each of the points $$$1, 2, \dots, n$$$. At point $$$i$$$, you can do the following:

* Move left one unit: it costs $$$1$$$ coin.
* Move right one unit: it costs $$$1$$$ coin.
* Use a teleporter at point $$$i$$$, if it exists: it costs $$$a\_i$$$ coins. As a result, you teleport to point $$$0$$$. Once you use a teleporter, you can't use it again.

You have $$$c$$$ coins, and you start at point $$$0$$$. What's the most number of teleporters you can use?

InputThe input consists of multiple test cases. The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 1000$$$) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains two integers $$$n$$$ and $$$c$$$ ($$$1 \leq n \leq 2\cdot10^5$$$; $$$1 \leq c \leq 10^9$$$)  — the length of the array and the number of coins you have respectively.

The following line contains $$$n$$$ space-separated integers $$$a\_1, a\_2, \dots, a\_n$$$ ($$$1 \leq a\_i \leq 10^9$$$) — the costs to use the teleporters.

It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2\cdot10^5$$$.

OutputFor each test case, output the maximum number of teleporters you can use.

ExampleInputCopy
```
105 61 1 1 1 18 32100 52 13 6 9 4 100 351 154 54 3 2 15 92 3 1 4 15 82 3 1 4 14 32 3 4 14 95 4 3 32 147 55 600000000500000000 400000000 300000000 200000000 100000000
```
OutputCopy
```
2
2
0
1
2
2
1
1
1
2

```
NoteIn the first test case, you can move one unit to the right, use the teleporter at index $$$1$$$ and teleport to point $$$0$$$, move two units to the right and use the teleporter at index $$$2$$$. You are left with $$$6-1-1-2-1 = 1$$$ coins you don't have enough coins to use another teleporter. You have used two teleporters, so the answer is two.

In the second test case, you go four units to the right and use the teleporter to go to $$$0$$$, then go six units right and use the teleporter at index $$$6$$$ to go to $$$0$$$. The total cost will be $$$4+6+6+4 = 20$$$. You are left with $$$12$$$ coins, but it is not enough to reach any other teleporter and use it so the answer is $$$2$$$.

In the third test case, you don't have enough coins to use any teleporter, so the answer is zero.
