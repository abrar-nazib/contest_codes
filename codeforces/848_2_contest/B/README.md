# B. The Forbidden Permutation 
 
 link: https://codeforces.com/contest/1778/problem/B 
 
 B. The Forbidden Permutationtime limit per test2 secondsmemory limit per test256 megabytesinputstandard inputoutputstandard outputYou are given a permutation $$$p$$$ of length $$$n$$$, an array of $$$m$$$ distinct integers $$$a\_1, a\_2, \ldots, a\_m$$$ ($$$1 \le a\_i \le n$$$), and an integer $$$d$$$.

Let $$$\mathrm{pos}(x)$$$ be the index of $$$x$$$ in the permutation $$$p$$$. The array $$$a$$$ is not good if 

* $$$\mathrm{pos}(a\_{i}) < \mathrm{pos}(a\_{i + 1}) \le \mathrm{pos}(a\_{i}) + d$$$ for all $$$1 \le i < m$$$.

For example, with the permutation $$$p = [4, 2, 1, 3, 6, 5]$$$ and $$$d = 2$$$: 

* $$$a = [2, 3, 6]$$$ is a not good array.
* $$$a = [2, 6, 5]$$$ is good because $$$\mathrm{pos}(a\_1) = 2$$$, $$$\mathrm{pos}(a\_2) = 5$$$, so the condition $$$\mathrm{pos}(a\_2) \le \mathrm{pos}(a\_1) + d$$$ is not satisfied.
* $$$a = [1, 6, 3]$$$ is good because $$$\mathrm{pos}(a\_2) = 5$$$, $$$\mathrm{pos}(a\_3) = 4$$$, so the condition $$$\mathrm{pos}(a\_2) < \mathrm{pos}(a\_3)$$$ is not satisfied.

In one move, you can swap two adjacent elements of the permutation $$$p$$$. What is the minimum number of moves needed such that the array $$$a$$$ becomes good? It can be shown that there always exists a sequence of moves so that the array $$$a$$$ becomes good.

A permutation is an array consisting of $$$n$$$ distinct integers from $$$1$$$ to $$$n$$$ in arbitrary order. For example, $$$[2,3,1,5,4]$$$ is a permutation, but $$$[1,2,2]$$$ is not a permutation ($$$2$$$ appears twice in the array) and $$$[1,3,4]$$$ is also not a permutation ($$$n=3$$$, but there is $$$4$$$ in the array).

InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows.

The first line of each test case contains three integers $$$n$$$, $$$m$$$ and $$$d$$$ ($$$2\leq n \leq 10^5$$$, $$$2\leq m\leq n$$$, $$$1 \le d \le n$$$), the length of the permutation $$$p$$$, the length of the array $$$a$$$ and the value of $$$d$$$. 

The second line contains $$$n$$$ integers $$$p\_1, p\_2, \ldots, p\_n$$$ ($$$1\leq p\_i \leq n$$$, $$$p\_i \ne p\_j$$$ for $$$i \ne j$$$). 

The third line contains $$$m$$$ distinct integers $$$a\_1, a\_2, \ldots, a\_m$$$ ($$$1\leq a\_i \leq n$$$, $$$a\_i \ne a\_j$$$ for $$$i \ne j$$$).

The sum of $$$n$$$ over all test cases doesn't exceed $$$5 \cdot 10^5$$$.

OutputFor each test case, print the minimum number of moves needed such that the array $$$a$$$ becomes good.

ExampleInputCopy
```
54 2 21 2 3 41 35 2 45 4 3 2 15 25 3 33 4 1 5 23 1 22 2 11 22 16 2 41 2 3 4 5 62 5
```
OutputCopy
```
1
3
2
0
2

```
NoteIn the first case, one way is to swap $$$p\_3$$$ and $$$p\_4$$$. After that, the array $$$a$$$ will be good because the condition $$$\mathrm{pos}(a\_2) \le \mathrm{pos}(a\_1) + d$$$ won't be satisfied.

In the second case, the $$$3$$$ moves could be: 

1. Swap $$$p\_3$$$ and $$$p\_4$$$.
2. Swap $$$p\_2$$$ and $$$p\_3$$$.
3. Swap $$$p\_1$$$ and $$$p\_2$$$.

 After these moves, the permutation $$$p$$$ will be $$$[2,5,4,3,1]$$$. The array $$$a$$$ will be good because the condition $$$\mathrm{pos}(a\_1) < \mathrm{pos}(a\_2)$$$ won't be satisfied. It can be shown that you can't make the array $$$a$$$ good with fewer moves.In the third case, the $$$2$$$ moves can be: 

1. Swap $$$p\_4$$$ and $$$p\_5$$$.
2. Swap $$$p\_3$$$ and $$$p\_4$$$.

 After these moves, the permutation $$$p$$$ will be $$$[3,4,2,1,5]$$$. The array $$$a$$$ will be good because the condition $$$\mathrm{pos}(a\_2) < \mathrm{pos}(a\_3)$$$ won't be satisfied. It can be shown that you can't make the array $$$a$$$ good with fewer moves.In the fourth case, the array $$$a$$$ is already good.

