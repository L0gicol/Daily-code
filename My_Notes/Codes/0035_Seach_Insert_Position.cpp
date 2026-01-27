#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            mid = (right + left) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
        }
        return left;
    }
};