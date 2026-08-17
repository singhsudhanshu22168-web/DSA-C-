class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int count = 0;
        for (int num : nums){
            int digit = 0;
            while (num > 0){
                num = num/10;
                digit++;
            }
            if (digit%2==0){
                count++;
            }
        
        }
        return count;
    }
};