#include <unistd.h>
void ft_putnbr(char *str)
{
    while (*str != ':')
        str++;
    str++;
    while (*str == ' ')
        str++;
    while (*str != '\n')
        write(1, str++, 1);
}

int main(int argc, char const *argv[])
{
    ft_putnbr("13: thirteen\n14: fourteen\n15: fifteen\n16: sixteen\n17: seventeen\n18: eighteen\n19: nineteen\n20: twenty\n30: thirty\n40: forty\n50: fifty\n60: sixty\n70: seventy\n80: eighty\n90: ninety\n100: hundred\n1000: thousand\n1000000: million\n1000000000: billion\n1000000000000: trillion\n1000000000000000: quadrillion\n1000000000000000000: quintillion\n1000000000000000000000: sextillion\n1000000000000000000000000: septillion\n1000000000000000000000000000: octillion\n1000000000000000000000000000000: nonillion\n1000000000000000000000000000000000: decillion\n1000000000000000000000000000000000000: undecillion\n");
    return 0;
}
