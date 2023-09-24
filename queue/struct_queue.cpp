#include <iostream>
using namespace std;
#define queue_size 5

typedef struct{
    int a;
    int b;
    int c;
}datas_t;

class queue{
public:
    int rear = 0;
    int front = 0;
    datas_t queue[queue_size];

    int push(datas_t value)
    {
        cout<<"push {"<<value.a<<" "<<value.b<<" "<<value.c<<"}"<<endl;
        queue[rear] = value;
        rear++;
    }
    
    int pop()
    {
        rear--;
        cout<<"{"<<queue[0].a<<" "<<queue[0].b<<" "<<queue[0].c<<"} 제거"<<endl;
        for(int i =0;i<queue_size; i++){
            queue[i] = queue[i+1];
        }
    }
    void show(){
        cout<<"result :"<<endl;
        for(int i = 0; i<queue_size; i++){
            cout<<queue[i].a<< " "<<queue[i].b<< " "<<queue[i].c<< endl;
        }
        cout<<endl;
        cout<<"addr :"<<endl;
        for(int i = 0; i<queue_size; i++){
            cout<<&queue[i].a<< " "<<&queue[i].b<< " "<<&queue[i].c<< endl;
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
    q.push(first_data);
    q.show();
    q.push(second_data);
    q.show();
    q.push(third_data);
    q.show();
    q.pop();
    q.show();
}
