//============================================================================
// Name        : quicksortmedian.c
// Author      : Bhumi Sabarwal
// Description : Implemets a optimized Quick Sort algorithm, taking the "median of 3" as the pivot element approach
//               Elements to be sorted are stored in "QuickSort.txt"
//============================================================================

#include <stdio.h>


int dopartition(int arr[], int low1, int high1)
{static int count=0;
    count=count+(high1-low1);
    printf("\n current value of count is %d",count);
	int a, b, temp,temp1;
	int pivot,mid, median ;
    
    mid=(high1+low1)/2;
    printf("\n low , high and mid are %d and %d amd %d", low1, high1, mid);
    if(((arr[low1]<=arr[mid])&&(arr[mid]<=arr[high1]))||((arr[low1]>=arr[mid])&&(arr[mid]>=arr[high1])))
    {
        median=mid;
    }else
        if(((arr[mid]<=arr[low1])&&(arr[low1]<=arr[high1]))||((arr[mid]>=arr[low1])&&(arr[low1]>=arr[high1])))
        {
            median=low1;
        }
    else
        if(((arr[low1]<=arr[high1])&&(arr[high1]<=arr[mid]))||((arr[low1]>=arr[high1])&&(arr[high1]>=arr[mid])))
           {
               median=high1;
           }
    printf("\n median is %d", median);
        temp1=arr[low1];
        arr[low1]=arr[median];
        arr[median]=temp1;
        pivot=arr[low1];
	printf("\n pivot is %d",pivot);
    a=low1+1;
	b=low1+1;
	while(b<=high1)
	{ printf("\n a and b initially are %d and %d",a,b);
		while((pivot>arr[a])&&(a<=high1)&&(b<=high1))
        {
			a++;
			b++;
			//cout<<"\n a and b are"<<a<<b;
        }
        
	    while((pivot<arr[b])&&(b<=high1))
        {b++;
			//cout<<"\n b is"<< b;
        }
        
        
        
	    // cout<<"\n i am here";
        if(b<=high1)
        {		if (arr[b]< pivot)
        {
			temp=arr[a];
			arr[a]=arr[b];
			arr[b]=temp;
			//cout<<"\n a and b after swap are"<< arr[a]<< arr[b];
			b++;
			a++;
            
		}
        }
        
	}
    
	temp=arr[low1];
	arr[low1]= arr[a-1];
	arr[a-1]=temp;
    
	return (a-1);
}


void doquicksort( int a[], int low, int high)
{
	int c=dopartition(a, low, high );
	printf("\n c is %d",c);
if(low<c-1)
        doquicksort(a, low, c-1);
	if(high>c+1)
        doquicksort(a, c+1, high);
    
}



int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int  i=0,totalNums;
    int numbers[10000];
    
    char line[100];  /* declare a char array */
    
    FILE *file;
    
    file=fopen("QuickSort.txt", "r");
    while(fgets(line, sizeof line, file) !=NULL)
    { numbers[i]=atoi(line);
        i++;
    }
    totalNums=i;
    for(i=0;i<totalNums;i++)
    {printf("Number is %d \n", numbers[i]);
    }
    
    
	// int a[]={3,9,8,4,6,10,2,5,7,1};
	doquicksort(numbers,0,9999);
    printf("\n sorted array is");
  /*  for(int i=0; i<=99 ; i++)
     printf("\n element is %d",numbers[i]); */
    
	return 0;
}
