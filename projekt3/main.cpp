// wersja 2
#include <iostream>

void tableFill (int table[], int length)
{
    int i = 0;
    while(i < length)
    {
        printf("Wpisz wartosc dla %d elementu:\n", i+1);
        scanf("%d", table + i);
        i = i + 1;
    }

}

void printTable(int table[],int length)
{
    int i =0;
    while(i<length)
    {
        printf("Wartosc dla %d elementu: %d\n",i+1,*(table + i));
        i = i + 1;
    }

}
int findMin(int table[], int length)
{
    int min = *table;
    int i = 0;
    while(i < length)
    {
        if(min > *(table + i))
        {
            min = *(table + i);
        }
        i = i + 1;
    }
    return min;
}
int findMax(int table[], int length)
{
    int max = *table;
    int i = 0;
    while(i < length)
    {
        if(max < *(table + i))
        {
            max = *(table + i);
        }
        i = i + 1;
    }
    return max;
}
float findAvg(int table[], int length)
{
    int sum = 0;
    float average = 0;
    int i = 0;
    while(i < length)
    {
        sum = sum + *(table + i);
        i = i + 1;
    }
    average = (float)sum/length;
    return average;

}
float findMedian(int table[],int length)
{
    float median;
    int sortTable[length];
    int i = 0;

    while(i < length)
    {
        sortTable[i] = *(table + i);
        i = i + 1;
    }

    i = 1;
    int j = 1;
    int temp = 0;

    while (j > 0)
    {
        j = 0;
        while (i < length)
        {
            if (sortTable[i-1] > sortTable[i])
            {
                temp = sortTable[i];
                sortTable[i] = sortTable[i-1];
                sortTable[i-1] = temp;
                j = j + 1;
            }
            i = i + 1;
        }
        i = 1;
    }

    if(length%2 == 0)
    {
        median = (((float)sortTable[length/2-1]+sortTable[(length/2)])/2);
        return median;
    }
    else
    {
        median = (sortTable[(length/2)]);
        return median;
    }
}

int main() {
    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;

    tableFill(numbers,10);

    printTable(numbers, 10);

    printf("Minimalna wartosc to: %d\n",findMin(numbers,10));

    printf("Maksymalna wartosc to: %d\n",findMax(numbers,10));

    printf("Srednia wynosi: %f\n",findAvg(numbers,10));

    printf("Mediana wynosi: %f\n",findMedian(numbers, 10));

    return 0;
}
