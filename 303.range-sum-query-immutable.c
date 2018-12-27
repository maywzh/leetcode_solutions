/*
 * @lc app=leetcode id=303 lang=c
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (35.54%)
 * Total Accepted:    119.4K
 * Total Submissions: 336K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
typedef struct
{
    int *arr;
    int Size;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
    NumArray *na = (NumArray *)malloc(sizeof(NumArray));
    na->arr = (int *)malloc(sizeof(int) * numsSize);
    na->Size = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        na->arr[i] = nums[i];
    }
    return na;
}

int numArraySumRange(NumArray *obj, int i, int j)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
    {
        sum += obj->arr[k];
    }
    return sum;
}

void numArrayFree(NumArray *obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
