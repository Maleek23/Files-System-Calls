# Assignment 1: System Calls and libc

For this assignment you will be making modifications to the egos-2000 operating system.  You will be implementing a new system call, a new libc function and a few assorted utility programs.

You may complete this assignment in groups of up to two people. If you wish to be in a group you must add your group to the spreadsheet linked in the Canvas assignment no later than 09/20/23 at at 11:59pm. 

## Requirements

### Default priority
All processes must start with a default priority of 2, except for the four kernel processes. The kernel processes start with a priority of 1.

### Implement setprio system call
Implement the setprio system call to allow processes to set their priority. The priority must be between 1 and 10.  

### Process control blocks
To the process control block add:
1. Priority, an integer from 1 to 10
2. The time the process was created
3. Number of context switches, an integer representing the nunmber of times a process is scheduled to be run by the scheduler

### kill system call

Add a system call, kill, that takes a PID as a command line parameter and kills the process that has the user supplied PID.  You will need to add a new type of proc_req: PROC_KILL and the associated code in servers.c and sys_proc.c

### kill application

Add a user application kill.c that takes a PID as a command line parameter and kills the process that has the user supplied PID.

You will need edit tools/mkfs.c to add your new executable to disk image.  

### ps 
Add functionality to the ps command in ps.c to display:
1. Process priority
2. Number of context switches

```shell
➜ /home/cse3320 ps
PID     STATUS  PRIORITY  CTX
1       11      1         50    
2       5       2         23
3       4       1         49
4       4       3         12
6       4       2         19
......
```
