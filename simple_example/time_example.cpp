#include <iostream>
#include <chrono>

using namespace std;

int print_time()
{
  static int prev_time = 0;
  auto now = std::chrono::system_clock::now(); // 초로 변환
  auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now); // time_t로 변환
  std::time_t current_time = std::chrono::system_clock::to_time_t(seconds);
  auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
  long  long_ms = milliseconds;

  if (prev_time == current_time) 
      return 0;
  else {
      prev_time = current_time;
      std::cout << "현재 초: " << current_time << std::endl;
      cout<<"Final_json = "<<Final_json<<endl;
      return Final_json;
  }
  if((long_ms %1000) == 999){
    cout<<"long milliseconds"<<endl;
  }
}

int main()
{
  while(1){
    cout<<print_time()<<endl;
  }
  return 0;
}

