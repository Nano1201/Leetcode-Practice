class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        for(auto &row : image) {

            int size = row.size();
            if(size % 2 == 1)
                row[size/2] = 1-row[size/2];
            for(int i = 0 ; i < size/2 ; i++) {

                swap(row[i], row[size-i-1]);
                row[i] = 1-row[i];
                row[size-i-1] = 1-row[size-i-1];
            }
        }

        return image;
    }
};