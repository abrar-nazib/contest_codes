# Sherlock and his AMMO quest 
 
 link: https://www.hackerearth.com/problem/algorithm/stl/ 
 
 ProblemSherlock is investigating that who was responsible for the massacre at the British embassy in Tbilisi.  

**AMMO codeword** signifies something. What can be its meaning? 


Sherlock is suspecting some people , and each of them has some jealousy coefficient.  

Consider yourself to be Dr.Watson. You need to **arrange these names in decreasing order of jealousy.** 


**If two or more people have same jealousy coefficient , they must be arranged in lexicographical order.** 


**Input**  

On the first line, you are provided the value **N - the number of people** Sherlock suspects.  

N lines follow.  

Each of these N lines comprises a **string S and an integer X**, signifying **the name and the associated jealousy coefficient respectively**. 


**Output**  

Print the N lines in the order specified above. 


**Constraints**  

1<=N<=100000  

1<=X<=1000  

1<=|S|<=100 

Sample Input
```
3
Smallwood 3
Vivian 5
Norbury 5
```
Sample Output
```
Norbury 5
Vivian 5
Smallwood 3
```
Time Limit: 1Memory Limit: 256Source Limit: ExplanationSherlock has 3 prime suspects.
Smallwood has jealousy coefficient 3.
Vivian and Norbury have jealousy coefficient 5 each.
Arranging in decreasing order, Vivian and Norbury should be put first, and then Smalwood. However, lexicographically Norbury should be put above Vivian in the list.

