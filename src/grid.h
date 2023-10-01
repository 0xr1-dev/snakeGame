#include"snake.h"
#define NBL 22
#define NBC 36


/*
 * Structure Grid, constitué d'une matrice,
 *  de sa taille (en x) exprimé en colonne
 * ainsi de sa hauteur (en y) exprimé en ligne
 */


typedef struct _Grid{
    char** grid;
    int nbc;
    int nbl;
}Grid;
void place_snake(Grid* grid, Snake* serpent);   /* Placement du serpent */
int  compute_size(int h, int w, int nbl, int nbc); /* taille de la grille et de la fenêtre */
void draw_grid(Grid* grid);
enum Element {WALL='w', EMPTY=' ', FRUIT='f', SNAKE='s'};
enum Element move_snake(Snake *serpent, Grid* grid);
Grid* allocate_grid(int n, int m);
int free_grid(Grid* grid, int* n, int* m);
void debug(Grid* grid, int nbl, int nbc);

