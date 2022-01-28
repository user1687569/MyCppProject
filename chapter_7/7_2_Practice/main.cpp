//Copyright (c) 2022 user1687569
#include <iostream>

const int MAXCOUNT = 10;
int enterScores(double scores[]);
void showScores(double scores[], int n);
double calculateAverage(double scores[], int n);

int main()
{
    int count = 0;
    double scores[10];

    count = enterScores(scores);
    showScores(scores, count);
    calculateAverage(scores, count);

    return 0;
}

int enterScores(double scores[])
{
    int count = 0;
    double score;

    std::cout << "Please enter up to 10 golf scores: " << std::endl;
    while(std::cin >> score && count < MAXCOUNT)
    {
        scores[count] = score;
        count++;
    }

    return count;
}

void showScores(double scores[], int n)
{
    std::cout << "You entered " << n << " number." << std::endl;
    std::cout << "Score list: ";
    for(int i = 0; i < n; i++)
    {
        std::cout << scores[i] << " ";
    }

    return;
}

double calculateAverage(double scores[], int n)
{
    double sum = 0;
    double average = 0;
    for(int i = 0; i < n; i++)
    {
        sum += scores[i];
    }

    average = sum / n;
    std::cout << "Average score is: " << average << std::endl;
    return average;
}