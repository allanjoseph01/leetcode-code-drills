class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int l=INT_MAX,h=INT_MIN;
        int siz1=a.size();
        for(int i=0;i<siz1;i++){
            l=min(l,a[i]);
            h=max(h,a[i]);
        }
        int siz2=b.size();
        for(int i=0;i<siz2;i++){
            l=min(l,b[i]);
            h=max(h,b[i]);
        }
        int m;
        int ans;
        while(l<=h){
            m=(l+h)/2;
            int c=0;
            for(int i=0;i<siz1;i++){
                if(a[i]<m){
                    c++;
                }
            }
            for(int i=0;i<siz2;i++){
                if(b[i]<m){
                    c++;
                }
            }
            if(c>=k){
                h=m-1;
            }else{
                l=m+1;
                ans=m;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int siz1=nums1.size();
        int siz2=nums2.size();
        if((siz1+siz2)%2==1){
            return double(kthElement(nums1,nums2,((siz1+siz2)/2)+1));
        }
        return double((double(kthElement(nums1,nums2,((siz1+siz2)/2)))+double(kthElement(nums1,nums2,((siz1+siz2)/2)+1)))/2);
    }
};