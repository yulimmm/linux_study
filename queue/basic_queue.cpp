#include <iostream>
using namespace std;
#define queue_size 5

class queue{
public:
    int rear = 0;
    int front = 0;
    int queue[queue_size];

    int push(int value)
    {
        cout<<"push "<<value<<endl;
        queue[rear] = value;
        rear++;
    }
    int pop()
    {
        rear--;
        cout<<queue[0]<<" 제거"<<endl;
        for(int i =0;i<queue_size; i++){
            queue[i] = queue[i+1];
        }
    }
    void show(){
        cout<<"result = ";
        for(int i = 0; i<queue_size; i++){
            cout<<queue[i]<< " ";
        }
        cout<<endl;
        cout<<"addr = ";
        for(int i = 0; i<queue_size; i++){
            cout<<&queue[i]<< " ";
        }
        cout<<endl;
    }
};

int main()
{
    class queue q;
    q.push(3);
    q.show();
    q.push(5);
    q.show();
    q.push(7);
    q.show();
    q.pop();
    q.show();
    q.pop();
    q.show();
    return 0;

}
