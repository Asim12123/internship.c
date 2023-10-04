// student grade mangement usiing c
#include <stdio.h>

#define MAX_SUBJECTS 10 

// Define a maximum number of subjects

struct Student 
{
    char name[50];
    char subjects[MAX_SUBJECTS][50];
    int scores[MAX_SUBJECTS];
    int numSubjects;
    float average;
    int highest;
    int lowest;
    char grade; 
};
    // New member to store the grade

void inputStudentInfo(struct Student *student) {
    printf("\nEnter student name: ");
    scanf("%s", student->name);

    printf("Enter the number of subjects (max %d): ", MAX_SUBJECTS);
    scanf("%d", &student->numSubjects);

    printf("Enter names and scores for %d subjects:\n", student->numSubjects);
    for (int i = 0; i < student->numSubjects; i++) {
        scanf("%s %d", student->subjects[i], &student->scores[i]);
    }
}

void calculateAverage(struct Student *student) {
    int total = 0;
    student->highest = student->scores[0];
    student->lowest = student->scores[0];
    for (int i = 0; i < student->numSubjects; i++) {
        total += student->scores[i];
        if (student->scores[i] > student->highest) {
            student->highest = student->scores[i];
        }
        if (student->scores[i] < student->lowest) {
            student->lowest = student->scores[i];
        }
    }
    student->average = (float)total / student->numSubjects;

    // Determine the grade
    
    if (student->average >= 90) {
        student->grade = 'O';
    } else if (student->average >= 80) {
        student->grade = 'E';
    } else if (student->average >= 70) {
        student->grade = 'A';
    } else if (student->average >= 60) {
        student->grade = 'B';
    }else if  (student->average>=40){
        student->grade= 'C';
    }
    else {
        student->grade = 'F';
    }
}

void displaySummary(struct Student *student) {
    printf("\nStudent Name: %s\n", student->name);
    printf("Number of Subjects: %d\n", student->numSubjects);
    printf("Subject Names and Scores:\n");
    for (int i = 0; i < student->numSubjects; i++) {
        printf("%s: %d\n", student->subjects[i], student->scores[i]);
    }
    printf("Average Score: %.2f\n", student->average);
    printf("Grade: %c\n", student->grade);
    printf("Highest Score: %d\n", student->highest);
    printf("Lowest Score: %d\n", student->lowest);
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];
    int highestScore = -1;
    int lowestScore = 101;
    int highestIndex, lowestIndex;

    for (int i = 0; i < numStudents; i++) {
        inputStudentInfo(&students[i]);
        calculateAverage(&students[i]);

        if (students[i].highest > highestScore) {
            highestScore = students[i].highest;
            highestIndex = i;
        }

        if (students[i].lowest < lowestScore) {
            lowestScore = students[i].lowest;
            lowestIndex = i;
        }
    }

    for (int i = 0; i < numStudents; i++) 
    {
        displaySummary(&students[i]);
    }

    printf("\nStudent with the highest average: %s\n", students[highestIndex].name);
    printf("Student with the lowest average: %s\n", students[lowestIndex].name);

    return 0;
}
