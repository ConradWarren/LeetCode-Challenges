class Solution {
public:
int Depth_First_Search(std::vector<std::vector<int>>& nodes, int last_edge, int idx, std::vector<int>& cache){

    if(idx >= nodes.size()){
        return 0;
    }

    if(last_edge >= nodes[idx][0]){
        return Depth_First_Search(nodes, last_edge, idx+1, cache);
    }

    if(cache[idx] != -1){
        return cache[idx];
    }

    int skip = Depth_First_Search(nodes, last_edge, idx+1, cache);

    int take = 1 + Depth_First_Search(nodes, nodes[idx][1], idx+1, cache);

    cache[idx] = (skip > take) ? skip : take;

    return cache[idx];
}

int findLongestChain(std::vector<std::vector<int>>& pairs) {

    std::vector<int> cache(pairs.size(), -1);
    std::sort(pairs.begin(), pairs.end());
    return Depth_First_Search(pairs, INT_MIN, 0, cache);
}
};
