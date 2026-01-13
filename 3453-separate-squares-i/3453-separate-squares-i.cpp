class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int maxY = 0;
        int siz= squares.size();
        for(int i=0;i<siz;i++){
            maxY= max(maxY, (squares[i][1]+squares[i][2]));
        }
        double low = 0; 
        double high= double(maxY);
        while(high - low > 1e-6){
            double mid= ((low+high)/(double(2)));
            double below = double(0);
            double above = double(0);
            for(int i=0;i<siz;i++){
                double y = squares[i][1], side = squares[i][2];
                if (y + side <= mid) {
                    below += side * side;
                }
                else if (y >= mid) {
                    above += side * side;
                }
                else {
                    below += (mid - y) * side;
                    above += (y + side - mid) * side;
                }
            }
            if (abs(below - above) < 1e-6){
                high=mid;
            }else if(below>above){
                high=mid;
            }else{
                low=mid;
            }
        }
        return low;
    }
};