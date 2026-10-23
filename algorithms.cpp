#include<iostream>

using namespace std;

void findLargest();
void traverse();
void insert(int a, int k);
void remove(int k);
void bubbleSort();
void linearSearch();
void binarySearch();

const int CAPACITY = 20;
int  myarray[CAPACITY] = {1,2,5,9,0,4,3,6,8,7};
int a,k;
int filledIndex = 9;    
char input;

void printArray(){
	cout<<"[ ";
	for(int i = 0; i<=filledIndex; i++){
		cout<<myarray[i]<<" ";
	}
	cout<<"]"<<endl;
}

int main(){
	bool exit = false;
	cout<<"Initial Array: ";
	printArray();
	cout<<"Algorithms available:\n 1- largest\n 2- traverse\n 3- insert\n 4- remove\n 5- bubble sort\n 6- linear search\n 7- binary search\n";
	cout<<"Commands available: h- help, e- exit\n";
	cout<<"Enter your choice:[1/2/3/4/5/6/7/h/e]: ";
	while(!exit){
	   cout<<"$ ";
       cin>>input;
       if(input == '1'){
       	findLargest();
       	cout<<endl;
       }	   
       else if(input == '2'){
       	traverse();
       	cout<<endl;
       }
       else if(input == '3'){
       	if(filledIndex == CAPACITY-1){
       		cout<<"Array full! Cannot insert new element\n";
       	}
       	else{
       		cout<<"Enter integer to be inserted: ";
       		cin>>a;
       		cout<<"Enter the required postion of the new element [1 to "<<filledIndex+2<<"]: ";
       		cin>>k;
       		k--;
       		cout<<endl;
       		insert(a,k);
       		cout<<endl;
       	}
       }
       else if(input == '4'){
        if(filledIndex < 0){
            cout<<"Array is already empty!\n";
        }
        else{
        	cout<<"Enter position of integer to be removed [1 to "<<filledIndex+1<<"]: ";
        	cin>>k;
        	k--;
        	cout<<endl;
        	remove(k);
        	cout<<endl;
        }    
       }
       else if(input == '5'){
       	bubbleSort();
       	cout<<endl;
       }
       else if(input == '6'){
       	linearSearch();
       	cout<<endl;
       }
       else if(input == '7'){
       	binarySearch();
       	cout<<endl;
       }
       else if(input == 'e'){
       	exit = true;
       }
       else if(input == 'h'){
       	cout<<"Algorithms available:\n 1- largest\n 2- traverse\n 3- insert\n 4- remove\n 5- bubble sort\n 6- linear search\n 7- binary search\n";
       	cout<<"Commands available: h- help, e- exit\n";
       	cout<<"Enter your choice:[1/2/3/4/5/6/7/h/e]: ";
       }
       else{
       	cout<<"Error: Invalid Command\n";
       }	
	}
	return 0;
}

//Algorithms

void findLargest(){
	int i = 0;
	int max = myarray[0];
	int pos = 0;
	while(i<=filledIndex){
		if(max < myarray[i]){
			max = myarray[i];
			pos = i;
		}
		i++;
	}
	cout<<"The largest integer in the array is: "<<max<<" at position: "<<pos;	
}

void traverse(){
	for(int i = 0; i<=filledIndex; i++){
		cout<<"Traversed element "<<i<<" array["<<i<<"] = "<<myarray[i]<<endl;		
	}
}

void insert(int a, int k){
	int i = filledIndex;
	while(i>=k){
		myarray[i + 1] = myarray[i];
		i--;
	}
	myarray[k] = a;
	cout<<"Inserted "<<a<<" at position "<<(k+1)<<endl;
	cout<<"Updated array: ";
	filledIndex++;
	printArray();
}

void remove(int k){
	for(int i = k; i<filledIndex; i++){
		myarray[i] = myarray[i + 1];
	}
	cout<<"Removed element at position "<<(k+1)<<endl;
	cout<<"Updated array: ";
	filledIndex--;
	printArray();
}

void bubbleSort(){
	for(int i = 0; i<filledIndex; i++){
		for(int j = 0; j<(filledIndex-i); j++){
			if(myarray[j]>myarray[j + 1]){
				int temp = myarray[j];
				myarray[j] = myarray[j + 1];
				myarray[j + 1] = temp;
			}
		}
	}
	cout<<"Sorted Array: ";
	printArray();
}

void linearSearch(){
    int a;
    cout<<"Enter value to be searched: ";
    cin>>a;
    bool found = false;
	for(int i = 0; i<=filledIndex; i++){
		if(a == myarray[i]){
			cout<<"\nFound "<<a<<" at position "<<i+1<<endl;
			found = true;
		}
	}
	if(!found){
		cout<<"Element Not Found!\n";
	}
}

void binarySearch(){
    bubbleSort();
	int a;
	int lb = 0;
	int ub = filledIndex;
	int mid = (lb + ub)/2;
	cout<<"Enter value to be binary searched: ";
	cin>>a;
	bool found = false;
	while(!found){
		if(a == myarray[mid]){
			cout<<"Found given element at position "<<mid+1<<endl;
			found = true;
		}
		else if(a < myarray[mid] && a >= myarray[0]){
			ub = mid-1;
			mid = (lb + ub)/2;
		}
		else if(a > myarray[mid] && a <= myarray[filledIndex]){
			lb = mid+1;
			mid = (lb + ub)/2;
		}
		else{
			break;
		}
	}
	if(!found){
		cout<<"Element Not Found!\n";
	}
	
}
