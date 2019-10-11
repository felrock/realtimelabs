#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <task.h>
#include <task.c>

int buffer;
int v1, v2;

void f1(void* args);
void f2(void* args);

void f3(void* args);
void f4(void* args);

void taskmain(int argc, char** argv);

void f1(void* args)
{
    Channel *c;
    c = args;
    v1 = 1;

    assert(v1 == v2);
    printf("test one complete!\n");
	taskcreate(f2, c, 32768);
    taskswitch();
    while(1){}
}

void f2(void* args)
{
    Channel *c;
   
    v2 = 0;
    assert(v1 != v2);
    print("test two  complete!\n");
    v1 = 1337;
    c = chancreate(sizeof(int), buffer);
	taskcreate(f3, c, 32768);
    c = chancreate(sizeof(int), buffer);
	taskcreate(f4, c, 32768);
    taskswitch();

    while(1){}
}

void f3(void* args)
{
    assert(v1 == 1337);
    printf("test three complete!\n");
    v1 = 7331;
    taskswitch();
    while(1){}
}

void f4(void* args)
{
    assert(v1 == 7331);
    printf("test four complete!\n");
    printf("All tests were completed!\n");
    taskexitall(0);
    while(1){}
}


void
taskmain(int argc, char **argv)
{
	Channel *c;
    
    v1 = 0;
    v2 = 1;
    
	c = chancreate(sizeof(int), buffer);
	taskcreate(f1, c, 32768);
    taskswitch();
    printf("done\n");
    while(1){}
}
