class Solution {
public:
    bool isPalindrome(string s) {
        int m = s.size()-1;
        string temp = "";
        for(int k=0;k<=m;k++){
            if(s[k] == ' ' || !isalnum(s[k])){
                continue;
            } else{
                temp+=tolower(s[k]);
            }
        }
        int i=0, j=temp.size()-1;
        while(i<j){
            if(temp[i]==temp[j]){
                i++;j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
