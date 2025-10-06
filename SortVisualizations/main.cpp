//Author: Jack Fontenot
//Assignment Title: Program 9
//Assignment Description: Sorting Visualization
//Due Date: 5/4/2025
//Date Created: 5/3/2025
//Date Last Modified: 5/4/2025

#include "SDL_Plotter.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



const int SIZE   = 1000;
const int SPEED  = 0;
const int RADIUS = 2;
bool TRACE = false;
SDL_Plotter *g;

void printInstructions();
void plotData(int[], int);

void NewData(int[], int );
//************************************************************
// description: Sorts the data by swapping the data until all data is in the
//              correct location.
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted
//
//************************************************************
void BubbleSort(int[], int);

//************************************************************
// description: Sorts the data by searching the data for the next element
//              and sorting it.
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void SelectionSort(int[], int);

//************************************************************
// description: Sorts the data by inserting each element into the correct
//              sorted spot.
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void InsertionSort(int[], int);

//************************************************************
// description: Sorts the data using the ShellSort Algorithm
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void ShellSort(int[], int);

//************************************************************
// description: Sorts the data by creating a heap and removing the top element
//              then reheaping with the remaining data and repeating
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void HeapSort(int[], int);

void percDown(int a[], int i, int n);

//************************************************************
// description: Sorts the data by recursively dividing the data in half
//              and recursively sorting the subsets
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void QuickSort(int[], int,int);

void qInsertionSort(int a[], int left, int right);

//************************************************************
// description: Partitions the data into two subarrays to be
//      recursively sorted
// return: Int
// precondition: the array data exists and is valid
// postcondition: a partition value is chosen and returned to
//      the calling QuickSort function
//
//************************************************************
int partition(int [], int left, int right);

//************************************************************
// description: Sorts the data by recursively dividing the data in half and
//              sorting the subsets
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void MergeSort(int[], int left, int right);
void MergeSort(int[], int[], int left, int right);

//************************************************************
// description: Merges two subarrays back into main array
// return: None
// precondition: two subarrays exist holding valid data
// postcondition: the arrays are merged
//
//************************************************************
void merge(int*, int*, int, int, int);

//************************************************************
// description: Sorts the data using the Radix Sort
// return: None
// precondition: the array data exists and is valid
// postcondition: the array is sorted and data is drawn to the screen
//
//************************************************************
void RadixSort(int[], int);

//
// Sorting Visualization Driver
//


int main(int argc, char **argv) {
	g = new SDL_Plotter(SIZE,SIZE);
    int *data = new int[g->getCol()];

    printInstructions();
    NewData(data, SIZE);

	while(!g->getQuit()){

		if(g->kbhit()){
			switch(toupper(g->getKey())){
			    case 'B': BubbleSort(data, SIZE);
			              break;
			    case 'C': ShellSort(data, SIZE);;
			              break;
			    case 'H': HeapSort(data, SIZE);
			              break;
			    case 'I': InsertionSort(data, SIZE);
			              break;
			    case 'M': MergeSort(data,0, SIZE);
			              break;
			    case 'Q': QuickSort(data, 0, SIZE);
			              break;
			    case 'N': NewData(data, SIZE);
			              break;
			    case 'R': RadixSort(data, SIZE);
			              break;
			    case 'S': SelectionSort(data, SIZE);
			              break;
			    case 'T': TRACE = !TRACE;
			              break;
			    case 'X': g->setQuit(true);
			              break;
			}
		}
	}

    delete [] data;
    delete g;
    return 0;
}

//Instructions

void printInstructions(){
	cout << "B: BubbleSort" << endl;
	cout << "C: ShellSort(data, SIZE)" << endl;
	cout << "H: HeapSort(data, SIZE)" << endl;
	cout << "I: InsertionSort(data, SIZE)" << endl;
	cout << "M: MergeSort(data,0, SIZE)" << endl;
	cout << "Q: QuickSort(data, 0, SIZE)" << endl;
	cout << "N: NewData(data, SIZE)" << endl;
	cout << "R: RadixSort(data, SIZE)" << endl;
	cout << "S: SelectionSort(data, SIZE)" << endl;
	cout << "T: TRACE = !TRACE" << endl;
	cout << "X: g->setQuit(true)" << endl;

}

// Bubble Sort

void BubbleSort(int a[], int n){
  for(int i = 0; i < n-1; i++){
	  for(int j = 0; j < n-1-i; j++){
		  if(a[j] > a[j+1]){
			  swap(a[j], a[j+1]);
		  }
	  }

	  plotData(a,n);
  }
}

void SelectionSort(int a[], int n){
    int lInd;

    for(int i = 0; i < n - 1; ++i){
        lInd = i;

        for(int j = i + 1; j < n; ++j){
            if(a[j] < a[lInd]){
                lInd = j;
            }
        }

        swap(a[i], a[lInd]);
        plotData(a, n);
    }
}

void InsertionSort(int a[], int n){
    int tmp;
    for(int p = 1; p < n; ++p){
        tmp = move(a[p]);

        int j;
        for(j = p; j > 0 && tmp < a[j-1]; --j){
            a[j] = move(a[j-1]);
        }
        a[j] = move(tmp);
        plotData(a, n);
    }
}

void ShellSort(int a[], int n){
    int tmp;
    int j;
    for(int gap = n/2; gap > 0; gap /=2){
        for(int i = gap; i < n; ++i){
            tmp = move(a[i]);

            for(j = i; j >= gap && tmp < a[j-gap]; j-=gap){
                a[j] = move(a[j-gap]);
            }
            a[j] = move(tmp);
            plotData(a, n);
        }
    }
}

void HeapSort(int a[], int n)
{
    for(int i = n/2-1; i >= 0; --i){
        percDown(a, i, n);
    }

    for(int j = n-1; j > 0; --j){
        plotData(a, n);
        swap(a[0], a[j]);
        percDown(a, 0, j);
    }
}

int leftChild(int i){
    return 2*i+1;
}

void percDown(int a[], int i, int n){
    int child;
    int tmp;

    for(tmp = move(a[i]); leftChild(i) < n; i = child){
        child = leftChild(i);
        if(child != n - 1 && a[child] < a[child+1]){
            ++child;
        }
        if(tmp < a[child]){
            a[i] = move(a[child]);
        }
        else{
            break;
        }
    }
    a[i] = move(tmp);
}

void QuickSort(int a[],int left, int right)
{
    int pivot;
    int i, j;
    if(left+10<=right){
        pivot = partition(a, left, right);

        i = left;
        j = right - 1;
        for( ; ; ){
            while(a[++i] < pivot){}
            while(pivot < a[--j]){}
            if(i < j){
                swap(a[i], a[j]);
            }
            else{
                break;
            }
        }
        swap(a[i], a[right - 1]);
        plotData(a, SIZE);
        QuickSort(a, left, i - 1);
        QuickSort(a, i + 1, right);
    }
    else{
        qInsertionSort(a, left, right);
        plotData(a, SIZE);
    }
}

void qInsertionSort(int a[], int left, int right){
    int tmp;
    for(left = left+1; left < right; ++left){
        tmp = move(a[left]);

        int j;
        for(j = left; j > 0 && tmp < a[j-1]; --j){
            a[j] = move(a[j-1]);
        }
        a[j] = move(tmp);
    }
}

int partition(int a[], int left, int right) {
    int center = (left+right)/2;

    if(a[center] < a[left]){
        swap(a[left], a[center]);
    }
    if(a[right] < a[left]){
        swap(a[left], a[right]);
    }
    if(a[right]<a[center]){
        swap(a[center], a[right]);
    }

    swap(a[center], a[right-1]);
    return a[right-1];
}

void MergeSort(int a[], int left, int right)
{
    int* temp = new int[right];
    MergeSort(a, temp, left, right - 1);
}

void MergeSort(int* a, int* tmpArray, int left, int right) {

    if(left < right){
        int center = (left + right)/2;
        MergeSort(a, tmpArray, left, center);
        MergeSort(a, tmpArray, center+1, right);
        merge(a, tmpArray, left, center+1, right);
        plotData(a, right+1);
    }

}

void merge(int* a, int* tmpArray, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while(leftPos <= leftEnd && rightPos <= rightEnd){
        if(a[leftPos] <= a[rightPos]){
            tmpArray[tmpPos++] = move(a[leftPos++]);
        }
        else{
            tmpArray[tmpPos++] = move(a[rightPos++]);
        }
    }

    while(leftPos <= leftEnd){
        tmpArray[tmpPos++] = move(a[leftPos++]);
    }

    while(rightPos <= rightEnd){
        tmpArray[tmpPos++] = move(a[rightPos++]);
    }

    for(int i = 0; i < numElements; ++i, --rightEnd){
        a[rightEnd] = move(tmpArray[rightEnd]);
    }
}

void countSort(int a[], int n, int exp){
    int out[n];
    int count[10] = {0};

    for(int i = 0; i < n; ++i){
        count[a[i]/exp%10]++;
    }

    for(int i = 1; i < 10; ++i){
        count[i] += count[i-1];
    }

    for(int i = n - 1; i >= 0; --i){
        out[count[(a[i]/exp%10)]-1] = a[i];
        count[(a[i]/exp)%10]--;
    }

    for(int i = 0; i < n; ++i){
        a[i] = out[i];
        plotData(a, n);
    }
}

void RadixSort(int a[], int n){

    int max = a[0];

    //get max
    for(int i = 0; i < n; ++i){
        if(a[i] > max){
            max = a[i];
        }
    }

    for(int exp = 1; max / exp > 0; exp*= 10){
        countSort(a, n, exp);
    }
}



// Select New Random Data
void NewData(int a[], int n){
	g->clear();
	for(int i =0; i < n; i++){
		a[i] = rand()%n;
	}
	plotData(a,n);
}


// main draw function, gets called over and over, as fast as possible
void plotData(int a[], int n){
	  if(!TRACE) g->clear();
	  for(int i = 0; i < n;i++){
		  for(int x = -RADIUS; x <= RADIUS; x++){
			  for(int y = -RADIUS; y <= RADIUS; y++){
				  if(x*x + y*y <= RADIUS*RADIUS){
					  g->plotPixel(x+i,y+a[i]);
				  }
			  }
		  }
	  }
	  g->update();
	  g->Sleep(SPEED);
}
