#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int count_max = 0; int count_min = 0;
    vector<int> freq;
    for (int i = 0; i < 26; i++)
        freq.push_back(0);    
        
    if (s.length() == 1)
        return "YES";

    for (int i = 0; i < s.length(); i++) {
        freq[s.at(i)-'a']++;
    }
    freq.erase(remove(freq.begin(), freq.end(), 0), freq.end());
    int max = *max_element(freq.begin(), freq.end());
    int min = *min_element(freq.begin(), freq.end());

    if (max == min)
        return "YES";
    
    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] == max) {
            count_max++;
        }
        if (freq[i] == min) {
            count_min++;
        }
    }

    if (count_max + count_min != freq.size())
        return "NO";
    if (count_min == 1 && min == 1)
        return "YES";
    if (count_max == 1 && max == min+1)
        return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}


int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
