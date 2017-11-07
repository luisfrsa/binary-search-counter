int simpleCountHigher(int arr[],int target,int init, int length){
	int count=0;                    //c
	int value;						//c
	for(int i=init;i<=length;i++){	//O(n)
		value = arr[i];				//c.O(n)	
		if(value==target){			//c.O(n)
			count++;				//c.O(n)
		}else{						//c.O(n)
			break;					//c.O(n)
		}						
	}
	return count;					//c.O(n)
}

int simpleCountLower(int arr[],int target,int init){
	int count=0;					//c
	int value;						//c
	for(int i=init;i>=0;i--){		//O(n)
		value = arr[i];				//c.O(n)
		if(value==target){			//c.O(n)
			count++;				//c.O(n)
		}else{						//c.O(n)
			break;					//c.O(n)
		}
	}
	return count;					//c.O(n)
}
int mySearch(int arr[],int target,int array_length,int init, int end){
	
	int higherInds,lowerInds;												//c
	int sub_length = end-init;												//c
	if(sub_length==0 || end-init<=1){										//c
		return 0;															//c
	}
	int mid = (sub_length/2)+init ;											//c

	if(arr[mid] > target){													//c
		return mySearch(arr,target,array_length,init,mid);					//T(n) = c -> se n<=1 ou T(n/2)+c -> se n>1
	}else if(arr[mid] < target){											//c
		return mySearch(arr,target,array_length,mid,end);					//T(n) = c -> se n<=1 ou T(n/2)+c -> se n>1
	}else {																	//c
		higherInds = simpleCountHigher(arr,target,(mid+1),array_length);    //????????
		lowerInds = simpleCountLower(arr,target,mid);						//????????
		return higherInds+lowerInds;										//c
	}
}
