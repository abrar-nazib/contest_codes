# B. Cake Assembly Line 
 
 link: https://codeforces.com/contest/1786/problem/B 
 
 B. Cake Assembly Linetime limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputA cake assembly line in a bakery was once again optimized, and now $$$n$$$ cakes are made at a time! In the last step, each of the $$$n$$$ cakes should be covered with chocolate.

Consider a side view on the conveyor belt, let it be a number line. The $$$i$$$-th cake occupies the segment $$$[a\_i - w, a\_i + w]$$$ on this line, each pair of these segments does not have common points. Above the conveyor, there are $$$n$$$ dispensers, and when a common button is pressed, chocolate from the $$$i$$$-th dispenser will cover the conveyor segment $$$[b\_i - h, b\_i + h]$$$. Each pair of these segments also does not have common points.

 ![](https://espresso.codeforces.com/bbc5be06b971ad6c5590957ed64e3361e773538e.png) Cakes and dispensers corresponding to the first example. The calibration of this conveyor belt part has not yet been performed, so you are to make it. Determine if it's possible to shift the conveyor so that each cake has some chocolate on it, and there is no chocolate outside the cakes. You can assume that the conveyour is long enough, so the cakes never fall. Also note that the button can only be pressed once.

 ![](https://espresso.codeforces.com/18b5a8624cd16d489df222065cebd2d2f17a9708.png) In the first example we can shift the cakes as shown in the picture. InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^5$$$). The description of the test cases follows.

The first line of each test case contains three integers $$$n$$$, $$$w$$$, and $$$h$$$ ($$$1 \le n \le 10^5$$$; $$$1 \le w, h \le 10^5$$$; $$$h \le w$$$) — the number of cakes and dispensers, as well as the halfwidths of cakes and segments on which the chocolate is dispensed.

The second line contains $$$n$$$ integers $$$a\_1$$$, $$$a\_2$$$, ..., $$$a\_n$$$ ($$$1 \le a\_i \le 10^9$$$) — the positions of the cakes centers. It is guaranteed that $$$a\_i + w < a\_{i + 1} - w$$$ for all $$$i$$$.

The third line contains $$$n$$$ integers $$$b\_1$$$, $$$b\_2$$$, ..., $$$b\_n$$$ ($$$1 \le b\_i \le 10^9$$$) — the positions of the dispensers. It is guaranteed that $$$b\_i + h < b\_{i + 1} - h$$$ for all $$$i$$$.

It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$10^5$$$.

OutputFor each test case output "YES", if it's possible to shift the conveyor in such a way that each cake ends up with some chocolate, and no chocolate is outside the cakes, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

ExampleInputCopy
```
43 10 565 95 16540 65 1455 2 11 6 11 16 214 9 14 19 243 3 213 22 295 16 254 4 127 36 127 13635 50 141 144
```
OutputCopy
```
YES
YES
NO
YES

```
NoteThe first example is shown in the figures in the statement.

In the second example, we can move the conveyor, for example, so that the centers of the cakes are at $$$4, 9, 14, 19, 24$$$.

In the third example, we can't move the conveyor accordingly.

