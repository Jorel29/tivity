#include "task.h"
#include <string>
#include <iostream>

#define DEFAULT_DESC "Write a description for this task..."

Task::Task()
{
	m_taskID = 0;
	m_priority = 0;
	m_desc = DEFAULT_DESC;
	m_is_complete = false;
};

Task::Task(unsigned int id)
{
	m_taskID = id;
	m_priority = 0;
	m_desc = DEFAULT_DESC;
	m_is_complete = false;
};

Task::Task(unsigned int id, unsigned int priority)
{
	m_taskID = id;
	m_priority = priority;
	m_desc = DEFAULT_DESC;
	m_is_complete = false;
};

Task::Task(unsigned int id, unsigned int priority, std::string desc)
{
	m_taskID = id;
	m_priority = priority;
	m_desc = desc;
	m_is_complete = false;
};

Task::Task(unsigned int id, bool is_complete, unsigned int priority, std::string desc)
{
  m_taskID = id;
  m_priority = priority;
  m_desc = desc;
  m_is_complete = is_complete;
};

void Task::edit_desc(std::string new_desc)
{
	m_desc = new_desc;
};

void Task::mark_complete(){ m_is_complete = true; };

void Task::mark_incomplete(){ m_is_complete = false; };

void Task::set_priority(unsigned int new_priority)
{
	m_priority = new_priority;
};

const unsigned int Task::get_taskid()
{
	return m_taskID;
};

const unsigned int Task::get_priority()
{
	return m_priority;
};

const std::string Task::get_desc()
{
	return m_desc;
};

const bool Task::is_complete()
{
	return m_is_complete;
};

std::ostream& operator<<(std::ostream& os, const Task& t)
{
  os << t.m_taskID << " " << t.m_is_complete << " " << t.m_priority << " " << t.m_desc << "\n";
  return os;
};
