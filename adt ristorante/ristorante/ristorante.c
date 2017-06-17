#include "ingrediente.h"
#include "ingredienti_list.h"
#include "piatto.h"
#include "piatti_list.h"

void stampa_menu(piatti_list list)
{
  if(list == NULL)
  {
    exit(1);
  }
  piatto *temp = list->first;
  while(temp!=NULL)
  {
    stampa_piatto(temp);
    temp = temp->next;
  }
}

void stampa_piatto(piatto p)
{
  stampa_nome_piatto(p);
  stampa_ingredienti(p);
  stampa_prezzo(p);
}

void stampa_nome_piatto(p)
{
    printf("%s: ", p->nome );
}

void stampa_ingredienti(piatto p)
{
  ingredienti_list *lista = p->lista_ingredienti;
  int n_of_el = p->n_ingredienti;
  ingrediente *ing = lista->first;
  int i = 0;
  while(ing!=NULL)
  {
    i++;
    printf("%s", ing->nome);
    if(i<n_of_el)
    {
      printf(",");
    }
    ing = ing->next;
  }
}

void stampa_prezzo(piatto p)
{
  printf("\t%d.\n", p->prezzo);
}

piatti_list new_piatti_list(void)
{
  struct piatti_list *list;
  list = malloc(sizeof(struct piatti_list));
  if(list!=NULL)
  {
    list->first = NULL;
    list->n_piatti = 0;
  }
  return list;
}

ingredienti_list new_ingredienti_list(void)
{
  struct ingredienti_list *list;
  list = malloc(sizeof(struct ingredienti_list));
  if(list!=NULL)
  {
    list->first = NULL;
    list->n_ingredienti = 0;
  }
  return list;
}

int inserisci_ingrediente_nella_lista(ingredienti_list list, int pos, char[20] nome, int calorie)
{
  if(list==NULL)
  {
    return 1;
  }
  else
  {
    if(pos<0 || pos>list->n_ingredienti)
    {
      return 1;
    }
    else
    {
      struct ingrediente* ing = inserisci_ingrediente(pos, nome, calorie, list->first);
      if(ing==NULL)
      {
        return 1;
      }

      list->first = ing;
      list->n_ingredienti++;

    }
  }
}

static struct ingrediente* crea_ingrediente(char[20] nome, int calorie, struct ingrediente* next)
{
  struct ingrediente *nuovo = malloc(sizeof(struct ingrediente));
  if(nuovo!=NULL)
  {
    nuovo->nome = nome;
    nuovo->next = next;
    nuovo->calorie = calorie;
  }
  return nuovo;
}

static struct ingrediente* inserisci_ingrediente (int pos, char[20] nome, int calorie, struct ingrediente* ing)
{
  if(pos == 0)
  {
    return crea_ingrediente(nome, calorie, ing);
  }
  else
  {
      int i = 0;
      struct ingrediente* curr = ing;
      while(i<pos-1)
      {
        curr = curr->next;
        i++;
      }
      struct ingrediente *new = crea_ingrediente(nome, calorie, curr->next);
      if(new == NULL)
      {
        return 1;
      }
      curr->next = ing;
  }
}
