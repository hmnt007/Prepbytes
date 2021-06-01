// https://www.interviewbit.com/problems/count-total-set-bits/

/**

Count Total Set Bits
Asked in:  
Amazon
Problem Description

Given a positive integer A, the task is to count the total number of set bits in the binary representation of all the numbers from 1 to A.

Return the count modulo 109 + 7.



Problem Constraints
1 <= A <= 109



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the ( Total number of set bits in the binary representation of all the numbers from 1 to A )modulo 109 + 7.



Example Input
Input 1:

 A = 3
Input 2:

 A = 1


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 DECIMAL    BINARY  SET BIT COUNT
    1          01        1
    2          10        1
    3          11        2
 1 + 1 + 2 = 4 
 Answer = 4 % 1000000007 = 4
Explanation 2:

 A = 1
  DECIMAL    BINARY  SET BIT COUNT
    1          01        1
 Answer = 1 % 1000000007 = 1
 
 **/


// code

int Solution::solve(int A) {
    if(A==0) return 0;
    int mod = 1000000007, p =0;
    long long int count = 0;
    while(pow(2,p)<=A) p++;
    p--;
    count += (p*pow(2,p)/2)+(A-pow(2,p)+1)+solve(A-pow(2,p));
    return count%mod;
}
