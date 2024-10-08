#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &arr)
{
    int aSize = arr.size();
    bool swapper = false;

    for (int i = 0; i < aSize - 1; i++)
    {
        swapper = false;
        for (int j = 0; j < aSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapper = true;
            }
        }
        if (!swapper)
            break;
    }
}

void insertionSort(std::vector<int> &arr)
{
    int aSize = arr.size();
    int pos = 0;
    int curVal = arr[0];
    for (int i = 1; i < aSize; i++)
    {
        curVal = arr[i];
        pos = i;
        while (pos > 0 && curVal < arr[pos - 1])
        {
            arr[pos] = arr[pos - 1];
            pos--;
        }
        arr[pos] = curVal;
    }
}

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int left = low;
    int right = high - 1;

    while (true)
    {
        while (left <= right && arr[left] < pivot)
            left++;
        while (right >= left && arr[right] > pivot)
            right--;
        if (left >= right)
            break;
        std::swap(arr[left], arr[right]);
        left++;
        right++;
    }
    std::swap(arr[left], arr[high]);
    return left;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int ind = partition(arr, low, high);

        quickSort(arr, low, ind - 1);
        quickSort(arr, ind + 1, high);
    }
}

void merge(std::vector<int> &arr, const std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> tmp;
    int li = 0;
    int ri = 0;

    while(li < left.size() && ri < right.size())
    {
        if (left[li] < right[ri])
        {
            tmp.push_back(left[li]);
            li++;
        }
        else
        {
            tmp.push_back(right[ri]);
            ri++;
        }
    }

    while (li < left.size())
    {
        tmp.push_back(left[li]);
        li++;
    }

    while (ri < right.size())
    {
        tmp.push_back(right[ri]);
        ri++;
    }

    arr = tmp;
}

void mergeSort(std::vector<int> &arr)
{
    if (arr.size() == 1) return;

    std::vector<int>::iterator mid = arr.begin() + (arr.size() / 2);
    std::vector<int> left(arr.begin(), mid);
    std::vector<int> right(mid, arr.end());

    mergeSort(left);
    mergeSort(right);
    merge(arr, left, right);
}

void printVector(const std::vector<int> &arr)
{
    for (int num : arr)
        std::cout << " " << num;
    std::cout << std::endl;
}

int main()
{
    std::cout << "Hello" << std::endl;
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    printVector(arr);
    // bubbleSort(arr);
    // insertionSort(arr);
    // quickSort(arr, 0, arr.size() - 1);
    mergeSort(arr);
    std::cout << "Sorted array: \n";
    printVector(arr);

    return 0;
}