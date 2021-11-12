#include <iostream>
#include <cstring>
using namespace std;

#define START 0
#define MAXLENGTH 100

typedef int pointer;

struct Titem {
    int id;
    char name[10];
};

struct Tlist{
    Titem item [MAXLENGTH];
    pointer first;
    pointer last;
};

void emptyList(Tlist &list){
    list.first = START;
    list.last = START;
}

void searchItem(Tlist &list ,Titem &item, pointer p){
    item.id = list.item[p].id; //searchs item id in the specified position
    strcpy(item.name, list.item[p].name); //copies the second argument to the first
}

bool isEmptyList(Tlist &list){
    return (list.first == list.last);
}

void append(Titem newItem, Tlist &list){
    if(list.last > MAXLENGTH){
        cout << "List's full";
    }else{
        list.item[list.last] = newItem; //insert the new item on last list position
        list.last++;                    //increments 1 on list length
    }
}

void remove(pointer p, Tlist &list, Titem &item){
    if(isEmptyList(list) || p >= list.last){
        cout << "Error: position doesn't exists!";
    }else{
        item = list.item[p]; //removes the item especified from the list
        list.last--;    // resize the list length

        for(int aux = p; aux < list.last; aux++){
            list.item[aux] = list.item[aux + 1]; //reorganize the list from the removed item position
        }
    }
}

void insertOnPosition(pointer position, Tlist &list, Titem &item){ //inserts on position deleting the value on that position
    if(isEmptyList(list) || (position >= list.last)){
        cout << "Error: position doesn't exists!";
    }else{
        list.item[position].id = item.id;           //inserts the id of new item on choosed item position
        strcpy(list.item[position].name, item.name); //inserts the name of new item on item position
    }
}

void printList(Tlist &list){
    if(isEmptyList(list)){
        cout<<"List is empty\n";
    }else{
        for(int aux = list.first; aux <= list.last; aux++){
            cout << "Item id: " << list.item[aux].id << endl;
            cout << "Item name: " << list.item[aux].name << endl;
        }
    }
}

int menu(){
    int op = 5;
    
    do{
        cout << "Choose an option by number: " <<endl;
        cout << "1 - Insert" << endl;
        cout << "2 - Delete" << endl;
        cout << "3 - Change" << endl;
        cout << "4 - Show list" << endl;
        cout << "0 - Close" << endl;
        cin >> op;
    }while((op > 4) || (op < 0));

    return op;
}

int main(){
    Tlist list;
    Titem item;
    int option, position;
    
    emptyList(list);
    
    option = menu();
    while(option != 0){
        switch(option){
            case 1: //insert
                cout<< "----- INSERT ITEM -----\n";
                cout<< "Insert the item id: ";
                cin >> item.id;
                cout<< "\nInsert the item name: ";
                cin>> item.name;
                append(item, list);
                break;
            case 2: //delete
                cout<< "----- REMOVE ITEM -----\n";
                cout<< "Insert the item position: ";
                cin >> position;
                remove(position, list, item);
                break;
            case 3: //change                
                cout<< "----- CHANGE ITEM -----\n";
                cout<< "Insert the position to be changed: ";
                cin >> position;
                searchItem(list, item, position);
                cout << "Insert the new item id: ";
                cin>> item.id;
                cout<<"\nInsert the new item name: ";
                cin>> item.name;
                cout<<"\nNew list -> ";
                printList(list);
                break;
            case 4: //showlist
                printList(list);
                break;
            default:
                cout << "Not a valid number";
                break;
        }
        option = menu();
    }

    return 0;
}
