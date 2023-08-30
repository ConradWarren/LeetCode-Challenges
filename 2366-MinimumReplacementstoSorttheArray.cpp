class Solution {
public:
long long minimumReplacement(std::vector<int>& nums) {

    long long result = 0;
    int last_number = nums.back();
    int current_operations = 0;

    for(int i = nums.size()-2; i>=0; i--){

        if(nums[i] <= last_number){
            last_number = nums[i];
            continue;
        }

        current_operations = (nums[i]+last_number-1)/last_number;
        result += current_operations - 1;
        last_number = nums[i]/current_operations;
    }

    return result;
}
};
