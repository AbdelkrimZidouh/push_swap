*This project has been created as part of the 42 curriculum by AbdelkrimZidouh*

# push_swap

**push_swap** is a sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a restricted set of operations, with as few moves as possible.

## Table of Contents

- [About the Project](#about-the-project)
- [Operations](#operations)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Further Reading](#further-reading)

## About the Project

Given a list of integers as arguments, `push_swap` outputs to stdout the list of instructions needed to sort stack `a` in ascending order using the fewest possible operations.

Two stacks are available:
- **Stack a** — initially contains the unsorted input integers.
- **Stack b** — initially empty; used as temporary storage.

## Operations

| Instruction | Description |
|-------------|-------------|
| `sa` | Swap the first 2 elements of stack a |
| `sb` | Swap the first 2 elements of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top element of stack b onto stack a |
| `pb` | Push the top element of stack a onto stack b |
| `ra` | Rotate stack a upward (first element becomes last) |
| `rb` | Rotate stack b upward (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack a (last element becomes first) |
| `rrb` | Reverse rotate stack b (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## Getting Started

### Prerequisites

- A C compiler (e.g. `gcc` or `clang`)
- `make`

### Building

```bash
git clone https://github.com/AbdelkrimZidouh/push_swap.git
cd push_swap
make
```

This produces the `push_swap` executable.

## Usage

```bash
./push_swap <integer1> <integer2> ... <integerN>
```

**Example:**

```bash
./push_swap 3 1 4 1 5 9 2 6
```

The program prints the sequence of instructions to sort the stack, one per line.

To count the number of moves:

```bash
./push_swap 3 1 4 1 5 9 2 6 | wc -l
```

To verify correctness using the provided checker:

```bash
./push_swap 3 1 4 1 5 9 2 6 | ./checker_linux 3 1 4 1 5 9 2 6
```

## Further Reading

- [42 push_swap subject (en.subject.pdf)](en.subject.pdf)
- [Wikipedia — Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Turk algorithm explanation](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
