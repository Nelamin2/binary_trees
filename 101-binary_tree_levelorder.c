#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} lev_ord;

lev_ord *list(lev_ord *head, const binary_tree_t *btnode);
void free_list(lev_ord *head);
lev_ord *find_children(lev_ord *head, const binary_tree_t *parent);
void levels_call(lev_ord *head, void (*func)(int));

/**
 * binary_tree_levelorder - Goes through a binary tree
 *                          using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	lev_ord *child_nodes = NULL;

	func(tree->n);
	child_nodes = find_children(child_nodes, tree);
	levels_call(child_nodes, func);

	free_list(child_nodes);
}

/**
 * levels_call - Calls func on all nodes at each level.
 * @head: Pointer to head of linked list with nodes at one level.
 * @func: Pointer to a function to call for each node.
 */
void levels_call(lev_ord *head, void (*func)(int))
{
	lev_ord  *child_nodes = NULL, *current = NULL;

	if (!head)
		return;
	for (current = head; current != NULL; current = current->next)
	{
		func(current->node->n);
		child_nodes = find_children(child_nodes, current->node);
	}
	levels_call(child_nodes, func);
	free_list(child_nodes);
}

/**
 * find_children - appends children of parent to linked list.
 * @head: Pointer to head of linked list where children will be appended.
 * @parent: Pointer to node whose children we want to append.
 * Return: Pointer to head of linked list of children.
 */
lev_ord  *find_children(lev_ord *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = list(head, parent->left);
	if (parent->right)
		head = list(head, parent->right);
	return (head);
}

/**
 * list - adds a new node at the end of a linkedlist
 * @head: pointer to head of linked list
 * @btnode: const binary tree node to append
 * Return: pointer to head, or NULL on failure
 */
lev_ord  *list(lev_ord  *head, const binary_tree_t *btnode)
{
	lev_ord  *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - frees all the nodes in a linked list
 * @head: pointer to the head of list_t linked list
 */
void free_list(lev_ord  *head)
{
	lev_ord  *pointer;
	pointer	= NULL;
	while (head != NULL) 
	{
		pointer = head->next;
		free(head);
		head = pointer;
	}
}
