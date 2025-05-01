class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        int j=0;
        while(m>1 && n>1){
            for(int l=0;l<n-1;l++){
                ans.push_back(matrix[i][j]);
                j++;
            }
            for(int l=0;l<m-1;l++){
                ans.push_back(matrix[i][j]);
                i++;
            }
            for(int l=0;l<n-1;l++){
                ans.push_back(matrix[i][j]);
                j--;
            }
            for(int l=0;l<m-1;l++){
                ans.push_back(matrix[i][j]);
                i--;
            }
            i++;
            j++;
            n-=2;
            m-=2;
        }
        if(m==1 && n==1){
            ans.push_back(matrix[i][j]);
        }else if(m==1){
            for(int l=0;l<n;l++){
                ans.push_back(matrix[i][j]);
                j++;
            }
        }else if(n==1){
            for(int l=0;l<m;l++){
                ans.push_back(matrix[i][j]);
                i++;
            }
        }
        return ans;
    }
};