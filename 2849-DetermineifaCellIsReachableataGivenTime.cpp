class Solution {
public:
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

	int distance_x = std::abs(sx - fx);
	int distance_y = std::abs(sy - fy);

	int total_distance = ((distance_y < distance_x) ? distance_y + (distance_x - distance_y) : distance_x + (distance_y - distance_x));

	if (total_distance == 0 && t == 1) {
	    return false;
    }

	return (total_distance <= t);
}
};
