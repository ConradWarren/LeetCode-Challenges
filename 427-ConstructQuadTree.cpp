/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
};
*/

class Solution {
public:
Node* Tree_Builder(std::vector<std::vector<int>>& grid, int left_edge, int right_edge, int top_edge, int bottom_edge){

	if (left_edge > right_edge || top_edge > bottom_edge) {
		return nullptr;
	}

	Node* root = new Node();

	bool valid_flag = true;

	for (int i = top_edge; i <= bottom_edge; i++) {
		for (int j = left_edge; j <= right_edge; j++) {
			if (grid[i][j] != grid[top_edge][left_edge]) {
				valid_flag = false;
				break;
			}
		}
	}

	root->isLeaf = valid_flag;
	root->val = (grid[top_edge][left_edge] == 1);

	if (valid_flag) {
		return root;
	}
	
	root->topLeft = Tree_Builder(grid, left_edge, (right_edge - left_edge) / 2 + left_edge, top_edge, (bottom_edge - top_edge) / 2 + top_edge);
	root->topRight = Tree_Builder(grid, (right_edge - left_edge)/2 + left_edge+1, right_edge, top_edge, (bottom_edge - top_edge) / 2 + top_edge);
	root->bottomLeft = Tree_Builder(grid, left_edge, (right_edge - left_edge) / 2 + left_edge, (bottom_edge - top_edge) / 2 + top_edge+1 , bottom_edge);
	root->bottomRight = Tree_Builder(grid, (right_edge - left_edge)/2 + left_edge+1,right_edge, (bottom_edge - top_edge) / 2 + top_edge + 1, bottom_edge);

	return root;
}


Node* construct(std::vector<std::vector<int>>& grid) {

	return Tree_Builder(grid, 0, grid[0].size()-1, 0, grid.size()-1);
}
};
