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
        i = 0;
        while (i  < 8)
        {
            result = message[index]  >> i & 1;
            if (result == 0)
                 kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            usleep(100);
            i++;
        }
        index++;

    }
   
    
}

int validate_pid(char *p)
{
    pid_t   pid;
    

    pid =  atoi(p);
    if (p == NULL || pid == 0)
    {
        ft_putstr("invalid pid\n");
        exit(1);
    }
    while (*p)
    {
        if (*p < '0' || *p > '9')
        {
            ft_putstr("invalid pid\n");
            print_usage();
            exit(0);
        }
        p++;
    }
    return pid;
}

void send_terminator(int pid)
{
    int i;

    i = 0;
    while(i < 8)
    {
        kill(pid, SIGUSR2);
        usleep(100);
        i++;
    }
}

int     main(int argc , char **argv)
{
    int pid;
    char *mypid;

    if (argc == 3)
    {
       pid =  validate_pid(argv[1]);
       mypid = ft_itoa(getpid());
       convert_and_send(pid, mypid);
       free(mypid);
       convert_and_send(pid, "\n");
       convert_and_send(pid , argv[2]);
       send_terminator(pid);
       ft_putstr("message recieved 😃\n");
    }
    else
    {
        print_usage();
        exit(1);
    }
    exit(0);
}