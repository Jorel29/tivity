#include "task.h"
#include <iostream>
#include <string>
#include <vector>

#define DBG(txt, x) std::cout<< txt << " " << x << std::endl;

void new_task(std::vector<Task> &t_list)
{
  DBG("new task function", "t_list")
}

int main()
{
  char input;
  std::vector<Task> m_task_list;
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
        new_task(m_task_list);
        break;
      case 'v':
        //prompt view task menu
        DBG("view task", input)
        break;
      case 'm':
        //manage tasks menu
        DBG("manage tasks", input)
        break;
      default:
        DBG("invalid input", input)
        break;
    }
  };
  return 0;
};
