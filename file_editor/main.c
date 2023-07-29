#include <stdio.h>
#include <stdlib.h>

void display_menu();
void create_new_file();
void open_file();
void save_file(FILE *file);
void edit_file(FILE *file);

int main() {
   int choice;
   FILE *file = NULL;

   while (1) {
      display_menu();
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            create_new_file();
            break;
         case 2:
            open_file();
            break;
         case 3:
            if (file != NULL) {
               fclose(file);
            }
            printf("Exiting text editor.\n");
            return 0;
         default:
            printf("Invalid choice. Please try again.\n");
      }
   }
   return 0;
}

void display_menu() {
   printf("\n--- Simple Text Editor Menu ---\n");
   printf("1. Create a new file\n");
   printf("2. Open an existing file\n");
   printf("3. Exit\n");
}

void create_new_file() {
   char filename[100];
   printf("Enter the name of the new file: ");
   scanf("%s", filename);

   FILE *file = fopen(filename, "w");

   if (file == NULL) {
      printf("Error creating the file.\n");
      return;
   }

   printf("File '%s' created successfully.\n", filename);

   edit_file(file);

   fclose(file);
}

void open_file() {
   char filename[100];
   printf("Enter the name of the file to open: ");
   scanf("%s", filename);

   FILE *file = fopen(filename, "r+");

   if (file == NULL) {
      printf("Error opening the file.\n");
      return;
   }

   printf("File '%s' opened successfully.\n", filename);

   edit_file(file);

   fclose(file);
}

void save_file(FILE *file) {
   if (file == NULL) {
      printf("No file is currently open.\n");
      return;
   }

   int c;
   while ((c = getchar()) != '\n' && c != EOF); // Flush stdin; this took me a while to figure out :D

   printf("Enter the new content for the file:\n");
   char content[1000];
   fgets(content, sizeof(content), stdin);

   fseek(file, 0, SEEK_SET);
   fputs(content, file);
   printf("File saved successfully.\n");
}

void edit_file(FILE *file) {
   if (file == NULL) {
      printf("No file is currently open.\n");
      return;
   }

   printf("Current content of the file:\n");

   int c;
   while ((c = fgetc(file)) != EOF) {
      putchar(c);
   }
   printf("Entering save file function");

   save_file(file);
}
