#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>

#include "task.h"

class TaskManager {
public:
  TaskManager(std::string filename);
  void start();
  void stop();
private:
  bool is_running;
  unsigned int read(std::vector<Task> &t_list);
  int full_write(std::vectore<Task> &t_list);
  int write(Task &task);
  void new_task(std::vector<Task> &t_list, unsigned int &curr_id);

};

TaskManager::TaskManager() {
}

TaskManager::~TaskManager() {
}

#endif
