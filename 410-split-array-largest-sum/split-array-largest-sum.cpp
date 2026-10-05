class Solution {
public:
    int noSub(vector<int>& nums, long long k){
        int n = nums.size();
        long long subArrSum = 0;
        int noSub = 0;

        for(int i=0;i<n;i++){
            if(subArrSum + nums[i] <= k){
                subArrSum += nums[i];
            }
            else{
                noSub++;
                subArrSum = nums[i];
            }
        }
        return noSub;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return -1;

        int maxi = INT_MIN;
        long long sum = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            maxi = max(maxi,nums[i]);
        }

        long long low = maxi , high = sum;

        while(low<=high){
            long long mid = low + (high-low)/2;
            int noSubarray = noSub(nums,mid);


            if(noSubarray >= k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    return low;
    }
};