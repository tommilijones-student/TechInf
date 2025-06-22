// wersja 4

#include <iostream>

void tableFill (int *p, int length)
{
    int i = 0;
    while(i < length)
    {
        printf("Wpisz wartosc dla %d elementu:\n", i+1);
        scanf("%d", p + i);
        i = i + 1;
    }

}

void printTable(const int *p,int length)
{
    int i =0;
    while(i<length)
    {
        printf("Wartosc dla %d elementu: %d\n",i+1,*(p + i));
        i = i + 1;
    }

}
int findMin(int *p, int length)
{
    int min = *p;
    int i = 0;
    while(i < length)
    {
        if(min > *(p + i))
        {
            min = *(p + i);
        }
        i = i + 1;
    }
    return min;
}
int findMax(int *p, int length)
{
    int max = *p;
    int i = 0;
    while(i < length)
    {
        if(max < *(p + i))
        {
            max = *(p + i);
        }
        i = i + 1;
    }
    return max;
}
float findAvg(int *p, int length)
{
    int sum = 0;
    float average = 0;
    int i = 0;
    while(i < length)
    {
        sum = sum + *(p + i);
        i = i + 1;
    }
    average = (float)sum/length;
    return average;

}
float findMedian(int *p,int length)
{
    float median;
    int sortTable[length];
    int i = 0;

    while(i < length)
    {
        sortTable[i] = p[i];
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
    const int *ptr_read = numbers;
    int *ptr_write = numbers;
    int i = 0;

    tableFill(ptr_write,10);

    printTable(ptr_read, 10);

    printf("Minimalna wartosc to: %d\n",findMin(ptr_write,10));

    printf("Maksymalna wartosc to: %d\n",findMax(ptr_write,10));

    printf("Srednia wynosi: %f\n",findAvg(ptr_write,10));

    printf("Mediana wynosi: %f\n",findMedian(ptr_write, 10));

    return 0;
}
