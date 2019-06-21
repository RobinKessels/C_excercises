#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
/* print Fahrenheit-Celsius table
  for fahr = 0, 20, ..., 300; */
void f_to_c()
{
  /*
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("%6s\t%7s", "celsius", "fahrenheit\n");
  while (fahr <= upper)
  {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%7.1f\t%10.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
*/
  float celsius;
  for (int i = UPPER; i >= LOWER; i = i - STEP)
  {
    celsius = (5.0/9.0) * (i-32.0);
    printf("%7d\t%10.1f\n", i, celsius);

  }

}

void c_to_f()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 100;
  step = 10;

  celsius = lower;
  printf("%6s\t%7s", "celsius", "fahrenheit\n");
  while (celsius <= upper)
  {
    fahr = (celsius * (9.0/5.0)) + 32.0;
    printf("%7.1f\t%10.1f\n", fahr, celsius);
    celsius = celsius + step;
  }
}


int main()
{
  f_to_c();
  printf("\n");
  c_to_f();
}
