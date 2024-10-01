#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct Node {
  char val;
  Node* left = nullptr;
  Node* right = nullptr;

  Node() = default;

  Node(char val, Node* left, Node* right) :
      val(val),
      left(left),
      right(right) {}


  // Destroy all child nodes
  ~Node() {
    if (left != nullptr) {
      delete left;
    }
    if (right != nullptr) {
      delete right;
    }
  }
};

Node* copy(Node* node) {
  if (node == nullptr) {
    return nullptr;
  }
  return (new Node(node->val, copy(node->left), copy(node->right)));
}

bool ContainsEps(Node* node) {
  if (node == nullptr) {
    return false;
  }
  // e - epsilon
  if ((node->val == 'e') || (node->val == '*')) {
    return true;
  }
  if (node->val == '.') {
    return (ContainsEps(node->left) && ContainsEps(node->right));
  }
  if (node->val == '+') {
    return (ContainsEps(node->left) || ContainsEps(node->right));
  }
  return false;
}

// Creating SyntaxTree
Node* MakeTree(std::string& regex) {
  // vector will not destroy tree, because pointers are saved
  std::vector<Node*> stack;

  Node* left;
  Node* right;
  for (char& c : regex) {
    if ((c == '+') || (c == '.')) {
      right = stack.back();
      stack.pop_back();
      left = stack.back();
      stack.pop_back();
      stack.push_back(new Node(c, left, right));
    } else if (c == '*') {
      left = stack.back();
      stack.pop_back();
      stack.push_back(new Node(c, left, nullptr));
    } else {
      stack.push_back(new Node(c, nullptr, nullptr));
    }
  }
  
  return stack.back();
}

Node* Derivative(Node* root, char c) {
  std::vector<Node*> stack;
  stack.push_back(root);

  while (!stack.empty()) {
    Node* node = stack.back();
    stack.pop_back();
    // # - empty set
    if ((node == nullptr) || node->val == '#') {
      continue;
    } else if (node->val == 'e') {
      node->val = '#';
    } else if (node->val == c) {
      node->val = 'e';
    } else if (node->val == '+') {
      stack.push_back(node->left);
      stack.push_back(node->right);
    } else if (node->val == '.') {
      if (ContainsEps(node->left)) {
        node->val = '+';
        Node* snode = new Node('.', node->left, node->right);
        node->left = snode;
        node->right = copy(snode->right);
        stack.push_back(node->left->left);
        stack.push_back(node->right);
      } else {
        stack.push_back(node->left);
      }
    } else if (node->val == '*') {
        Node* star = copy(node);
        node->val = '.';
        node->right = star;
        stack.push_back(node->left);
      } else {
        node->val = '#';
      }
    }

  return root;
}

bool Find(std::string& regex, std::string& word) {
  Node* node = MakeTree(regex);

  for (char& c : word) {
    Derivative(node, c);
  }
  bool ans = ContainsEps(node);
  delete node;
  return ans;
}

int Evaluate(std::string& regex, std::string word) {
  int answer = word.size();
  while (!word.empty()) {
    bool result;
    result = Find(regex, word);
    if (result == true) {
      break;
    }
    word.pop_back();
    --answer;
  }
  return answer;
}
