#include <iostream>
#include <cstdlib>

using namespace std;

int *p1, *p2;

int add (){
    return (*p1 + *p2);
}

int sub(){
    return (*p1 - *p2);
}

int mult(){
    return (*p1 * *p2);
}


int div(){
    return (*p1 / *p2);  
}

int main(){
    
    int x = 10;
    int *PX;

    PX = &x;

    cout << "the value of variable X is: " << x << endl;

    *PX = *PX + 3;

    cout << "the value of variable X is: " << x << endl;


    cout << "-------OPERATIONS---------- " << endl;

    int option;
    int value1, value2;

    p1 = &value1;
    p2 = &value2;

    cout << "First value: ";
    cin >> value1;
    cout << "Second value: ";
    cin >> value2;

    cout << "\nType on operation by number: " <<endl;
    cout << "1 - Addition\n";
    cout << "2 - Subtraction\n";
    cout << "3 - Multiplication\n"; 
    cout << "4 - Division\n"; 
    cin >> option;

    switch(option){
        case 1:
            cout << "Add: " << add();
            break;
        case 2:
            cout << "Sub: " << sub();
            break;
        case 3:
            cout << "Mult: " << mult();
        case 4:
            cout << "Div: " << div();
            break;
        default:
            cout << "Not a number valid";
            break;
    }

    return 0;

}
