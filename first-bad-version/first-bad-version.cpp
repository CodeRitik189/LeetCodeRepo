// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int check(int st, int ed){
        if(st<=ed){
            int mid = st+(ed-st)/2;
            if(isBadVersion(mid)){
                return min(mid,check(st,mid-1));
            }else{
                return check(mid+1,ed);
            }
        }
        return INT_MAX;;
    }
    int firstBadVersion(int n) {
        return check(1,n);
    }
};