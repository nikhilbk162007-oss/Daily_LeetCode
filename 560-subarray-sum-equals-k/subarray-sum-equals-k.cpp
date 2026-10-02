class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        int sum = 0;
        mpp[0] = 1;
        int cnt = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            int remove = sum - k;
            cnt += mpp[remove];
            mpp[sum] += 1;
        }
        return cnt;
    }
};