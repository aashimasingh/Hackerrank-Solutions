#include <iostream>
#include <string>
#include <unordered_set>

class Node {
  public:
    int data;
    Node *next;

    Node( int data ) {
      this->data = data;
      this->next = NULL;
    }
};

void removeDuplicates (Node *node) {
  std::unordered_set<int> seen;
  Node *curr = node;
  Node *prev = node;
  while (curr != NULL) {
    if (seen.find(curr->data) != seen.end()) {
      prev->next = curr->next;
      delete(curr);
    }
    else {
      seen.insert(curr->data);
      prev = curr;
    }
    std::cout << "current:" << curr->data << "\n";
    std::cout << "prev:" << prev->data << "\n";
    curr = prev->next;
  }
}

void printList( Node *node ) {
  while(node != NULL) {
    std::cout << node->data << " -> ";
    node = node->next;
  }
  std::cout << "\n";
}

int main() {
  Node *start = new Node(10);
  start->next = new Node(11);
  start->next->next = new Node(10);
  start->next->next->next = new Node(13);

  printList(start);

  removeDuplicates(start);

  printList(start);
}