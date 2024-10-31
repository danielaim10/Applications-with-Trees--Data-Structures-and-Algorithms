# Assignment 2 - Munteanu Irina Daniela

First, I initialized a tree structure using nodes that contain two variables: `value`, which stores the character of the node, and `level`, which indicates the level of the node in the tree. Importantly, our root is at level 0.

## Requirements

### Requirement 1
We begin inserting suffixes in the `main()` function by appending the character `$` to the end of each suffix before calling the `insertSuffix` function. This function processes each suffix individually, determining its index using ASCII values (with `$` assigned to index 0). We check if the child already exists; if not, we insert the character value into the node and proceed to the next suffix. If it does exist, we make the child the new root to continue processing. Finally, the display function applies a BFS traversal of the tree to show the elements in breadth-first order, considering the special case of the node with value `$`.

### Requirement 2
Three functions with different utilities:

1. **Count Leaf Nodes**: 
   This function uses a variable called `count` to keep track of leaf nodes. It first checks if the root is null (indicating no children) and returns 0. If `count` is still 1 after the loop, it means all children of the current node are null, indicating the current node is a leaf. We increment `count` by 1 to account for this leaf. For each non-null child of the current node, the function recursively calls `countLeaf` on that child. The value returned from the recursive call (the number of leaf nodes in the child’s subtree) is added to `count`.

2. **Count Suffixes of Length k**:
   This function checks if the current node (root) has the value `$` (indicating the end of a string) and is at level `k + 1`. If both conditions are satisfied, we increment `count` by 1 to register the suffix of length `k`. For each non-null child of the current node, the function recursively calls `countK` on that child. A variable `t` is incremented to track the number of nodes traversed in the current path. The value returned from the recursive call (the number of suffixes of length `k` found in the child’s subtree) is added to `count`. After traversing the children recursively, we check if the current node is `$` and if `t` equals `k`. If both conditions are met, it indicates that a suffix of length `k` has been found by concatenating the labels of nodes along the current path (excluding the current node).

3. **Maximum Number of Descendants**:
   For each non-null child (`root->children[i]`), we increment `current` by 1 to count an additional descendant. We then compare the current number of nodes with the maximum determined so far and update `maxCount` with the greater value.

### Requirement 3
We reinitialize since this time we need to read two variables `N` and `M`, as well as two strings with different applications. The `check` function verifies if the `M` strings are suffixes of the tree formed from the `N` words. It checks if the child at the current node (root) with the given index exists. If it does not exist, it means the suffix is not present in the tree, and it returns 0. We compare the character value from the suffix (at the current index `i`) with the child’s value. If they do not match, it indicates the suffix does not fit the path in the tree, and it returns 0. If these checks pass, we continue verifying the children of the current node. We check if there is a child `$` at the current node. If it exists, it means the suffix ends at a terminal node (`$`), representing a complete suffix, and it returns 1. If there is no child `$`, it means the suffix does not terminate at a terminal node and is not a complete suffix of the original string, and it returns 0.

## Acknowledgments
Thank you for your attention! I hope you find this project insightful. It has been an exciting challenge, and I've enjoyed the process of developing it.
