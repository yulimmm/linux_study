#include <iostream>
#define queue_size 4
#define size 5
using namespace std;

typedef struct{
    int a;
    int b;
    int c;
}datas_t;

int rear = 0;
int front = 0;
datas_t *queue[queue_size][size];

int push(datas_t *values[])
{
    cout<<"add: "<<endl;
    for(int i = 0; i<size; i++){
        cout<<values[i]->a<<" "<<values[i]->b<<" "<<values[i]->c<<endl;
    }
    cout<<endl;
    for(int i = 0; i< size; i++){
        queue[rear][i] = values[i];
    }
    cout<<"====== done push =========\n";
    rear++;
    return 0;
}

datas_t* pop()
{
    datas_t* return_data = new datas_t[5];
    cout<<"delete:"<<endl;
    for(int i = 0; i<5; i++){
        cout<<queue[0][i]->a<<" "<<queue[0][i]->b<<" "<<queue[0][i]->c<<endl;
        return_data[i] = *(queue[0][i]);
    }

    cout<<endl;
    for(int i =0;i<queue_size; i++){
        for(int j =0; j<size; j++){
            queue[i][j] = queue[i+1][j];
        }
    }
    cout<<"====== done pop =========\n";
    rear--;
    return return_data;
}

int main() {

    datas_t *arr1[5];
    for(int i = 0; i<5; i++){
        arr1[i] = new datas_t;
        arr1[i]->a = 10;
        arr1[i]->b = 20;
        arr1[i]->c = 30;
    }

    datas_t *arr2[5];
    for(int i = 0; i<5; i++){
        arr2[i] = new datas_t;
        arr2[i]->a = 40;
        arr2[i]->b = 50;
        arr2[i]->c = 60;
    }

    datas_t *arr3[5];
    for(int i = 0; i<5; i++){
        arr3[i] = new datas_t;
        arr3[i]->a = 70;
        arr3[i]->b = 80;
        arr3[i]->c = 90;
    }

    push(arr1);
    push(arr2);
    datas_t* result = pop();
    for(int i = 0; i< 5; i++){
        //cout<<result[i].a<<" "<<result[i].b<<" "<<result[i].c<<endl;;
    }
    push(arr3);

    cout<<"-=-=-=-=-=-=-=-= result -=-=-=-=-=-=-=-=-=\n";
    for(int q =0; q <4; q++){
        for(int i = 0; i<5; i++){
            cout<< queue[q][i]->a <<" "<<queue[q][i]->b <<" "<<queue[q][i]->c<<endl;
        }
        cout<<endl;
    }

    return 0;
}
