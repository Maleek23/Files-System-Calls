#pragma once

#include <stddef.h>
#include "elf.h"
#include "disk.h"
#define MAX_NPROCESS 16 


struct process{
    int pid;
    int status;
    int receiver_pid; /* used when waiting to send a message */
    void *sp, *mepc;  /* process context = stack pointer (sp)
                       * + machine exception program counter (mepc) */
    /* Student's code goes here to add to the process control block (priority / scheduler)*/
    int priority;
    int contextSwitchNum;
    long long creaTime;
};

struct process proc_set[MAX_NPROCESS]; 

extern struct process proc_set[MAX_NPROCESS];

enum {
    PROC_UNUSED,
    PROC_LOADING, /* allocated and wait for loading elf binary */
    PROC_READY,   /* finished loading elf and wait for first running */
    PROC_RUNNING,
    PROC_RUNNABLE,
    PROC_WAIT_TO_SEND,
    PROC_WAIT_TO_RECV
};

extern int proc_curr_idx;

#define curr_pid      proc_set[proc_curr_idx].pid
#define curr_status   proc_set[proc_curr_idx].status

void timer_init();
void timer_reset();
long long mtime_get();

void proc_init();
int  proc_alloc();
void proc_free(int);
void proc_set_ready (int);
void proc_set_running (int);
void proc_set_runnable (int);
int  proc_get_pid( );
int  proc_kill( int pid );
int  proc_set_priority( int pid, int priority);
struct process * proc_get_proc_set( );

void ctx_entry(void);
void ctx_start(void** old_sp, void* new_sp);
void ctx_switch(void** old_sp, void* new_sp);
