#include <cstdlib>
#include <iostream>

using namespace std;

typedef enum {dom, seg, ter, qua, qui, sex, sab} dias_semana;

int main(int argc, char const *argv[])
{
    dias_semana dia;
    int num;

    cout << "Digite um numero de 1 a 7: ";
    cin>> num;

    switch (num -1)
    {
    case dom:
        cout << "Domingo";
        break;
    case seg:
        cout << "Segunda-feira";
        break;
    case ter:
        cout << "Terça-feira";
        break;
    case qua:
        cout << "Quarta-feira";
        break;
    case qui:
        cout << "Quinta-feira ";
        break;
    case sex:
        cout << "Sexta-feira";
        break;
    case sab:
        cout << "Sábado ";
        break;
    default:
        break;
    }

    cout<<endl;
    return 0;
}
