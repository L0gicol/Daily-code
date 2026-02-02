class Solution {
public:
	struct State {
	int x, y;
	int cost;
	State(int _x, int _y, int _c) : x(_x), y(_y), cost(_c) {}
	bool operator>(const State& other) const {
		return cost > other.cost;
	}
};
    int minimumEffortPath(vector<vector<int>>& heights) {
		int n = heights.size();
		int m = heights[0].size();
		
		priority_queue<State, vector<State>, greater<State>> pq;
		
		vector<vector<int>> dist(n, vector<int>(m, 2e9));
		
		pq.push(State(0, 0, 0));
		dist[0][0] = 0;
		
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};
		
		while (!pq.empty()) {
			State cur = pq.top();
			pq.pop();
			
			if (cur.cost > dist[cur.x][cur.y]) continue;

			if (cur.x == n - 1 && cur.y == m - 1) return cur.cost;

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				int diff = abs(heights[nx][ny] - heights[cur.x][cur.y]);
				int new_cost = max(cur.cost, diff);
				if(new_cost < dist[nx][ny]){
					dist[nx][ny] = new_cost;
					pq.push(State(nx,ny,new_cost));
				}
			}
		}
		return 0;
	}
};