#include<iostream>
using namespace std;
void bubbleSort(int arr[],int size);
bool canarrange(int arr[],int size);
main()
{
    int size;
    cout<<"Enter Length of Array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter Array's Elements:"<<endl; 
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr,size);
    bool output=canarrange(arr,size);
    if(output)
    {
        cout<<"Can be arranged!";
    }
    else
    {
        cout<<"Can not be arranged!";
    }
}

void bubbleSort(int arr[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool canarrange(int arr[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]==arr[i+1] || arr[i+1]-arr[i]!=1)
        {
            return false; 
        }
    }
    return true;
}