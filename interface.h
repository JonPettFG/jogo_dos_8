struct zeropos{
  int i,j;
};

struct zeropos* zero_pos(int matriz[3][3]);
void imprimeMatriz(int m[3][3], WINDOW * game);
void keyDown(int matriz[3][3], WINDOW * game, int* scr);
void keyUp(int matriz[3][3], WINDOW * game, int* scr);
void keyRight(int matriz[3][3], WINDOW * game, int* scr);
void keyLeft(int matriz[3][3], WINDOW * game, int* scr);
int solvable(int matriz[3][3]);
void embaralhaMatriz(int m[3][3], int maux[3][3]);
void gamer(int m[3][3], WINDOW * game);
void windows(WINDOW * game);
void ncurses();
int won(int matriz[3][3]);
void matrizDefault(int m[3][3]);
