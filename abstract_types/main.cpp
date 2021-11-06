#include <iostream>

using namespace std;

int main(){

    struct product {
        int weight;
        double price;
    };

    product product1;
    product1.weight = 10;
    product1.price = 20.21;

    cout << "Produto preço: " << product1.price;
    cout << "Produto: " << product1;

    return 0;
}
