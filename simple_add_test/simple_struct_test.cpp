#include <iostream>

using namespace std;

typedef struct {
    int school_num;
    int people_num;
} NUM;

void A(NUM *num) {
    num->school_num = 1;
    num->people_num = 2;
}

int main() {
    int length = 3;
    NUM NUM_arr[length];
    for (int i = 0; i < length; i++) {
        A(&NUM_arr[i]);
    }

    for (int i = 0; i < length; i++) {
        cout << NUM_arr[i].school_num << endl;
    }
    
    return 0;

}
