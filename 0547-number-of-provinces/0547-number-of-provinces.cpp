class Solution {
public:
    struct DSU {
	vector<int> parent;
	int count;
	DSU(int n) {
		parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        count = n;
	}
	int find(int x) {
		if(parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(int x, int y) {
		int a = find(x);
		int b = find(y);
		if(a == b) return;
		parent[a] = b;
        count--;
	}
};
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU all(n);
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(isConnected[i][j] == 1) all.unite(i,j);
            }
        }
        return all.count;
    }
};