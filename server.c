#include "minitalk.h"
/// 0000001  << 

unsigned char rev_bits(unsigned char nb)
{
   
    nb = ~nb;
    unsigned char rev = 0;
     
    // traversing bits of 'n' from the right
    while (nb > 0)
    {
        // bitwise left shift
        // 'rev' by 1
        rev <<= 1;
         
        // if current bit is '1'
        if ((nb & 1) == 1)
            rev ^= 1;
         
        // bitwise right shift
        // 'n' by 1
        nb >>= 1;
             
    }
     
    // required number
    return rev;
}

void sig_handler(int sig)
{
    static unsigned char resutl;
    static int power ;
  

    resutl += (sig  ==  SIGUSR1)  << power ;
    power++;
    if (power  > 7)
    {
      
         resutl =  rev_bits(resutl);
        ft_putchar(resutl);
        resutl = 0;
        power = 0;
    }
    
}

int main()
{
    const  int pid = getpid();

    ft_putstr("SERVER PID: ");
    ft_putnbr(pid);
    ft_putchar('\n');
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    while(1)
        pause();
}