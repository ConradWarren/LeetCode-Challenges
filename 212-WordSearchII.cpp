#include <vector>
#include <unordered_set>
#include <string>

class Trie_Node {

public:

	std::unordered_map<char, Trie_Node*> character_map;
	int end_word_flag;
	
	Trie_Node() {
		end_word_flag = -1;
	}
};


class Solution {
public:
void Depth_First_Search(std::vector<std::vector<char>>& grid, int y_pos, int x_pos, Trie_Node* current, std::unordered_set<int>& result, std::vector<std::vector<bool>>& visted){

	if (y_pos < 0 || x_pos < 0 || y_pos >= grid.size() || x_pos >= grid[0].size()) {
		return;
	}

	if (current->character_map.find(grid[y_pos][x_pos]) == current->character_map.end()) {
		return;
	}

	if (visted[y_pos][x_pos]) {
		return;
	}

	visted[y_pos][x_pos] = true;

	current = current->character_map[grid[y_pos][x_pos]];

	if (current->end_word_flag != -1) {
		result.insert(current->end_word_flag);
	}

	Depth_First_Search(grid, y_pos+1, x_pos, current, result, visted);
	Depth_First_Search(grid, y_pos, x_pos+1, current, result, visted);
	Depth_First_Search(grid, y_pos-1, x_pos, current, result, visted);
	Depth_First_Search(grid, y_pos, x_pos-1, current, result, visted);

	visted[y_pos][x_pos] = false;
}

std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {

	Trie_Node* start_point = new Trie_Node();
	Trie_Node* current = start_point;
	std::unordered_set<int> valid_indexs;
	std::vector<std::string> result;
	std::vector<std::vector<bool>> visted(board.size(), std::vector<bool>(board[0].size(), false));

	for (int i = 0; i < words.size(); i++) {

		current = start_point;

		for (int j = 0; j < words[i].length(); j++) {

			if (current->character_map.find(words[i][j]) == current->character_map.end()) {
				current->character_map[words[i][j]] = new Trie_Node();
			}

			current = current->character_map[words[i][j]];
			if (j == words[i].length() - 1) {
				current->end_word_flag = i;
			}
		}
	}

	for (int i = 0; i < board.size(); i++) {

		for (int j = 0; j < board[0].size(); j++) {
			Depth_First_Search(board, i, j, start_point, valid_indexs, visted);
		}
	}

	for (int i = 0; i < words.size(); i++) {
		if (valid_indexs.find(i) != valid_indexs.end()) {
			result.push_back(words[i]);
		}
	}

	return result;
}
};
