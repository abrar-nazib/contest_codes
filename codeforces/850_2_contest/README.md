# A1. Non-alternating Deck (easy version) 
 
 link: https://codeforces.com/contest/1786/problem/A1 
 
 A1. Non-alternating Deck (easy version)time limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputThis is an easy version of the problem. In this version, all cards have the same color.

Alice has $$$n$$$ cards, each card is white, and the cards are stacked in a deck. Alice deals the cards to herself and to Bob, dealing at once several cards from the top of the deck in the following order: one card to herself, two cards to Bob, three cards to Bob, four cards to herself, five cards to herself, six cards to Bob, seven cards to Bob, eight cards to herself, and so on. In other words, on the $$$i$$$-th step, Alice deals $$$i$$$ top cards from the deck to one of the players; on the first step, she deals the cards to herself and then alternates the players every two steps. When there aren't enough cards at some step, Alice deals all the remaining cards to the current player, and the process stops.

 ![](https://espresso.codeforces.com/90f25561152d91bc7b0626576a28084466511e83.png) First Alice's steps in a deck of many cards. How many cards will Alice and Bob have at the end?

InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 200$$$). The description of the test cases follows

The only line of each test case contains a single integer $$$n$$$ ($$$1 \le n \le 10^6$$$) — the number of cards.

OutputFor each test case print two integers — the number of cards in the end for each player — in this order: cards Alice has, cards Bob has.

ExampleInputCopy
```
51061781000000
```
OutputCopy
```
5 5
1 5
10 7
3 5
500202 499798

```
