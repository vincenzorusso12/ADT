#define NULLITEMHASH NULL

typedef struct item *item;


struct item {
char key[20]; /* chiave:titolo canzone */
char cantante[20];
int durata;
struct item *next;
};


item new_item(char *key,char *cantante,int durata);
item input_item();
void output_item(item x);
