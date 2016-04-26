//interpret.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cmdSet{
  char *str;
  int pointer;
};

char *read_string(){
  int size=4;
  int cur=0;
  char *store=malloc((size+1)*sizeof(char));
  while(1){
    char ch=getchar();
    if(ch==EOF){
      *(store+cur)='\0';
      break;
    }
    if(cur==size-1){
      size*=2;
      store=realloc(store,(size+1)*sizeof(char));
    }
    *(store+cur)=ch;
    cur+=1;
  }
  int len=strlen(store);
  store=realloc(store,(len+1)*sizeof(char));
  return store;
}

struct cmdSet *make_cmd(char *strings){
  struct cmdSet *ret=malloc(sizeof(struct cmdSet));
  ret->str=strings;
  ret->pointer=0;
}

