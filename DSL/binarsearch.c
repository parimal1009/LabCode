#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    printf("Enter the element to search for:");
    int w,q=-1;
    scanf("%d",&w);
    int b=0,e=9;
    while(b<=e){
        int mid=(b+e)/2;
        if(arr[mid]==w){
            q=mid;
            break;
        }
        else{
            if(w>arr[mid]){
                b=mid+1;
            }
            else if (w<arr[mid]){
                e=mid-1;
            }
        }
    }
    if(q==-1){
        printf("Element not found");
    }
    else{
        printf("Found at %d postion",q);
    }
}