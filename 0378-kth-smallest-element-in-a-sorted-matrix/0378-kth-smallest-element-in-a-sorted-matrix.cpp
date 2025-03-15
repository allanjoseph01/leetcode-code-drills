class Solution {
public:
    int small(vector<int>& row,int mid){
        int n=row.size();
        int l=0;
        int h=n-1;
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(row[m]>mid){
                h=m-1;
            }else{
                ans=m+1;
                l=m+1;
            }
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0];
        int h=matrix[n-1][n-1];
        int m;
        int ans;
        while(l<=h){
            m=(l+h)/2;
            int c=0;
            for(int i=0;i<n;i++){
                if(matrix[i][n-1]<=m){
                    c+=n;
                }else{
                    c+=small(matrix[i],m);
                }
            }
            // cout << m << " " << c << endl;
            if(c>=k){
                h=m-1;
                ans=m;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};