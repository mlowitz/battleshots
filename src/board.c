#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"
 
unsigned long _hash(char *position)
{
  /*
   *program hashes using sum of charters in word from 1-26 
   */
  
  int c;
  unsigned long hash=wordToInt(position); 
    
  
  return hash;

}
 

board *board_create(int size)
{
  /* 
   *program creates hash tables 

   */
  board *board = malloc(sizeof(board));
 
  board->size = size;
 
  board->tbl = calloc(1, size * sizeof(struct square *));
 
  return board;
}
//free memory from hash table 
void board_destroy(board *board)
{
  if (!board) return;
 
  int i;
  for (i = 0; i < board->size; i++) {
    struct square *n = board->tbl[i];
    while (n) {
      struct square *n_old = n;
 
      n = n->nxt;
 
      free(n_old->position);
      n_old->position = NULL;
      free(n_old);
      n_old = NULL;
    }
  }
 
  free(board->tbl);
  free(board);
 
  board = NULL;
}
 

//will fetch and print entire linked list from hashvalue 
char* board_get(board *board, char *position, char* player)
{
  if (!board) return NULL;
 
  unsigned long idx = _hash(position) % board->size;
 
  struct square *n = board->tbl[idx];
 /* while (n) {
      return n->val;
      n = n->nxt;*/
  if (player[1]=='1')
  {
    return n->P1;//return player1 
  }
  else if(player[1]=='2')
    {
      return n->P2;//retrun player 2
    }  
      
  else 
  return NULL;
}
//will fetch linked list same as board_get but will scan for false positives 
void *ana_get(board *board, char *position)
{
  /*  if (!board) return NULL;
 
dx = _hash(position) % board->size;
 
  struct board_node *n = board->tbl[idx];
 /* while (n) {
      return n->val;
      n = n->nxt;
  }
  while (n) {
      
      if (match(position,n->val)){
      printf("%s\n",n->val) ;}
      n = n->nxt;
      //return list->str;
      
  }*/
  return NULL;
}
 


//function to add to hasboardable 
void board_put(board *board, char *position, char *player, char *status)
{
  if (!board) return;
  if(!board->tbl[idx]){
  unsigned long idx = _hash(position) % board->size;
 
  struct square *n_new = calloc(1, sizeof(struct square));
  n_new->position = calloc(1, strlen(position,BOARD_MAX_positionLEN)+1)
    strcpy(new_position,position);
  if(player[1]=='1')
    {
      n_new->P1= calloc(1, strlen(status, board_MAX_positionLEN) + 1);//creates plaer 1
      strcpy(n_new->P1,status);
    }
  if(player[1]=='2')
    {
      n_new->P2= calloc(1, strlen(status, board_MAX_positionLEN) +1);
      strcpy(n_new->P2,status);
    }

    n_new->nxt = board->tbl[idx];
    board->tbl[idx] = n_new;}
  else
    board_add(board, position, player,status
}
//adds players ship  to already existing square. 
void board_add(board *board, char *position, char *player, char*status)
{
  if (!board) return;
 
  unsigned long idx = _hash(position) % board->size;
  struct square *n = board->tbl[idx];
  while (n) {
    if (strcmp(position, n->position) == 0) {
      n->position = calloc(1, strlen(position) + 1);
  if(player[1]=='1')
    {
      n->P1= calloc(1, strlen(status) + 1);//creates plaer 1
      strcpy(n->P1,status);
    }
  if(player[1]=='2')
    {
      n->P2= calloc(1, strlen(status) +1);
      strcpy(n->P2,status);
    }
 
      break;
    }
 
    
    n = n->nxt;
  }
}
