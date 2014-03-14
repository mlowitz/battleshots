/* hasBOARDable using linked lists for collision hadleing 
 *specialized for puposes of dictionary 
 *does not hash normaly uses special hash 
 */
 
#define BOARD_MAX_position 50
struct square {
  char *position;;
  char *P1;
  char *P2;
  struct square **nxt;
};
 
typedef struct board {
  struct square **tbl;
  int size;
} board;
 
board *board_create(int size);                    /* allocate hasBOARDable mem */
void board_destroy(board *board);                  
char* board_get(board *board, char *position, char *player); 
void board_put(board *board, char *position, char *player, char *status);  /* store entry */
void board_remove(board *board, char *position);          /* remove entry */
void *ana_get(board *board, char *position);            /*prints list of anagrams */    
