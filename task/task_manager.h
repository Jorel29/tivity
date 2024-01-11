#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <string>
#include <vector>

#include "task.h"

class TaskManager {
public:
  TaskManager(std::string filename);
  void start();
  void stop();

private:
  friend class Writer;
  friend class Manager;
  bool m_is_running;
  std::string m_filename;
};

#endif
