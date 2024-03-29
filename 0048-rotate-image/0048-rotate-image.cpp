class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(), k=n-2, temp=0;
        for(int i=0;i<(n/2);i++){
            for(int j=i;j<=k;j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
            k--;
        }
    }
};