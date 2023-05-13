#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
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

public:
  void insert(T data) {
    m_rootPtr = privateInsert(m_rootPtr, data);  
  }

  bool search(T data) {
    return privateSearch(m_rootPtr, data); 
  }
};

#endif
