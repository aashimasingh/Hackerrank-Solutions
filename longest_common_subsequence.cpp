#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int **C = new int*[s1.size() + 1];
    for (int i = 0; i < s1.size() + 1; i++) 
        C[i] = new int[s2.size() + 1];
    
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1.at(i) == s2.at(j)) {
                C[i+1][j+1] = C[i][j] + 1;
            }
            else {
                C[i+1][j+1] = max(C[i][j+1], C[i+1][j]);
            }
        }
    }

    return C[s1.size()][s2.size()];

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
