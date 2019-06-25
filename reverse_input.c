#include <stdio.h>
#include <string.h>
#define STRING_LIMIT 1000

void reverse(char str[]);
void reverse_by_line();
void append(char* s, char c);

/*
  Write a function reverse(s) that reverses the character string s.
  Use it to write a program that reverses its input a line at a time.
*/
int main()
{
  reverse_by_line();
}

void reverse(char str[])
{
  long len;
  char reversed_str[STRING_LIMIT];
  len = strlen(str)-1; // characters before the null terminator '\0'

  for(int i = len; i >= 0; --i)
  {
    reversed_str[len - i] = str[i];
  }

  for(int i = 0; i <= len; ++i)
  {
    str[i] = reversed_str[i];
  }
}

void reverse_by_line()
{
  int c;
  char current_line[STRING_LIMIT];
  char paragraph[STRING_LIMIT];

  while((c = getchar()) != EOF)
  {
    append(current_line, c);
    if(c == '\n')
    {
      reverse(current_line);
      strcat(paragraph, current_line);
      current_line[0] = '\0';
    }
  }
  printf("%s\n", paragraph);
}

void append(char* str, char c)
{
        int len = strlen(str);
        str[len] = c;
        str[len+1] = '\0';
}
