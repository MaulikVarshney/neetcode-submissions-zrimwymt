class Solution {
public:
    int maxArea(vector<int>& h) {
        int i=0,j=h.size()-1;
        // int lMax = h[i];
        // int rMax = h[j];
        int ans = 0;
        while(i<j){
            ans = max(ans,(j-i) * (min(h[i],h[j])));
            if(h[i] <= h[j]){
                i++;
                // lMax = max(lMax, h[i]);
            } else {
                j--;
                // rMax = max(rMax,h[j]);
            }
        }
        return ans;
    }
};
