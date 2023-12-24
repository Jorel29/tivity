#include "task.h"
#include <iostream>
#include <string>
#include <vector>

#define DBG(txt, x) std::cout<< txt << " " << x << std::endl;

void new_task(std::vector<Task> &t_list, unsigned int &currid)
{
  std::string desc;
  unsigned int priority;
  DBG("new task function", "t_list")
  std::cout << "Write a description for this new task" << std::endl;
  std::cin >> desc;
  std::cout <<"What priority is this task?" << std::endl;
  std::cin >> priority;
  while(std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cout << "Invalid input, put in a number" << std::endl;
    std::cin >> priority;
  }
}

int main()
{
  unsigned int taskids = 0;
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
        new_task(m_task_list, taskids);
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
