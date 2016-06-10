//interpret.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct matrix_row{
  char * row;
  int row_len;
  int size;
};

//a matrix formed by rows
struct matrix{
  struct matrix_row **row;
  int size;
  int row_len;
  int row_count;
};

// row fucntions
//create a new empty row
struct matrix_row * new_row(){
  struct matrix_row * n = malloc(sizeof(struct matrix_row));
  n->row_len = 1;
  n->size = 1;
  char * r = malloc(sizeof(char));
  n -> row = r;
  return n;
}//O(1)

//set the length of a row
void set_row_len(struct matrix_row *m,int r){
  m->row_len = r;
  m->row = realloc(matrix_row->row,sizeof(char)*(r+1));
}//O(1)

//copy a string to a row
void row_cp_from_str(struct matrix_row *m,char *s){
  int len = m->row_len;
  *((m->row)+len)='\0';
  for(int i=len; i<len; i++){
    *((m->row)+i)=*(s+i);
  }
}

//set the pos elem in m to be s
void set_row_elem(struct matrix_row *m,int pos,char s){
  *((m->row)+pos)=s;
}

//delete a row
void delete_matrix_row(sturct matrix_row *m){
  free(m->row);
  free(m);
}

// Matrix Functions
//create an empty new matrix
struct matrix *new_matrix(){
  struct matrix *m=malloc(sizeof(matrix_col));
  m->size = 1;
  struct matrix ** r = malloc(sizeof(matrix *));
  m->row = r;
  m->row_len=1;
  m->row_count=1;
  return m;
}

//form a matrix from an array of rows each with length of len
struct matrix *make_matrix_from_array(struct matrix_row ** rows, int len){
  struct matrix *m = malloc(sizeof(matrix_col));
  m->row = rows;
  m->row_count = len;
  m->row_len = (*rows)->row_len;
  return m;
}

//add a row to a matrix
int add_row(struct matrix *m, struct matrix_row * r){
  int len = r->row_len;
  if(len != m->row_len) return -1;
  if(m->size == m->row_count){
    int s = m->size;
    s*=2;
    m->size = s;
    m->row = realloc(m->row,s*(sizeof(struct matrix_row *)));
  }
  *((m->row) + (m->row_count)) = r;
  int ret = m->row_count;
  m->row_count +=1;
  return ret;
}
