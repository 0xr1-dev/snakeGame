#include<stdio.h>
#include<string.h>
#include <MLV/MLV_all.h>
#include"snake.c"

typedef struct _Grid{
    char** grid;        /* Définition de la matrice */
    int nbc;
    int nbl;
}Grid;

enum Element {WALL='w', EMPTY=' ', FRUIT='f', SNAKE='s'};

void debug(Grid* grid, int nbl, int nbc){
        for(int i=0;i<nbl;i++)
        {
                for(int j=0;j<nbc+1;j++)
                {
                        printf("%c", grid->grid[i][j]);
                }
        }
}


int  compute_size(int h, int w, int nbl, int nbc)
{
	int i, j;
	i = h/nbl;
	j = w/nbc;
	return i < j ? i:j;
}


/*
 * La fonction draw_grid() si dessous déssine des cases en fonction du type de caractère
 * lu dans le fichier qui constitue la grille. La fonction utilise l'enum Element
 * déclarer plus haut qui match un caractère avec un type
 */

void draw_grid(Grid* grid){
	int h, w, carre;
	h = MLV_get_window_height ();
	w = MLV_get_window_width ();
	carre = compute_size(h, w, grid->nbl, grid->nbc);
        for(int i=0;i<grid->nbl;i++)
                for(int j=0;j<grid->nbc+1;j++)
                {
                    if (grid->grid[i][j] == WALL){
                        MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_BLACK );
                    }
                    else if(grid->grid[i][j] == EMPTY){
                        MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_WHITE );
                    }
                    else if(grid->grid[i][j] == FRUIT){
                        MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_GOLD );
                    }
                    else if(grid->grid[i][j] == SNAKE){
                        MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_GREEN );
                    }
                }
        }

        /*
         *  La fonction place_snake place le serpent sur la grille en fonction
         *  de sa position déclaré dans le script game.c
         */

void place_snake(Grid* grid, Snake*  serpent) {
    Coord *now = serpent->segments_list;
    while (now != NULL){
        grid->grid[now->x][now->y] = 's';
        now = now->next;
    }

}

/*
 * Fonction qui à chaque boucle prend en compte la direction envoyée par l'utilisateur.
 * Elle renvoie le type de la dernière case touché par la tête du serpent.
 * A chaque itération la dernière case du serpent (sa queu) se transforme en espace ' '
 * ce qui permet au serpent de garder une taille constante
 */

enum Element move_snake(Snake *serpent, Grid* grid){
	int val;
	Coord * now = serpent->segments_list;
    grid->grid[serpent->segments_list->x][serpent->segments_list->y] = ' ';
	crawl(serpent, grid->nbl, grid->nbc);
    while (now->next != NULL){
        now = now->next;
    }
	switch (grid->grid[now->x][now->y]) {
        case WALL:
           val = WALL;
            break;
        case EMPTY:
            val= EMPTY;
            break;
        case FRUIT:
            val= FRUIT;
            break;
    	}
    	grid->grid[now->x][now->y] = 's';
	    debug(grid, grid->nbl, grid->nbc);
    	return val;
}

/*
 * Allocation dans la mémoire nécessaire dans le tas
 * Cette allocation se fait en fonction de la taille de la grille
 * défini dans le script game.c
 */

Grid* allocate_grid(int n, int m){
    int i;
    Grid* g = malloc(sizeof(Grid));
    g->grid = malloc(n*sizeof(char*));
    for(i=0;i<n;i++){
        g->grid[i] = malloc(m*sizeof(char));
    }
    g->nbl = n;
    g->nbc = m;
    return g;
}

int free_grid(Grid* grid, int* n, int* m){
    free(n);
    free(m);
    free(grid);
    return 0;
}
