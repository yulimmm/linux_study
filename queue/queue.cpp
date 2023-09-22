#include <iostream>
#include <queue>

using namespace std;

// 사용자 정의 구조체 정의
struct MyStruct {
    int data1;
    double data2;
    // 추가 필드나 멤버 함수를 정의할 수 있습니다.
};

int main() {
    // 큐 생성
    std::queue<MyStruct> myQueue;

    // 구조체 요소 추가
    MyStruct element1 = {1, 3.14};
    MyStruct element2 = {2, 2.71};
    cout<<"element1: "<<element1.data1<<endl;
    cout<<"element1: "<<element1.data2<<endl;
    cout<<"element2: "<<element2.data1<<endl;
    cout<<"element2: "<<element2.data2<<endl;

    myQueue.push(element1);
    myQueue.push(element2);

    cout<<myQueue.front().data2<<endl;

    // 큐의 첫 번째 구조체 출력
    while (!myQueue.empty()) {
        MyStruct frontElement = myQueue.front();
        std::cout << "Front element data1: " << frontElement.data1 << ", data2: " << frontElement.data2 << std::endl;
        myQueue.pop();
    }

    return 0;
}
