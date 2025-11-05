#include <stdio.h>
#include <string.h>


struct Student {
    int rollNo;
    char name[50];
    int age;
    float avgMarks;
};

int main() {
    struct Student s[100];
    int n, i, j;
    struct Student temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

 
    for(i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }

 
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(s[j].avgMarks < s[j + 1].avgMarks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    
    printf("\nStudents sorted in descending order of Average Marks:\n");
    printf("RollNo\tName\tAge\tAverage\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%.2f\n", s[i].rollNo, s[i].name, s[i].age, s[i].avgMarks);
    }

    return 0;
}
