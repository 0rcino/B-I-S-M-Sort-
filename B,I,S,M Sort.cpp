/*Based on the provided Sorting Algorithms, develop a C++ Program that can perform each.
1. Develop a Menu (Bubble, Insertion, Selection or Merge) for the user to select which sorting algorithm to perform.
2. Random Number Generator (Ask how many numbers, does he or she want)
3. Then, Perform the Desired Algorithm.
*/

/*Group 2*/

/*Leader: Allen Jefferson C. Orcino
  Member: Carl Angelo Recodig
*/

#include <iostream>
#include <vector>
#include <random>
using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void print(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

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
    cout << ": ";
    print(arr);
    if (!swapped)
      break;
  }
}

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
    cout << ": ";
    print(arr);
  }
}

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

void selectionSort(vector<int> &arr)
{
  for (int i = 0; i < arr.size() - 1; i++)
  {
    int min = minIndex(arr, i);
    if (min != i)
      swap(arr[i], arr[min]);
    cout << ": ";
    print(arr);
  }
}

vector<int> merge(vector<int> &left, vector<int> &right, int arrs)
{
  vector<int> result;
  int i = 0, j = 0;
  while (i < left.size() && j < right.size())
  {
    if (left[i] <= right[j])
    {
      result.push_back(left[i]);
      i++;
    }
    else
    {
      result.push_back(right[j]);
      j++;
    }
  }
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
  cout << ": ";
  print(result);
  return result;
}

vector<int> mergeSort(vector<int> &arr, int arrs)
{
  if (arr.size() <= 1)
    return arr;
  int mid = arr.size() / 2;
  vector<int> left(arr.begin(), arr.begin() + mid);
  vector<int> right(arr.begin() + mid, arr.end());
  left = mergeSort(left, arrs);
  right = mergeSort(right, arrs);
  return merge(left, right, ++arrs);
}

vector<int> random(int size)
{
  vector<int> arr;
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, 100);
  for (int i = 0; i < size; i++)
  {
    arr.push_back(dis(gen));
  }
  return arr;
}

int main()
{
  cout << "+------------------------------------------+\n";
  cout << "| Bubble, Insertion, Selection, Merge Sort |\n";
  cout << "+------------------------------------------+\n";
  cout << endl;

  char continueSort;
  do
  {
    int choice;
    int size;
    vector<int> arr;
    cout << endl;
    cout << "What is the desired number generation number? : ";
    cin >> size;
    cout << endl;
    while (size < 1)
    {
      cout << "Unvalidated data entered. Kindly input a positive number." << endl;
      cin >> size;
    }
    arr = random(size);
    cout << "Generation of Ramdon Numbers is: ";
    print(arr);
    cout << endl;
    cout << "Which sorting algorithm would you want to use ? " << endl;
    cout << "1. Bubble sort" << endl;
    cout << "2. Insertion sort" << endl;
    cout << "3. Selection sort" << endl;
    cout << "4. Merge sort" << endl;
    cout << "Choose an option (1-4): ";
    cin >> choice;
    cout << endl;
    while (choice < 1 || choice > 4)
    {
      cout << "Unvalid selection. Enter a number between 1 and 4." << endl;
      cin >> choice;
    }
    int arrs = 0;
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
      arr = mergeSort(arr, arrs);
      cout << endl;
      cout << "Merge Sort is: ";
      print(arr);
      break;
    }
    cout << endl;
    cout << "Do you want to continue? (y/n): ";
    cin >> continueSort;
  } while (continueSort == 'y' || continueSort == 'Y');
}