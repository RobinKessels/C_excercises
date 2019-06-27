#include <stdio.h>
#include <string.h>
#define ARR_SIZE 1000

/*
  Excercise 1-23
  Write a program to remove all comments from a C program.
  Don't forget to handle quoted strings and character constants properly.
  C comments do not nest.
*/

void remove_comments();
void append(char* str, char c);

int main()
{
  remove_comments();
  return 0;
}

void remove_comments()
{
  char code[ARR_SIZE];
  int c, nextchar;
  code[0] = '\0';
  nextchar = '0';
  while((c = getchar()) != EOF)
  {
    if(c == '\'')
    {
      append(code, c);
      while((c = getchar()) != EOF)
      {
        append(code, c);
        if(c == '\'')
        {
          break;
        }
      }
    }
    else if(c == ('\"'))
    {
      append(code, c);
      while((c = getchar()) != EOF)
      {
        append(code, c);
        if(c == '\"')
        {
          break;
        }
      }
    }
    else if(c == '/')
    {
      nextchar = getchar();
      if(nextchar != EOF && nextchar == '/') // line comment
      {
        while((c = getchar()) != EOF)
        {
          if(c == '\n')
          {
            break;
          }
        }
      }
      else if(nextchar != EOF && nextchar == '*') // line comment
      {
        while((c = getchar()) != EOF)
        {
          nextchar = getchar();
          if(nextchar != EOF && c == '*' && nextchar == '/')
          {
            break;
          }
        }
      }
    }
    else
    {
      append(code, c);
    }
  }
  printf("%s", code);
}

void append(char* str, char c)
{
  int len = strlen(str);
  str[len] = c;
  str[len+1] = '\0';
}
