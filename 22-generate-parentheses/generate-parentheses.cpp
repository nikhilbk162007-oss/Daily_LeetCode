class Solution {
public:
    bool isValid(string s){
        int cnt = 0;

        for(char c : s){
            if(c == '('){
                cnt++;
            } else {
                cnt--;
            }

            if(cnt < 0){
                return false;
            }
        }
        return cnt == 0;
    }

    void allPara(string curr , vector<string>& allP , int n){
        if(curr.length() == 2*n){
            if(isValid(curr)){
                allP.push_back(curr);
            }
            return;
        }

        allPara(curr + '(',allP,n);
        allPara(curr + ')',allP,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> allP;
        allPara("",allP,n);
        return allP;
    }
};