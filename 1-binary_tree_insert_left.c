#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The data to store in the new node.
 * Return: NULL if node is not created
 * Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = parent->left;
    new_node->right = NULL;

    if (parent->left != NULL)
        parent->left->parent = new_node;
    parent->left = new_node;

    return (new_node);
}
