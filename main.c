#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
void debug(int arr[],int target,int array_length,int init, int end,int mid){
	printf("\n Myseach ");
	printf("target: %d - ",target);
	printf("array_length: %d - ",array_length);
	printf("init: %d - ",init);
	printf("end: %d - ",end);
	printf("mid (index): %d - ",mid);
	printf("mid (value) : %d - ",arr[mid]);
}
void print_array(int *array, int length){
	printf("\nPrintando array ");
    for (int i = 0; i < length; i++) {
    	printf("\narray[%d] => %d; ",i,array[i]);
    }
}
/*
Fonte: http://www.geeksforgeeks.org/merge-sort/
*/
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j]; 
    i = 0; 
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    } 
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }    
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
/*
Fonte: http://www.geeksforgeeks.org/merge-sort/
*/
void mergeSort(int arr[], int l, int r){
    if (l < r)    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r);
    }
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
	if(sub_length==0 || end-init<=1){
		return 0;
	}
	int mid = (sub_length/2)+init ;

	//debug(arr, target, array_length, init,end, mid);

	if(arr[mid] > target){
		return mySearch(arr,target,array_length,init,mid);
	}else if(arr[mid] < target){
		return mySearch(arr,target,array_length,mid,end);
	}else {
		higherInds = simpleCountHigher(arr,target,(mid+1),array_length);
		lowerInds = simpleCountLower(arr,target,mid);
		return higherInds+lowerInds;
	}
}

int main(int argc, char *argv[]){
	
	size_t len = 0;

	FILE *file;

	char *line = NULL,
	     *split,
		 read,
		 arquivo[50];
	long ind =0;
	int target,
		*v,
		countSimples,
		countMine;	

	clock_t startS, 
			endS,
			startM, 
			endM;

 	double cpu_time_usedS, 
 		   cpu_time_usedM;

 /****************FIM DEFINICAO DE VARIAVEIS****************/

	printf("\n Digite o nome do arquivo para ser carregado: ");
	scanf("%[^\n]",arquivo);

	printf("\n Digite o numero a ser buscado: ");
	scanf("%d", &target);

	file = fopen(arquivo, "r");
	if(file != NULL){
		while ((read = getline(&line, &len, file)) != -1) {
			while((split = strsep(&line," ")) != NULL ){
				v = (int *) realloc(v, (ind+1)*sizeof(int));
				v[ind]=atoi(split);	
				ind++;
			}
		}

	    mergeSort(v, 0, ind - 1);
	    
     	startS = clock();    
		countSimples = simpleCount(v,target,ind);
		endS = clock();
		
     	startM = clock();    
		countMine = mySearch(v,target,ind,0,ind);
		endM = clock();
		
     	cpu_time_usedS = ((double) (endS - startS)) / CLOCKS_PER_SEC;
     	cpu_time_usedM = ((double) (endM - startM)) / CLOCKS_PER_SEC;


		printf("\n %.10f ms para encontrar %d ocorrencias em O(n)",cpu_time_usedS,countSimples);
		printf("\n %.10f ms para encontrar %d ocorrencias em O(log n)",cpu_time_usedM,countMine);
	}else{
    	printf("Erro, nao foi possivel abrir o arquivo\n");
    }
	printf("\n");
    return 0;
}