#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int partition( vector<int> prices, int low, int high );
void quickSort( vector<int> prices, int low, int high );

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    int max = 0;
    /*for (int i = 0; i < prices.size(); i++) {
        for (int j = 0; j < prices.size()-1; j++) {
            if (prices[j+1] < prices[j]) {
                tmp = prices[j+1];
                prices[j+1] = prices[j];
                prices[j] = tmp;
            }
        }
    }*/
    sort(prices.begin(), prices.end());

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] <= k) {
            k -= prices[i];
            max++;
        }
    }
    return max;
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (vector<int> prices, int low, int high) 
{ 
    int pivot = prices[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (prices[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&prices[i], &prices[j]); 
        } 
    } 
    swap(&prices[i + 1], &prices[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(vector<int> prices, int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(prices, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(prices, low, pi - 1); 
        quickSort(prices, pi + 1, high); 
    } 
} 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
