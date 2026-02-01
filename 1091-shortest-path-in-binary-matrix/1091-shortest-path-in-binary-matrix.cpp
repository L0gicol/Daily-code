class Solution {
public:
	typedef struct point{
		int x;
		int y;
		int step;
		point(int a,int b,int c) : x(a),y(b),step(c){};
	};
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if(grid.empty()) return -1;
		if(grid[0][0] == 1) return -1;
		if(grid.back().back() == 1) return -1;
		int n = grid.size();
		int m = grid[0].size();
		queue<point> que;
		que.push(point(0,0,1));
		int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
		grid[0][0] = 1;
		while(!que.empty()){
			point curr = que.front();
			que.pop();
			if (curr.x == n - 1 && curr.y == m - 1) {
				return curr.step;
			}
			for(int i = 0; i < 8; i++) {
				int nx = curr.x + dir[i][0];
				int ny = curr.y + dir[i][1];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
					grid[nx][ny] = 1;
					que.push(point(nx, ny, curr.step + 1));
				}
			}
		}
		
		return -1; 
	}
};