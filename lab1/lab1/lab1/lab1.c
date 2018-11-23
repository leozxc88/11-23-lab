#include<stdio.h>
#include<stdlib.h>
#define students 3
#define exams 4

void mini(int grade[][exams], int pupils, int tests);
void maxi(int grade[][exams], int pupils, int tests);
void average(int grade[][exams], int pupils, int tests);
void printarray(int grade[][exams], int pupils, int tests);
void printmenu(void);

int main()
{
	void(*processGrades[4])(int[][exams], int, int) = { printarray,mini,maxi,average };
	int choice = 0;
	int studentGrades[students][exams] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };
	while (choice != 4)
	{
		do
		{
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
		{
			(*processGrades[choice])(studentGrades, students, exams);
		}
		else
		{
			printf("Program Ended.\n");
		}
	}
	system("pause");
	return 0;
}

void mini(int grade[][exams], int pupils, int tests)
{
	int i, j, lowGrade = 100;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grade[i][j] < lowGrade)
			{
				lowGrade = grade[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d\n", lowGrade);
}
void maxi(int grade[][exams], int pupils, int tests)
{
	int i, j, highGrade = 0;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grade[i][j] > highGrade)
			{
				highGrade = grade[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d\n", highGrade);
}
void average(int grade[][exams], int pupils, int tests)
{
	int i, j,total= 0;
	printf("\n");

	for (i = 0; i < pupils; i++)
	{
		total = 0;
		for (j = 0; j < tests; j++)
		{
			total+=grade[i][j];
		}
		printf("\tThe average for student is %d %.1f\n",i+1,(double)total/tests);
	}
}
void printarray(int grade[][exams], int pupils, int tests)
{
	int i, j;
	printf("\n\t	       [0]    [1]    [2]    [3]");
	for (i = 0; i < pupils; i++)
	{
		printf("\n\tstudentgrade[%d]", i);
		for (j = 0; j < tests; j++)
		{
			printf("%-7d", grade[i][j]);
		}
	}
	printf("\n");
}
void printmenu(void)
{
	printf("\n\tEnter a choice:\n"
		"\t  0 Print the array of grades\n"
		"\t  1 Find the minimum grade\n"
		"\t  2 Find the maximum grade\n"
		"\t  3 Find the average on all"
		" tests for each student\n"
		"\t  4 End program\n"
		"\t?");
}