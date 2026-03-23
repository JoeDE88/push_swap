***This project has been created as part of the 42 curriculum by gblas-he, jdiaz-ec.***
# PUSH SWAP
---
## DESCRIPTION

### push_swap is a program which calculates and displays on the standard output the smallest program, made of *push swap language* operations, that sorts the integers received as arguments.

## &emsp;The goals of this project are:

### &emsp;· To study and learn about algorithmic complexity.
### &emsp;· To choose the most adapt sort algorithms depending on the algorithm complexity.

## &emsp;The project is divided in two different parts:
### &emsp;· Parsing the input data, which can receive from 0 to 2 flags and an undefined number of integers.
### &emsp;· Sorting the integers using three different algorithms, based on the numbers of integers to be sorted, the disorder or by forcing the strategy selected in the input.

## About the algorithms:

### SELECTION SORT (--simple)
### Time complexity: &emsp;&emsp;`O(n²)`
### The O(N²) time complexity means that the running time of an algorithm grows quadratically with the size of the input. In the case of selection sort, there are two nested loops:
### &emsp;· One loop to select an element of the array one by one = O(n)
### &emsp;· Another loop to compare that element with every other array element = O(n)
### therefore, the overall complexity is: O(n) * O(n) = O(n²).
### Despite its time complexity of O(n²) - which makes it a slow algorithm - it can be considered one of the best quadratic algorithm to use for small datasets.
### &emsp;
### CHUNKS SORT (--medium)
### Time complexity: &emsp;&emsp;O(n√n)
### The O(n√n) time complexity indicates that the running time of an algorithm grows in proportion to `n` multiplied by the square root of `n`. It is slower than linear complexity `O(n)`, but faster than `O(n²)`, making it efficient for moderate input sizes, since nearly sorted chunks cost almost nothing.
&emsp;
### RADIX SORT (--complex)
### Time complexity: &emsp;`O(n log n)`
### The radix sort sorts a dataset by individual digits, starting with the least significant digit - the rightmost one.
### Instead of comparing numbers to each other, we simplify their values into contiguous indexes (0 to N). Then, we look at the binary representation of each index. Bit by bit (starting from the least significant bit), if the bit is 1, we rotate A (ra), if it's 0, we push to B (pb).
&emsp; 
## INSTRUCTIONS
### &emsp;  To compile the program:
```bash
make
```
This will generate push_swap.

### &emsp;  Additional rules:
```bash
make clean    # Remove object files
make fclean   # Remove object files and push_swap
make re       # Recompile everything
```
### &emsp;  To run the program:

```bash
./push_swap 47 16 63 18 29 -5 12
```
### &emsp;  To run the program AND pipe the output into the checker to see if the program correctly sorted the numbers:
```bash
./push_swap 47 16 63 18 29 -5 12 | ./checker_linux 47 16 63 18 29 -5 12
```

## RESOURCES

### The 42 peer-to-peer method was a huge helpful resource, The willingness of 42 students to help and support one another is truly amazing.
### Some other helpful resources were: stackoverflow.com, youtube.com, geekforgeeks.org
#### AI such as claude.ai was also a powerful resource when further explanations were needed to understand deeply and visually the different algorithms and time complexity differences.
#### No copy-paste was used while developping this project.