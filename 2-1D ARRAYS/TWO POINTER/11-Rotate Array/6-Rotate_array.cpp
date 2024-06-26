// https://leetcode.com/problems/rotate-array/ leetcode ->189
#include <iostream>
#include <vector>
using namespace std;

// First approach

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> temp(k);
        k = k % n;
        int j = 0;
        for (int i = n - k; i < n; i++)
        {
            temp[j++] = nums[i];
        }

        for (int i = n - 1; i >= k; i--)
        {
            nums[i] = nums[i - k];
        }

        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }
    }
};

// Second approach

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            int new_ = (i + k) % nums.size();

            result[new_] = nums[i];
        }

        nums = result;
    }
};

// Third approach

class Solution
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start <= end)
            swap(nums[start++], nums[end--]);
    }
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();

        k %= n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
