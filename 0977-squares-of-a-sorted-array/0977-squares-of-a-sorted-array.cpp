class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int front = 0;
        int tail = nums.size()-1;
        int n = nums.size();
        int insert_index=n-1;
        vector<int> result(n);
        while(front<=tail){
            if(nums[front]*nums[front] >= nums[tail]*nums[tail]){
                result[insert_index] = nums[front]*nums[front];
                front++;
            }
            else{    
                result[insert_index] = nums[tail]*nums[tail];
                tail--;
            }
            insert_index--;
        }
        return result;
    }
};