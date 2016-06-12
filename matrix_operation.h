/**
 File: matrix_operation.h
Enter a description for this file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct matrix_row{
  char *row;
  int row_len;
  int size;
};

//a matrix formed by rows
struct matrix{
  struct matrix_row **row;
  int size;// how much memories there actually is for matrix_row s
  int row_len;
  int row_count;
};

// row fucntions
//create a new empty row
struct matrix_row * new_row();//O(1)

//set the length of a row
void set_row_len(struct matrix_row *m,int r);//O(1)

//copy a string to a row
void row_cp_from_str(struct matrix_row *m,char *s);

//form a row from a string
struct matrix_row *row_from_str(char *s);

//set the pos elem in m to be s
int set_row_elem(struct matrix_row *m,int pos,char s);

//delete a row
void delete_matrix_row(struct matrix_row *m);

// Matrix Functions
//create an empty new matrix
struct matrix *new_matrix();

//form a matrix from an array of rows each with length of len
struct matrix *make_matrix_from_array(struct matrix_row ** rows, int len);

//add a row to a matrix
int add_row(struct matrix *m, struct matrix_row * r);

//add a column to a matrix
int add_col(struct matrix *m, char *col, int len);


//get the element [x,y]
char get_elem(struct matrix *m, int x, int y);

//delete matrix
void delete_matrix(struct matrix *m);
