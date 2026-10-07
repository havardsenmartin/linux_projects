#ifndef NODE_H
#define NODE_H

/*
 * BST stores pointers only.
 * The caller retains ownership of value memory.
 */

typedef struct BST_Node {
  void *value;
  struct BST_Node *left;
  struct BST_Node *right;
} BST_Node;

// goofy ass syntax
// Comparator is a pointer to a function that
// takes two const void * arguments and returns an int.
typedef int (*Comparator)(const void *, const void *);

typedef void (*Printer)(const void *);

typedef struct {
  BST_Node *root;
  const Comparator cmp;
  const Printer printer;
} BST;

BST_Node *allocate_node(const void *value);

void add_node(BST_Node **node, const void *value, const Comparator cmp);

void print_inorder(const BST_Node *node, const Printer printer);

BST_Node **node_find(BST_Node **node, const void *value, const Comparator cmp);

BST_Node *node_min(BST_Node *node);

BST_Node *node_max(BST_Node *node);

int node_delete(BST_Node **node, const void *value, const Comparator cmp);

void free_nodes(BST_Node *node);

void free_tree(BST *bst);

// iterative version

void add_node_iterative(BST *root, const void *value);

BST_Node **bst_find_link_iterative(BST *bst, const void *value);

BST_Node *node_min_iterative(BST_Node *node);

BST_Node *node_max_iterative(BST_Node *node);

int node_delete_iterative(BST *bst, const void *value);

#endif
