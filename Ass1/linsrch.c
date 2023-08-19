#include <stdio.h>
int main()
{
       int l,x,f=0,i;
       printf("enter length of array:");
       scanf("%d",&l);
       int arr[l];
       printf("Enter %d numbers: \n",l);
       for(i=0;i<l;i++)
       {
              scanf("%d",&arr[i]);
       }
              printf("enter number to find:\n");
              scanf("%d",&x);
              for( i=0;i<l;i++)
              {
                     if(x==arr[i])
                     {
                            f=1;
                            break;
                     }
                     
              }
              if(f!=0)
              {printf("number found in %d position \n",i+1);}
              else
                     {
                     printf("Number not found");
                     }
              return 0;
              }

