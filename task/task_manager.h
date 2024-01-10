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
  friend class Manager;
  friend class Writer;
  bool is_running;
  std::string m_filename;
};

#endif
