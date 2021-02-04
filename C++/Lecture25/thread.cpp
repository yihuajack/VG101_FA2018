#include <iostream>       // std::cout
#include <thread>         // std::thread
 
int global = 1;

void foo() 
{
  while(global != 0)
  {
    std::cout << "global = " << global << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void bar(int x)
{
  while(global != 0) std::cin >> global;
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();  // pauses until first finishes
  second.join(); // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}
