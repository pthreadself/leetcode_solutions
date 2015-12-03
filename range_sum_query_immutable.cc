/*
https://leetcode.com/problems/range-sum-query-immutable/

Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

*/

//by wang.ke

class NumArray {
public:
    NumArray(vector<int> &nums) : a(nums.size(), 0) {
        int size = nums.size();
        if (size >= 1)
            a[0] = nums[0];
        for (int i = 1; i < size; ++i) 
            a[i] = a[i - 1] + nums[i];
    }

    int sumRange(int i, int j) {
        if (i >= 1)
            return a[j] - a[i - 1];
        else
            return a[j];
    }
private:
    vector<int> a;
};