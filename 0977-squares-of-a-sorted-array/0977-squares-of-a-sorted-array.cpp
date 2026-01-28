class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int front = 0;
        int tail = nums.size()-1;
        vector <int> result;
        while(front<=tail){
            if(nums[front]*nums[front] >= nums[tail]*nums[tail]){
                result.insert(result.begin(),nums[front]*nums[front]);
                front++;
            }
            else{    
                result.insert(result.begin(),nums[tail]*nums[tail]);
                tail--;
            }
        }
        return result;

    }
};