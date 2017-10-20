#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void debug(int arr[],int target,int array_length,int init, int end,int mid){
	printf("\n Myseach ");
	printf("target: %d - ",target);
	printf("array_length: %d - ",array_length);
	printf("init: %d - ",init);
	printf("end: %d - ",end);
	printf("mid (index): %d - ",mid);
	printf("mid (value) : %d - ",arr[mid]);
}

int simpleCount(int arr[],int target,int array_length){
	int count=0;
	int value;
	for(int i=0;i<array_length;i++){
		value = arr[i];
		if(value <= target){
			if(value==target){
				count++;
			}	
		}else{
			break;
		}
	}
	return count;
}
/*********/
int simpleCountHigher(int arr[],int target,int init, int length){
	int count=0;
	int value;
	for(int i=init;i<=length;i++){
		value = arr[i];
		if(value==target){
			count++;
		}else{
			break;
		}
	}
	return count;
}

int simpleCountLower(int arr[],int target,int init){
	int count=0;
	int value;
	for(int i=init;i>=0;i--){
		value = arr[i];
		if(value==target){
			count++;
		}else{
			break;
		}
	}
	return count;
}
int mySearch(int arr[],int target,int array_length,int init, int end){
	
	int higherInds,lowerInds;
	int sub_length = end-init;
	if(sub_length==0){
		return 0;
	}
	int mid = (sub_length/2)+init ;

	debug(arr, target, array_length, init,end, mid);

	if(arr[mid] > target){
		return mySearch(arr,target,array_length,init,mid);
	}else if(arr[mid] < target){
		return mySearch(arr,target,array_length,mid,end);
	}else{
		higherInds = simpleCountHigher(arr,target,(mid+1),array_length);
		lowerInds = simpleCountLower(arr,target,mid);
		return higherInds+lowerInds;
	}
	sleep(1);
}

falta pensar em maneira de passar array por arquivo,
se ficar muito hard, fazer inline mesmo
não fazer .h, se fopen ficar hard por conta de retornar um vetor,e  ter que
calcular o size of, então fazer inline

int main(int argc, char *argv[]){

	int array_length = sizeof(v)/sizeof(v[0]);

	int count;

	count = simpleCount(v,8,array_length);

	printf("\n Foram encontradas %d ocorrencias\n ",count);

	count = mySearch(v,8,array_length,0,array_length);

	printf("\n Foram encontradas %d ocorrencias\n ",count);

    return 0;
}

