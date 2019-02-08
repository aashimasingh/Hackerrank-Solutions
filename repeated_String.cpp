#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long count = 0;
    string s2; string result;
    //result.assign(s);
    if (s.length() == 1 && s.at(0)=='a')
        return n;
    else if (s.length() == 1)
        return 0;
    /*if ( s.length() < n ) {
    for (int j = 0; j < (n/s.length())+1; j++) {
        result += s;
    }
    }
    for (long i = 0; i < n; i++) {
        if (result.at(i) == 'a') 
            count++;
    }*/

    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == 'a')
            count ++;
    }
    count = count*(n/s.length());
    result = s.substr(0, n%s.length());
    cout << result <<"\n";
    for (int i = 0; i < result.length(); i++) {
        if (result.at(i) == 'a')
            count++;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
