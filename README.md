# Assignment 2 – Q2: Online Bookstore BST (PCCST303)

## Files
- bst.c – source code
- input.txt – input data
- output.txt – program output

## Tree (insert order 45,20,60,10,30,50,70,25,55)
```
            45
        /       \
      20         60
     /  \       /  \
   10    30   50    70
        /       \
      25         55
```
Height = 3 edges (4 levels), n = 9

## Traversals
| Traversal | Result |
|---|---|
| Inorder | 10 20 25 30 45 50 55 60 70 (sorted) |
| Preorder | 45 20 10 30 25 60 50 55 70 |
| Postorder | 10 25 30 20 55 50 70 60 45 |

## Search trace (comparisons = nodes examined)
| Key | BST path | BST cmps | Linear cmps (position) |
|---|---|---|---|
| 25 | 45→20→30→25 | 4 | 8 (index 7) |
| 55 | 45→60→50→55 | 4 | 9 (index 8) |
| 90 | 45→60→70→null | 3 | 9 (not found) |
| Total | | 11 | 26 |

## Complexity
| | BST Search | Linear Search |
|---|---|---|
| Best | O(1) | O(1) |
| Average | O(log n) | O(n) |
| Worst | O(n) (skewed tree) | O(n) |
| Space | O(h) recursion / O(1) iterative | O(1) |

Balanced BST height = floor(log2 n) = 3 for n = 9, so this tree is perfectly height-balanced.
Observed BST comparisons (3–4) match log2(9) ≈ 3.17; linear needed up to n = 9.

## Analysis
- Height controls the cost: each search costs at most h+1 comparisons.
- This tree is balanced, so cost ≈ log n. Had keys been inserted in sorted order (10,20,...,70) it would degenerate into a chain with height 8, and BST search would cost O(n), same as linear.
- Linear search uses 26 comparisons vs 11 for BST on the same three searches (~58% fewer).

## Conclusion
BST search is preferable for the ISBN dataset: fewer comparisons, and inorder traversal gives sorted ISBNs for free. For very large or sorted-insertion datasets, use a self-balancing tree (AVL / Red-Black) to guarantee O(log n).
