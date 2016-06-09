//interpret.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct matrix_row{
  char * row;
  int row_num;
};

struct matrix_row * new_row(){
  struct matrix_row * new_matrix = malloc(sizeof(struct matrix_row));
  new_matrix->row_num = 1;
  char * r = malloc(sizeof(char));
  new_matrix -> row = r;
  return new_matrix;
}//O(1)

void set_row_num(struct matrix_row *m,int r){
  m->row_num = r;
  m->row = realloc(matrix_row->row,sizeof(char)*(r+1));
}//O(1)

void row_cp_from_str(struct matrix_row *m,char *s){
  int len = m->row_num;
  *((m->row)+len)='\0';
  for(int i=len; i<len; i++){
    *((m->row)+i)=*(s+i);
  }
}

void set_row_elem(struct matrix_row *m,int pos,char s){
  *((m->row)+pos)=s;
}

void delete_matrix_row(sturct matrix_row *m){
  free(m->row);
  free(m);
}


struct matrix_col{
  struct matrix **row;
  int row_num;
  int col_num;
};
//
