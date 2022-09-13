#include "List.h"
#include "Array.h"

void kizk(){

    Array a;
    InitArray(a);
    PrintArray(a);
    Del(a, 2);
    PrintArray(a);
    Add(a, 2, 2);
    PrintArray(a);
}


int main(){
    
    kizk();
    return 0;

}