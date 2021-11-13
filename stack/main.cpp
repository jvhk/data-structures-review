#include <iostream>

using namespace  std;

#define MAX 100

typedef int Pointer;

struct Titem{
    int code;
    char name[10];
};

struct Tstack{
    Titem item[MAX];
    Pointer top;
};

void makeEmptyStack(Tstack &stack){
    stack.top = -1;
}

bool isEmptyStack(Tstack &stack){
    return (stack.top == -1);
}

void toStack(Titem item, Tstack &stack){
    if(stack.top == MAX){
        cout << "Stack is full";
    }else{
        stack.top++;
        stack.item[stack.top] = item;
    }
}

void unstack(Titem &item, Tstack &stack){
    if (isEmptyStack(stack)){
        cout << "Empty stack";
        item.code = -1;
    }else{
        item = stack.item[stack.top];
        stack.top--;
    }
}

int stackSize(Tstack &stack){
    return (stack.top + 1);
}

int menu(){
    int op = 5;
    
    do{
        cout << "Choose an option by number: " <<endl;
        cout << "1 - To stack" << endl;
        cout << "2 - Unstack" << endl;
        cout << "3 - Show stack size" << endl;
        cout << "0 - Close" << endl;
        cin >> op;
    }while((op > 3) || (op < 0));

    return op;
}


int main(){
    Tstack stack;
    Titem item;
    int op;

    makeEmptyStack(stack);

    op = menu();

    while(op != 0){
        switch(op){
            case 1:
                cout << "INSERT ITEM\n";
                cout<< "Type the item code: " << endl;
                cin>>item.code;
                cout << "Type the item name: " <<endl;
                cin>>item.name;
                toStack(item, stack);
                break;
            case 2:
                cout << "REMOVE ITEM\n";
                cout<< "Unstacking item.." << endl;
                unstack(item, stack);
                if(item.code > 0){
                    cout<<"Item not removed\n";
                    cout<<"Code: " << item.code <<endl;
                    cout<<"Name: " << item.name << endl;
                }
                break;
            case 3:
                cout << "STACK SIZE\n";
                cout<< "Number of items on stack: " << stackSize(stack) << endl;
                break;
            default:
                cout<< "Invalid option!\n";
                break;
        }
        op = menu();
    }
    return 0;
}
