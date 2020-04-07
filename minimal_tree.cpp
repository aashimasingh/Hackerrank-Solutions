#include <iostream>

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node (int data) {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
}; 

Node* sortedArrayToBST ( int arr[], int start, int end ) {
  if (start > end)  
    return NULL;

  int mid = (start + end) / 2;
  std::cout << start << " " << mid << " " << end << "\n";
  Node *root = new Node(arr[mid]);

  root->left = sortedArrayToBST( arr, start, mid-1 );
  root->right = sortedArrayToBST( arr, mid+1, end );

  return root; 
}

void preOrder (Node *root) {
  if (root == NULL)
    return;
  std::cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main() {
int arr[] = {1,2,3,4,5,6,7};
int n = sizeof(arr) / sizeof(arr[0]);

Node *root = sortedArrayToBST( arr, 0, n-1 );
preOrder(root);
}