class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 0) return "";
        
        int cols = n / rows;
        
        vector<vector<char>> mat(rows, vector<char>(cols));
        
        // Fill matrix row-wise
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }
        
        // Read diagonally
        string result = "";
        
        for (int col = 0; col < cols; col++) {
            int i = 0, j = col;
            while (i < rows && j < cols) {
                result += mat[i][j];
                i++;
                j++;
            }
        }
        
        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};
