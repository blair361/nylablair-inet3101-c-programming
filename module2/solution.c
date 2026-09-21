/* binary.c -- prints integer in binary form */
#include <stdio.h>
void to_base_n(unsigned long n, int base);
void print_digits(unsigned long n, int base);

int main(void)
{
	unsigned long number;
  int base;
	printf("Enter an integer and a base from 2-16, or q to quit:\n");
	while (scanf("%lu %d", &number, &base) == 2)
	{
		to_base_n(number , base);
		putchar('\n');
		printf("Enter an integer and a base from 2-16, or q to quit:\n");
	}
	printf("Done.\n");
	
	return 0;
}

void to_base_n(unsigned long n, int base) 
{
  if (base<2 || base>16)
  {
    printf("Error: base needs to be between 2 and 16");
    return;
  }
  if (base == 8)
    printf("0");
  if (base == 16)
    printf("0x");
  print_digits(n, base);
  
}

void print_digits(unsigned long n, int base) 
{
  const char *symbols = "0123456789!@#$%^";
  int r;
  r = n % base;
  if (n >= base)
    print_digits(n / base, base);
  putchar(symbols[r]);
}
