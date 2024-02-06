#include "app.h"
#include "../grass/process.h"

int main(int argc, char** argv) {
  int i;
  struct process* process_table = grass->proc_get_proc_set();
  printf("PID\tSTATUS\tPRIORITY\tCTX");
  for(i = 0; i < MAX_NPROCESS; i++) {
    if(process_table[i].pid > 0) 
    {
      int priority = process_table[i].priority;
      int ctx_switches = process_table[i].contextSwitchNum;
      printf("%d\t%d\t%d\t%d", process_table[i].pid, process_table[i].status, priority, ctx_switches);
    }
  }
  return 0;
}