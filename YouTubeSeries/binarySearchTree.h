#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <climits>
#include <iostream>
#include <queue>

template<typename T>
class BinarySearchTree {
private:
  struct BstNode {
    T data;
    BstNode *left;
    BstNode *right;
  };

  BstNode *m_rootPtr{nullptr};

  BstNode *getNewNode(T data) {
    return new BstNode{data, nullptr, nullptr};
  }

public: 
  BinarySearchTree() = default;

  ~BinarySearchTree() = default;
// These private functions allow me to create recursive solutions that can be executed from outside the class without needing to give access
  // to private members.
private:
  BstNode *privateInsert(BstNode* currentNode, T data) {
    if (currentNode == nullptr) {
      currentNode = getNewNode(data);
      return currentNode;

    } else if (data <= currentNode->data) {
      currentNode->left = privateInsert(currentNode->left, data);
    } else {
      currentNode->right = privateInsert(currentNode->right, data);
    }

    return currentNode;
  }

  bool privateSearch(BstNode *currentNode, T data) {
    if (currentNode == nullptr) return false;
    else if (currentNode->data == data) return true;
    else if(data <= currentNode->data) return privateSearch(currentNode->left, data);
    else return privateSearch(currentNode->right, data);
  }

  int privateHeight(BstNode *currentNode) {
    if (currentNode == nullptr) return -1;

    return std::max(privateHeight(currentNode->left), privateHeight(currentNode->right)) + 1;
  }

public:
  void insert(T data) {
    m_rootPtr = privateInsert(m_rootPtr, data);  
  }

  bool search(T data) {
    return privateSearch(m_rootPtr, data); 
  }

  T min() {
    if (m_rootPtr == nullptr) {
      std::cout << "BST is empty, no min value";
      return T{};
    } 
    BstNode *current{m_rootPtr};

    while(current->left != nullptr) {
      current = current->left;
    }

    return current->data;
  }

  T max() {
    if (m_rootPtr == nullptr) {
      std::cout << "BST is empty, no min value";
      return T{};
    }

    BstNode *current{m_rootPtr};

    while (current->right != nullptr) {
      current = current->right;
    }

    return current->data;
  }

  int height() {
    return privateHeight(m_rootPtr);
  }

  void levelOrderTraversal() {
    if (m_rootPtr ==  nullptr) return;
    std::queue<BstNode*> discovered; 

    discovered.push(m_rootPtr);
    if (!discovered.front()) std::cout << "NULL";
    while (!discovered.empty()) {
      BstNode *current = discovered.front();
      std::cout << current->data << " ";
      if (current->left != nullptr) discovered.push(current->left);
      if (current->right != nullptr) discovered.push(current->right);
      discovered.pop();
    }
  }

private:
  void privatePreOrderTraversal(BstNode *currentPtr) {
    if (currentPtr == nullptr) return;
    std::cout << currentPtr->data << " ";
    privatePreOrderTraversal(currentPtr->left);
    privatePreOrderTraversal(currentPtr->right);
  }

  void privateInOrderTraversal(BstNode *currentPtr) {
    if (currentPtr == nullptr) return;
    privateInOrderTraversal(currentPtr->left);
    std::cout << currentPtr->data << " ";
    privateInOrderTraversal(currentPtr->right);
  }

  void privatePostOrderTraversal(BstNode *currentPtr) {
    if (currentPtr == nullptr) return;
    privatePostOrderTraversal(currentPtr->left);
    privatePostOrderTraversal(currentPtr->right);
    std::cout << currentPtr->data << " ";
  }

public:
  void preOrderTraversal() {
    privatePreOrderTraversal(m_rootPtr);
    std::cout << '\n';
  }

  void inOrderTraversal() {
    privateInOrderTraversal(m_rootPtr);
    std::cout << '\n';
  }

  void postOrderTraversal() {
    privatePostOrderTraversal(m_rootPtr);
    std::cout << '\n';
  }

private:
  bool privateIsBinarySearchTree(BstNode *root, int minValue, int maxValue) {
    if (root == nullptr) return true;

    if (root->data > minValue && root->data < maxValue
    && privateIsBinarySearchTree(root->left, minValue, root->data)
    && privateIsBinarySearchTree(root->right, root->data, maxValue)) {
     return true; 
    } else {
      return false;
    }
  }

public:
  bool isBinarySearchTree() {
    return privateIsBinarySearchTree(m_rootPtr, INT_MIN, INT_MAX);
  }

private:
  BstNode *privateDelete(BstNode *root, const T data) {
    if (root == nullptr) return root;
    else if (data < root->data) root->left = privateDelete(root->left, data);
    else if (data > root->data) root->right = privateDelete(root->right, data);
    else {
      // Case 1 - No children
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr;
      }

      // Case 2: One child
      else if(root->left == nullptr) {
        BstNode *temp = root;
        root = root->right;
        delete temp;
      }

      else if (root->right == nullptr) {
        BstNode *temp = root;
        root = root->left;
        delete temp;
      }

      // Case 3: two children
      else {
        // Find min value
        BstNode *current = root->right;
        while(current->left != nullptr) {
          current = current->left;
        }

        BstNode *temp = current;
        std::cout << current->data << '\n';
        root->data = temp->data;
        root->right = privateDelete(root->right, temp->data);
      }
    }
    return root;
  }

public:
  void deleteNode(const T data) {
    privateDelete(m_rootPtr, data);
  }

private:
  BstNode *searchBstNode(BstNode *root, const T &data) {
    if (root == nullptr) return nullptr;
    else if (root->data == data) return root;
    else if(data <= root->data) return searchBstNode(root->left, data);
    else return searchBstNode(root->right, data);
  }

  BstNode *privateInOrderSuccessor(BstNode *root, const T &data) {
    BstNode* current{searchBstNode(root, data)};
    if (current == nullptr) return nullptr;

    // Case 1 - No right subtree
    if (current->right != nullptr) {
      BstNode *temp{current->right};
      while (temp->left != nullptr) {
        temp = temp->left;
      }
      std::cout << temp->data;
      return temp;
    } 
    //Case 2: No right subtree
    else {
      BstNode *successor{nullptr};
      BstNode *ancestor{root};
      while (ancestor != current) {
        if (current->data < ancestor->data) {
          successor = ancestor;
          ancestor = ancestor->left;
        } else {
          ancestor = ancestor->right;
        }
      }
      return successor;
    }
  }
public:
  BstNode *inOrderSuccessor(const T &data) {
    privateInOrderSuccessor(m_rootPtr, data);
  }
};

#endif
