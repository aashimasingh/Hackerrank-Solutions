#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* newNode( int key ) {
    Node* temp = new Node;
    temp->data = key;
    temp->left = NULL; temp->right = NULL;
    return temp;
}

vector<int> swap (int k, int level, Node* root, vector<int> vec) {
    if (root != NULL) {
        if (level % k == 0) {
            Node* temp = root->left;
            root->left = root->right;
            root->right = temp;
            temp = NULL;
        }
        vec = swap( k, level+1, root->left, vec);
        //cout << root->data << " "; 
        vec.push_back(root->data);
        vec = swap( k, level+1, root->right, vec);
    }
    return vec;
}
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */
    vector<vector<int>> res;
    Node* root = newNode(1);
    Node* cur = root;
    queue<Node*> nodes;
    nodes.push(root);
    for (int i = 0; i < indexes.size(); i++) {
        cur = nodes.front();
        nodes.pop();
        cur->left = (indexes[i][0] == -1) ? NULL : newNode(indexes[i][0]);
        cur->right = (indexes[i][1] == -1)? NULL : newNode(indexes[i][1]);
        if (cur->left != NULL && cur->left->data != -1)
          nodes.push(cur->left);
        if (cur->right != NULL && cur->right->data != -1)
          nodes.push(cur->right);
    }
    for (int i = 0; i < queries.size(); i++) {
        vector<int> vec;
        res.push_back(swap(queries[i], 1, root, vec));
        cout << "\n";
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }
    //swapNodes(indexes, queries);
    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }
    
    fout << "\n";
    
    fout.close();

    return 0;
}
