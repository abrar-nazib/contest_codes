# A. Lame King 
 
 link: https://codeforces.com/contest/1804/problem/A 
 
 A. Lame Kingtime limit per test1 secondmemory limit per test512 megabytesinputstandard inputoutputstandard outputYou are given a checkerboard of size 201×201201 \times 201, i. e. it has 201201 rows and 201201 columns. The rows of this checkerboard are numbered from −100-100 to 100100 from bottom to top. The columns of this checkerboard are numbered from −100-100 to 100100 from left to right. The notation (r,c)(r, c) denotes the cell located in the rr-th row and the cc-th column.

There is a king piece at position (0,0)(0, 0) and it wants to get to position (a,b)(a, b) as soon as possible. In this problem our king is lame. Each second, the king makes exactly one of the following five moves. 

* Skip move. King's position remains unchanged.
* Go up. If the current position of the king is (r,c)(r, c) he goes to position (r+1,c)(r + 1, c).
* Go down. Position changes from (r,c)(r, c) to (r−1,c)(r - 1, c).
* Go right. Position changes from (r,c)(r, c) to (r,c+1)(r, c + 1).
* Go left. Position changes from (r,c)(r, c) to (r,c−1)(r, c - 1).

 King is not allowed to make moves that put him outside of the board. The important consequence of the king being lame is that he is not allowed to make the same move during two consecutive seconds. For example, if the king goes right, the next second he can only skip, go up, down, or left.What is the minimum number of seconds the lame king needs to reach position (a,b)(a, b)?

InputThe first line of the input contains a single integer tt (1≤t≤1041 \leq t \leq 10^4) — the number of test cases. Then follow tt lines containing one test case description each.

Each test case consists of two integers aa and bb (−100≤a,b≤100-100 \leq a, b \leq 100) — the position of the cell that the king wants to reach. It is guaranteed that either a≠0a \ne 0 or b≠0b \ne 0.

OutputPrint tt integers. The ii-th of these integers should be equal to the minimum number of seconds the lame king needs to get to the position he wants to reach in the ii-th test case. The king always starts at position (0,0)(0, 0).

ExampleInputCopy
```
5-4 14 40 -6-5 -47 -8
```
OutputCopy
```
7
8
11
9
15

```
NoteOne of the possible solutions for the first example is: go down, go right, go down, go right, go down, go left, go down.

One of the possible solutions for the second example is to alternate "go right" and "go up" moves 44 times each.

One of the possible solutions for the third example is to alternate "go left" and "skip" moves starting with "go left". Thus, "go left" will be used 66 times, and "skip" will be used 55 times.

