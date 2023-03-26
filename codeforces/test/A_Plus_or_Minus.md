# A. Plus or Minus 
 
 link: https://codeforces.com/contest/1807/problem/A 
 
 A. Plus or Minustime limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputYou are given three integers $$$a$$$, $$$b$$$, and $$$c$$$ such that exactly one of these two equations is true: 

* $$$a+b=c$$$
* $$$a-b=c$$$

 Output + if the first equation is true, and - otherwise.InputThe first line contains a single integer $$$t$$$ ($$$1 \leq t \leq 162$$$) — the number of test cases.

The description of each test case consists of three integers $$$a$$$, $$$b$$$, $$$c$$$ ($$$1 \leq a, b \leq 9$$$, $$$-8 \leq c \leq 18$$$). The additional constraint on the input: it will be generated so that exactly one of the two equations will be true.

OutputFor each test case, output either + or - on a new line, representing the correct equation.

ExampleInputCopy
```
111 2 33 2 12 9 -73 4 71 1 21 1 03 3 69 9 189 9 01 9 -81 9 10
```
OutputCopy
```
+
-
-
+
+
-
+
+
-
-
+

```
NoteIn the first test case, $$$1+2=3$$$.

In the second test case, $$$3-2=1$$$.

In the third test case, $$$2-9=-7$$$. Note that $$$c$$$ can be negative.

