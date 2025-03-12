class Solution {
public:
    int rectangle(vector<int>& arr){
        int siz=arr.size();
        vector<int> left(siz,-1);
        stack<int> ls;
        for(int i=0;i<siz;i++){
            while(!ls.empty() && arr[ls.top()]>=arr[i]){
                ls.pop();
            }
            if(!ls.empty()){
                left[i]=ls.top();
            }
            ls.push(i);
        }
        stack<int> rs;
        vector<int> right(siz,siz);
        for(int i=siz-1;i>=0;i--){
            while(!rs.empty() && arr[rs.top()]>=arr[i]){
                rs.pop();
            }
            if(!rs.empty()){
                right[i]=rs.top();
            }
            rs.push(i);
        }
        int area=0;
        for(int i=0;i<siz;i++){
            int w=right[i]-left[i]-1;
            area=max(area,w*arr[i]);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> mat(m,vector<int> (n,0));
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                if(matrix[j][i]=='1'){
                    c++;
                    mat[j][i]=c;
                }else{
                    c=0;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            ans=max(ans,rectangle(mat[i]));
        }
        return ans;
    }
};