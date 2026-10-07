#include <node.h>
#include <stdio.h>
#include <stdlib.h>

BST_Node *allocate_node(const void *value) {
  BST_Node *new_node = malloc(sizeof(BST_Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void add_node(BST_Node **node, const void *value, const Comparator cmp) {
  /*
   * Adds `target` beneath `node`.
   * Less than or equal means left-side.
   */
  if (*node == NULL) {
    *node = allocate_node(value);
    return;
  }

  int result = cmp(value, (*node)->value);

  if (result > 0) {
    add_node(&(*node)->right, value, cmp);
  } else if (result < 0) {
    add_node(&(*node)->left, value, cmp);
  } else {
    add_node(&(*node)->left, value, cmp);
  }
}

void print_inorder(const BST_Node *node, const Printer printer) {
  if (node == NULL) {
    return;
  }
  print_inorder(node->left, printer);
  printer(node->value);
  print_inorder(node->right, printer);
}

// finds the link (pointer) that
// connects to a node with a certain value
BST_Node **node_find(BST_Node **node, const void *value, const Comparator cmp) {
  if (node == NULL || *node == NULL)
    return NULL;
  int result = cmp(value, (*node)->value);

  if (result > 0) {
    return node_find(&(*node)->right, value, cmp);
  } else if (result < 0) {
    return node_find(&(*node)->left, value, cmp);
  } else {
    return node;
  }
}

BST_Node *node_min(BST_Node *node) {
  if (node == NULL)
    return NULL;
  if (node->left == NULL)
    return node;
  return node_min(node->left);
}

BST_Node *node_max(BST_Node *node) {
  if (node == NULL)
    return NULL;
  if (node->right == NULL)
    return node;
  return node_max(node->right);
}

int node_delete(BST_Node **node, const void *value, const Comparator cmp) {
  /*
   * Deletes first node with given value
   */
  BST_Node **link = node_find(node, value, cmp);
  if (link == NULL)
    return 0;
  BST_Node *target_node = *link;
  BST_Node *right_subtree_node = (*link)->right;
  BST_Node *left_subtree_node = (*link)->left;
  if (left_subtree_node == NULL) {
    *link = right_subtree_node;
  } else {
    *link = left_subtree_node;
    node_max(left_subtree_node)->right = right_subtree_node;
  }
  free(target_node);
  return 1;
}

void free_nodes(BST_Node *node) {
  if (node == NULL)
    return;
  free_nodes(node->left);
  free_nodes(node->right);
  free(node);
}

void free_tree(BST *bst) {
  free_nodes(bst->root);
  bst->root = NULL;
}

void add_node_iterative(BST *bst, const void *value) {
  if (bst == NULL || bst->cmp == NULL) {
    printf("Tree was uninitialized\n");
    return;
  }

  BST_Node **link = &bst->root;

  while (*link != NULL) {
    int result = bst->cmp(value, (*link)->value);

    if (result > 0)
      link = &(*link)->right;
    else
      link = &(*link)->left;
  }

  *link = allocate_node(value);
}

/*

This version never explicitly asks:

"Is the right child NULL?"

Instead it asks:

"Have I reached a NULL link yet?"

which is often how experienced C programmers think about these structures.

*/

BST_Node **bst_find_link_iterative(BST *bst, const void *value) {
  if (bst == NULL || bst->cmp == NULL) {
    printf("Tree was uninitialized\n");
    return NULL;
  }
  BST_Node **link = &bst->root;
  while ((*link) != NULL) {
    int result = bst->cmp(value, (*link)->value);
    if (result == 0)
      return link;
    if (result > 0) {
      link = &(*link)->right;
    } else {
      link = &(*link)->left;
    }
  }
  return NULL;
}

BST_Node *node_min_iterative(BST_Node *node) {
  if (node == NULL)
    return NULL;
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

BST_Node *node_max_iterative(BST_Node *node) {
  if (node == NULL)
    return NULL;
  while (node->right != NULL) {
    node = node->right;
  }
  return node;
}

int node_delete_iterative(BST *bst, const void *value) {
  if (bst == NULL || bst->cmp == NULL) {
    printf("Tree was uninitialized\n");
    return 0;
  }
  BST_Node **target_link = bst_find_link_iterative(bst, value);
  if (target_link == NULL) {
    printf("Couldn't delete node. Node not found.\n");
    return 0;
  }
  BST_Node *target_node = *target_link;

  BST_Node *left_subtree_node = (*target_link)->left;
  BST_Node *right_subtree_node = (*target_link)->right;

  if (left_subtree_node == NULL) {
    *target_link = right_subtree_node;
  } else {
    *target_link = left_subtree_node;
    if (right_subtree_node != NULL)
      node_max_iterative(left_subtree_node)->right = right_subtree_node;
  }
  // NOTE: `value` must not be freed.
  // The BST does not own the nodes `value`
  // memory
  free(target_node);
  printf("Deleted node.\n");
  return 1;
}
