



#include <stdio.h>
void main()
{
 int i,n,a;
 printf("Enter the number of elements: ");
 scanf("%d", &n);
 int y[n];
 i = 0;
 for(i = 0; i<n; i++)
 {  
   printf("Enter the element: ");
   scanf("%d", &a);
   y[i] = a;
 }
 
 printf("\n");
 printf("The elements of the array are: ");
 
 
 for(i = 0; i<n; i++)
 {  
   printf("%d ", y[i]);
 }
 
 printf("\n");
 
 //BUBBLE SORT//
 
int step, temp = y[i];
 
for (int step = 0; step < n - 1; ++step)

{
  for (int i = 0; i < n - step - 1; ++i)
   {
     
      if (y[i] > y[i + 1])
      {
        int temp = y[i];
        y[i] = y[i + 1];
        y[i + 1] = temp;
      }
    }
}
  printf("The sorted array is: ");
  for(i = 0; i<n; i++)
  {  
   printf("%d ", y[i]);
  }

  // BINARY SEARCH //
  int low = 0, high = n-1, key, found = 0;
  printf("\n");
  printf("Enter the element to be searched: ");
  scanf("%d", &key);

 while (low<=high)
 {
  int mid = (low + high)/2;
  if(key == y[mid])
  {
    printf("The element is at the index number: %d", mid);
    found = 1;
    break;
  }
  else if (key > y[mid])
  {
    low = mid+1; 
  } 
  else
  {
    high = mid-1; 
  }

 }
 if (found == 0)
 {
  printf("The element is not present in the array!");
 }
 
}
} 

 
 


