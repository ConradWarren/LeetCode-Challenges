class Solution {
public:

int Union_Find(int x, std::vector<int>& groups) {

	if (groups[x] != x) groups[x] = Union_Find(groups[x], groups);
	
	return groups[x];
}

void Union(int a, int b, std::vector<int>& groups, std::vector<int>& rank) {

	int a_group = Union_Find(a, groups);
	int b_group = Union_Find(b, groups);

	if (a_group != b_group) {

		if (rank[a_group] > rank[b_group]) {
			groups[b_group] = a_group;
		}
		else {
			groups[a_group] = b_group;
			if (rank[a_group] == rank[b_group]) {
				rank[b_group]++;
			}
		}
	}
}

bool equationsPossible(std::vector<std::string>& equations) {

	std::vector<int> groups(26);
	std::vector<int> ranks(26, 1);

	for (int i = 0; i < groups.size(); i++) {
		groups[i] = i;
	}

	for (int i = 0; i < equations.size(); i++) {
		if (equations[i][1] == '=') Union(int(equations[i][0]) - int('a'), int(equations[i][3]) - int('a'), groups, ranks);
	}

	for (int i = 0; i < equations.size(); i++) {
		if (equations[i][1] == '!' && Union_Find(int(equations[i][0]) - int('a'), groups) == Union_Find(int(equations[i][3]) - int('a'), groups)) {
			return false;
		}
	}

	return true;
}
};
