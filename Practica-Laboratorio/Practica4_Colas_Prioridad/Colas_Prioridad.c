#include <stdio.h>
#include <stdlib.h>

void Insert(int *heap, int value, int *size);
void HeapifyUp(int *heap, int index);
void Swap(int *a, int *b);
void PrintHeap(int *heap, int size);

int main()
{
    int *heap = (int *)malloc(sizeof(int) * 10);
    int temp[10] = {2, 4, 1, 5, 8, 7, 12, 11, 10, 3};
    int heapSize = 0;

    for (int i = 0; i < 10; i++)
    {
        Insert(heap, temp[i], &heapSize);
    }
    PrintHeap(heap, heapSize); // Print the heap after each insertion
    Insert(heap, 0, &heapSize);

    PrintHeap(heap, heapSize); // Print the heap after each insertion
    free(heap);
    return 0;
}

void Insert(int *heap, int value, int *size)
{
    heap[*size] = value;
    (*size)++;
    HeapifyUp(heap, *size - 1);
}

void HeapifyUp(int *heap, int index)
{
    int parentIndex = (index - 1) / 2;
    while (index > 0 && heap[index] < heap[parentIndex])
    {
        Swap(&heap[index], &heap[parentIndex]);
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintHeap(int *heap, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
