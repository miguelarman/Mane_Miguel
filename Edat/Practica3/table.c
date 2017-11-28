#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table.h"
#include "type.h"

/*USAR -std=c99*/

struct table_ {
  FILE *fp;
  int ncols;
  type_t *types;
  long first;
  void **values;
};

/* 
   Creates a file that stores an empty table. This function doesn't
   keep any information in memory: it simply creates the file, stores
   the header information, and closes it.
*/
void table_create(char* path, int ncols, type_t* types) {
  /* To be implemented */
  return;
}

/* 
   Opens a table given its file name. Returns a pointer to a structure
   with all the information necessary to manage the table. Returns
   NULL is the file doesn't exist or if there is any error.
*/
table_t* table_open(char* path) {
  /* To be implemented */
  
  t->values=(void **)malloc(t->ncols * sizeof(void*));
  t->values[0]=malloc(1);
  return NULL;
}

/* 
   Closes a table freeing the alloc'ed resources and closing the file
   in which the table is stored.
*/
void table_close(table_t* table) {
  /* To be implemented */
  return;
}

/* 
   Returns the number of columns of the table 
*/
int table_ncols(table_t* table) {
  /* To be implemented */
  return 0;
}

/* 
   Returns the array with the data types of the columns of the
   table. Note that typically this kind of function doesn't make a
   copy of the array, rather, it returns a pointer to the actual array
   contained in the table structure. This means that the calling
   program should not, under any circumstance, modify the array that
   this function returns.
 */
type_t* table_types(table_t* table) {
  /* To be implemented */
  return NULL;
}

/* 
   Returns the position in the file of the first record of the table 
*/
long table_first_pos(table_t* table) {
  /* To be implemented */
  return 0L;
}

/* 
   Returns the position in the file in which the table is currently
   positioned. 
*/
long table_cur_pos(table_t* table) {
  /* To be implemented */
  return 0L;
}

/* 
   Returns the position just past the last byte in the file, where a
   new record should be inserted.
*/
long table_last_pos(table_t* table) {
  /* To be implemented */
  return 0L;
}

/* 
   Reads the record starting in the specified position. The record is
   read and stored in memory, but no value is returned. The value
   returned is the position of the following record in the file or -1
   if the position requested is past the end of the file.
*/
long table_read_record(table_t* table, long pos) {

  free(table->values[0]);
  
  fseek(table->fp, pos, SEEK_SET);
  int len;
  fread(&len,sizeof(int), 1, table->fp);
  
  char *buf = (char *)malloc(len*sizeof(char));
  
  fread(buf, sizeof(char), len, table->fp);
  
  for (int i=0; i<table->ncols;i++) {
      table->values[i] = buf;
      
      buf +=value_length(table->types[i], table->values[i]);
  }
  
  
  return -1L;
}

/*
  Returns a pointer to the value of the given column of the record
  currently in memory. The value is cast to a void * (it is always a
  pointer: if the column is an INT, the function will return a pointer
  to it).. Returns NULL if there is no record in memory or if the
  column doesn't exist.
*/
void *table_column_get(table_t* table, int col) {
  /* To be implemented */
  return NULL;
}


/* 
   Inserts a record in the last available position of the table. Note
   that all the values are cast to void *, and that there is no
   indication of their actual type or even of how many values we ask
   to store... why?
  */
void table_insert_record(table_t* table, void** values) {
  /* To be implemented */
  return;
}
