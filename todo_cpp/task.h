#ifndef TASK_H
#define TASK_H

typedef enum { INCOMPLETE, COMPLETE } Status;

typedef struct {
   char description[100];
   Status status;
   char deadline[20];
} Task;

#endif /* TASK_H */
