#include "binary_trees.h"
#include <stdlib.h>

/**
 * new_node - Makes a new node for the tree
 * @n: The value to store in node
 * @tree: Existing tree
 * Returns: Pointer to new node
 */

avl_t *new_node(int n, avl_t *tree)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (node == NULL)
		return (NULL);

    if (tree == NULL)
	{
		node->parent = NULL;
		tree = node;
	}
	else
		node->parent = tree;

	node->left = NULL;
	node->right = NULL;
	node->n = n;


	return (node);
}

/**
 * branching - Recursive assembly of the tree
 * @tree: Tree being assembled
 * @array: The array being converted
 * @sart: Start of the sorted array
 * @end: End of the sorted array
 * Returns: Binary tree of sorted array
 */

avl_t *branching(avl_t *tree, int *array, int start, int end)
{
	int middle = (start + end) / 2;

    if (start > end)
		return (NULL);

	tree = new_node(array[middle], tree);

    if (tree == NULL)
        return (NULL);

	tree->left = branching(tree, array, start, (middle - 1));
	tree->right = branching(tree, array, (middle + 1), end);

	return (tree);
}

/**
 * sorted_array_to_avl - Converts a sorted array to avl tree
 * @array: The sorted array
 * @size: The size of the sorted array
 * Return: The avl of the sorted array
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size <= 0)
		return (NULL);
	return (branching(NULL, array, 0, size - 1));
}
