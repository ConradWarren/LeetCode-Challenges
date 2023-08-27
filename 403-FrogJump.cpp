#include <vector>
#include <unordered_map>

class Solution {
public:
bool Solve(std::unordered_map<int, bool>& stones, int last_jump,int idx, std::unordered_map<int, std::unordered_map<int, bool>>& cache){

    
    if(stones.find(idx) == stones.end()){
        return false;
    }

    if(stones[idx]){
        return true;
    }

    if(cache[idx].find(last_jump) != cache[idx].end()){
        return cache[idx][last_jump];
    }

    bool jump_same = Solve(stones, last_jump, idx+last_jump, cache);

    bool jump_more = Solve(stones, last_jump+1, idx+last_jump+1, cache);

    bool jump_less = (last_jump > 1) ? Solve(stones, last_jump-1, idx + last_jump -1, cache) : false;

    cache[idx][last_jump] = (jump_less || jump_more || jump_same);

    return (jump_less || jump_more || jump_same);
}

bool canCross(std::vector<int>& stones) {

    std::unordered_map<int, bool> stone_map;
    std::unordered_map<int, std::unordered_map<int, bool>> cache;
    for(int i = 0; i<stones.size(); i++){
        stone_map[stones[i]] = false;
    }
    stone_map[stones.back()] = true;

    return Solve(stone_map, 1, 1, cache);
}
};
