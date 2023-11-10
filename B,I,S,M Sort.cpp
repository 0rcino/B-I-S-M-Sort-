
#include <iostream>
#include <vector>
#include <random>
using namespace std;

// A function to swap two elements in a vector
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// A function to print a vector
void print(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// A function to perform bubble sort on a vector
void bubbleSort(vector<int> &arr)
{
  bool swapped;
  for (int i = 0; i < arr.size() - 1; i++)
  {
    swapped = false;
    for (int j = 0; j < arr.size() - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    // Display the numbers after each iteration
    cout << "After iteration " << i + 1 << ": ";
    print(arr);
    if (!swapped)
      break; // If no swap occurred, the vector is already sorted
  }
}

// A function to perform insertion sort on a vector
void insertionSort(vector<int> &arr)
{
  for (int i = 1; i < arr.size(); i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
    // Display the numbers after each iteration
    cout << "After iteration " << i << ": ";
  }
}

// A function to find the minimum element in a vector from a given index
int minIndex(vector<int> &arr, int start)
{
  int min = start;
  for (int i = start + 1; i < arr.size(); i++)
  {
    if (arr[i] < arr[min])
      min = i;
  }
  return min;
}

// A function to perform selection sort on a vector
void selectionSort(vector<int> &arr)
{
  for (int i = 0; i < arr.size() - 1; i++)
  {
    int min = minIndex(arr, i); // Find the index of the minimum element from i
    if (min != i)
      swap(arr[i], arr[min]); // Swap the minimum element with the current element
    // Display the numbers after each iteration
    cout << "After iteration " << i + 1 << ": ";
    print(arr);
  }
}

// A function to merge two sorted vectors into one sorted vector
vector<int> merge(vector<int> &left, vector<int> &right)
{
  vector<int> result; // The merged vector
  int i = 0, j = 0;   // The indices of the left and right vectors
  while (i < left.size() && j < right.size())
  {
    if (left[i] <= right[j])
    {                            // If the current element of the left vector is smaller or equal to the current element of the right vector
      result.push_back(left[i]); // Add it to the result vector
      i++;                       // Increment the left index
    }
    else
    {                             // Otherwise, the current element of the right vector is smaller than the current element of the left vector
      result.push_back(right[j]); // Add it to the result vector
      j++;                        // Increment the right index
    }
  }
  // If there are any remaining elements in the left or right vectors, add them to the result vector
  while (i < left.size())
  {
    result.push_back(left[i]);
    i++;
  }

  while (j < right.size())
  {
    result.push_back(right[j]);
    j++;
  }
  return result;
}

// A function to perform merge sort on a vector
vector<int> mergeSort(vector<int> &arr)
{
  if (arr.size() <= 1)
    return arr;             // Base case: if the vector has one or zero elements, it is already sorted
  int mid = arr.size() / 2; // Find the middle index of the vector
  // Divide the vector into two subvectors: left and right
  vector<int> left(arr.begin(), arr.begin() + mid);
  vector<int> right(arr.begin() + mid, arr.end());
  // Recursively sort the left and right subvectors using merge sort
  left = mergeSort(left);
  right = mergeSort(right);
  // Merge the sorted left and right subvectors and return the result
  return merge(left, right);
}

// A function to generate a vector of random numbers of a given size
vector<int> random(int size)
{
  vector<int> arr;
  random_device rd;                       // A random device to generate random seeds
  mt19937 gen(rd());                      // A pseudo-random number generator
  uniform_int_distribution<> dis(1, 100); // A uniform distribution of integers from 1 to 100
  for (int i = 0; i < size; i++)
  {
    arr.push_back(dis(gen)); // Generate a random number and add it to the vector
  }
  return arr;
}

// The main function
int main()
{
  int choice;      // The user's choice of sorting algorithm
  int size;        // The size of the vector to be sorted
  vector<int> arr; // The vector to be sorted
  // Display a menu for the user to select which sorting algorithm to perform
  cout << "+------------------------------------------+\n";
  cout << "| Bubble, Insertion, Selection, Merge Sort |\n";
  cout << "+------------------------------------------+\n";
  cout << endl;
  cout << endl;
  cout << "Which sorting algorithm would you want to use ? " << endl;
  cout << "1. Bubble sort" << endl;
  cout << "2. Insertion sort" << endl;
  cout << "3. Selection sort" << endl;
  cout << "4. Merge sort" << endl;
  cout << "Choose an option (1-4): ";
  // Get the user's choice and validate it
  cin >> choice;
  while (choice < 1 || choice > 4)
  {
    cout << "Unvalid selection. Enter a number between 1 and 4." << endl;
    cin >> choice;
  }

  // Ask the user how many numbers they want to sort and validate it
  cout << "What is the desired number generation number? : ";
  cin >> size;
  cout << endl;
  while (size < 1)
  {
    cout << "Unvalidated data entered. Kindly input a positive number." << endl;
    cin >> size;
  }

  // Generate a vector of random numbers of the given size
  arr = random(size);

  // Display the original vector
  cout << "Generation of Ramdon Numbers is: ";
  print(arr);
  cout << endl;

  // Perform the desired sorting algorithm and display the sorted vector
  switch (choice)
  {
  case 1:
    cout << "Performing bubble sort..." << endl;
    bubbleSort(arr);
    cout << endl;
    cout << "Bubble Sort is: ";
    print(arr);
    break;
  case 2:
    cout << "Performing insertion sort..." << endl;
    insertionSort(arr);
    cout << endl;
    cout << "Insertion Sort is: ";
    print(arr);
    break;
  case 3:
    cout << "Performing selection sort..." << endl;
    selectionSort(arr);
    cout << endl;
    cout << "Selection Sort is: ";
    print(arr);
    break;
  case 4:
    cout << "Performing merge sort..." << endl;
    arr = mergeSort(arr);
    cout << endl;
    cout << "Merge Sort is: ";
    print(arr);
    break;
  }
}