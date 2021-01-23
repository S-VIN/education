#include <iostream>
#include "Deque.h"


void PrintDeq(Deque<int> a){
    for(int i = 0; i < a.Size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {

    Deque<int> a{ {1, 2, 3}};


    PrintDeq(a);

    a.PushBack(4);
    a.PushBack(4);


    PrintDeq(a);

    cout << a.At(0) << " " << a.At(a.Size() - 1) << endl;
    cout << a.Size() << endl;
    cout << a.Back() << " " << a.Front()<< endl;



    return 0;
}
