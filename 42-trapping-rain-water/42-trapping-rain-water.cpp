class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
//         vector<int>right(n);
        
//         int mx = height[n-1],ans = 0;
        
//         for(int i=n-1; i>=0; i--){
//             mx = max(mx,height[i]);
//             right[i] = mx;
//         }
        
//         mx = height[0];
        
//         for(int i=0; i<n; i++){
//             mx = max(mx,height[i]);
//             ans += (min(mx,right[i]) - height[i]);
//         }
//         return ans;
        int lmax = 0,rmax = 0,res = 0,left = 0,right = n-1;
        
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=lmax){
                    lmax = height[left];
                }else{
                    res += lmax-height[left];
                }
                left++;
            }else{
                if(height[right]>=rmax){
                    rmax = height[right];
                }else{
                    res += rmax-height[right];
                }
                right--;
            }
        }
        return res;
    }
};