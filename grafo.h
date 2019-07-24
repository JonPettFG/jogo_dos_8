typedef struct no{
  int profundidade;
  int distancia_manhattan;
  struct no *pai;
  struct no *filho;
  Estado estado_atual;
}no;
no* primeiro_no(Estado * estado_atual);
no* a_star(no * no_inicial);
int custo(no* game);