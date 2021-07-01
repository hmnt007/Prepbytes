// https://leetcode.com/problems/subsets/

/**
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
**/

// code
// TC O(2^n)*O(n) worst case
// SC O(2^n)*O(k)
// AUx. Space O(N)

class Solution {
public:
    vector<vector<int> > ans;
    void helper(vector<int> &nums, int index, vector<int> temp){
        ans.push_back(temp);
        for(int i=index; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(nums, i+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<int> temp;
        helper(nums, index, temp);
        return ans;
    }
};
