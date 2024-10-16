int desperate_optimization(int precision){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
    return 0;
}

class Solution {
public:
    Solution(){
        desperate_optimization(10);
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> a(m, 0);
        vector<int> s;
        int mm = 0;
        int j;
        int k;
        for(int i = 0; i < n; ++i){
            for(j = 0; j < m; ++j){
                if(matrix[i][j] == '1'){
                    ++a[j];
                }
                else a[j]=0;
            }
            for(j = 0; j <= m; ++j){
                while(s.size() && (j == m || a[s.back()] >= a[j]))
                {
                    k = s.back();s.pop_back();
                    if(s.size() == 0) mm = max(mm, a[k] * j);
                    else mm = max(mm, a[k] * (j - s.back() - 1));
                }
                s.push_back(j);
            }
            while(s.size()) s.pop_back();
        }
        return mm;
    }
};