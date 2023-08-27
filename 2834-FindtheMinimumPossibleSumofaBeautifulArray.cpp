class Solution {
public:
long long minimumPossibleSum(int n, int target) {

    std::unordered_set<int> used_nums;
    int current = 1;
    long long sum = 0;

    while(n > 0){

        if(used_nums.find(target - current) == used_nums.end()){
            used_nums.insert(current);
            n--;
            sum += current;
        }

        current++;
    }

    return sum;
}
};
