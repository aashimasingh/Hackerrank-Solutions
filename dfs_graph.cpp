#include <bits/stdc++.h>

using namespace std;

// Complete the maxRegion function below.
int countRegion(vector<vector<int>>& grid, int i, int j ) {
    //int count = 0;
    if ( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return 0;
    if (grid[i][j] == 0)
        return 0;
    int count = grid[i][j]--;
    //grid[i][j] = grid[i][j] - 1;
    count += countRegion(grid, i+1, j);
    count += countRegion(grid, i-1, j);
    count += countRegion(grid, i, j+1);
    count += countRegion(grid, i, j-1);
    count += countRegion(grid, i+1, j+1);
    count += countRegion(grid, i-1, j-1);
    count += countRegion(grid, i-1, j+1);
    count += countRegion(grid, i+1, j-1);
    return count;
}

int maxRegion(vector<vector<int>> grid) {
    int maxi = 0; 
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            maxi = max(maxi, countRegion(grid, i, j));
        }
    }
    return maxi;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}