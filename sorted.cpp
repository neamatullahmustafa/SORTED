#include <iostream>
#include <chrono>
int arr[] = { 10,80,30,90,40,70,50,23,24,56,7,86,44,90,24,78,55,22,56,54,21,45,78,98,8,87,76,39,40,73,51,64,63,78,3,4,24,21,67,89,45,36,27,26,26,24,26,26,38,47 };
long long time()
{
	using namespace std::chrono;
	return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}
using namespace std;
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "  ";
	cout << "\n";
}
void merge(int array[] = { 0 }, int start = 0, int pointer = 0, int end = 0)
{
	int n1 = pointer - start + 1;
	int n2 = end - pointer;
	int* left = new int[n1 + 1];
	int* right = new int[n2 + 1];
	for (int i = 0; i < n1; i++)
	{
		left[i] = array[start + i];
	}
	for (int i = 0; i < n2; i++)
	{
		right[i] = array[pointer + 1 + i];
	}
	left[n1] = 10000;
	right[n2] = 10000;
	int i = 0, j = 0, k = start;
	for (k; k < end; k++)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
	}
}
void merge_sort(int array[] = { 0 }, int start = 0, int end = 0)
{
	int pointer = 0;
	if (start < end)
	{
	  pointer = (start+end)/2;
	  merge_sort(array, start, pointer);
	  merge_sort(array, pointer + 1, end);
	  merge(array, start, pointer, end );
	}
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int L, int H)
{
int pivot = arr[H];
int i = (L - 1);
for (int j = L; j <= H - 1; j++)
{
	if (arr[j] < pivot)
	{
		i++;
		swap(&arr[i], &arr[j]);
	}
}
swap(&arr[i + 1], &arr[H]);
return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int main()
{
	long long start_time_quick_sort = 0, end_time_quick_sort = 0
		, start_time_merge_SORT = 0, end_time_merge_SORT = 0;
	start_time_quick_sort = time();
	cout << "array: \n";
	printArray(arr, 49);
	cout << "\t\t QUICK SORT \n";
	cout << "\t\t------------ \n";
	quickSort(arr, 0, 49);
	cout << "Sorted array: \n";
	printArray(arr, 49);
	end_time_quick_sort = time();
	cout << "time with quick sort = " << end_time_quick_sort - start_time_quick_sort << "\n";
	int arr1[] = { 10,80,30,90,40,70,50,23,24,56,7,86,44,90,24,78,55,22,56,54,21,45,78,98,8,87,76,39,40,73,51,64,63,78,3,4,24,21,67,89,45,36,27,26,26,24,26,26,38,47 };
	start_time_merge_SORT = time();
	cout << "\t\t merge SORT \n";
	cout << "\t\t------------ \n";
    merge_sort(arr1, 0,49);
    cout << "Sorted array: \n";
    printArray(arr1, 49);
    end_time_merge_SORT =time();
    cout << "time with merge sort = " << end_time_merge_SORT - start_time_merge_SORT << "\n";
	return 0;
}