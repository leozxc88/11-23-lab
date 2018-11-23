#include<stdio.h>
#include<stdlib.h>
#define issues 5
#define ratings 10

void record(int i, int response);
void highestratings();
void lowestratings();
float averageratings(int issue);
void displayresults();

int responses[issues][ratings];
const char *topics[issues] = { "Global Warming","the Economy","War","Heath Care","Education" };

int main(void)
{
	int response, i;
	do
	{
		printf("Please rate the following topics on a scale from 1 - 10"
			"\n 1=least important,10=most important\n");
		for (i = 0; i < issues; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("? ");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			record(i, response);
		}
		printf("Enter 1 to stop.Enter 0 to rate the issue again. ");
		scanf_s("%d", &response);
	} while (response != 1);
	displayresults();
	system("pause");
	return 0;
}
void record(int issue, int rating)
{
	responses[issue][rating - 1]++;
}
void highestratings(void)
{
	int highrating = 0, hightopic = 0, i, j;
	for (i = 0; i < issues; i++)
	{
		int topicrating = 0;
		for (j = 0; j < ratings; j++)
		{
			topicrating += responses[i][j]*(j+1);
		}
		if (highrating < topicrating)
		{
			highrating = topicrating;
			hightopic = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", topics[hightopic]);
	printf(" with a total rating of %d\n", highrating);
}
void lowestratings(void)
{
	int lowestratings = 0, lowtopic = 0, i, j;
	for (i = 0; i < issues; i++)
	{
		int topicrating = 0;
		for (j = 0; j < ratings; j++)
		{
			topicrating += responses[i][j] * (j + 1);
		}
		if (i == 0)
		{
			lowestratings = topicrating;
		}
		if (lowestratings > topicrating)
		{
			lowestratings = topicrating;
			lowestratings = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowtopic]);
	printf(" with a total rating of %d\n", lowestratings);
}
float averageratings(int issue)
{
	float total = 0;
	int counter = 0, j;
	for (j = 0; j < ratings; j++)
	{
		if (responses[issue][j] != 0)
		{
			total += responses[issue][j] * (j + 1);
			counter += responses[issue][j];
		}
	}
	return (total / counter);
}
void displayresults()
{
	int i, j;
	printf("%20s", "topic");
	for (i = 1; i <= ratings; i++)
	{
		printf("%4d", i);
	}
	printf("%20s", "Average Rating\n");
	for (i = 0; i < issues; i++)
	{
		printf("%20s", topics[i]);
		for (j = 0; j < ratings; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f\n", averageratings(i));
	}
	highestratings();
	lowestratings();
}