#include <stdio.h>
#include "graph.h"
int min = INF; // global minimum variable.

//function to check the array minimum cost.
void tsp(pnode head, int cities[], int size)
{
    int tmp_min = 0;         // temporary weight to be accumlated using dijkstra method.
    int curr_id = cities[0]; // src
    int next_id = 0;         // dst

    // now to check other connected nodes weights.
    for (int i = 1; i < size; ++i)
    {
        next_id = cities[i];                         // dst
        tmp_min += dijkstra(head, curr_id, next_id); // using dijsktra sums the shortest path to all.
        curr_id = cities[i];                         //src
    }
    if (min > tmp_min)
    {
        min = tmp_min;
    }
}

//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//permutation function
void permutation(pnode head,int *arr, int start, int end)
{
    if (start == end)
    {
        tsp(head, arr, end + 1);
        return;
    }
    int i;
    for (i = start; i <= end; i++)
    {
        //swapping numbers
        swap((arr + i), (arr + start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(head,arr, start + 1, end);
        swap((arr + i), (arr + start));
    }
}
int main()
{
    //taking input to the array
    int size;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    int i;
    int arr[size];
    for (i = 0; i < size; i++) // getting cities.
        scanf("%d", &arr[i]);
    //calling permutation function
    permutation(head,arr, 0, size - 1);
    printf("The minimum cost is : %d",min);
    // return 0;
}
