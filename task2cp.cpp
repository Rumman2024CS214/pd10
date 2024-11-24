#include<iostream>
using namespace std;
int rotation(string arr[],int size);
main()
{
    int size;
    cout<<"Enter the number of rotations: ";
    cin>>size;
    string arr[size];
    cout<<"Enter directions:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int output;
    output=rotation(arr,size);
    cout<<"Number of Rotations: "<<output;
}

int rotation(string arr[],int size)
{
    int total;
    int degree=90;
    string base=arr[0];
    for(int j=1;j<size;j++)
    {
        if(base==arr[j])
        {
            degree=degree+90;
        }
        else if(base!=arr[j])
        {
            degree=degree-90;
        }
    }
    if(degree<360)
    {
        total=0;
    }
    else if(degree>=360)
    {
        total=degree/360;
    }
    return total;
}