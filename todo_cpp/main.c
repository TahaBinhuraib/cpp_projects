#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "task.c"
#include "task.h"

#define MAX_TASKS 100

// Function prototypes
void print_menu();
void add_task(Task tasks[], int* taskCount);
void list_tasks(const Task tasks[], int taskCount);
void mark_task_completed_cli(Task tasks[], int taskCount);
void remove_completed_tasks(Task tasks[], int* taskCount);

int main() {
   Task tasks[MAX_TASKS];
   int taskCount = 0;
   char choice;

   do {
      print_menu();
      printf("Enter your choice: ");
      scanf(" %c", &choice);

      switch (choice) {
         case '1':
            add_task(tasks, &taskCount);
            break;
         case '2':
            list_tasks(tasks, taskCount);
            break;
         case '3':
            mark_task_completed_cli(tasks, taskCount);
            break;
         case '4':
            remove_completed_tasks(tasks, &taskCount);
            break;
         case 'q':
         case 'Q':
            printf("Exiting the program.\n");
            break;
         default:
            printf("Invalid choice. Try again.\n");
      }
   } while (choice != 'q' && choice != 'Q');

   return 0;
}

void print_menu() {
   printf("\n-- To-Do List Manager --\n");
   printf("1. Add Task\n");
   printf("2. List Tasks\n");
   printf("3. Mark Task as Complete\n");
   printf("4. Remove Completed Tasks\n");
   printf("Q. Quit\n");
}

void add_task(Task tasks[], int* taskCount) {
   if (*taskCount == MAX_TASKS) {
      printf("To-do list is full. Cannot add more tasks.\n");
      return;
   }

   char description[100];
   char deadline[20];
   printf("Enter task description: ");
   scanf(" %[^\n]", description);
   printf("Enter task deadline (or press Enter to skip): ");
   scanf(" %19[^\n]", deadline);

   tasks[*taskCount] = create_task(description, deadline);
   (*taskCount)++;

   printf("Task added successfully!\n");
}

void list_tasks(const Task tasks[], int taskCount) {
   if (taskCount == 0) {
      printf("No tasks in the to-do list.\n");
      return;
   }

   printf("-- To-Do List --\n");
   for (int i = 0; i < taskCount; i++) {
      printf("Task %d:\n", i + 1);
      display_task(&tasks[i]);
   }
}

void mark_task_completed_cli(Task tasks[], int taskCount) {
   if (taskCount == 0) {
      printf("No tasks in the to-do list.\n");
      return;
   }

   printf("Enter the task number to mark as complete: ");
   int taskNumber;
   scanf("%d", &taskNumber);

   if (taskNumber < 1 || taskNumber > taskCount) {
      printf("Invalid task number.\n");
   } else {
      mark_task_complete(&tasks[taskNumber - 1]);
      printf("Task marked as complete!\n");
   }
}

void remove_completed_tasks(Task tasks[], int* taskCount) {
   if (*taskCount == 0) {
      printf("No tasks in the to-do list.\n");
      return;
   }

   int i = 0;
   while (i < *taskCount) {
      if (tasks[i].status == COMPLETE) {
         // Remove the completed task by shifting all subsequent tasks
         for (int j = i; j < *taskCount - 1; j++) {
            tasks[j] = tasks[j + 1];
         }
         (*taskCount)--;
      } else {
         i++;
      }
   }

   printf("Completed tasks removed successfully!\n");
}
