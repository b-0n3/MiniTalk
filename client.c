#include "minitalk.h"
#include <stdio.h>

void    print_usage()
{
    ft_putstr("usage: \n");
    ft_putstr("\t ./client <PID> <MESSGE>");
}

void    convert_and_send(int pid, char *message)
{
    int index;
    int i;
    int result;

    index = 0;
    while (message[index] !='\0')
    {
        i = 7;
        while (i  >= 0)
        {
            result = message[index]  >> i & 1;
            printf("%d", result);
            if (result == 0)
                 kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            usleep(100);
            i--;
        }
        index++;

    }
   
    
}

int     main(int argc , char **argv)
{
    int pid;

    if (argc == 3)
    {
        pid = atoi(argv[1]);
        convert_and_send(pid , argv[2]);
    }
    else
    {
        print_usage();
        exit(1);
    }
    exit(0);
}