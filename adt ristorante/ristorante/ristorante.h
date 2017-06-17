void stampa_menu(piatti_list list);
void stampa_nome_piatto(piatto p);
void stampa_piatto(piatto p);
void stampa_ingredienti(piatto p);
void stampa_prezzo(piatto p);
int inserisci_ingrediente_nella_lista(ingredienti_list list, int pos, char[20] nome, int calorie);
static struct ingrediente* crea_ingrediente(char[20] nome, int calorie, struct ingrediente* next);
static struct ingrediente* inserisci_ingrediente (int pos, char[20] nome, int calorie, struct ingrediente* ing);
