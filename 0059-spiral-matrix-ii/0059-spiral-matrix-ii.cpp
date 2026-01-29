class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int index_row = 0;
        int index_column = 0;
        int count = 0;
        int val = 1;
        for (int i = 0; i < n / 2 ; i++)
        {
            index_row = count;
            index_column = count;
            for (int j = 0; j < n - 1 - count * 2; j++)
            {
                matrix[index_row][index_column] = val;
                val += 1;
                index_column += 1;
            }
            for (int j = 0; j < n - 1 - count * 2; j++)
            {
                matrix[index_row][index_column] = val;
                val += 1;
                index_row += 1;
            }
            for (int j = 0; j < n - 1 - count * 2; j++)
            {
                matrix[index_row][index_column] = val;
                val += 1;
                index_column -= 1;
            }
            for (int j = 0; j < n - 1 - count * 2; j++)
            {
                matrix[index_row][index_column] = val;
                val += 1;
                index_row -= 1;
            }
            count += 1;
        }
        if (n % 2 == 1) {
            matrix[n / 2][n / 2] = val;
        }
        return matrix;
    }
};