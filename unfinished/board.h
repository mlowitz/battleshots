/* hasBOARDable using linked lists for collision hadleing 
 *specialized for puposes of dictionary 
 *does not hash normaly uses special hash 
 */
 
#define BOARD_MAX_positionLEN 50
struct info
{
	char *status;
};
struct square {
  char *position;
  struct square *nxt;
  struct char *P1;
  struct char *P2;
};
 
typedef struct board {
  struct square **tbl;
  int size;
} BOARD;
 
BOARD *board_create(int size);                    /* allocate hasBOARDable mem */
void board_destroy(BOARD *board);                    /* free hasBOARDable mem */
void *board_get(BOARD *board, char *position);            /* retrieve entry */
void board_put(BOARD *board, char *position, char *player, char *status);  /* store entry */
void board_remove(BOARD *board, char *position);          /* remove entry */
void *ana_get(BOARD *board, char *position);            /*prints list of anagrams */    
