#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};
        int left = searchleft(nums, target);
        int right = searchright(nums, target);
        return {left, right};
    }

private:
    int searchleft(vector<int> &nums, int target)
    {
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        int candidate = -1;
        while (left <= right )
        {
            mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                right = mid - 1;
                candidate = mid;
            }
            else if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
        }
        return candidate;
    }
    int searchright(vector<int> &nums, int target)
    {
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        int candidate = -1;
        while (left <= right )
        {
            mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                left = mid + 1;
                candidate = mid;
            }
            else if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
        }
        return candidate;
    }
};
