#include <stdio.h>

#define CAPACITY 5
#define SCORES 3

struct Student
{
    int id;
    int scores[SCORES];
    int scores_count;
    int average_grade;
};

int main()
{
    struct Student classroom[CAPACITY];
    int student_count = 0;

    // manually create the students
    classroom[0].id = 100;
    student_count++;
    classroom[0].scores_count = 0;
    classroom[0].scores[0] = 90;
    classroom[0].scores_count++;
    classroom[0].scores[1] = 91;
    classroom[0].scores_count++;
    classroom[0].scores[2] = 89;
    classroom[0].scores_count++;
    classroom[0].average_grade = 0;

    classroom[1].id = 101;
    student_count++;
    classroom[1].scores_count = 0;
    classroom[1].scores[0] = 75;
    classroom[1].scores_count++;
    classroom[1].scores[1] = 40;
    classroom[1].scores_count++;
    classroom[1].scores[2] = 61;
    classroom[1].scores_count++;
    classroom[1].average_grade = 0;

    classroom[2].id = 102;
    student_count++;
    classroom[2].scores_count = 0;
    classroom[2].scores[0] = 94;
    classroom[2].scores_count++;
    classroom[2].scores[1] = 85;
    classroom[2].scores_count++;
    classroom[2].scores[2] = 97;
    classroom[2].scores_count++;
    classroom[2].average_grade = 0;

    for (int outer_i = 0; outer_i < student_count; outer_i++)
    {
        printf("\n");
        printf("student name: %d\n", classroom[outer_i].id);
        for (int inner_i = 0; inner_i < classroom[outer_i].scores_count; inner_i++)
        {
            printf("score %d: %d\n", inner_i + 1, classroom[outer_i].scores[inner_i]);
        }
        classroom[outer_i].average_grade = (classroom[outer_i].scores[0] + classroom[outer_i].scores[1] + classroom[outer_i].scores[2]) / SCORES;
        printf("average grade: %d\n", classroom[outer_i].average_grade);
    }

    //print the student with the highest average
    int max = classroom[0].average_grade;
    if (classroom[1].average_grade > max) max = classroom[1].average_grade;
    if (classroom[2].average_grade > max) max = classroom[2].average_grade;
    printf("the highest average grade was: %d\n", max);

    return 0;
}