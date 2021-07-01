// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3799/

/**
Gray Code

Solution
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

 

Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
Example 2:

Input: n = 1
Output: [0,1]
 

Constraints:

1 <= n <= 16

**/

// code

class Solution {
public:
    
    vector<string> produceGrayCode(int n) {
        //base case
        if(n==1){
            return {"0", "1"};
        }
        //recursion
        vector<string> rres = produceGrayCode(n-1);
        vector<string> mres;
        for(int i=0; i<rres.size(); i++){
            mres.push_back('0'+rres[i]);
        }
        for(int i=rres.size()-1; i>=0; i--) {
            mres.push_back('1'+rres[i]);
        }
        return mres;
    }
    vector<int> grayCode(int n) {
        vector<string> temp = produceGrayCode(n);
        vector<int> ans;
        for(auto str:temp){
            int i=0;
            int val = 0;
            while(i<str.size()){
                if(str[i] == '1') val = (val*2)+1;
                else val *=2;
                i++;
            }
            ans.push_back(val);
        }
        return ans;
    }
};


// Optimized code
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i=0; i< (1<<n); i++){
            int x = i ^ (i/2);
            ans.push_back(x);
        }
        return ans;
    }
};
