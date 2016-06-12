/**
 File: matrix_operation.c
Enter a description for this file.
*/

//interpret.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_operation.h"




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
  m->size = r+1;
  m->row = realloc(m->row,sizeof(char)*(r+1));
}//O(1)

//copy a string to a row
void row_cp_from_str(struct matrix_row *m,char *s){
  int rlen = m->size;
  int slen = strlen(s);
  if(slen<rlen){
    strcpy(m->row,s);
    return;
  }
  *((m->row)+rlen)='\0';
  for(int i=rlen; i<rlen; i++){
    *((m->row)+i)=*(s+i);
  }
}

//form a row from a string
struct matrix_row *row_from_str(char *s){
  int len = strlen(s);
  struct matrix_row *r = new_row();
  r->row = s;
  r->size = len;
  r->row_len = len;
  return r;
}

//set the pos elem in m to be s
int set_row_elem(struct matrix_row *m,int pos,char s){
  if(pos >= m->row_len) return -1;
  *((m->row)+pos)=s;
  return pos;
}

//delete a row
void delete_matrix_row(struct matrix_row *m){
  free(m->row);
  free(m);
}

// Matrix Functions
//create an empty new matrix
struct matrix *new_matrix(){
  struct matrix *m=malloc(sizeof(struct matrix_row *));
  m->size = 1;
  struct matrix_row ** r = malloc(sizeof(struct matrix *));
  m->row = r;
  m->row_len=1;
  m->row_count=1;
  return m;
}

//form a matrix from an array of rows each with length of len
struct matrix *make_matrix_from_array(struct matrix_row ** rows, int len){
  struct matrix *m = malloc(sizeof(struct matrix));
  m->row = rows;
  m->row_count = len;
  m->row_len = (*rows)->row_len;
  m->size = len;
  return m;
}

//add a row to a matrix
int add_row(struct matrix *m, struct matrix_row * r){
  int len = r->row_len;
  // if the size of row does not match the other rows in the matrix
  if(len != m->row_len) return -1;
  //if the row array is full,resize the row array
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

int add_col(struct matrix *m, char *col, int len){
  //first check if the size of column matches row_count
  if(len != m->row_count) return -1;
  //if the rows are filled. resize all of the row
  if(m->row_len == (*(m->row))->size){
    (*(m->row))->size *= 2;
    int size = (*(m->row))->size;
    for(int i = 0;i < (m->row_count); i++){
      (*((m->row)+i))->size = size;
      (*((m->row)+i))->row = realloc(*((m->row)+i),(size+1)*sizeof(char));
    }
  }
  // copying the actual data
  int rowlen = m->row_len;
  for(int i = 0;i < (m->row_count); i++){
    struct matrix_row **row_array = m->row;
    struct matrix_row *target_row = *(row_array + i);
    char *char_array = target_row->row;
    *(char_array + rowlen) = *(col+i);
    //*(*((*((m->row)+i))->row) + rowlen) = *(col+i);
    target_row->row_len += 1;
  }
  int ret = m->row_len;
  m->row_len += 1;
  return ret;
}

//get the element [x,y]
char get_elem(struct matrix *m, int x, int y){
  if(x<0 || x>= m->row_len) return '\0';
  if(y<0 || x>= m->row_count) return '\n';
  return *(((*((m->row)+y))->row)+x);
}

//delete matrix
void delete_matrix(struct matrix *m){
  for(int i=0;i< m->row_count;i++){
    delete_matrix_row(*(m->row+i));
  }
  free(m->row);
  free(m);
}
