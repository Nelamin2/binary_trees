#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return:  NULL if no ancestor is found, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent1, *parent2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	parent1 = first->parent, parent2 = second->parent;
	if (first == parent2 || !parent1 || (!parent1->parent && parent2))
		return (binary_trees_ancestor(first, parent2));
	else if (parent1 == second || !parent2 || (!parent1->parent && parent1))
		return (binary_trees_ancestor(parent1, second));
	return (binary_trees_ancestor(parent1, parent2));
}
