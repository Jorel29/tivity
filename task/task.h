#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
	private:
		unsigned int m_taskID;
		unsigned int m_priority;
		std::string m_desc;
		bool m_is_complete;

	public:
		//default constructor
	  
		Task();

		Task(unsigned int id);
		
		Task(unsigned int id, unsigned int priority);

		Task(unsigned int id, unsigned int priority, std::string desc);
		
    Task(unsigned int id, bool is_complete, unsigned int priority, std::string desc);

    void edit_desc(std::string new_desc);

		void mark_complete();

		void mark_incomplete();

		void set_priority(unsigned int new_priority);

		const unsigned int get_taskid();

		const unsigned int get_priority();

		const std::string get_desc();
		
		const bool is_complete();

    friend std::ostream& operator<<(std::ostream& os, const Task& t);
};

#endif
