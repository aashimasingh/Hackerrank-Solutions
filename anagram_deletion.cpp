#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int count1[26] = {0}; int count2[26] = {0};
    
    for (int i = 0; i < a.size(); i++) {
        count1[a.at(i) - 'a']++;
    }
    for (int j = 0; j < b.size(); j++) {
        count2[b.at(j) - 'a']++;
    }
    int result = 0;
    for (int k = 0; k < 26; k++) {
        result += abs(count1[k] - count2[k]);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

