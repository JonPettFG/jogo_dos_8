//Este arquivo conterá as funções que geraram a interface do trabalho
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "interface.h"
 
/***
 *    ███████╗██╗     ██╗██████╗ ██╗███╗   ██╗ ██████╗     ██████╗ ██╗   ██╗███████╗███████╗██╗     ███████╗
 *    ██╔════╝██║     ██║██╔══██╗██║████╗  ██║██╔════╝     ██╔══██╗██║   ██║╚══███╔╝╚══███╔╝██║     ██╔════╝
 *    ███████╗██║     ██║██║  ██║██║██╔██╗ ██║██║  ███╗    ██████╔╝██║   ██║  ███╔╝   ███╔╝ ██║     █████╗  
 *    ╚════██║██║     ██║██║  ██║██║██║╚██╗██║██║   ██║    ██╔═══╝ ██║   ██║ ███╔╝   ███╔╝  ██║     ██╔══╝  
 *    ███████║███████╗██║██████╔╝██║██║ ╚████║╚██████╔╝    ██║     ╚██████╔╝███████╗███████╗███████╗███████╗
 *    ╚══════╝╚══════╝╚═╝╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝     ╚═╝      ╚═════╝ ╚══════╝╚══════╝╚══════╝╚══════╝
 
    by: Maryanne Cerqueira, Vitor Terra, Joao Pedro FG, Joao Lucas MS. 
 *                                                                                                          
 */
  
struct zeropos* zero_pos(int matriz[3][3]){
  struct zeropos *pointer;
  int i, j;
  
  pointer=(struct zeropos*)malloc(sizeof(struct zeropos));
  
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(matriz[i][j]==0){
        pointer->i=i;
        pointer->j=j;
      }
    }
  }
  
  return pointer;
}
 
void imprimeMatriz(int m[3][3], WINDOW * game){
    wprintw(game, "\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            wprintw(game, "  %d ", m[i][j]);
        }
        wprintw(game, "\n\n");
    }
    wrefresh(game);
}
 
void keyDown(int matriz[3][3], WINDOW * game, int* scr){
  struct zeropos *zp;
  int temp, i, j;
  
  zp=zero_pos(matriz);
  
  if(zp->i==0){
    return;
  }
  temp=matriz[zp->i-1][zp->j];
  matriz[zp->i-1][zp->j]=0;
  matriz[zp->i][zp->j]=temp;
 
  ++(*scr); 
  free(zp);
}
  
void keyUp(int matriz[3][3], WINDOW * game, int* scr){
  struct zeropos *zp;
  int temp, i, j;  
  
  zp=zero_pos(matriz);
  if(zp->i==2){
    return;
  }
 
  temp=matriz[zp->i+1][zp->j];
  matriz[zp->i+1][zp->j]=0;
  matriz[zp->i][zp->j]=temp;
 
  ++(*scr);
  free(zp);
}

void keyRight(int matriz[3][3], WINDOW * game, int* scr){
  struct zeropos *zp;
  int temp, i, j;
  
  zp=zero_pos(matriz);
  
  if(zp->j==0){
    return;
  }
  temp=matriz[zp->i][zp->j-1];
  matriz[zp->i][zp->j-1]=0;
  matriz[zp->i][zp->j]=temp;
 
  ++(*scr);
  free(zp);
}
  
void keyLeft(int matriz[3][3], WINDOW * game, int* scr){
  struct zeropos *zp;
  int temp, i, j;
  
  zp=zero_pos(matriz);
  
  if(zp->j==2){
    return;
  }
  temp=matriz[zp->i][zp->j+1];
  matriz[zp->i][zp->j+1]=0;
  matriz[zp->i][zp->j]=temp;
 
  ++(*scr);
  free(zp);
}
  
int solvable(int matriz[3][3]){
  int i, j, k, l, ans=0;
    for(k=0;k<3;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(l=0;l<3;l++){
                    if(matriz[j][l]<matriz[k][i] && j>=k && matriz[j][l]!=0 && matriz[k][i]!=0){
                        ans++;
                        if(j==k){
                            if(l<i)
                                ans--;
                        }
                    }
                }
            }
        }
    }
    return ans%2;
}

void matrizDefault(int m[3][3]){
  int var=1;
  for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            m[i][j]=var;
            var++;
            if(i==2&&j==2){
                m[i][j]=0;
            }
        }
    }
}
 
void embaralhaMatriz(int m[3][3], int maux[3][3]){
    srand(time(NULL)); //essa funçao impossibilita que a rand() gere sempre a mesma sequencia numerica, reiniciando a seed dessa funçao
    int i, j, auxrandomcol=0,auxrandomrow=0, temp, rsvvl, var=1;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            m[i][j]=var;
            var++;
            if(i==2&&j==2){
                m[i][j]=0;
            }
        }
    }
    do{
    for (int i=0;i<3;i++){ //resumindo, embaralha a matriz sorteando posiçoes aleatorias para colocar os numeros, usando rand
        for (int j=0;j<3;j++){
            auxrandomcol=(rand()%2)+1;
            auxrandomrow=(rand()%2)+1;
            temp=m[i][j];
            m[i][j]=m[auxrandomrow][auxrandomcol];
            m[auxrandomrow][auxrandomcol]=temp;
        }
       }
      maux=m;
    rsvvl=solvable(m);
    }while(rsvvl==1);
}

int won(int matriz[3][3]){ //retorna 1 se o usuario ganhou e 0 se nao
    int aux=1, i, j, comp[3][3]={
        {1,2,3},{4,5,6},{7,8,0}
      };
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(matriz[i][j]!=comp[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
 
void gamer(int m[3][3], WINDOW * game){
    int* scr= (int *) malloc (sizeof(int));
    int pscr = 0;
    scr = &pscr;
    char answr;
 
    while(answr!='q' && answr != 'Q'){
        WINDOW * auxscore = newwin(4, 5, 9, 144);    
        wbkgd(auxscore, COLOR_PAIR(2));

        WINDOW * aux = newwin(7, 14, 16, 70);
        init_pair(1, COLOR_YELLOW, COLOR_MAGENTA);
        wbkgd(aux, COLOR_PAIR(1));

        WINDOW * leaderboard = newwin(10, 14, 29, 130);
        wbkgd(leaderboard, COLOR_PAIR(1));
 	setbuf(stdin,NULL);
       // __fpurge(stdin);
        scanf(" %c", &answr);
 
        switch(answr){
          case 's':
          case 'S':
            keyDown(m, game, &pscr);
            break;
  
          case 'a':
          case 'A':
            keyLeft(m, game, &pscr);      
            break;
  
          case 'w':
          case 'W':
            keyUp(m, game, &pscr);
            break;
  
          case 'd':
          case 'D':
            keyRight(m, game, &pscr);
            break;
  
          case 'q': 
          case 'Q':
          break;

          default:
          break;
        }

      imprimeMatriz(m, aux);     
      overwrite(aux, game);
      wrefresh(aux);

      wprintw(auxscore, "%d", pscr);
      wrefresh(auxscore);
      refresh();

      if(won(m) == 1){
        char name[50];
        WINDOW * win = newwin(14, 83, 5, 34);
        wbkgd(win, COLOR_PAIR(1));
        wrefresh(win);
        wprintw(win, " YOU WON! \n TYPE YOUR NAME \n");
        scanf("%s", name);
        wrefresh(win);
        }
      }
}

void windows(WINDOW * game){
    int row, col, rowdeco2, coldeco2;
    getmaxyx(stdscr,row,col); //stdscr= a windows principal

    WINDOW * decoration = newwin(row, 30, 0, 0);
    WINDOW * decoration2 = newwin(row, col/3, 0, 121); 
    getmaxyx(decoration2,rowdeco2,coldeco2);
    WINDOW * title = newwin(7, 83, 3, 34);
    WINDOW * score = newwin(10, (coldeco2/2)+5, 3, 130);
    WINDOW * best = newwin(10, coldeco2/2, 16, 130);
    WINDOW * instruction = newwin(row/3, 81, row/2, 35);
//    WINDOW * goal = newwin(7, 14, 29, 140); //ficar debaixo do best
    WINDOW * goal = newwin(7, 14, 3, 7);
//WINDOW *newwin(int nlines, int ncols, int begin_y, int begin_x);
 
    if(has_colors && can_change_color)
    {
        init_color(COLOR_YELLOW, 190,190,300); //yellow eh um azul meio verde
        init_color(COLOR_MAGENTA, 100, 1000, 1000);
        init_color(COLOR_BLACK, 300, 200, 590); //roxo das decoraçoes
        init_color(COLOR_WHITE, 700,700,750); //cinzinha da tela
        init_color(COLOR_RED, 400, 1000, 1000);  //AZUL MT VIBRANTE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        init_color(COLOR_GREEN, 300, 120,120);
 
        // red; green; blue
        init_pair(3, COLOR_BLACK, COLOR_BLACK);
        wbkgd(decoration2, COLOR_PAIR(3));
        wbkgd(decoration, COLOR_PAIR(3));
 
        init_pair(1, COLOR_YELLOW, COLOR_MAGENTA);
        wbkgd(game, COLOR_PAIR(1));
 
        init_pair(2, COLOR_RED, COLOR_YELLOW);
        wbkgd(title, COLOR_PAIR(2));
        wbkgd(score, COLOR_PAIR(2));
        wbkgd(best, COLOR_PAIR(2));
        wbkgd(instruction, COLOR_PAIR(2));
        wbkgd(goal, COLOR_PAIR(2));

        init_pair(4, COLOR_WHITE, COLOR_WHITE);
        wbkgd(stdscr, COLOR_PAIR(4))
;    }
 
    wrefresh(stdscr);
    wrefresh(decoration);
    wprintw(title, "\n  ___  __    ____  ____  ____  _  _  ___    ____  __  __  ____  ____  __    ____ \n / __)(  )  (_  _)(  _ \\(_  _)( \\( )/ __)  (  _ \\(  )(  )(_   )(_   )(  )  ( ___)\n \\__ \\ )(__  _)(_  )(_) )_)(_  )  (( (_-.   )___/ )(__)(  / /_  / /_  )(__  )__) \n (___/(____)(____)(____/(____)(_)\\_)\\___/  (__)  (______)(____)(____)(____)(____)");
    wrefresh(title);
    wrefresh(decoration2);
 
    wprintw(score, "      ____   ___  __  ____  ____ \n     / ___) / __)/  \\(  _ \\(  __)\n     \\___ \\( (__(  O ))   / ) _) \n     (____/ \\___)\\__/(__\\_)(____)");
//fonte= bulbhead
    wrefresh(score);
 
    wprintw(best, "      ____  ____  ___  ____ \n     (  _ \\( ___)/ __)(_  _)\n      ) _ < )__) \\__ \\  )(  \n     (____/(____)(___/ (__) ");
    wrefresh(best);
    wprintw(instruction, "   ____  _  _  ___  ____  ____  __  __  ___  ____  ____  _____  _  _  ___ \n  (_  _)( \\( )/ __)(_  _)(  _ \\(  )(  )/ __)(_  _)(_  _)(  _  )( \\( )/ __)\n   _)(_  )  ( \\__ \\  )(   )   / )(__)(( (__   )(   _)(_  )(_)(  )  ( \\__ \\\n  (____)(_)\\_)(___/ (__) (_)\\_)(______)\\___) (__) (____)(_____)(_)\\_)(___/ \n\n     w = up \n     a = left \n     d = right \n     s = down");
    wrefresh(instruction);

    int mGoal[3][3];
    matrizDefault(mGoal);
    imprimeMatriz(mGoal, goal);
    wrefresh(goal);
  
}

void ncurses(){
    initscr();  
    start_color(); 
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
 
    int m[3][3], maux[3][3];
    embaralhaMatriz(m, maux);
     
    WINDOW * game = newwin(7, 14, 16, 70);
    windows(game);

    imprimeMatriz(m, game);
 
    struct zeropos *pos_do_zero = zero_pos(m);
 
    gamer(m, game);

    free(game);
    endwin();   
}
 
int main(){
    ncurses();
}
