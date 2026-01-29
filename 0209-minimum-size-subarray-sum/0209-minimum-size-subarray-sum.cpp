class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int tail = -1;
        int front = 0;
        int ans = 0;
        int window_sum=0;
        for(auto p = nums.begin();p != nums.end();p++){
            window_sum += *p;
            tail++;
            while(window_sum>=target){
                if(ans == 0){
                    ans = 10000000;
                }
                if(tail - front + 1< ans) ans = tail - front + 1;              
                window_sum -= nums[front];
                front++;              
            }
        }
        return ans;
    }
};