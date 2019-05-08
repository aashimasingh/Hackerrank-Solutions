#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long count = 0;
    for (int i = 0; i < n; i++) {
      // if the current symbol is in the middle of palindrome, e.g. aba
      int offset = 1;
      while (i - offset >= 0 && i + offset < n &&
             s.at(i - offset) == s.at(i - 1) &&
             s.at(i + offset) == s.at(i - 1)) {
        count++;
        offset++;
      }
      // if this is repeatable characters aa
      int repeats = 0;
      while (i + 1 < n && s.at(i) == s.at(i + 1)) {
        repeats++;
        i++;
      }
      count += repeats * (repeats + 1) / 2;
    }
    return count + n;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
