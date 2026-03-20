class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while(left <= right){
            int mid = left + (right - left) / 2;
            long long ops = 0;

            for(int x : nums){
                ops += (x - 1) / mid;
            }

            if(ops <= maxOperations){
                ans = mid;
                right = mid - 1;
            } 
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
};