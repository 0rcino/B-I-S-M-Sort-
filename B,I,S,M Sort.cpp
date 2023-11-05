#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void printArray(int arr[], int n);

int main()
{
  // Initialize random seed
  srand(time(0));
  cout << "+------------------------------------------+\n";
  cout << "| Bubble, Insertion, Selection, Merge Sort |\n";
  cout << "+------------------------------------------+\n";
  cout << endl;
  // Ask the user how many numbers to generate
  // Random Number Generator
  while (1)
  {
    cout << endl;
    cout << "How many numbers do you want to generate?:";
    int n;
    cin >> n;

    // Check if the input is valid
    if (n <= 0)
    {
      cout << "Invalid input. Please enter a positive number." << endl;
      return 0;
    }

    // Create an array of random numbers
    int arr[n];
    for (int i = 0; i < n; i++)
    {
      arr[i] = rand() % 100; // Generate a number between 0 and 99
    }

    // Print the original array
    cout << "The original array is:";
    printArray(arr, n);
    cout << endl;

    // Develop a menu for the user to select which sorting algorithm to perform
    cout << "Which sorting algorithm do you want to perform?" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Exit " << endl;
    cout << "Enter your choice (1-5):";
    int choice;
    cin >> choice;
    cout << endl;

    // Perform the desired algorithm and print the sorted array
    switch (choice)
    {
    case 1:
      bubbleSort(arr, n);
      cout << "Bubble sort is:";
      printArray(arr, n);
      cout << endl;
      break;
    case 2:
      insertionSort(arr, n);
      cout << "Insertion sort is:";
      printArray(arr, n);
      cout << endl;
      break;
    case 3:
      selectionSort(arr, n);
      cout << "Selection sort is:";
      printArray(arr, n);
      cout << endl;
      break;
    case 4:
      mergeSort(arr, 0, n - 1);
      cout << "Merge sort is:";
      printArray(arr, n);
      cout << endl;
      break;
    case 5:
      exit(1);
      cout << "Press Enter to Exit . . .";
      cout << endl;
      break;
    default:
      cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
      break;
    }
  }
}

// Bubble sort algorithm
void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap the elements
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Insertion sort algorithm
void insertionSort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i]; // The element to be inserted
    int j = i - 1;    // The index of the previous element
    // Shift the elements that are greater than the key to the right
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    // Insert the key at the correct position
    arr[j + 1] = key;
  }
}

// Selection sort algorithm
void selectionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i; // The index of the minimum element
    // Find the minimum element in the unsorted part of the array
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    // Swap the minimum element with the first element of the unsorted part
    if (minIndex != i)
    {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}
// Merge sort algorithm
void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    // Find the middle point
    int m = (l + r) / 2;
    // Sort the left and right halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}
// Merge function
void merge(int arr[], int l, int m, int r)
{
  // Find the sizes of the two subarrays
  int n1 = m - l + 1;
  int n2 = r - m;
  // Create temporary arrays
  int L[n1], R[n2];
  // Copy the data to the temporary arrays
  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = arr[m + 1 + j];
  }
  // Initialize the indices of the subarrays and the merged array
  int i = 0; // Index of the first subarray
  int j = 0; // Index of the second subarray
  int k = l; // Index of the merged array
  // Merge the subarrays in ascending order
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  // Copy the remaining elements of the subarrays if any
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}
// Print array function
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}