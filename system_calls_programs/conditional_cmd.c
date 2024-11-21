#include<stdio.h>
#include<stdlib.h>
#ifdef DEBUG
    printf("hello\n");
#else
    exit(0);
#endif

