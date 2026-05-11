#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int roll_no;
    char division[10];
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int count = 0;

void addStudent() {
    if (count >= MAX_STUDENTS) {
        printf("Maximum capacity reached. Cannot add more students.\n");
        return;
    }
    struct Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);
    printf("Enter Division: ");
    scanf(" %s", s.division);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    
    students[count] = s;
    count++;
    printf("Student added successfully.\n");
}

void displayStudents() {
    if (count == 0) {
        printf("\nNo students to display.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d, Division: %s, Name: %s, Marks: %.2f\n", students[i].roll_no, students[i].division, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    if (count == 0) {
        printf("\nNo students to search.\n");
        return;
    }
    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll) {
            printf("\nStudent Found: Roll No: %d, Division: %s, Name: %s, Marks: %.2f\n", students[i].roll_no, students[i].division, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}