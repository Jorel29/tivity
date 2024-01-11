#include "task.h"
#include <iostream>
#include <ios>
#include <limits>
#include <string>
#include <vector>
#include <fstream>

#define DBG(txt, x) std::cout<< txt << " " << x << std::endl;
#define MAX_DESC_CHAR_LEN 1000
//TODO - Be able to specify which file to read at startup
//     - Create a task_manager API 
//     - Specify which functions to expose to the user
//     - Find out if calling member m_filename is valid
//     - Check if file actually compiles
class Writer{
  public:
    static unsigned int read(std::vector<Task> &t_list, std::string filename)
    {
      //need to find max id somehow (task ids need to be unique)
      std::ifstream in;
      in.open(filename);
      
      unsigned int max_id = 0;
      unsigned int taskid;
      bool is_complete;
      unsigned int priority;
      char input_desc[MAX_DESC_CHAR_LEN];
      std::string desc;
      if(!in.is_open()) return max_id;

      while(!in.fail()) 
      {
        if (in >> taskid >> is_complete >> priority)
        {
          if(taskid > max_id)
          {
            max_id = taskid;
          }
          in.getline(input_desc,MAX_DESC_CHAR_LEN,'\n'); 
          desc = input_desc;
          Task task = Task(taskid, is_complete, priority, desc);
          DBG("existing task ", task)
          t_list.push_back(task);
        }
      }
      return max_id + 1;
    }

    static int full_write(std::vector<Task> &t_list, std::string filename)
    {
      std::ofstream out;
      out.open(filename, std::ios::out);

      for (Task task : t_list)
      {
        if(out.is_open())
        {
          out << task;
        }
        else 
        {
          return -1;  
        }
      }

      return 0;
    }

    static int write(Task &task, std::string filename)
    {
      std::ofstream out;
      out.open(filename, std::ios::app);
      
      if(out.is_open())
      {
        out << task;
      }
      else 
      {
        return -1;
      }
      
      return 0;
    }
}

class Manager{
  private:
    friend class Writer;
  public:
    Manager() = default;
    ~Manager() = default;

    void new_task(std::vector<Task> &t_list, unsigned int &curr_id)
    {
      std::string desc;
      unsigned int priority;
      std::cout << "Write a description for this new task" << std::endl;
      std::cin.ignore();
      std::getline(std::cin, desc); 
      std::cout <<"What priority is this task?" << std::endl;
      std::cin >> priority;

      while(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, put in a number" << std::endl;
        std::cin >> priority;
      }
      Task new_task = Task(curr_id, priority, desc);
      Writer::write(new_task, m_filename);
      t_list.push_back(new_task);
      curr_id++;
    }

    void view_tasks(std::vector<Task> &t_list)
    {
      if (t_list.empty())
      {
        std::cout << "There are no tasks" << std::endl;
      }
      for (Task a_task : t_list)
      {
        std::cout << a_task << std::endl;
      }
    }

    void edit_status(Task &task)
    {
      char input;
      while(true)
      {
        std::cout << "Status: " << task.is_complete() << std::endl;
        std::cout << "Mark Complete(c)   Mark Incomplete(i) Done Marking(d)" << std::endl;
        std::cin >> input;
        if (input == 'd') break;

        switch(input)
        {
          case 'c':
            task.mark_complete();
            break;
          case 'i':
            task.mark_incomplete();
            break;
          default:
            DBG("Invalid input ", input)
            break;
        }

      }

    }

    void set_priority(Task &task)
    {
      unsigned int new_priority;
      std::cout << "Write a new priority for this task" << std::endl;
      std::cin >> new_priority;
      while(std::cin.fail())
      {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, put in a proper priority" << std::endl;
        std::cin >> new_priority;
      }
      
      task.set_priority(new_priority);
    }


    void edit_desc(Task &task)
    {
      std::string new_desc;
      std::cout << "Write a new description for this task" << std::endl;
      std::cin.ignore();
      std::getline(std::cin, new_desc);
      while(std::cin.fail())
      {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, put in a proper description" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, new_desc);
      }

      task.edit_desc(new_desc);
    }

    void manage_tasks(std::vector<Task> &t_list)
    {
      view_tasks(t_list);
      unsigned int taskid;
      std::cout << "Select a task" << std::endl;
      std::cin >> taskid;
      while(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, input a proper id (positive integer)" << std::endl;
        std::cin >> taskid;
      }

      std::cout << "Managing task: " << taskid << std::endl;
      Task &managed_task = t_list[taskid];

      char input;
      while (true) 
      {
        std::cout << managed_task << std::endl;
        std::cout << "Task Status (s)   Set Priority (p)   Edit Desc (d)   Remove Task (r)  Exit Management(e)" << std::endl;
        std::cin >> input;
        if(input == 'e') break;
        
        if(input == 'r')
        {
          std::cout << "Would you like to remove this task? [y / n]" << std::endl;
          std::cin >> input;
          if (input == 'y')
          {
            t_list.erase(t_list.begin() + taskid);
            Writer::full_write(t_list, m_filename);
            break;
          }else {
            continue;
          }
        }

        switch (input) {
          case 's':
            edit_status(managed_task);
            break;

          case 'p':
            set_priority(managed_task);
            break;

          case 'd':
            edit_desc(managed_task);
            break;
          
          default:
            DBG("Invalid input ", input)
            break;
        }
        Writer::full_write(t_list, m_filename);
      }
      
    }

    int runner()
    {
      unsigned int curr_id = 0;
      char input;
      std::vector<Task> m_task_list;
      curr_id = Writer::read(m_task_list, m_filename);
      while(m_is_running)
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
            new_task(m_task_list, curr_id);
            break;
          case 'v':
            //prompt view task menu
            view_tasks(m_task_list);
            break;
          case 'm':
            //manage tasks menu
            manage_tasks(m_task_list);
            break;
          default:
            DBG("Invalid input", input)
            break;
        }
      }
      return 0;
    }
}
