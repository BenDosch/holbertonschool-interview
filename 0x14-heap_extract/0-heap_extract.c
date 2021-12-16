#include "binary_trees.h"

/**
 * heap_extract - Extracts the max value of a max heap.
 *
 * @root: root of max heap.
 *
 * Return: extracted max of heap.
 */

int heap_extract(heap_t **root)
{
	int max;
	heap_t *last;

	if (root == NULL || *root == NULL)
		return (0);

	max = (*root)->n;

	if (get_height(*root) == 1)
	{
		free(*root);
		*root = NULL;
		return (max);
	}

	last = find_last(*root);

	(*root)->n = last->n;

	if (last->parent->right == last)
			last->parent->right = NULL;
	else
		last->parent->left = NULL;
	free(last);

	fix_heap(*root);

	return (max);
}


/**
 * get_height - Finds the height of a max heap.
 *
 * @node: Root node of heap.
 *
 * Return: height of heap.
 */

int get_height(heap_t *node)
{
	int height;

	if (node == NULL)
		return (0);

	height = get_height(node->left);
	return (height + 1);
}

/**
 * find_last - Finds the last node of a max heap.
 *
 * @node: Root node of heap.
 *
 * Return: last node of heap.
 */

heap_t *find_last(heap_t *node)
{
	int lh = 0, rh = 0;

	if (node->left == NULL && node->right == NULL)
		return (node);
	if (node->left)
		lh = get_height(node->left);
	if (node->right)
		rh = get_height(node->right);
	if (rh == lh)
		return (find_last(node->right));
	return (find_last(node->left));
}

/**
 * fix_heap - fixes
 *
 * @node: Root node of heap.
 *
 * Return: node
 */

void fix_heap(heap_t *node)
{
	int temp;
	heap_t *max;

	if (node->left == NULL && node->right == NULL)
		return;

	max = node->left;

	if (node->right && node->right->n > max->n)
		max = node->right;

	if (max->n > node->n)
	{
		temp = node->n;
		node->n = max->n;
		max->n = temp;
		fix_heap(max);
	}
}
