#include <iostream> 

using namespace std;


typedef struct Tcell *pointer;

struct Titem{
    int id;
    char name[10];
};

struct Tcell {
    Titem item;
    pointer next;
} cell;         

struct Tlist{
    pointer first;
    pointer last;
};

    
void make_empty_list(Tlist *list){
    list->first = (pointer) malloc(sizeof(cell));
    list->last = list->first;
    list->first->next = NULL;
}

int is_empty_list(Tlist list){
    return (list.first == list.last);
}

void append_on_list(Titem item, Tlist *list){
    list->last->next = (pointer) malloc(sizeof(cell));
    list->last = list->last->next;
    list->last->item = item;
    list->last->next = NULL;
}


void remove(pointer p,Tlist*list,Titem *item){
   pointer aux;

    if(is_empty_list(*list) || p == NULL || p->next == NULL){
        cout<< "Empty list or inexistent position";
    }else{
        aux = p->next;
        *item = aux->item;
        p->next = aux->next;

        if(p->next == NULL){
            list->last = p;

            free(aux);
        }
    }
}

void print_list(Tlist list){
    pointer aux;
    int counter = 0;

    aux = list.first->next;
    while(aux != NULL){
        cout<<"\nPosition: ";
        cout<<"\nID: " << aux->item.id;
        cout<<"\nName: " << aux->item.name;

        counter++;
        aux = aux->next;    
    }
}

int main(){
    return 0;
}

