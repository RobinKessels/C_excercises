#include <stdio.h>
#include <string.h>
#define STRING_LIMIT 1000

void reverse(char string[]);
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

void reverse(char string[])
{
  long len;
  char reversed_string[STRING_LIMIT];
  len = strlen(string)-1; // characters before the null terminator '\0'

  for(int i = len; i >= 0; --i)
  {
    reversed_string[len - i] = string[i];
  }

  for(int i = 0; i <= len; ++i)
  {
    string[i] = reversed_string[i];
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

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
