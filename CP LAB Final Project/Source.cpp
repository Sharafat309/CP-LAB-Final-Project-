#include<iostream>
#include<string>

using namespace std;
void combinedArray(int array1[], int array2[], int mergedArray[], int size1, int size2) {
    for (int i = 0; i < size1; i++) {
        mergedArray[i] = array1[i];
    }
    for (int i = 0; i < size2; i++) {
        mergedArray[size1 + i] = array2[i];
    }
    //making the the merged array in asscending order
    int temp;
    for (int i = 0; i < size1 + size2; i++) {
        for (int j = i + 1; j < size1 + size2; j++) {
            if (mergedArray[i] > mergedArray[j]) {
                temp = mergedArray[i];
                mergedArray[i] = mergedArray[j];
                mergedArray[j] = temp;
            }
        }
    }
}

void findCommonElements(int array1[], int array2[], int size1, int size2) {
    cout << "Common elements: ";
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (array1[i] == array2[j]) {
            cout << array1[i] << " ";
            i++;
            j++;
        }
        else if (array1[i] < array2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    cout << endl;
}

int main() 
{
	int array1[5], array2[7];
    cout << "Enter the elements of 1st array:\n";
    for (int i = 0; i < 5; i++) {
        cin >> array1[i];
    }

    cout << "Enter the elements of 2nd array:\n";
    for (int i = 0; i < 7; i++) {
        cin >> array2[i];
    }

    int mergedArray[12];
    combinedArray(array1, array2, mergedArray, 5, 7);

    cout << "Merged and sorted array: ";
    for (int i = 0; i < 12; i++) {
        cout << mergedArray[i] << " ";
    }

    cout << endl;
    findCommonElements(array1, array2, 5, 7);
    system("pause");
    return 0;
}

