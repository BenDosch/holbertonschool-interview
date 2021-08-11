#include "binary_trees.h"



heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new;

    if (root == NULL)
    {
        *root = binary_tree_node(*root, value);
        return *root;
    }
    new = traverse_insert(*root, value);
    if (new == NULL)
        return (NULL);
    return(new);
}

heap_t *traverse_insert(heap_t *parent, int value)
{
    heap_t *new;
    size_t l_height=0, r_height=0;

    if (!parent)
        return (NULL);
    if (parent->left)
        l_height = binary_tree_height(parent->left);
    if (parent->right)
        r_height = binary_tree_height(parent->right);

    if (!parent->left)
    {
        new = binary_tree_node(parent, value);
        if (new == NULL)
            return (NULL);
        parent->left = new;
        return new;
    }
    else if (!parent->right)
    {
        new = binary_tree_node(parent, value);
        if (new == NULL)
            return (NULL);
        parent->right = new;
        return new;
    }
    else
    {
        if(is_full(parent))
        {
            new = traverse_insert(parent->left, value);
            if (new == NULL)
                return (NULL);
            return(new);
        }
        else if (l_height > r_height && !is_full(parent->left))
            {
                new = traverse_insert(parent->left, value);
                if (new == NULL)
                    return (NULL);
                return (new);
            }
        else
        {
            new = traverse_insert(parent->right, value);
            if (new == NULL)
                return (NULL);
            return (new);
        }
    }
}

/**
* binary_tree_height - function that detrmines the height of a binary tree.
* @tree: Pointer to the tree to check
* Return: height of tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh = 0, rh = 0;

	if (tree)
	{
		if (tree->left)
			lh = 1 + binary_tree_height(tree->left);
		if (tree->right)
			rh = 1 + binary_tree_height(tree->right);
		if (lh >= rh && lh != 0)
			return (lh);
		else if (rh > lh && rh != 0)
			return (rh);
	}
	return (0);
}

/**
* binary_tree_nodes - function that measures the nodes of a binary tree.
* @tree: Pointer to the tree to check
* Return: nodes
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t total = 0;

	if (tree)
	{
		if (!(tree->left == NULL && tree->right == NULL))
			total += 1;
		if (tree->left)
			total += binary_tree_nodes(tree->left);
		if (tree->right)
			total += binary_tree_nodes(tree->right);
		return (total);
	}
	return (0);
}

size_t is_full(binary_tree_t *parent)
{
    size_t l_height, r_height, l_count, r_count;

    l_height = binary_tree_height(parent->left);
    l_count = binary_tree_nodes(parent->left);
    r_height = binary_tree_height(parent->right);
    r_count = binary_tree_nodes(parent->right);

    if (l_height == r_height && l_count == r_count)
        return 1;
    else
        return 0;
}
