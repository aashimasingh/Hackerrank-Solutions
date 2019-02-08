#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int count = 0; int l = 0;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'D') 
            l--;
        else if (s.at(i) == 'U')
            l++;

        if (l == 0 && s.at(i) == 'U')
            count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
