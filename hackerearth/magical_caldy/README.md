# Monk and the Magical Candy Bags 
 
 link: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4 
 
 ProblemOur Monk loves candy!  

 While taking a stroll in the park, he stumbled upon **N** Bags with candies. The **i**'th of these bags contains **Ai** candies.  

He picks up a bag, eats all the candies in it and drops it on the ground. But as soon as he drops the bag, the number of candies in the bag increases magically! Say the bag that used to contain **X** candies (before eating), now contains [**X**/2] candies! ,where [x] is the greatest integer less than x ([Greatest Integer Function](http://www.mathnstuff.com/math/spoken/here/1words/g/g6.htm)).  

Amazed by the magical spell, Monk can now have a lot more candies! But he has to return home in **K** minutes. In a **single** minute,Monk can consume all the candies in a **single** bag, regardless of the number of candies in it.  

Find the **maximum** number of candies that Monk can consume. 


**Input**:  

First line contains an integer **T**. **T** test cases follow.  

First line of each test case contains two space-separated integers **N** and **K**.  

Second line of each test case contains **N** space-separated integers,the number of candies in the bags. 


**Output**:  

Print the answer to each test case in a new line. 


**Constraints**:  

1 ≤ **T** ≤ 10  

1 ≤ **N** ≤ 105  

0 ≤ **K** ≤ 105  

0 ≤ **Ai** ≤ 1010

Sample Input
```
1
5 3
2 1 7 4 2
```
Sample Output
```
14

```
Time Limit: 2Memory Limit: 256Source Limit: ExplanationThe state of bags is:  

2 1 7 4 2  

Monk eats all candies from Third bag (7). The state of bags becomes:  

2 1 3 4 2   

Monk eats all candies from Fourth bag (4). The state of bags becomes:  

2 1 3 2 2  

Monk eats all candies from Third bag (3). The state of bags becomes:  

2 1 1 2 2   

Hence, the Monk eats 7+4+3= 14

Contributers: [![avatar](https://he-s3.s3.amazonaws.com/media/avatars/pulkit_180894/resized/30/a7e43351899990_10152231326374674_388541599_n_overlay.jpg)Pulkit Mendiratta](/@pulkit_180894)[![avtar](https://he-s3.s3.amazonaws.com/media/avatars/deepankarak/resized/30/61329581329079262844.png)Deepankar Anil](/@deepankarak)