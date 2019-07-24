typedef struct{
  int movimento; //Movimento que levou a esse estado
  int game[3][3];
}Estado;
 
Estado* CriarEstado(int mov, int game[3][3]);
int DistanciaManhattan(Estado *estado_atual);
int CompararEstados(Estado * estado1, Estado * estado2);
