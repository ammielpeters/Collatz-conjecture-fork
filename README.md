# Collatz Conjecture using fork()

This project demonstrates the Collatz Conjecture sequence using **C** and the **fork() system call**.

## Problem
The Collatz conjecture applies the following rules to a positive integer `n`:
- If `n` is even → `n = n / 2`
- If `n` is odd  → `n = 3 * n + 1`

The sequence always reaches `1`.  
Example for `n = 35`:  

## Program Description
- The **child process** (created with `fork()`) generates and prints the Collatz sequence.  
- The **parent process** waits for the child to finish (`wait()`).  

## Compilation
```bash
gcc collatz.c -o collatz
