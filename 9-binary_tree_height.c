#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: 0 if tree doesn't exist, your fu else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t hieght, left_height, right_height;
		left_height = 0;
		right_height = 0;
		hieght = 0;

		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);
		if (left_height > right_height)
			hieght = 1 + left_height;
		else 
			hieght = 1 + right_height;
		return (hieght);
	}
	return (0);
}
