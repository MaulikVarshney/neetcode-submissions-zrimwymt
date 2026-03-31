class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int t = 0, b = matrix.size() - 1;
        int l = 0, r = matrix[0].size() - 1;
        int dir = 0;

        while(t <= b && l <= r){

            if(dir == 0){ // left → right
                for(int i = l; i <= r; i++){
                    ans.push_back(matrix[t][i]);
                }
                t++;
            }
            else if(dir == 1){ // top → bottom
                for(int i = t; i <= b; i++){
                    ans.push_back(matrix[i][r]);
                }
                r--;
            }
            else if(dir == 2){ // right → left
                for(int i = r; i >= l; i--){
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }
            else{ // bottom → top
                for(int i = b; i >= t; i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }

            dir = (dir + 1) % 4;
        }

        return ans;
    }
};