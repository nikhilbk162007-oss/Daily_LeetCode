class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLength = strs[0].length();

        for(string& str:strs){
            minLength = min(minLength,(int)str.length());
        }

        string res = "";

        for(int i=0;i<minLength;i++){
            char ch = strs[0][i];

            for(string& str:strs){
                if(str[i]!=ch){
                    return res;
                }
            }

            res.push_back(ch);
        }

        return res;
    }
};