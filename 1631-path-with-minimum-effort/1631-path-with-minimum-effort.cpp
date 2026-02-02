class Solution {
public:
    // 定义一个结构体，存 {当前消耗, x坐标, y坐标}
    struct Node {
        int cost, x, y;
        // 小顶堆需要重载 > 符号
        bool operator>(const Node& other) const {
            return cost > other.cost;
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // 1. 准备 dist 数组 (存最小消耗)
        // 初始化为无穷大 (INT_MAX)
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        // 2. ★★★ 准备 st 数组 (存是否已确定) ★★★
        // 这就是你要的！用来代替 "if (cost > dist...)"
        vector<vector<bool>> st(rows, vector<bool>(cols, false));

        // 3. 准备优先队列
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        // 4. 起点初始化
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        // 方向数组 (上下左右)
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!pq.empty()) {
            // 5. 弹出堆顶
            auto t = pq.top(); pq.pop();
            int d = t.cost;
            int x = t.x;
            int y = t.y;

            // 6. ★★★ 核心判重逻辑 (跟洛谷那题一模一样) ★★★
            // 如果这个格子之前已经处理过了，现在的这个是垃圾包，扔掉
            if (st[x][y]) continue;
            
            // 标记为已处理 (盖棺定论)
            st[x][y] = true;

            // 如果到了终点，因为是第一次弹出，直接返回 (Dijkstra 的特性)
            if (x == rows - 1 && y == cols - 1) return d;

            // 7. 遍历邻居 (上下左右)
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 越界检查
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    // 计算从当前格子走到邻居的消耗
                    // 注意：这道题的题意是求 "路径上的最大高度差"，不是求和
                    // 所以松弛逻辑稍微变了一点点，但框架没变
                    int newCost = max(d, abs(heights[x][y] - heights[nx][ny]));

                    // 8. 松弛操作
                    // 如果发现了一条消耗更小的路
                    if (dist[nx][ny] > newCost) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                        // 注意：入队的时候千万不要标记 st=true，出队才标记！
                    }
                }
            }
        }
        return 0; // 这里的返回值其实没用，因为上面一定会返回
    }
};