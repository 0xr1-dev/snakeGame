#include<stdio.h>
#include "../MLV/MLV/MLV_all.h"
#include <getopt.h>
#include"grid.h"
#include "getlong.h"
#include<strings.h>


int count_nb_line(FILE *stream){
	char c;
	int count = 0;
	for (c = getc(stream); c!= EOF; c = getc(stream))
		if (c == '\n')
			count = count + 1;
	return count;
}

int count_nb_colonne(FILE *stream){
	char c;
	int nombre_c = 0;
	for (c = getc(stream); c!= EOF && c != '\n'; c = getc(stream))
			nombre_c++;
	return nombre_c;
}

void copy(char *src, char *dst){
	int i = 0;
	for(i=0; src[i]!='\0';i++){
		dst[i]=src[i];
	}
}



int main(int argc, char *argv[]){
    Snake * snake;
	int nbl = 0;
	int nbc = 0;
	size_t size_buf=0;
	FILE * stream;      /*Fichier passé en argument */
	FILE * stream;
	FILE * grille;
	char * buf=NULL;
	int resultat = -1;
	Grid *g;            /* Objet Grid défini dans grid.h*/
	int i;
    int size_tmp;
    int nb_fruits= 0;
    int elem;
    int next_option;
    int zdebug = 0;
    int zdebug=0;


	program_name = argv[0];
	const char* const short_options = "hoi:v";
  	const struct option long_options[] = {
    		{ "help",     0, NULL, 'h' },
    		{ "debug",   0, NULL, 'd' },                /* Gestion des arguments  */
    		{ "verbose", 0, NULL, 'v' },
            {"input", 0, NULL, 'i'},
    		{ NULL,       0, NULL, 0}
	};
	do {
        next_option = getopt_long(argc, argv, short_options,
                                  long_options, NULL);
        switch (next_option) {
            case 'h':
                print_usage(stdout, 0);
                break;
            case 'i':
                stream = fopen(argv[2], "r");           /* Ouverture de la grille*/
                nbl = count_nb_line(stream);
                if (zdebug == 1){ printf("\n[Nb de ligne de la grille] -> [%d]\n", nbl);}
                rewind(stream);
                nbc = count_nb_colonne(stream);
                if (zdebug == 1){ printf("\n[Nb de colonne de la grille] -> [%d]\n", nbc);}
                g = allocate_grid(nbl, nbc);        /* allocation de la mémoire en fonction de la taille de la grille */
                g->nbl = nbl;                       /* Objet Grid */
                stream = fopen(argv[2], "r");
                nbl = count_nb_line(stream);
                if (zdebug){ printf("\n[Nb de ligne de la grille] -> [%d]\n", nbl);}
                rewind(stream);
                nbc = count_nb_colonne(stream);
                if (zdebug){ printf("\n[Nb de colonne de la grille] -> [%d]\n", nbc);}
                g = allocate_grid(nbl, nbc);
                g->nbl = nbl;
                g->nbc = nbc;
                rewind(stream);
                for (i = 0; i < nbl; i++) {
                    size_tmp = getline(&buf, &size_buf, stream);
                    if (size_tmp != nbc+1) {
                        exit(1);
                    }
                    copy(buf, g->grid[i]);
                }
                break;
            case 'd':
                zdebug  = 1;
                break;
            default:
                break;
        }

    }while(next_option != -1);


	if (argv[2]==NULL){
        stream = fopen("grid.txt", "r");
        nbl = count_nb_line(stream);
        if (zdebug == 1){ printf("\n[Nb de ligne de la grille] -> [%d]\n", nbl);}
        rewind(stream);
        nbc = count_nb_colonne(stream);
        if (zdebug == 1){ printf("\n[Nb de colonne de la grille] -> [%d]\n", nbc);}
        g = allocate_grid(nbl, nbc);
        g->nbl = nbl;
        g->nbc = nbc;
        rewind(stream);
        for (i = 0; i < nbl; i++) {
            size_tmp = getline(&buf, &size_buf, stream);
            if (size_tmp != nbc+1) {
                exit(1);
            }
            copy(buf, g->grid[i]);
        }
	}
	if (nbc == 0){
        stream = fopen("grid.txt", "r");
        nbl = count_nb_line(stream);
        if (zdebug == 1){ printf("\n[Nb de ligne de la grille] -> [%d]\n", nbl);}
        rewind(stream);1991293066155
        nbc = count_nb_colonne(stream);
        if (zdebug == 1){ printf("\n[Nb de colonne de la grille] -> [%d]\n", nbc);}

	if (argv[1]==NULL){
        stream = fopen("grid.txt", "r");
        nbl = count_nb_line(stream);
        if (zdebug){ printf("\n[Nb de ligne de la grille] -> [%d]\n", nbl);}
        rewind(stream);
        nbc = count_nb_colonne(stream);
        if (zdebug){ printf("\n[Nb de colonne de la grille] -> [%d]\n", nbc);}
        g = allocate_grid(nbl, nbc);
        g->nbl = nbl;
        g->nbc = nbc;
        rewind(stream);
        for (i = 0; i < nbl; i++) {
            size_tmp = getline(&buf, &size_buf, stream);
            if (size_tmp != nbc+1) {
                exit(1);
            }
            copy(buf, g->grid[i]);
        }
	}

   int coordx[4] = {1,1,1,1};   /* Coordonné du serpent en X au début du jeu */
   int coordy[4] = {4,3,2,1};/* Coordonné du serpent en Y au début du jeu */
	snake = new_snake();    /* Fonction de création du serpent dans snake.h */
	snake->size = 4;
    for(i=0;i<snake->size;i++){
        add_segment(snake, coordx[i], coordy[i]);
    }

    MLV_Keyboard_button touche = MLV_KEYBOARD_NONE;
    int width = 900, height = 700;

    /* Ouverture de la fenêtre graphique */
    MLV_create_window( "SNAKE", "3R-IN1B", width, height );
    MLV_change_frame_rate( 10 );
    for(int i=0;i<nbl;i++){
        for(int j=0;j<nbc+1;j++){
            if(g->grid[i][j] == 'f'){
                nb_fruits++;
            }
        }
    }
    if (zdebug == 1){ printf("\n [nombre de fruits] -> [%d]\n", nb_fruits);}

    MLV_init_audio();
    MLV_Music * music= MLV_load_music("song/dino.mp3");
    MLV_play_music(music,10,3);

    while(
        MLV_get_event (
            &touche, NULL, NULL,
            NULL, NULL,
            NULL, NULL, NULL,
            NULL
        ) == MLV_NONE ||
        touche != MLV_KEYBOARD_ESCAPE
    ){
        MLV_clear_window( MLV_COLOR_BROWN );
    	draw_grid(g);   /* Dessine la gride en fonction du nb de ligne & colonne, défini dans grid.h */
    	place_snake(g, snake);
        MLV_actualise_window();

	    elem = move_snake(snake, g);
        if(zdebug == 1){debug(g, nbl, nbc);}
	    elem = move_snake(tab, g);

        if(zdebug){debug(g, nbl, nbc);}

	    MLV_actualise_window();

	switch (elem) {
            case FRUIT:
                nb_fruits--;
            if (nb_fruits == 0)
                 resultat = 0;
                break;
            case WALL:
                resultat = 1;
                break;
            case SNAKE:
                resultat = 1;
                break;
        }

	switch (touche) {           /* Gestion du déplacement du serpent */
            case MLV_KEYBOARD_DOWN:
                snake->dir = 'x';
                break;
            case MLV_KEYBOARD_UP:
                snake->dir = 'z';
                break;
            case MLV_KEYBOARD_RIGHT:
                snake->dir = 'd';
                break;
            case MLV_KEYBOARD_LEFT:
                snake->dir = 'q';
                break;
        }

        touche = MLV_KEYBOARD_NONE;
        MLV_delay_according_to_frame_rate();

        if(resultat == 1 || resultat == 0 ){
            MLV_free_window();
            break;
        }
    }
    /*
     * Fenetres de fin du jeu
     */


    if(resultat == 0) {
        MLV_create_window("VICTOIRE", "3R-IN1B", width, height);
        MLV_draw_text(10, 10, "Vous avez gagné !!", MLV_COLOR_YELLOW);
        MLV_actualise_window();
        MLV_wait_seconds( 15 );
        MLV_free_window();
        }
    if (resultat == 1) {
        MLV_create_window("DÉFAITE", "3R-IN1B", width, height);
        MLV_draw_text(10, 10, "Vous avez perdu !!", MLV_COLOR_RED);
        MLV_actualise_window();
        MLV_wait_seconds( 15 );
        MLV_free_window();
    }

    return 0;

}
