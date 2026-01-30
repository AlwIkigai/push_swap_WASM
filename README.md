# push_swap

## Short Description

A 42 School project implemented in C that sorts a list of integers using only a limited set of stack operations. The program accepts input numbers via the command line, validates them and then outputs a sequence of operations (`sa`, `pb`, `rr`, etc.) that will sort the numbers. The objective is to use as few operations as possible within the constraints of the `push_swap` problem.

## What the Project Does

- Accepts a series of integer arguments from the command line. Each argument must be a valid 32‑bit integer; duplicates or non‑numeric values produce an error.
- Allocates two stacks (`a` and `b`) as linked lists and assigns a rank to each element to facilitate comparisons.
- Detects if the input is already sorted to avoid unnecessary operations.
- Uses specialised routines for small lists:
  - Two elements: swaps if necessary.
  - Three elements: applies a small sorting strategy based on simple comparisons and rotate/reverse operations.
- For larger lists:
  - Computes a median and pushes elements below the median to stack B, leaving a small set in stack A to be sorted.
  - Recursively sorts the remainder of stack A (typically three elements).
  - Iteratively reinserts elements from stack B into their correct position in stack A by calculating the cost of each potential move (taking into account rotation direction and combined operations) and choosing the cheapest.
  - Rotates stack A so that the smallest element finishes on top.
- Implements all required operations for the challenge: push (`pa`, `pb`), swap (`sa`, `sb`, `ss`), rotate (`ra`, `rb`, `rr`) and reverse rotate (`rra`, `rrb`, `rrr`).
- Prints the selected operations to standard output using `ft_printf` without additional commentary.

## Key Concepts / What I Learned

- **Stack‑based data structures:** Built singly linked lists to represent stacks and provided push, pop, rotate and swap operations.
- **Input parsing and validation:** Implemented checks for numeric values, range limits and duplicate detection before processing input.
- **Sorting under constraints:** Designed a sorting algorithm that respects the limited set of allowed operations. For small cases, used hand‑crafted sequences; for large cases, used median partitioning and greedy insertion based on cost calculations.
- **Ranking and indexing:** Assigned ranks and indices to each node to simplify comparisons and compute relative positions within a stack.
- **Cost evaluation:** Calculated the number of operations required to move each element from stack B back to stack A, including combined rotations to minimise total moves.
- **Modular programming:** Organised functionality into separate modules (error checking, list management, allocation, ranking, sorting, cost calculation and each operation), leading to clearer code.
- **Memory management:** Allocated and freed dynamic structures carefully to avoid leaks, including cleaning up on error conditions.
- **Library reuse:** Leveraged personal `libft` and `ft_printf` implementations for utility functions and formatted output.

## Implementation Notes

- The core data structure is `t_stack`, a linked‑list node containing the value (`content`), rank, index, cost and links to the next node. Cost fields track rotations and combined operations needed to insert the node into its target position.
- `push_swap.c` handles argument parsing, error checking and orchestrates the sorting procedure (`sort_stack_a`).
- `sort_stack_a` dispatches to specialised routines for lists of length 2 or 3, or to the general algorithm for larger lists. The general algorithm:
  - Calculates indices and assigns ranks to all nodes.
  - Pushes roughly half of the elements to stack B based on the median rank.
  - Sorts the remaining elements in stack A.
  - Finds the cheapest target in stack B to move back into stack A by computing the cost of possible moves (`find_target_and_calculate_cost` and `calculate_cost`).
  - Executes the chosen sequence of combined rotations and pushes (`execute_move`).
  - Continues until stack B is empty, then performs a final rotation to position the smallest element at the top.
- Operations are printed as they are performed; there is no additional user interface or debugging output.
- Uses `float` for computing medians and certain lengths; while adequate here, this introduces minor rounding considerations for large lists.

## Limitations / Notes

- Only the `push_swap` program is provided. There is no accompanying *checker* utility to verify the correctness of the output sequence.
- The program expects each integer as a separate argument; it does not support quoted strings containing multiple numbers.
- Error handling is minimal: invalid input or duplicates cause a generic `Error` message before exiting.
- The cost‑based algorithm is a heuristic aimed at reducing the number of operations; it may not always yield the absolute optimal solution, especially on very large or specially crafted sequences.
- Floating‑point arithmetic is used for median and cost calculations, which might not be precise for extremely large lists.
- The solution is written for Unix‑like environments. Building or running on other platforms may require adapting the build system or replacing `ft_printf` and `libft`.

## How to Build / Run

Compile the program and its dependencies using `make`. The `Makefile` also builds the `libft` and `ft_printf` subprojects.

```sh
git clone https://github.com/AlwIkigai/push_swap.git
cd push_swap
make

# Example: sort three numbers
./push_swap 2 1 3

# Example: sort a larger set of numbers
./push_swap 3 5 2 1 4
