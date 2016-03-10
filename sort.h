#define SIZE 100000

//utility
void print(int values[], int length);
void swap(int &one, int &two);
int random(int low, int high);
void createInputData(int asc[], int dsc[], int rd[]);

//quicksort
void qsort(int values[], int p, int r);
void quicksort(int values[], int length);
int partition(int values[], int p, int r);
int randomPartition(int values[], int p, int r);

//mergesort
void mergesort(int A[], int length);
void divide(int A[], int B[], int start, int end);
void merge(int A[], int B[], int start, int mid, int end);

//insertion sort
void insertionsort(int A[], int length);