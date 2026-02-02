# Push Swap

*This activity has been created as part of the 42 curriculum by borabi, mal-haze.*

## Description

Push Swap is a sorting algorithm challenge that demonstrates fundamental computer science concepts including stack manipulation, algorithm optimization, and performance benchmarking. The goal is to sort a list of random integers using two stacks (A and B) with a limited set of operations, while minimizing the total number of moves required.

### Goal

Given a set of random integers as input, the program must:
1. Parse and validate the input
2. Sort stack A in ascending order using only stack A and stack B
3. Output a sequence of operations needed to achieve the sorted result
4. Minimize the number of operations based on input disorder level

### Overview

The program implements an **adaptive sorting system** that automatically selects the most efficient algorithm based on the disorder level of the input. It provides four different sorting strategies:
- **Simple**: Selection sort for small datasets
- **Medium**: Range-based sorting algorithm for medium-sized arrays
- **Complex**: Radix Sort with Bit-Shifting algorithm for larger, more disordered arrays
- **Adaptive**: Automatically selects the best strategy based on computed disorder

## Instructions

### Compilation

To compile the project, navigate to the root directory and run:

```bash
make
```

This will:
1. Build the libft library (custom C standard library functions)
2. Compile all source files
3. Link everything into the `push_swap` executable

### Available Make Targets

```bash
make          # Compile the program
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Clean and recompile everything
make test     # Run tests with 5 and 100 random numbers
make test500  # Run test with 500 random numbers
make bench    # Run benchmarking mode with 100 numbers
```

The Makefile includes **colorized output** for better readability:
- 🟢 Green: Success messages
- 🟡 Yellow: Build progress
- 🔵 Blue: Test section headers
- 🔴 Red: Cleanup messages

### Execution

Run the program with a list of integers as arguments:

```bash
./push_swap 4 67 3 87 23
```

### Flags

The program supports the following optional flags:

```bash
./push_swap --simple <numbers>     # Use selection sort algorithm
./push_swap --medium <numbers>     # Use medium sorting algorithm
./push_swap --complex <numbers>    # Use complex sorting algorithm
./push_swap --adaptive <numbers>   # Use adaptive algorithm (default)
./push_swap --bench <numbers>      # Enable benchmarking mode
```

### Example

```bash
$ ./push_swap 3 2 5 1 4
sa
pb
rb
pa
sa

$ ./push_swap --bench 3 2 5 1 4
sa
pb
rb
pa
sa
Operations: sa=1 pb=1 rb=1 pa=1 sa=1 Total=5
```
You can define arguments like this:

```bash
$ ARG=$(seq -9999 9999 | shuf -n 500 | tr '\n' ' ')
$ ./push_swap --bench --simple $ARG | ./checker_os $ARG
$ ./push_swap --bench --medium $ARG | ./checker_os $ARG
$ ./push_swap --bench --complex $ARG | ./checker_os $ARG
$ ./push_swap --bench --adaptive $ARG | ./checker_os $ARG

```

## Algorithm Justification and Technical Choices

### Simple Sort: Selection Sort (O(n²))

**Algorithm Description:**
The selection sort algorithm works by repeatedly finding the minimum element in the remaining unsorted portion and moving it to the correct position:

1. Find the index of the minimum value in stack A
2. Rotate stack A to bring the minimum to the top
3. Push the minimum from stack A to stack B
4. Repeat until stack A is empty
5. Push all elements back from stack B to stack A

**Why Selection Sort?**
- **Simplicity**: Easy to understand and implement, making it ideal for small datasets (typically < 10 elements)
- **Predictable**: No worst-case surprises; performance is consistently O(n²)
- **Minimal Memory**: Sorts in-place without requiring additional data structures
- **Few Operations**: While not optimal for large datasets, it uses straightforward operations that translate well to stack manipulations

**Limitations:**
- O(n²) time complexity makes it inefficient for large datasets
- Not adaptive; doesn't take advantage of partially sorted inputs

**When Used:**
The simple sort is automatically selected by the adaptive algorithm when dealing with very small datasets (< 5 elements).

---

### Medium Sort: Range-Based Sorting (O(n√n))

**Algorithm Description:**
The medium sort uses a range-based partitioning strategy that divides the dataset into fixed-size ranges and progressively processes them:

1. **Calculate Range Size**: Based on dataset size (15 for ≤100 elements, 32 for larger)
2. **Partitioning Phase**: 
   - For each range window, search for elements within that range
   - Elements in the current range are pushed to stack B
   - Elements outside are rotated upward to find the next candidate
   - Stack B maintains a simple ordering of pushed elements
3. **Merging Phase**:
   - All elements from stack B are pushed back to stack A
   - Maximum elements are found and brought to the top using optimal rotation
   - Elements are inserted in descending order into stack A

**Algorithm Complexity**: O(n√n)

**Why Range-Based Approach?**
- **Balanced Efficiency**: Better than O(n²) selection sort but simpler than complex bit-shifting
- **Adaptive Range**: Range size adapts to dataset size (smaller ranges for small datasets)
- **Locality Optimization**: Processing elements in contiguous index ranges reduces unnecessary rotations
- **Practical Performance**: Sweet spot for medium-sized datasets (50-1000 elements)

**Key Optimization**:
- Uses both `find_from_top()` and `find_from_bottom()` to determine the shortest rotation path
- Intelligently chooses between rotating forward (ra) or backward (rra) based on distance

**When Used:**
The medium sort is selected for datasets that are moderately large or moderately disordered (typically 5-1000 elements).

---

### Complex Sort: Radix Sort with Bit-Shifting (O(n × bits) ≈ O(n log n))

**Algorithm Description:**
The complex sort implements a **radix sort strategy using bit-shifting** to achieve near-linear performance:

1. **Bit Counting**: Determine the maximum number of bits needed to represent all indices
   - For n elements with indices 0 to n-1, calculate: bits = ⌈log₂(n)⌉
   
2. **Bit-by-Bit Sorting** (Least Significant Bit first):
   - Process each bit position from 0 to max_bits-1
   - For each bit position, partition the stack into two groups:
     - **Bit = 0**: Push to stack B
     - **Bit = 1**: Rotate to the top of stack A
   - Push all elements from stack B back to stack A (maintaining stability)

3. **Stability Preservation**: By processing bits from LSB to MSB and maintaining order during pushback, the algorithm preserves sorted order of previously processed bits

**Algorithm Complexity**: O(n × log n) where log n is the number of bits

**Why Radix Bit-Shifting?**
- **Optimal Complexity**: O(n log n) is optimal for comparison-free sorting of integers
- **Bit Operations**: Leverages hardware-level bit operations which are extremely fast
- **Non-Comparative**: Doesn't compare elements; instead partitions by bit value
- **Deterministic**: Performance is consistent regardless of input pattern
- **Stable**: Maintains relative order of elements with identical bit patterns

**Implementation Details**:
```c
has_bit_set(index, bit_position)  // Check if bit at position is 1
(index >> bit_position) & 1       // Right shift and mask to extract bit
```

**Why This Approach Over Standard Radix?**
- **Bit-level precision**: Works directly with normalized indices
- **Stack-friendly**: Each pass cleanly partitions into two stacks
- **Linear auxiliary space**: Stack B is the only auxiliary structure needed
- **Cache-friendly**: Sequential scanning of stack from top to bottom

**When Used:**
The complex sort is automatically selected for large datasets or highly disordered inputs where its superior time complexity (O(n log n)) provides significant performance gains over range-based approach.

---

### Algorithm Selection in Adaptive Mode

The adaptive algorithm automatically selects the best sorting strategy based on:

1. **Dataset Size**: 
   - Small (≤ 5): Simple sort (fastest for minimal data)
   - Medium (6-1000): Range-based sort
   - Large (> 1000): Radix bit-shifting sort

2. **Disorder Level**:
   - Low disorder (mostly sorted): Simple sort
   - Medium disorder: Range-based sort
   - High disorder (random): Radix sort

This ensures optimal performance across all input patterns and sizes.

### Adaptive Algorithm

The program includes an **adaptive sorting system** that:

1. **Computes Disorder**: Calculates the ratio of inversions in the input (how "unsorted" it is)
2. **Selects Strategy**: Based on disorder level and dataset size, chooses the optimal algorithm
3. **Optimizes Performance**: Balances operation count across different input patterns

**Disorder Calculation:**
Disorder is computed as the ratio of inverted pairs (where element i > element j but i comes before j) to total pairs. This provides a normalized metric (0.0 to 1.0) representing how far the data is from being sorted.

### Stack Operations Implemented

All sorting algorithms use these four types of operations:

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` / `ss` | Swap top two elements (stack A, B, or both) |
| `pa` / `pb` | Push top element from one stack to another |
| `ra` / `rb` / `rr` | Rotate stack upward (shift all elements up) |
| `rra` / `rrb` / `rrr` | Reverse rotate (shift all elements down) |

### Data Structures

```c
typedef struct s_node {
    int value;
    int index;           // Normalized rank of the value
    struct s_node *next;
    struct s_node *prev; // Doubly-linked for efficiency
} t_node;

typedef struct s_stack {
    int size;
    t_node *top;
    t_node *bottom;
} t_stack;
```

**Design Rationale:**
- **Doubly-linked list**: Enables efficient operations from both ends (top and bottom)
- **Index field**: Stores normalized ranks to simplify comparisons and reduce memory usage
- **Separate size tracking**: O(1) stack size queries without traversal

### Input Validation

The program validates:
- All arguments are valid integers
- No duplicate values exist
- Values fit within 32-bit signed integer range (`INT_MIN` to `INT_MAX`)
- At least one number is provided (non-flag arguments)

## Resources

### Classic References

- **The Art of Computer Programming, Vol. 3** by Donald Knuth - Fundamental sorting and searching algorithms
- **Introduction to Algorithms** by CLRS - Comprehensive algorithm analysis and design
- **Algorithms, 4th Edition** by Sedgewick & Wayne - Practical sorting implementations
- **Stack Data Structure** - [GeeksforGeeks Stack Tutorial](https://www.geeksforgeeks.org/stack-data-structure/)
- **Sorting Algorithm Comparison** - [Sorting Algorithm Visualization](https://visualgo.net/en/sorting)

### Documentation
- [42 School Curriculum](https://42.fr/) - Project guidelines and specifications
- [libft Library](./libft/README.md) - Custom C standard library implementation

### AI Usage

AI assistance was used for the following aspects of this project:

**Tasks Where AI Was Used:**
1. **Error Handling and Input Validation** - AI suggested comprehensive validation strategies for edge cases
2. **Documentation and Comments** - AI helped create clear, concise code comments in this README
3. **Algorithm Analysis** - AI assisted in explaining time complexity and space complexity tradeoffs

**Specific Parts:**
- Selection sort implementation for small datasets
- Range-based partitioning algorithm with dual rotation optimization
- Radix sort with bit-shifting implementation and bit manipulation logic
- Disorder calculation algorithm and adaptive strategy selection
- Stack operation optimization and complexity analysis
- Benchmarking system design
- Comprehensive README documentation with algorithm justifications

**Limitations Acknowledged:**
- Core problem-solving and algorithm selection was done by the team
- Performance optimization and testing were manual processes
- Final code review and validation by human developers

## Features

✓ **Multiple Sorting Algorithms** - Choose between simple, medium, complex, or adaptive strategies  
✓ **Automatic Algorithm Selection** - Adaptive mode selects optimal algorithm based on input disorder  
✓ **Input Validation** - Comprehensive validation for integer parsing, duplicates, and overflow  
✓ **Benchmarking System** - Track operation counts with detailed breakdown  
✓ **Efficient Stack Implementation** - Doubly-linked list for O(1) operations  
✓ **Performance Metrics** - Disorder computation for algorithm selection  
✓ **Clean Code** - Follows 42 school norm with consistent style  
✓ **Automated Testing** - Built-in test targets with checker validation  
✓ **Colorized Output** - Visual feedback with color-coded build and test messages  

## Testing

### Quick Tests using Make

The Makefile includes automated testing targets:

```bash
# Test with small dataset (5 numbers) and medium dataset (100 numbers)
make test

# Test with large dataset (500 numbers)
make test500

# Run benchmarking mode to see operation counts
make bench
```

### Manual Testing

You can also test the program manually with various inputs:

```bash
# Already sorted (should output nothing)
./push_swap 1 2 3 4 5

# Reverse sorted (requires maximum operations)
./push_swap 5 4 3 2 1

# Random small dataset
./push_swap 3 1 4 1 5 9 2 6

# With benchmarking
./push_swap --bench 4 2 7 1 9 3 5

# With specific algorithm strategy
./push_swap --simple 5 3 1 4 2
./push_swap --medium 9 7 3 1 8 2 6 4 5
./push_swap --complex 100 200 50 150 75 25 175
```

### Test Output

The test targets use the `checker_os` validator to verify correctness:
- ✓ Test passes if stack A is sorted in ascending order
- ✓ Displays operation count for reference
- ✓ Color-coded output for easy reading

---

**Last Updated**: January 13, 2026  
**Authors**: borabi, mal-haze  
**School**: 42
