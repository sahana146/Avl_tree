# avl_tree

AVL trees are balanced binary search trees.It ensures that at every moment the tree is balanced at every node.
This makes searching for a particular node more efficient.That is, if the binary search tree was not balanced than
incase we had to find a node which is at the leftmost end of the tree which has nodes only to the left of the root,then in
that case we would have to traverse through all the nodes in the tree(ie. n) but if it was balanced then half of the
nodes would be on the left of the new root and the other half on the right which would reduce the search node to half(ie. n/2).
So this is how the search time is reduced.
The first file avl.c shows implementation of insertion in avl trees.When a new node is inserted we need to update the heights of all the
ancestor nodes and check if they are all balanced,if not then balance them using either left,right,left-right or right-left 
rotation technique. 
The second file avl_deletion.c shows implementation of deletion in avl trees.whenever a node is deleted also we need to rebalance the tree.
