*This project has been created as part of the 42 curriculum by azidouh*

# push_swap

## Description
**push_swap** is a 42 School algorithmic project. The goal is to sort a list of integers using **two stacks** (`a` and `b`) and a **limited set of operations**, while producing the **smallest possible number of moves**.

Your program:
- takes integers as command-line arguments,
- builds **stack `a`** from them (stack `b` starts empty),
- prints to **stdout** a sequence of operations (one per line) that sorts `a` in **ascending** order.

This project emphasizes:
- parsing and validating input,
- choosing an efficient sorting strategy under constraints,
- optimizing the number of operations.

---

## Instructions

### Requirements
- `gcc` (or `clang`)
- `make`

### Compile
```bash
make
```

Useful Makefile targets:
```bash
make        # build push_swap
make clean  # remove object files
make fclean # remove objects + executable
make re     # full rebuild
```

### Run
```bash
./push_swap <int1> <int2> ... <intN>
```

Example:
```bash
./push_swap 3 2 1
```

### Count the number of moves
```bash
./push_swap 3 2 1 | wc -l
```

### Check correctness (with 42 checker)
If you have a compatible checker binary (this repo includes `checker_linux`):
```bash
./push_swap 3 2 1 | ./checker_linux 3 2 1
```
Expected output: `OK` (or `KO` if not sorted).

---

## Allowed operations
The only instructions that can be printed are:

| Instruction | Effect |
|------------|--------|
| `sa` | swap the first 2 elements of stack `a` |
| `sb` | swap the first 2 elements of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | push top of `b` onto `a` |
| `pb` | push top of `a` onto `b` |
| `ra` | rotate `a` up (first becomes last) |
| `rb` | rotate `b` up (first becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | reverse rotate `a` (last becomes first) |
| `rrb` | reverse rotate `b` (last becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

---

## Notes / expected behavior
- Input must be valid integers (within `int` range).
- Duplicates are not allowed.
- On invalid input, the program should output `Error` to stderr and exit.
- If the input is already sorted, the program should ideally print nothing.

---

## Resources

### Classic references (push_swap / algorithms)
- Big-O / complexity refresher: https://www.bigocheatsheet.com/
- Sorting algorithms overview: https://en.wikipedia.org/wiki/Sorting_algorithm
- Stack operations / permutations concepts: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

### How AI was used (required)
AI was used for:
- **Documentation writing**: structuring and drafting this `README.md` according to 42 requirements.
- **Algorithm understanding**: understanding the chunks algorithm.


