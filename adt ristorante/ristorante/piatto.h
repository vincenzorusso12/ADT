typedef struct piatto {
  char[20] nome;
  int prezzo;
  ingredienti_list *lista_ingredienti;
  piatto *next;
};
