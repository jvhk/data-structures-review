#include <iostream>

using namespace std;

#define MAXSIZE 5

typedef int Pointer;

struct Titem{
    int Id;
    char Name[];
};

struct Tqueue{
    Titem item[MAXSIZE];
    Pointer head;
    Pointer tail;
};

void clear_queue(Tqueue &queue){
    queue.tail = queue.head - 1;
}

int is_empty_queue(Tqueue &queue){
    return queue.head == queue.tail;
}

void append_to_queue(Titem item,Tqueue &queue){
    queue.item[queue.tail -1] = item;
    queue.tail = (queue.tail % MAXSIZE + 1);
}

void remove_from_queue(Tqueue &queue, Titem &item){
    if(is_empty_queue(queue)){
        cout<< "\n\nEmpty queue!";
    }else{
        item = queue.item[queue.head - 1];
        queue.head = (queue.head % MAXSIZE + 1);
    }
}

int main(){
    return 0;
}
