#include "task.h"
#include <iostream>
#include <string>

#define DBG(txt, x) std::cout<< txt << x << std::endl;

int main()
{
  char input;
  std::vector<Task> TaskList;
  while(true)
  {
    std::cout << "Welcome to tivity!" << std::endl;
    std::cout << "New Task (n)   View Tasks (v)   Manage Tasks (m)   Quit(q)" << std::endl;
    std::cin >> input;
    if(input == 'q')
    {
      break;
    }
    switch (input) {
      case 'n':
        //Prompt new task menu
        DBG("new task", input)
        break;
      case 'v':
        //prompt view task menu
        DBG("view task", input)
      case 'm':
        //manage tasks menu
        DBG("manage tasks", input)
      default:
        DBG("invalid input", input)
        break;
    }
  };
  return 0;
};
