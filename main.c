#include <stdio.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char * line);

int main(){

  char command[] = "ls -a -l"; //command
  char ** args = parse_args(command); //get array of commands
  execvp(args[0], args); //execute commands

  return 0;
}

//parses a string command and puts the parts into a 2D array
char ** parse_args(char * line){
  char **args;
  char *token, *p = line;
  int i=0;

  while (p){
    token = strsep(&p, " "); //separate string on first delimiter
    args[i++]=token; //add separated part to the array
  }

  args[i]=NULL; //last arg must be NULL
  return args;
}
