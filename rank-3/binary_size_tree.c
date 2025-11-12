#include "binary_search.h"

int	size_binary_tree(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + size_binary_tree(root->left) + size_binary_tree(root->right));
}

