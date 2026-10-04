class Solution {
public:
    int maxElement(vector<int>& piles){
        int n = piles.size();
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }

    long long totalH(vector<int>& piles, int hourly){
        int n = piles.size();
        long long TotalH = 0;

        for(int i=0;i<n;i++){
            TotalH += ((long long)piles[i] + (hourly-1))/(hourly);
        }

        return TotalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = maxElement(piles);

        while(st<=end){
            int mid = st +(end-st)/2;
            long long TotalH = totalH(piles,mid);

            if(TotalH <= h){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
};