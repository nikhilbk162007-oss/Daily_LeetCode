class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivIdx = -1;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivIdx = i;
                break;
            }
        }

        if(pivIdx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>pivIdx;i--){
            if(nums[pivIdx]<nums[i]){
                swap(nums[i],nums[pivIdx]);
                break;
            }
        }

        int i = pivIdx + 1;
        int j = n-1;

        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};