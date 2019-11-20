// https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/discuss/431144/cpp-BFS-%2B-DFS-solution
class Solution {
public:
    int m, n;
	vector<vector<int>> dict;
	vector<vector<int>> walk;
	vector<vector<int>> dir{ { 0, -1 },{ 0, 1 },{ 1, 0 },{ -1, 0 } };

	bool isVaild(vector<vector<char>>& grid, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n) return false;
		return grid[i][j] != '#';
	}

	bool dfs(vector<vector<char>>& grid, int x, int y, int i, int j) {
		if (!isVaild(grid, x, y)) return false;
		if (walk[x][y] == 1 || grid[x][y] == '#') return false;
		walk[x][y] = 1;
		if (x == i && y == j) return true;
		for (auto& d : dir) {
			if (dfs(grid, x + d[0], y + d[1], i, j))
				return true;
		}
		return false;
	}
	bool canWalk(vector<vector<char>>& grid, int x, int y, int i, int j) {
		//see if man can walk from(x, y) to (i, j)
		if (!isVaild(grid, x, y) || !isVaild(grid, i, j)) return false;
		int start = x * n + y, end = i * n + j;
		if (dict[start][end] != -1) return dict[start][end];
		bool ans= dfs(grid, x, y, i, j);
		walk = vector<vector<int>>(m, vector<int>(n, 0));
		return (dict[start][end] = ans);
	}

	int minPushBox(vector<vector<char>>& grid) {
		if (grid.empty()) return 0;
		m = grid.size(), n = grid[0].size();
		dict = vector<vector<int>>(m * n, vector<int>(m* n, -1));
		for (int i = 0; i < m * n; ++i)
			dict[i][i] = 1;
		int start = -1, goal = -1, person = -1;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 'B') {
					start = i * n + j;
				}
				else if (grid[i][j] == 'T') {
					goal = i * n + j;
				}
				else if (grid[i][j] == 'S') {
					person = i * n + j;
				}
			}
		}
		set<pair<int,int>> visit;
		walk = vector<vector<int>>(m, vector<int>(n, 0));
		//people - box
		queue<pair<int, int>> q;
		visit.insert({ person, start });
		q.push({ person, start });
		int ans = 0;
		while (!q.empty()) {
			ans += 1;
			int l = q.size();
			for (int i = 0; i < l; ++i) {
				auto f = q.front();
				q.pop();
				//box position
				int cur = f.second;
				int x = cur / n, y = cur%n;
				//person position
				int p = f.first;
				//make the box an obstacle
				grid[x][y] = '#';
				for (auto& d : dir) {
					int bx = x + d[0], by = y + d[1];
					int px = x - d[0], py = y - d[1]; // new_box_pos, box_origin_pos, person_pos
					if (isVaild(grid, bx, by) && canWalk(grid, p / n, p %n, x - d[0], y - d[1]) && visit.count({px * n + py, bx * n + by}) == 0) {
						if (bx == goal / n && by == goal% n) return ans;
						visit.insert({ px * n + py, bx * n + by });
						q.push({ px * n + py, bx * n + by });
					}
				}
				grid[x][y] = '.';
			}
		}
		return -1;
	}
};
