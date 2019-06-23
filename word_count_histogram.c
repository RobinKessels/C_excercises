#include <stdio.h>
#include <stdlib.h>
#define LIMIT 10


/*
  Write a program to print a histogram of the lengths of words in its input.
*/
void print_histogram(int* lengths)
{
  for(int i = 0; i < LIMIT; ++i)
  {
    int l = *(lengths+i);
    if (l != 0)
    {
      printf("%d: ", i);
      for(int i = 0; i < l; ++i)
      {
        printf("%s", "#");
      }
      printf("\n");
    }
  }
}

int* word_counter(int* lengths)
{
  int c, length;
  // init lengths to 0
  length = 0;

  while((c  = getchar()) != EOF)
  {
    if(c == 'x') break;
    else if(c == ' ' || c == '\t' || c == '\n')
    {
      // we are out of word, up the counter of length and reset length
      ++(*(lengths + length));
      length = 0;
    }
    else
    {
      if(length < LIMIT - 1) { ++length; }
    }
  }
  return lengths;
}

void print_array(int* arr)
{
  for(int i = 0; i < LIMIT; ++i)
  {
    printf("%d", *arr);
    ++arr;
  }
  printf("\n");
}


int main()
{
  int* lengths = calloc(LIMIT, sizeof(int));
  word_counter(lengths);
  print_array(lengths);
  print_histogram(lengths);
  free(lengths);
}
