# Operating System (RTOS) Project 

Welcome to my  Operating System  project repository! This repository showcases my implementation of system calls and libc functions tailored for a real-world application in an educational setting. Designed to deepen students' understanding of operating systems, this project encompasses essential components developed from scratch within the context of the egos-2000 teaching operating system.
![Screenshot of egos-2000](references/screenshots/egos-2000.jpg)

## Project Highlights

- **Innovative System Calls**: Implemented a new `setprio` system call to manage process priorities effectively, enriching the system's functionality.
  
- **Process Management**: Developed process control blocks to meticulously track crucial process attributes such as priority, creation time, and context switches.
  
- **Enhanced Process Control**: Introduced a `kill` system call and corresponding application to facilitate graceful process termination by PID, enhancing system stability and management.
  
- **Improved Monitoring**: Enhanced the `ps` command to provide comprehensive insights into process details, aiding in system monitoring and analysis.

## Documentation and Resources

To delve deeper into this project, explore the following resources:

- **Assignment Requirements**: Detailed instructions and specifications are available in the [ASSIGNMENT.md](ASSIGNMENT.md) file.
  
- **Development Journal**: Gain insights into my development process, strategies, and challenges by referring to the [JOURNAL.md](JOURNAL.md) file.
  
- **Code Documentation**: Dive into the intricacies of key functions and data structures through the comprehensive documentation available in the [docs/README.md](docs/README.md) file.

## Getting Started

You can quickly build and run the project using the provided commands:

```bash
make
make qemu
```

Watch the system in action within the QEMU window.

## Contributions and Feedback

This project was spearheaded by [John Doe](https://github.com/john_doe) as part of a systems class. I welcome contributions, feedback, and suggestions for further enhancements. Feel free to submit issues or pull requests to enrich this repository further!

## Vision and Impact

This project aspires to democratize access to operating system knowledge, making it accessible and comprehensible to every college student. With the lightweight and educational egos-2000 operating system, students can explore the intricacies of OS design and implementation firsthand. By fostering a deeper understanding of OS principles, this project aims to empower future generations of developers and engineers.

## Acknowledgments

I extend my gratitude to esteemed educators and mentors, including [Robbert van Renesse](https://www.cs.cornell.edu/home/rvr/), [Lorenzo Alvisi](https://www.cs.cornell.edu/lorenzo/), [Shan Lu](https://people.cs.uchicago.edu/~shanlu/), and [Hakim Weatherspoon](https://www.cs.cornell.edu/~hweather/), for their invaluable support and guidance throughout this endeavor. Special thanks to Meta for their support through the [Meta Fellowship](https://research.facebook.com/fellows/zhang-yunhao/). I also express my appreciation to all the students who have contributed to and improved this project over the years.

## License

This project is licensed under the MIT License. For more details, refer to the [LICENSE](LICENSE) file.




