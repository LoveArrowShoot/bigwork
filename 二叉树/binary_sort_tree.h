//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define Status int

#include<iostream>
#include<deque>
#include<stack>
typedef int ElemType;
class sorttree {
public:
    typedef struct Node {
        ElemType value;
        struct Node* left, * right;
    }Node;
    Node* root = NULL;
    int length = 0;
    /**
     * BST initialize
     * @param BinarySortTreePtr BST
     * @return is complete
     */
    sorttree();

    /**
     * BST insert
     * @param BinarySortTreePtr BST
     * @param ElemType value to insert
     * @return is successful
     */
    Node* BST_insert(Node*, ElemType);

    /**
     * BST delete
     * @param BinarySortTreePtr BST
     * @param ElemType the value for Node which will be deleted
     * @return is successful
     */
    Node* BST_delete(Node*, ElemType);

    /**
     * BST search
     * @param BinarySortTreePtr BST
     * @param ElemType the value to search
     * @return is exist
     */
    Status BST_search(Node*, ElemType);

    /**
     * BST preorder traversal without recursion
     * @param BinarySortTreePtr BST
     * @param (*visit) callback
     * @return is successful
     */
    Status BST_preorderI(Node*, void (*visit)(Node*));

    /**
     * BST preorder traversal with recursion
     * @param BinarySortTreePtr BST
     * @param (*visit) callback
     * @return is successful
     */
    Status BST_preorderR(Node*, void (*visit)(Node*));

    /**
     * BST inorder traversal without recursion
     * @param BinarySortTreePtr BST
     * @param (*visit) callback
     * @return is successful
     */
    Status BST_inorderI(Node*, void (*visit)(Node*));

    /**
     * BST inorder traversal with recursion
     * @param BinarySortTreePtr BST
     * @param (*visit) callback
     * @return is successful
     */
    Status BST_inorderR(Node*, void (*visit)(Node*));

    /**
     * BST preorder traversal without recursion
     * @param BinarySortTreePtr BST
     * @param (*visit) callback
     * @return is successful
     */
    Status BST_postorderI(Node*, void (*visit)(Node*));

    /**
     * BST postorder traversal with recursion
     * @param BinarySortTreePtr BST
     * @param (*visit) callback
     * @return is successful
     */
  //  Status BST_postorderR(Node*, void (*visit)(Node*));
    Status BST_postorderR(Node*, void (*visit)(Node*));
    /**
     * BST level order traversal
     * @param BinarySortTreePtr BST
     * @param (*visit) callback
     * @return is successful
     */
    Status BST_levelOrder(Node*, void (*visit)(Node*));

};

void visit(sorttree::Node*);
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
