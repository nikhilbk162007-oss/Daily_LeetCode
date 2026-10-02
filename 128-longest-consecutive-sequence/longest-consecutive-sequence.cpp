class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;

        unordered_set<int>set;

        for(int i=0;i<n;i++){
            set.insert(nums[i]);
        }

        for(auto it:set){
            if(set.find(it-1)==set.end()){
                int x = it;
                int cnt = 1;

                while(set.find(x+1)!=set.end()){
                    x = x+1;
                    cnt++;
                }

                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};