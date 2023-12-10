#include <iostream>
using namespace std;

int getMax(int array[], int size){
    int max = array[0];
    for (int i=1; i<size; i++){
        if (max < array[i])
            max = array[i];
    }
    return max;
}

void CountSort(int array[], int size, int div){
    int output[size];
    int count[10] = {0};

    for (int i=0; i<size; i++)
        count[(array[i] / div) % 10]++;
    for (int i=1; i<size; i++)
        count[i] += count[i-1];

    for (int i=(size-1); i>=0; i--){
        output[count[(array[i] / div) %  10] - 1] = array[i];
        count[(array[i] / div) % 10]--;
    }

    for (int i=0; i<size; i++)
        array[i] = output[i];
}

void RadixSort(int array[], int size){
    int m = getMax(array, size);
    for (int div=1; (m/div) > 0; div = div*10)
        CountSort(array, size, div);
}

int main(){
    int array[10] = {4, 2, 7, 1, 8, 9, 3, 5, 6, 0};
    RadixSort(array, 10);
    for (int i=0; i<10; i++){
        cout << array[i] << " ";
    }
    return 0;
}