#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void bubble(int arr[], int n);
void insertion(int arr[], int n);
void selection(int arr[], int n);
void mergeS(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void array(int arr[], int n);

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
  cout << endl;
  cout << "What is the desired number generation number? :";
  int n;
  cin >> n;
  cout << endl;
  // Check if the input is valid
  if (n <= 0)
  {
    cout << "Unvalidated data entered. Kindly input a positive number." << endl;
    return 0;
  }
  // Create an array of random numbers
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 100; // Generate a number between 0 and 99
  }
  // Print the original array
  cout << "Generation of Ramdon Numbers is: ";
  array(arr, n);
  cout << endl;
  // Develop a menu for the user to select which sorting algorithm to perform
  cout << "Which sorting algorithm would you want to use?" << endl;
  cout << "1. Bubble Sort" << endl;
  cout << "2. Insertion Sort" << endl;
  cout << "3. Selection Sort" << endl;
  cout << "4. Merge Sort" << endl;
  cout << "5. Exit " << endl;
  cout << "Choose an option (1-4): ";
  int choice;
  cin >> choice;
  cout << endl;
  // Perform the desired algorithm and print the sorted array
  switch (choice)
  {
  case 1:
    bubble(arr, n);
    cout << "Bubble Sort is: ";
    array(arr, n);
    cout << endl;
    break;
  case 2:
    insertion(arr, n);
    cout << "Insertion Sort is: ";
    array(arr, n);
    cout << endl;
    break;
  case 3:
    selection(arr, n);
    cout << "Selection Sort is: ";
    array(arr, n);
    cout << endl;
    break;
  case 4:
    mergeS(arr, 0, n - 1);
    cout << "Merge Sort is: ";
    array(arr, n);
    cout << endl;
    break;
  default:
    cout << "Unvalid selection. Enter a number between 1 and 4." << endl;
        break;
  }
}
// Bubble sort algorithm
void bubble(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap the elements
        int temps = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temps;
      }
    }
  }
}
// Insertion sort algorithm
void insertion(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int keys = arr[i]; // The element to be inserted
    int j = i - 1;     // The index of the previous element
    // Shift the elements that are greater than the key to the right
    while (j >= 0 && arr[j] > keys)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    // Insert the key at the correct position
    arr[j + 1] = keys;
  }
}
// Selection sort algorithm
void selection(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int index = i; // The index of the minimum element
    // Find the minimum element in the unsorted part of the array
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[index])
      {
        index = j;
      }
    }
    // Swap the minimum element with the first element of the unsorted part
    if (index != i)
    {
      int temps = arr[i];
      arr[i] = arr[index];
      arr[index] = temps;
    }
  }
}
// Merge sort algorithm
void mergeS(int arr[], int l, int r)
{
  if (l < r)
  {
    // Find the middle point
    int m = (l + r) / 2;
    // Sort the left and right halves
    mergeS(arr, l, m);
    mergeS(arr, m + 1, r);
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
void array(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}