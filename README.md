# Bitset Utility README

This program implements a bitset utility in C for handling arrays of bits efficiently. It provides functionalities for creating, manipulating, and freeing bitsets, along with operations like setting and getting individual bits.

## Features

- **Bitset Structure Definition**: Defines a data structure `bitset_t` for representing arrays of bits.
- **Macros for Bitset Operations**:
  - `bitset_create`: Creates and initializes a bitset.
  - `bitset_alloc`: Allocates memory dynamically for a bitset.
  - `bitset_free`: Frees dynamically allocated memory for a bitset.
  - `bitset_size`: Returns the size of the bitset in bits.
  - `bitset_fill`: Fills the entire bitset with a specified boolean value.
  - `bitset_setbit`: Sets the value of a specific bit in the bitset.
  - `bitset_getbit`: Retrieves the value of a specific bit in the bitset.
- **Error Handling**: Provides error handling functionalities using the `error.c` module.
- **Platform Compatibility**: Works on both 32-bit and 64-bit platforms.
- **Conditional Compilation**: Supports conditional compilation for defining inline functions (`USE_INLINE` symbol).
- **Efficient Memory Usage**: Utilizes memory efficiently by using an array of type `unsigned long []`.
- **Performance Testing**: Includes a test case for measuring the performance using the Eratosthenes sieve algorithm.

## Eratosthenes Sieve Algorithm

The program includes an implementation of the Eratosthenes sieve algorithm (`Eratosthenes` function) to compute prime numbers efficiently. It calculates the last 10 prime numbers within a range from 2 to 666,000,000.

## Building and Running

- **Compilation**: Use the provided `Makefile` to compile the program. Run `make` to compile both the main program and the error module.
- **Execution**: Run the compiled program, named `primes`, to execute the bitset utility. Use `./primes` followed by any additional options or arguments as needed.

## Performance Measurement

- The program includes functionality to measure the runtime using the `clock()` function. It calculates the elapsed time for executing the program and prints the result to `stderr`.
- Performance testing involves comparing the efficiency of implementations with and without inline functions.

## Limitations

- The program assumes UTF-8 encoded input source files.
- Local arrays might require increasing the stack size limit, which can be done using the `ulimit` command on UNIX systems.

## Files

- **bitset.h**: Header file containing the bitset interface definition.
- **bitset.c**: Source file implementing the bitset utility functions.
- **eratosthenes.c**: Source file implementing the Eratosthenes sieve algorithm.
- **error.h, error.c**: Header and source files providing error handling functionalities.
- **primes.c**: Main program implementing the bitset utility and performance testing.
- **Makefile**: Makefile for compiling and running the program.

## Usage

1. **Compile**: Run `make` to compile the program.
2. **Execute**: Run `./primes` followed by any additional options or arguments.
