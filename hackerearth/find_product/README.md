# Find Product 
 
 link: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/find-product/ 
 
 ProblemYou have been given an array *A* of size *N* consisting of positive integers. You need to find and print the product of all the number in this array **Modulo** 109+710^9+7. 


**Input Format**:  

The first line contains a single integer *N* denoting the size of the array. The next line contains *N* space separated integers denoting the elements of the array


**Output Format**:  

Print a single integer denoting the product of all the elements of the array Modulo 109+710^9+7. 


**Constraints**:  

1≤N≤103 1 \le N \le 10^3   

1≤A[i]≤103 1 \le A[i] \le 10^3  

Sample Input
```
5
1 2 3 4 5
```
Sample Output
```
120
```
Time Limit: 1Memory Limit: 256Source Limit: ExplanationThere are *5* integers to multiply. Let's store the final answer in answeranswer variable. Since *1* is identity value for multiplication, initialize answeranswer as *1*.


So the process goes as follows:


answer=1answer = 1  

answer=(answer×1answer = (answer \times 1) % (109+7)(10^9+7)  

answer=(answer×2answer = (answer \times 2) % (109+7)(10^9+7)  

answer=(answer×3answer = (answer \times 3) % (109+7)(10^9+7)  

answer=(answer×4answer = (answer \times 4) % (109+7)(10^9+7)  

answer=(answer×5answer = (answer \times 5) % (109+7)(10^9+7) 


The above process will yield answer as 120120 

