#include "task.h"
#include <stdio.h>
#include <string.h>

// Function to create a new task
Task create_task(const char* description, const char* deadline) {
   Task newTask;
   strcpy(newTask.description, description);
   newTask.status = INCOMPLETE;
   if (deadline) {
      strcpy(newTask.deadline, deadline);
   } else {
      strcpy(newTask.deadline, "N/A");
   }
   return newTask;
}

// Function to display task details
void display_task(const Task* task) {
   printf("Task: %s\nStatus: %s\nDeadline: %s\n\n", task->description,
          (task->status == INCOMPLETE) ? "Incomplete" : "Complete",
          task->deadline);
   return;
}

// Function to mark a task as complete
void mark_task_complete(Task* task) {
   task->status = COMPLETE;
   return;
}
