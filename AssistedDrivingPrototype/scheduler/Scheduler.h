#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "../scheduler/Task.h"
#include "../scheduler/Timer.h"

#define MAX_TASKS 10

class Scheduler : public Runnable {
  
  int basePeriod;
  int nTasks;
  Task* taskList[MAX_TASKS];  
  Timer* timer;

public:
  
  void init(int basePeriod);  
  virtual bool addTask(Task* task);
  virtual void run();
  virtual void sleep();
};

#endif
