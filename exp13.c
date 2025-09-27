#include<stdio.h>

void sortDescending(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;i<n-i-1;j++){
			if(arr[j]<arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main(){
	int i,n,k;
	printf("Enter number of events:");
	scanf("%d",&n);
	int A[n];
	printf("Enter activity points for each events:\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Enter max numbers of events you can participate:");
	scanf("%d",&k);
	sortDescending(A,n);
	int maxpoints=0;
	for(i=0;i<k;i++){
		maxpoints=maxpoints+A[i];
	}
	printf("Maximum activity points you can earn:%d\n",maxpoints);
return 0;
}
