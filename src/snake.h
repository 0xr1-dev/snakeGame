#define SNAKE_SIZE 4

/*
 * Liste chaîné permettant de définir la postion du serpent en x et y sur la grille
 */


typedef struct _Coord{
    int x;
    int y;
    struct _Coord *next;
}Coord;

typedef enum  {TOP='q', BOTTOM='d', LEFT='z', RIGHT='x' } direction;


/*
 * Liste chaîné permettant de dynamiser la taille du serpent.
 *
 */

typedef struct struct_snake{
    Coord *segments_list;
    int size;
    direction dir;
}Snake;

void crawl(Snake *serpent, int nbl, int nbc);   /* Gestion des déplacements */
Snake* new_snake();
void add_segment(Snake* serpent, int x, int y); /* Allocation des coordonnées du serpent */
void free_snake(Snake *serpent);
void update_pos(Snake *serpent, int x, int y);