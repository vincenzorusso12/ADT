typedef struct item * item;

#define NULLITEM NULL


item new_item();
int item_cmp(item x,item y);
item input_item();
void output_item(item x);
char * get_titolo(item x);
