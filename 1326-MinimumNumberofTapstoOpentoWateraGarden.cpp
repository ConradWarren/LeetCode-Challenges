#include <vector>
#include <queue>

class Solution {
public:
int shortest_path_in_dag(std::vector<std::vector<int>>& graph,std::vector<int>& cache, std::vector<bool>& end_points, int n, int starting_idx){

    int result = INT_MAX;
    int current_node = 0;
    int distance = 0;
    std::queue<std::pair<int, int>> nodes;

    nodes.push({starting_idx, 1});

    while(!nodes.empty()){

        current_node = nodes.front().first;
        distance = nodes.front().second +1;

        if(end_points[current_node]) result = (result < nodes.front().second) ? result : nodes.front().second;

        nodes.pop();

        for(int i = 0; i< graph[current_node].size(); i++){
            if(cache[graph[current_node][i]] > distance){
                cache[graph[current_node][i]] = distance;
                nodes.push({graph[current_node][i], distance});
            }
        }
        
    }

    return result;
}

int minTaps(int n, std::vector<int>& ranges) {

    std::vector<std::vector<int>> graph(ranges.size());
    std::vector<std::pair<int, int>> range_pairs(ranges.size());
    std::vector<bool> end_points(ranges.size(), false);
    std::vector<int> cache(ranges.size(), INT_MAX);
    int starting_idx = 0;
    int result = 0;

    for(int i = 0; i<ranges.size(); i++){
        range_pairs[i].first = (0 > i - ranges[i]) ? 0 : i - ranges[i];
        range_pairs[i].second = (n < i + ranges[i]) ? n : i + ranges[i];
    }

    std::sort(range_pairs.begin(), range_pairs.end());

    if(range_pairs.front().first != 0){
        return -1;
    }

    while(starting_idx + 1 < range_pairs.size() && range_pairs[starting_idx+1].first == 0){
        starting_idx++;
    }
    
    cache[starting_idx] = 0;

    for(int i = starting_idx; i<range_pairs.size(); i++){

        if(range_pairs[i].second == n) end_points[i] = true;

        for(int j = i+1; j<range_pairs.size(); j++){
            if(range_pairs[i].second < range_pairs[j].first){
                break;
            }
            graph[i].push_back(j);
        }
    }
    
    result = shortest_path_in_dag(graph, cache, end_points, n, starting_idx);
    
    return (result != INT_MAX) ? result : -1;
}
};
