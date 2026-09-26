class Solution {
public:
    int bs(string a){
    vector<int> ab(26,0);
    int mf = 0;
    int lf = INT_MAX;

    for(int i=0;i<a.size();i++){
        ab[a[i]-'a']++;
    }
    for(int i=0;i<ab.size();i++){
        mf = max(mf,ab[i]);
        if(ab[i]>=1){
            lf=min(lf,ab[i]);
        }
    }
    return mf-lf;
    }
    
    int beautySum(string s) {
        int beauty = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(j-i+1 >= 3){
                beauty += bs(s.substr(i,j-i+1));
                }
            }
        }
        return beauty;
    }
};