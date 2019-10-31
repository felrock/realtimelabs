#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <task.h>

int buffer;
int goal;

void printtask(void* args)
{
	int i;
    Channel *c, *nc;
    c = args;
    
    i = chanrecvul(c);
    if(i > goal)
        taskexitall(0);
    printf("num: %i\n", i);
    nc = chancreate(sizeof(int), buffer);
    taskcreate(printtask, nc, 32768);
    i += 1;
    while(1){
        chansendul(nc, i);
    }
}

void
taskmain(int argc, char **argv)
{
	Channel *c;

	if(argc>1)
		goal = atoi(argv[1]);
	else
		goal = 100;

	c = chancreate(sizeof(int), buffer);
	taskcreate(printtask, c, 32768);
    while(1)
	    chansendul(c, 0);
}
