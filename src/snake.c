#include "snake.h"
#include "stdio.h"
#include "stdlib.h"

/*
 * La fonction craw() qui permet de déplacer le serpent dans une direction
 * en fonction de la touche entrée par l'utisateur au clavier.
 */


void crawl(Snake *serpent, int nbl, int nbc){
        Coord* head = serpent->segments_list;
        int x,y;
        printf("\nx =%d | y = %d\n", serpent->segments_list->x, serpent->segments_list->y);
       while (head->next != NULL){
            head = head->next;
        }

        switch (serpent->dir) {
            case LEFT:
                x = (head->x-1+nbl)%nbl;
                y = head->y;
                break;
            case RIGHT:
                x = (head->x+1+nbl)%nbl;
                y = head->y;
                break;
            case TOP:

                y = (head->y-1+nbc)%nbc;
                x = head->x;
                break;
            case BOTTOM:
                y = (head->y+1+nbc)%nbc;
                x = head->x;
                break;
            default:
                y = (head->y+1+nbc)%nbc;
                x = head->x;
                break;
        }

       /*
        * Envoie la valeure matricielle afin de constituer la nouvelle case qui représentera la tête
        */
       update_pos(serpent, x, y);

}

void update_pos(Snake *serpent, int x, int y){
    Coord * queu = serpent->segments_list;
    Coord *body = serpent->segments_list->next;
    Coord *head = serpent->segments_list;
    Coord *new_head = (Coord*)malloc(sizeof(Coord));  /*Allocation dynamique dans le tas de la nouvelle coordonnée de la tête*/

    /*
     * Parcour d'une boucle sur la chaîne listée qui permet de récupérer le dernier élément
     * de la chaîne qui pointe toujours vers NULL
     */
    while (head->next != NULL){
        head = head->next;
    }


    serpent->segments_list = body;
    new_head->x = x;
    new_head->y = y;
    head->next = new_head;
    body = body->next;
    queu = queu->next;
}


/*
 * Création et allocation dans le tas du serpent
 */
Snake* new_snake()
{
        Snake *snake = (Snake*)malloc(sizeof(snake));
        snake->segments_list=NULL;
        snake->size=0;
        return snake;
}

/*
 * Alloue un type Coord (définis dans grid.h)
 * qui nous permettra de récupérer la 1ère coordonnée du serpent
 * grâce à un pointeur
 */

void add_segment(Snake* serpent, int x, int y)
{
	Coord *Coord1 = (Coord *)malloc(sizeof(Coord));

    Coord1->x = x;
    Coord1->y = y;
    Coord1->next = serpent->segments_list;
    serpent->segments_list = Coord1;
}


void free_snake(Snake *serpent)
{
	Coord *asupprime;
	while(serpent->segments_list != NULL){
		asupprime = serpent->segments_list;
		serpent->segments_list = serpent->segments_list->next;
		free(asupprime);
	}
}





