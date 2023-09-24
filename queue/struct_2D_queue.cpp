#include <iostream>
using namespace std;
#define queue_size 3
#define data_size 5

typedef struct{
    int a;
    int b;
    int c;
}datas_t;

class queue{
public:
    int rear = 0;
    int front = 0;
    datas_t queue[queue_size][data_size];

    int push(datas_t *values, int size)
    {
        size = data_size;
        cout<<"push: "<<endl;
        for(int i =0;i<size;i++){
            cout<<"{" << values[i].a << " "<< values[i].a << " "<< values[i].a <<"}"<<endl;
        }
        for(int i = 0; i<size; i++){
            queue[rear][i] = values[i];
        }
        rear++;
    }
    
    int pop()
    {
        rear--;
        int size = 5;
        cout<<"remove: "<<endl;
        for(int i =0;i<size;i++){
            cout<<"{" << queue[0][i].a << " "<< queue[0][i].a << " "<< queue[0][i].a <<"}"<<endl;
        }

        for(int i =0;i<queue_size; i++){
            for(int j =0; j<size; j++){
                queue[i][j] = queue[i+1][j];
            }
        }
    }
    
    void show(){
        cout<<"result :"<<endl;
        for(int i = 0; i<queue_size; i++){
            for(int j = 0; j<data_size; j++){
                cout<<queue[i][j].a<< " "<<queue[i][j].b<< " "<<queue[i][j].c<< endl;
            }
        }
        cout<<endl;
        cout<<"addr :"<<endl;
        for(int i = 0; i<queue_size; i++){
            for(int j = 0; j<data_size; j++){
                cout<<&queue[i][j].a<< " "<<&queue[i][j].b<< " "<<&queue[i][j].c<< endl;
            }
        }
        cout<<endl;
    }
};

int main()
{
    class queue q;
    datas_t first_data = {1,1,1};
    datas_t second_data = {2,2,2};
    datas_t third_data = {3,3,3};
    datas_t fourth_data = {4,4,4};
    datas_t fifth_data = {5,5,5};

    datas_t first_values[5];
    first_values[0] = first_data;
    first_values[1] = second_data;
    first_values[2] = third_data;
    first_values[3] = fourth_data;
    first_values[4] = fifth_data;

    datas_t second_values[5];
    second_values[0] = third_data;
    second_values[1] = third_data;
    second_values[2] = third_data;
    second_values[3] = third_data;
    second_values[4] = third_data;

    datas_t array[2][5];
    for(int i = 0; i<5;i++){
        array[0][i] = first_values[i];
    }
    for(int i = 0; i<5;i++){
        array[1][i] = second_values[i];
    }

    q.push(array[0], 5);
    q.push(array[1], 5);
    q.pop();
    q.show();
}
