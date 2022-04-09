class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 1;
        
        for(int i = 0; i<digits.size(); i++){
            int temp = (carry+digits[i])/10;
            digits[i] = (carry+digits[i])%10;
            carry = temp;
        }
        
        if(carry>0){
            digits.push_back(1);
        }
        reverse(digits.begin(),digits.end());
        
        return digits;
    }
};