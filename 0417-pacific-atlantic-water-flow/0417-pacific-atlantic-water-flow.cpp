class Solution {
public:
	void dfs(int x, int y, int num, vector<vector<int>>& v, vector<vector<int>>& heights){
		if(x<0 || x>=heights.size() || y<0 || y>=heights[0].size() || heights[x][y]<num || v[x][y]){return;}
		v[x][y]=1;
		dfs(x-1, y, heights[x][y], v, heights);
		dfs(x, y-1, heights[x][y], v, heights);
		dfs(x+1, y, heights[x][y], v, heights);
		dfs(x, y+1, heights[x][y], v, heights);
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		vector<vector<int>>v1(heights.size(), vector<int>(heights[0].size(), 0));
		vector<vector<int>>v2(heights.size(), vector<int>(heights[0].size(), 0));
		for(int i=0; i<heights.size(); i++){
			if(!v1[i][0]){dfs(i, 0, heights[i][0], v1, heights);}
			if(!v2[i][heights[0].size()-1]){dfs(i, heights[0].size()-1, heights[i][heights[0].size()-1], v2, heights);}
		}
		for(int i=0; i<heights[0].size(); i++){
			if(!v1[0][i]){dfs(0, i, heights[0][i], v1, heights);}
			if(!v2[heights.size()-1][i]){dfs(heights.size()-1, i, heights[heights.size()-1][i], v2, heights);}
		}
		// for(int i=0; i<heights.size(); i++){
		//     for(int j=0; j<heights[0].size(); j++){
		//         cout<<v1[i][j]<<" ";
		//     }cout<<endl;
		// }cout<<endl;
		// for(int i=0; i<heights.size(); i++){
		//     for(int j=0; j<heights[0].size(); j++){
		//         cout<<v2[i][j]<<" ";
		//     }cout<<endl;
		// }
		vector<vector<int>>ans;
		for(int i=0; i<heights.size(); i++){
			for(int j=0; j<heights[0].size(); j++){
				if(v1[i][j] && v2[i][j]){
					ans.push_back({i, j});
				}
			}
		}
		return ans;
	}
};