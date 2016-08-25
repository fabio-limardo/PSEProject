#include "../scheduler/Scheduler.h"

#include "Arduino.h"
#include <avr/sleep.h>

void Scheduler::init(int basePeriod){
  this->basePeriod = basePeriod;
  timer = new Timer(this);
  timer->setupPeriod(basePeriod);  
  nTasks = 0;
}

bool Scheduler::addTask(Task* task){
  if (nTasks < MAX_TASKS -1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}
  
void Scheduler::run(){
  for (int i = 0; i < nTasks; i++){
    if (taskList[i]->updateAndCheckTime(basePeriod)){
      taskList[i]->tick();
    }    
  }
}

void Scheduler::sleep(){
  set_sleep_mode(SLEEP_MODE_IDLE);
  //documentation at http://www.atmel.com/webdoc/AVRLibcReferenceManual/group__avr__sleep.html
  sleep_enable();  
  sleep_mode();  
  /** The program will continue from here. **/  
  /* First thing to do is disable sleep. */  
  sleep_disable();   
  
}

