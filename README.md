# push_swap

*This project has been created as part of the 42 curriculum by mchakir.*

# Push_swap

## Description

`Push_swap` is an algorithm-focused project where the objective is to sort a sequence of integers using two stacks (Stack A and Stack B) and a restricted set of operations.

The purpose of this project is to deepen understanding of algorithmic complexity and sorting strategies. Unlike traditional sorting methods (such as Bubble Sort) that directly swap elements inside an array, this project requires manipulating linked stack structures through specific operations like `push`, `swap`, and `rotate`. The real difficulty is not only sorting correctly, but doing so with the smallest possible number of operations in order to meet strict evaluation limits.

## Instructions

A `Makefile` is included to compile all source files (parsing, stack handling, and sorting logic) into an executable named `push_swap`.

### Compilation

To build the project, run the following command in the root directory:

```Bash
make
```

### Usage Example

Execute the program by passing a list of integers as arguments. The program will print the sequence of operations needed to sort them.

```bash
# Example
./push_swap 2 1 3 6 5 8

# Output:
# sa
# pb
# pb
# ...
```

You may also provide the numbers as a single quoted string:

```Bash
./push_swap "2 1 3 6 5 8"
```

To confirm that the output correctly sorts the numbers, you can pipe it into the checker:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
# Should print "OK" I hope...
```

## Resources

Below are some references that helped me during the development of this project:

### Youtube Videos & Guides:

* **Radix Sort Algorithm Introduction in 5 Minutes:** https://www.youtube.com/watch?v=XiuSW_mEn7g
* **Gitbook Guide by Laendrun** https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line

### AI Usage:

- Used Google Gemini's Guided Reading functionality to simulate the evaluation defense, and break down the bitwise logic required for Radix Sort.
- Used Google Gemini to help structure and format the README into a legible markdown format.


## Algorithm Explanation & Justification

Although approaches like Turk or Chunk-based sorting are known to achieve better performance (especially for bonus requirements), I chose to implement Radix Sort. It may not be the most optimized strategy, but it is reliable, structured, and simpler to implement correctly.

### The Algorithm Steps:

**Step 1: Indexing**

* Radix sort relies on bitwise operations, which work best on a continuous range of positive integers.
* I assign a "Rank" (index) to every number in the stack based on its value. The smallest number gets `index 0`, the next `index 1`, and so on.
* This simplifies the problem: no matter if the input is `{-1000, 2, 50}` or `{0, 1, 2}`, the algorithm treats them exactly the same.

**Step 2: Bitwise Radix Sort**

* I sort the numbers by processing their binary representation bit by bit, from the Least Significant Bit (LSB) to the Most Significant Bit (MSB).
* **The Loop:** For each bit position `i`:
* I iterate through the entire Stack A.
* If the number's index has a `0` at bit `i`, I push it to Stack B (`pb`).
* If it has a `1`, I rotate Stack A (`ra`) to keep it there.


* After checking all numbers, I push everything back from B to A (`pa`).
* This process repeats until the most significant bit is processed.

**Step 3: Tiny Sorts (Hardcoded)**

* Radix sort is overkill for very small lists (3-5 numbers).
* For these cases, I hardcoded a simple logic (finding the min/max and rotating) to ensure I pass the strict "maximum 12 operations" limit for 5 numbers.

---