/*
 * (C) 2022, Cornell University
 * All rights reserved.
 */

/* Author: Yunhao Zhang
 * Description: helper functions for managing processes
 */

#include "egos.h"
#include "process.h"
#include "syscall.h"
//#include <string.h>
//#include <stdlib.h>
#define MAX_APP_PID 200
#define SYSCALL_EXCP 1
#define INIT_PID 1
#define PMP_RWX 0x7  // Example bitmask for read, write, and execute permissions
#define PMP_RX 0x5   // Example bitmask for read and execute permissions
#define PMP_R 0x4    // Example bitmask for read-only permissions
#define PMP_RW 0x6   // Example bitmask for read and write permissions

void handle_syscall();
void kill_proc(int);
void set_pmp_tor(int, uint32_t, int);
void set_pmp_napot(int, uint32_t, uint32_t, int);
void proc_set_status(int, int);

void intr_entry(int id);

void excp_entry(int id) {
    /* Student's code goes here (handle memory exception). */

    FATAL("excp_entry: kernel got exception %d", id);
}

void proc_init() {
    earth->intr_register(intr_entry);
    earth->excp_register(excp_entry);

  /* Student's code goes here (PMP memory protection). */


  // TOR region for entire lower half memory - rwx


  // NAPOT region 1 for peripheral regs - r-x
  

  // NAPOT region 2 for kernel memory - r--


  // NAPOT region 3 for UART regs - rw-

  proc_set_running(proc_alloc());
}

void proc_set_status(int pid, int status) {
    for (int i = 0; i < MAX_NPROCESS; i++)
        if (proc_set[i].pid == pid) proc_set[i].status = status;
}

int proc_alloc() {
    static int proc_nprocs = 0;
    for (int i = 0; i < MAX_NPROCESS; i++)
        if (proc_set[i].status == PROC_UNUSED) {
            proc_set[i].pid = ++proc_nprocs;
            proc_set[i].status = PROC_LOADING;
            return proc_nprocs;
        }

    FATAL("proc_alloc: reach the limit of %d processes", MAX_NPROCESS);
}

void proc_free(int pid) {
    if (pid != -1) {
        earth->mmu_free(pid);
        proc_set_status(pid, PROC_UNUSED);
        return;
    }

    /* Free all user applications */
    for (int i = 0; i < MAX_NPROCESS; i++)
        if (proc_set[i].pid >= GPID_USER_START &&
            proc_set[i].status != PROC_UNUSED) {
            earth->mmu_free(proc_set[i].pid);
            proc_set[i].status = PROC_UNUSED;
        }
}

void proc_set_ready(int pid) { proc_set_status(pid, PROC_READY); }
void proc_set_running(int pid) { proc_set_status(pid, PROC_RUNNING); }
void proc_set_runnable(int pid) { proc_set_status(pid, PROC_RUNNABLE); }
int  proc_get_pid( ){ return curr_pid; }
struct process * proc_get_proc_set( ){ return &proc_set[0];}

int proc_set_priority(int pid, int priority)
{
    int i;

    printf("setting %d to  %d\n", pid, priority);
    for (int i=0;i<MAX_NPROCESS;i++)
    {
        if (proc_set[i].pid==pid)
        {
            printf("setting %d to piority %d\n", pid, priority);
            proc_set[i].priority = priority;
            return 0;
        }
    }
    return 1;
}


int proc_kill(int pid)
{
    proc_set_priority(pid, 0);
    return 1;
}
