class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int mx = height[n-1],ans = 0;
//         vector<int>right(n);
//         right[n-1] = height[n-1];
        
//         for(int i=n-2;i>=0;i--){
//             mx = max(mx,height[i]);
//             right[i] = mx;
//         }
        
//         mx = height[0];
//         for(int i=1;i<n;i++){
//            mx = max(mx,height[i]);
//            ans += (min(mx,right[i])-height[i]);
//         }
        int i=0,j=n-1;
        while(i<j){
           // cout<<height[i]<<" "<<height[j]<<endl;
            ans = max(ans,(min(height[i],height[j])*(j-i)));
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};