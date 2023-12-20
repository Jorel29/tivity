#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "task.h"
#include <iostream>
#include <string>
#define MSGDEBUG(x) std::cout << x << std::endl;

TEST_CASE("task is initialized with default values"){
	Task* inittask = new Task();
	unsigned int taskid = inittask->get_taskid();
	unsigned int priority = inittask->get_priority();
       	std::string desc = inittask->get_desc();
	bool isComplete = inittask->is_complete();	

	SUBCASE("check id"){
		CHECK(taskid == 0);
	}
	SUBCASE("check priority"){
		CHECK(priority == 0);
	}
	SUBCASE("check desc"){
		std::string test = "Write a description for this task...";	
		std::cout<< "desc: " << desc << std::endl;
		int res = desc.compare(test);
		CHECK(res == 0);
	}
	SUBCASE("check task_status"){
		CHECK(isComplete == false);
	}
	delete inittask;
}

TEST_CASE("task is initialized with given id"){
	Task* task = new Task((unsigned int)(10));
	unsigned int taskid = task->get_taskid();
	CHECK(taskid == 10);
	delete task;
}

TEST_CASE("task is initialized with given id, priority"){
	Task* task = new Task((unsigned int)(17), (unsigned int)(6));
	unsigned int taskid = task->get_taskid();
	unsigned int priority = task->get_priority();
	std::cout << priority << std::endl;
	CHECK(taskid == 17);
	CHECK(priority == 6);
	delete task;
}

TEST_CASE("task is initialized with given id, priority, desc"){
	std::string desc("Desc");	
	Task* task = new Task((unsigned int)(30), (unsigned int)(3), desc);
	unsigned int taskid = task->get_taskid();
	unsigned int priority = task->get_priority();
	std::string curr_desc = task->get_desc();

	CHECK(taskid == 30);
	CHECK(priority == 3);
	int res = curr_desc.compare(desc);
	CHECK(res == 0);

	delete task;
}

TEST_CASE("task desc gets altered"){
	std::string desc("Desc");
	Task* task = new Task((unsigned int)(30), (unsigned int)(3), desc);
	std::string new_desc("New Task");
	unsigned int taskid = task->get_taskid();
	unsigned int priority = task->get_priority();

	CHECK(taskid == 30);
	CHECK(priority == 3);
	SUBCASE("check desc is updated from default"){
		task->edit_desc(new_desc);
		std::string curr_desc = task->get_desc();
	       	int res = curr_desc.compare(new_desc);
		CHECK(res == 0);
	}
	delete task;
}

TEST_CASE("task mark complete and unmark complete"){
	Task* task = new Task();
	task->mark_complete();

	bool isComplete = task->is_complete();

	CHECK(isComplete == true);
	task->mark_incomplete();
	isComplete = task->is_complete();
	CHECK(isComplete == false);

	delete task;

}

TEST_CASE("task priority gets updated"){
	Task* task = new Task();

	task->set_priority((unsigned int)(5));

	unsigned int priority = task->get_priority();

	CHECK(priority == 5);

	delete task;
}

