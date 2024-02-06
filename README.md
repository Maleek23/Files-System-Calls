Here is an improved README for your RTOS assignment repository:

# RTOS Assignment 1: System Calls and libc

This repository contains my implementation of system calls and libc functions for an RTOS assignment. The goal is to help students understand key concepts in operating systems by implementing essential components from scratch.

## Overview

This assignment involves making modifications to the egos-2000 teaching operating system. I have implemented:

- A new `setprio` system call to set process priority
- Process control blocks to track priority, creation time, and context switches  
- A `kill` system call and application to terminate processes by PID
- Enhanced `ps` command to display process details

## Documentation

The `README.md` provides an overview of the project. More detailed documentation can be found here:

- [Assignment requirements](ASSIGNMENT.md)
- [Development journal](JOURNAL.md) - describes approach and challenges
- [Code documentation](docs/README.md) - documents key functions and data structures

## Getting Started

The code can be built and run using:

```bash
make
make qemu
```

Output will be visible in the QEMU window.

## Contributions

This was developed by [John Doe](https://github.com/john_doe) as part of a systems class. Feel free to submit issues and pull requests!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


