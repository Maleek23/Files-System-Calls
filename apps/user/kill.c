#include "app.h"
#include "../grass/process.h"

int main(int argc, char** argv) {
    int pid;
    if (argc != 2)
    {
        printf("usage: kill [pid]\n");
        return 1;
    }
    pid = (int)argv[1][0] - 48;
    kill(pid);
    return 0;

}