// #include<iostream>

// using std::cin;
// using std::cout;

// int main(){
//     for(int i=0;i<10;i++){
//         for(int k=10;k>10-i;k--){
//             cout<<" ";
//         }
//         for(int j=10; j>i ; j--){
//             if(j%2==0){
//                 cout<<"#";
//             }
//         }
//         cout<<"\n";
//     }
//     return 0;
// }


// int main(){
//     for(int i=0; i<10; i++){
//         for(int j=i-5; j<=i-5; j++){
//             int k = 0;
//             while(k<abs(j)){
//                 cout<<"#";
//                 k++;
//             }
//         }
//         cout<<"\n";
//     }
// }


// int main()
// {
//     int space, rows;
//     cout <<"Enter number of rows: ";
//     cin >> rows;
//     for(int i = 1, k = 0; i <= rows; i++, k = 0)
//     {
//         for(space = 1; space <= rows-i; ++space)
//         {
//             cout <<"  ";
//         }
//         while(k != 2*i-1)
//         {
//             cout << "* ";
//             ++k;
//         }
//         cout << "\n";
//     }    
//     return 0;
// }


// int main(){
//     for(int row=1;row<=7;row++){
//         for(int hashNum = 1; hashNum<=4-abs(4-row);hashNum++){
//             cout<<"#";
//         }
//         cout<<"\n";
//     }
// }


//Get original number

//Double alternate digits

//Add all digits

//Find mod 10 (smallest number to be added to make it divisible by 10)

//Return the full number

// int doubleDigitValue(int digit){
//     int doubleDigit = digit*2;
//     int sum;

//     if(doubleDigit>=10){
//         sum = 1+(doubleDigit%10);
//     }
//     else{
//         sum = doubleDigit;
//     }
//     return sum;
// }


// int main(){
//     char digit;
//     int checksum = 0;
//     int i = 1;
//     cout<< "Enter your number: ";
//     digit = cin.get();
//     while (digit!=10){
//         if(i%2==0){
//             checksum+=digit-'0';
//         }else{
//             checksum+=doubleDigitValue(digit-'0');
//         }
//         digit = cin.get();
//         i++;
//     }

    
//     if(checksum%10==0){
//         cout<<"Checksum is valid.";
//     }else{
//         cout<<"Checksum is invalid";
//     }
// }


// char getNewModulo(char prevModulo){
//     char newModulo;
//     switch(prevModulo){
//         case 'U':
//             newModulo = 'L';
//             break;
//         case 'L':
//             newModulo = 'P';
//             break;
//         case 'P':
//             newModulo = 'U';
//             break;
//     }
//     return newModulo;
// }

// char getCalculatedValue(char property, int inputNum){
//     int opNum;
//     char outputChar;

//     char punctuationDecoder[] = {'!','?',',','.',' ',';','"','\''};
    
//     switch(property){
//         case 'U':
//             opNum = (inputNum%27);
//             if (opNum!=0){
//                 outputChar = static_cast<char>(opNum+64);
//             }else{
//                 outputChar = '0';
//             }
//             break;
        
//         case 'L':
//             opNum = (inputNum%27);
//             if (opNum!=0){
//             outputChar = static_cast<char>(opNum+96);
//             }else{
//                 outputChar = '0';
//             }
//             break;

//         case 'P':
//             opNum = (inputNum%9);
//             if (opNum!=0){
//             outputChar = punctuationDecoder[opNum-1];
//             }else{
//                 outputChar = '0';
//             }
//             break;
//     }
//     return outputChar;
// }



// int main(){
//     int inputString[] = {18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10};
//     //char digit;
//     //int index = 0;
//     //int inputString[] = {};
//     char modulo = 'U';
//     char calcResult;
    
//     //cout<<"Enter your digits. Press enter twice once done: ";
//     //digit = cin.get();

//     // while(sizeof(digit) > 0){
//     //     inputString[index] = int(digit);
//     //     digit = cin.get();
//     //     index++;
//     // }



//     for(int i : inputString){
//         calcResult = getCalculatedValue(modulo, i);
//         if(calcResult == '0'){
//             modulo = getNewModulo(modulo);
//         }else{
//         cout<<calcResult;
//         }
//     }
// }

// using namespace std;
// class Name{
    
//     public : string myName;

//     public : string displayName(string myName){
//         cout<<"My name is "+ myName;
//     }
// };

// int main(){
//     Name testName;
//     testName.displayName("Rudra");

// }


// #include<C:\users\rumitra\Desktop\CPP\Student.cpp>

// int main(){
//     Student stud1 = Student(1, "Rudra", 100);

//     cout<<stud1.studentId;
//     cout<<stud1.studentName;
//     cout<<stud1.marks;

//     stud1.printDetails();
    
//     return 0;
// }



// int selectionSort(int unsorted[]){
//     int arrayLen = sizeof(unsorted)/sizeof(unsorted[0]);
//     for(int i=0; i< arrayLen; i++){
//         int leastElemIndex = i;
//         for(int j = i+1; j<arrayLen; j++){
//             if(unsorted[leastElemIndex] > unsorted[j]){
//                 leastElemIndex = j;
//             }
//         }

//         if(leastElemIndex!=i){
//             int temp = unsorted[i];
//             unsorted[i] = unsorted[leastElemIndex];
//             unsorted[leastElemIndex] = temp;
//         }
//     }
// }


// int main(){
//     int myArr[] = {23,1,45,2,65,3};
//     selectionSort(myArr);
// }


// #define ROW 4
// #define COLUMN 5

// void islandCalc(int island[ROW][COLUMN], int i, int j){
//     if(i<0 || i>=ROW || j<0 || j>=COLUMN || island[i][j] == 0){
//         //Base case
//         return;
//     }else{
//         island[i][j] = 0;
//         //recursive call
//         islandCalc(island,i+1,j);
//         islandCalc(island,i-1,j);
//         islandCalc(island,i,j+1);
//         islandCalc(island,i,j-1);
//     }
// }


// int main(){

//     int islandCount = 0;
//     int island[ROW][COLUMN] = {{1,1,1,0,0},
//                                {1,1,0,0,0},
//                                {1,0,0,1,1},
//                                {0,1,0,0,1}};
    
//     for (int i=0;i<ROW;i++){
//         cout<<"\n";
//         for(int j=0;j<COLUMN;j++){
//             cout<<island[i][j];
//         }
//     }

//     for (int i=0;i<ROW;i++){
//         for(int j=0;j<COLUMN;j++){
//             if(island[i][j] == 1){
//                 islandCount++;
//                 islandCalc(island,i,j);
//             }
//         }
//     }

//     cout<<"\n";
//     cout<<"Number of islands: ";
//     cout<<islandCount;
// }

// #include<cmath>
// #include<bits/stdc++.h>

// void printArray(int inputArray[], int size){
//     for(int i=0;i<size;++i){
//         cout<<inputArray[i]<<" ";
//     }
// }

// void sieveOfEratosthenes(int n){
//     bool prime[n+1];
//     memset(prime,true,sizeof(prime));
    
//     for(int i=2;i*i<=n;++i){
//         if(prime[i] == true){
//             for(int j=i*i;j<=n;j+=i){
//                 prime[j] = false;
//             }
//         }
//     }

//     for(int k=0;k<n;++k){
//         if(prime[k])
//         cout<<k<<" ";
//     }
// }

// int main(){
//     sieveOfEratosthenes(50);
// }

// int squareByVal(int n){
//     return n*n;
// }

// void squareByPointer(int *n){
//     *n*=*n;
// }

// void squareByRef(int &n){
//     n*=n;
// }

// int main(){
//     int n1 = 5;
//     int n2 = 6;
//     int n3 = 4;
//     cout<<squareByVal(n1)<<std::endl;
//     squareByPointer(&n2);
//     squareByRef(n3);
//     cout<<n2<<std::endl;
//     cout<<n3<<std::endl;
// }

// int main(){
//     int *pointerA;
//     int varB = 20;

//     pointerA = &varB;

//     cout<<&varB<<std::endl;
//     cout<<varB<<std::endl;
//     cout<<pointerA<<std::endl;
//     cout<<*pointerA;
// }


// #include <iostream> 
// #include <vector>

// int main(){
//     std::vector<int> testVector;
//     for(int i=0;i<5;++i){
//         testVector.push_back(i);
//     }

//     auto a = testVector.end();
//     cout<<a<<std::endl;

// }


// #include <iostream>
// using namespace std;

// int main() {
// 	//code
// 	int count;
// 	int a,b;
// 	cin>>count;
//     for(int i=0;i<count;++i){
// 	    cin>>a;
//         cin>>b;
//         cout<<a*b<<endl;
// 	}
// 	return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

//9687
// int getReversedNumber(int originalNum){
// 	int arr[15];
// 	int rem,reversed = 0, count = 0;
// 	int sign = 1;
// 	int sizeNum = originalNum;
// 	while(sizeNum!=0){
// 		sizeNum/=10;
// 		++count;
// 	}
// 	int unit = ceil(pow(10,count-1));
// 	cout<<unit<<std::endl;
// 	if (originalNum<0) sign=-1;
// 	while(originalNum>10){
// 		rem = originalNum%10;
// 		reversed=rem*unit+reversed;
// 		unit/=10;
// 		originalNum = originalNum/10;
// 		cout<<"OriginalNum "<<originalNum<<std::endl;
// 		cout<<"Rev "<<reversed<<std::endl;
// 		cout<<"Rem "<<rem<<std::endl;
// 	}
// 	reversed = originalNum*unit+reversed;
// 	return reversed*sign;
// }


// int getReversedNumberStr(int originalNum){
// 	string numberStr = to_string(originalNum);
// 	std::vector<char> numberVector;
// 	for(char i:numberStr){
// 		numberVector.insert(v.);
// 	}
// 	return 1;
// }


// int main(){
// 	int originalNum = 96872;
// 	int reversed = getReversedNumberStr(originalNum);
// 	cout<<reversed<<std::endl;
// }

// #include<bits/stdc++.h>
// using namespace std;


// char getMostCommonLetter(string inputStr, int *count){
// 	map<char,int> charMap;
// 	char key;
// 	for(char i:inputStr){
// 		if ( charMap.find(i) == charMap.end()){
// 			charMap.insert({i,1});
// 		}else{
// 			charMap[i]+=1;
// 		}
// 	}
// 	for(auto it = charMap.cbegin(); it != charMap.cend(); ++it){
// 		if(it->second >*count){
// 			key = it->first;
// 			*count=it->second;
// 		}
// 	}
// 	return key;
// }


// int main(){
// 	string testStr = "rudrajit";
// 	int count = 0;
// 	char result = getMostCommonLetter(testStr,&count);
// 	cout<<"Character "<<result<<" occurs "<<count<<" times in the string "<<testStr<<endl;
// }


// #include<bits/stdc++.h>
// using namespace std;

//first duplicate

// int main(){
// 	string testStr = "rudrajit";
// 	bool flag = false;
// 	vector<char> testVec;
// 	for(char i:testStr){
// 		if(std::count(testVec.begin(), testVec.end(),i)){
// 			flag=true;
// 			cout<<"Element occuring for the 2nd time is: "<<i<<endl;
// 		}else{
// 			testVec.push_back(i);
// 		}
// 	}
// 	if(!flag) cout<<"No duplicates."<<endl;
// }

//Index of first occurring duplicated

// int main(){
// 	string inputStr = "samhita";
// 	unordered_set<char> charSet;
// 	for(char i:inputStr){
// 		if(charSet.find(i) == charSet.end()){
// 			charSet.insert(i);
// 		}else{
// 			cout<<i<<endl;
// 		}
// 	}
// }


//Find first duplicate
//Constraints: values of array should be lesser than max length of array
//values > 0

// int getFirstDuplicate(int arr[], int size){
// 	for(int i=0;i<size;i++){
// 		if(arr[arr[i]]<0){
// 			return i;
// 		}else{
// 			arr[arr[i]] = arr[arr[i]]*-1;
// 		}
// 	}
// 	return -1;
// }

// int main(){
// 	int inputArr[] = {2,5,1,7,2,3,5};
// 	int size = sizeof(inputArr)/sizeof(inputArr[0]);
// 	//cout<<size<<endl;
// 	int index = getFirstDuplicate(inputArr,size);
// 	cout<<index<<endl;
// }


// #include<bits/stdc++.h>
// using namespace std;

// void swap(int *a, int *b){
// 	int temp = *b;
// 	*b = *a;
// 	*a = temp;
// }

// void heapify(int arr[],int n, int i){
// 	int largest = i;
// 	int leftChildIndex = 2*i+1;;
// 	int rightChildIndex = 2*i+2;;
	
// 	if(leftChildIndex<n && arr[leftChildIndex] > arr[largest]){
// 		largest = leftChildIndex;
// 	}
// 	if(rightChildIndex<n && arr[rightChildIndex] > arr[largest]){
// 		largest = rightChildIndex;
// 	}
// 	if(largest!=i){
// 		swap(&arr[largest],&arr[i]);
// 		heapify(arr,n,largest);
// 	}
// }

// void heapsort(int arr[], int n){
// 	//heapify the array
// 	for(int i=n/2-1;i>=0;--i) heapify(arr,n,i);
// 	//sorting part
// 	for(int i=n-1;i>=0;--i){
// 		//storing the top node of the heap in the last index
// 		swap(&arr[i],&arr[0]);
// 		//turning the new array into a heap again
// 		heapify(arr,i,0);
// 	}
// }


// int partition(int arr[], int low, int high){
// 	int pivot_pos = high;
// 	int pivot_value = arr[pivot_pos];
// 	high-=1;

// 	while(true){
// 		while(arr[low] < pivot_value) low++;
// 		while(arr[high] > pivot_value) high--;
// 		if(low>=high) break;
// 		else swap(&arr[low],&arr[high]);
// 	}
// 	swap(&arr[low],&arr[pivot_pos]);
// 	return low;
// }

// void quickSort(int arr[],int low,int high){
// 	if(low<high){
// 		int partition_pos = partition(arr,low,high);
// 		quickSort(arr,low,partition_pos-1);
// 		quickSort(arr,partition_pos+1,high);
// 	}
// }


// void merge(int arr[], int left, int mid, int right){
// 	int i,j,k;
// 	int nl = mid-left+1;
// 	int nr = right - mid;
// 	int L[nl], R[nr];
// 	for(i=0;i<nl;i++) L[i] = arr[left+i];
// 	for(j=0;j<nr;j++) R[j] = arr[mid+j+1];
	
// 	i=0,j=0,k=left;

// 	while(i<nl && j<nr){
// 		if(L[i]>=R[j]){
// 			arr[k++] = R[j++];
// 		}else{
// 			arr[k++] = L[i++];
// 		}
// 	}
// 	while(i<nl){
// 		arr[k++] = L[i++];
// 	}
// 	while(j<nr){
// 		arr[k++] = R[j++];
// 	}
// }


// void mergeSort(int arr[], int low, int high){
// 	if(low<high){
// 		int mid = low+(high-low)/2;
		
// 		mergeSort(arr, low, mid);
// 		mergeSort(arr, mid+1, high);
// 		merge(arr, low, mid, high);
// 	}
// }


// void heapify(int arr[], int n, int i){
// 	int largest = i;
// 	int leftChild = 2*i+1;
// 	int rightChild = 2*i+2;
// 	if(arr[leftChild]>arr[i] && leftChild<n) largest = leftChild;
// 	if(arr[rightChild] > arr[largest] && rightChild<n) largest = rightChild;
// 	if(largest!=i){
// 		swap(&arr[i],&arr[largest]);
// 		heapify(arr,n,largest);//heapify the affected branch
// 	}
// }

// void heapSort(int arr[], int n){
// 	for(int i=n/2-1;i>=0;i--){//heapify the array
// 		heapify(arr,n,i);
// 	}
// 	for(int i=n-1;i>=0;i--){
// 		swap(&arr[0],&arr[i]);//send 1st element(largest in max heap) to the end of the array. Bring last element to 0th index.
// 		heapify(arr,i,0);//heapify reduced heap. i->reduced size of array. n=0 -> starts heapihyinh
// 	}
// }

// int main(){
// 	int inputarr[] = {2,18,30,27,15,12};
// 	int n = sizeof(inputarr)/sizeof(inputarr[0]);
// 	heapSort(inputarr, n);
	
// 	for(int j:inputarr){
// 		cout<<j<<endl;
// 	}
// }


//Rotate an array matrix 90 degrees

// #include<bits/stdc++.h>
// using namespace std;

// void swap(int *a, int *b){
// 	int temp = *b;
// 	*b = *a;
// 	*a = temp;
// }


// int main(){

// 	int size = 4;
// 	int arr[size][size] =  {{1,  2, 3, 4},
// 				     		{5,  6, 7, 8},
// 				     		{9, 10,11,12},
// 				     		{13,14,15,16}};
	
// 	//Display array
// 	for(int i=0;i<size;i++){
// 		for(int j=0;j<size;j++){
// 			cout<<arr[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}


// 	//Rotation starts

// 	//Step1: Transpose the array (Transform rows into columns)(swap diagonally opp elements)
// 	for(int i=0;i<size;i++){
// 		for(int j=i;j<size;j++){
// 			swap(&arr[i][j], &arr[j][i]);
// 		}
// 	}

// 	cout<<endl;
// 	//Display array
// 	for(int i=0;i<size;i++){
// 		for(int j=0;j<size;j++){
// 			cout<<arr[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}

// 	//Rows got tranformed into columns

// 	//Step2: Swap 1st and last elements of each row in the array, going inwards from both end
// 	for(int i=0;i<size;i++){
// 		for(int j=0;j<size/2;j++){
// 			swap(&arr[i][j],&arr[i][size-1-j]);
// 		}
// 	}

// 	cout<<endl;
// 	//Display array
// 	for(int i=0;i<size;i++){
// 		for(int j=0;j<size;j++){
// 			cout<<arr[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}

// }


// #include<bits/stdc++.h>
// using namespace std;


// void swap(int &a, int &b){
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }

// int main(){
// 	string number1 = "10000000000000000000005";
// 	string number2 = "4000000000000000000005";

// 	if(number1.size()>number2.size()) swap(number1,number2);

// 	int n1_size = number1.size();
// 	int n2_size = number2.size();

// 	string sumStr;

// 	reverse(number1.begin(),number1.end());
// 	reverse(number2.begin(),number2.end());
	
// 	int sum = 0;
// 	int carry = 0;

// 	for(int i=0;i<n1_size;++i){
// 		sum = (number1[i] - '0') + (number2[i]-'0') + carry;
// 		sumStr.push_back((sum%10)+'0');
// 		carry = sum/10;
// 	}

// 	for(int j=n1_size;j<n2_size;++j){
// 		sum = carry + (number2[j] - '0');
// 		sumStr.push_back((sum%10)+'0');
// 		carry = sum/10;
// 	}
// 	if(carry){
// 		sumStr.push_back(carry+'0');
// 	}

// 	reverse(sumStr.begin(), sumStr.end());

// 	cout<<sumStr<<endl;

// }



// string getSumOfStrings(string num1, string num2){
// 	if(num1.length()>num2.length()) swap(num1,num2);
	
// 	int num1_size = num1.length();
// 	int num2_size = num2.length();

// 	reverse(num1.begin(), num1.end());
// 	reverse(num2.begin(), num2.end());

// 	int sum = 0, carry = 0;
// 	string result = "";

// 	for(int i=0;i<num1_size;++i){
// 		sum = (num1[i] - '0') + (num2[i] - '0') + carry;
// 		result.push_back((sum%10)+'0');
// 		carry = sum/10;
// 	}

// 	for(int i=num1_size;i<num2_size;++i){
// 		sum = (num2[i] - '0') + carry;
// 		result.push_back((sum%10)+'0');
// 		carry = sum/10;
// 	}

// 	if(carry) result.push_back(carry + '0');

// 	reverse(result.begin(), result.end());

// 	return result;
// }

// int main(){
// 	string num1 = "150";
// 	string num2 = "250";

// 	string result = getSumOfStrings(num1,num2);
// 	cout<<result<<endl;
// }


// #include<bits/stdc++.h>
// using namespace std;


// void swap(int &a, int &b){
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }


//Knapsack - basic

// int main(){
// 	vector<int> profit = {4,9,7,5,8,3,6};
// 	vector<int> weight = {2,3,7,2,4,1,3};
// 	int max_cap = 15;

// 	vector<double> p_w_ratio;

// 	for(int i=0; i<profit.size();++i){
// 		p_w_ratio.push_back((static_cast<double>(profit[i]))/weight[i]);
// 	}

// 	//for(int j:p_w_ratio) cout<<j<<endl;
// 	cout<<static_cast<double>(profit[0])<<endl;
// }


// int main(){
// 	int arr[] = {-11,-7,-3,2,5,8,10};
// 	int n = sizeof(arr)/sizeof(arr[0]);
// 	int i=0, j = n-1;
// 	vector<int> resVec;
// 	while(i<=j){
// 		if(abs(arr[i])>abs(arr[j])){
// 			resVec.insert(resVec.begin(),ceil(pow(arr[i],2)));
// 			++i;
// 		}else{
// 			resVec.insert(resVec.begin(),ceil(pow(arr[j],2)));
// 			--j;
// 		}
// 	}
// 	//Display vector
// 	for(int i:resVec){
// 		cout<<i<<endl;
// 	}
// }

// Knapsack - basic

// int main(){
// 	vector<int> profit = {4,9,7,5,8,3,6};
// 	vector<int> weight = {2,3,7,2,4,1,3};
// 	int max_cap = 15;

// 	map<int,double> p_w_ratio;
// 	for(int i=0; i<profit.size();++i){
// 		p_w_ratio.insert(make_pair(i,(static_cast<double>(profit[i])/weight[i])));
// 	}

// 	//sort p/w ration
// 	// sort(p_w_ratio.begin(), p_w_ratio.end());
// 	// reverse(p_w_ratio.begin(), p_w_ratio.end());

// 	for(auto i:p_w_ratio){
// 		cout<<i.first<<" "<<i.second<<endl;
// 	}

// 	int i = 0, Weight=0,Value=0;
// 	while(Weight<max_cap){

// 	}
	
// 	//for(int i=0;i<)
// }


// vector<vector<int>> getChunkedArray(vector<int> inputVec, int units){
// 	vector<vector<int>> resultVec;
// 	int size = inputVec.size();
// 	int possible_chunks = int(ceil(static_cast<double>(size)/units));
// 	cout<<"possible_chunks "<<possible_chunks<<endl;
// 	int index = 0;
// 	for(int i=0;i<possible_chunks;++i){
// 		int counter = 0;
// 		vector<int> chunk_vec;
// 		while(counter<units && index<size){
// 			chunk_vec.push_back(inputVec[index]);
// 			counter++;
// 			index++;
// 		}
// 		resultVec.push_back(chunk_vec);
// 	}
// 	return resultVec;
// }

// #include<bits/stdc++.h>

// //Template for slicing an array based on start and end indexes
// template<typename T>
// std::vector<T> slice(std::vector<T> const &inputVec, int startIndex, int endIndex){
// 	auto start = inputVec.cbegin() + startIndex;
// 	auto end = inputVec.cend()+endIndex;
// 	std::vector<T> slicedVec(start,end);
// 	return slicedVec;
// }

// template<typename T>
// std::vector<std::vector<T>> getChunkedVector(std::vector<T> const &intputVec, int chunks){
// 	std::vector<std::vector<T>> resVec;
// 	int size = intputVec.size();
// 	int index=0;
// 	while(index<size){
// 		resVec.push_back(slice(intputVec, index, index+chunks));
// 		index+=chunks;
// 	}
// 	return resVec;
// }

// int main(){
// 	std::vector<int> vec = {2,3,4,5,6,7,8,9,10};
// 	int chunks = 3;
// 	std::vector<std::vector<int>> res = getChunkedVector(vec,chunks);

// 	// std::cout<<"[";
// 	// for(int i=0;i<res.size();++i){
// 	// 	std::cout<<"[";
// 	// 	for(int j=0;j<res[i].size();++j){
// 	// 		std::cout<<res[i][j]<<",";	
// 	// 	}
// 	// 	std::cout<<"],"<<std::endl;;
// 	// }
// 	// std::cout<<"]"<<std::endl;

// 	//std::cout<<res;
// 	std::vector<std::vector<int> >::iterator row;
// 	std::vector<int>::iterator col;
// 	std::cout<<"[";
// 	for (row = res.begin(); row != res.end(); row++) {
// 		std::cout<<"[";
//     	for (col = row->begin(); col != row->end(); col++) {
//         	std::cout<<*col<<",";
//     }
// 	std::cout<<"]"<<std::endl;
// }
// std::cout<<"]"<<std::endl;
// }


// #include<bits/stdc++.h>
// using namespace std;

// bool ishappyNum(int n){
// 	std::unordered_set<int> seen;
// 	std::unordered_set<int>::iterator it;
// 	while(n!=1){
// 		int current = n;
// 		int sum = 0;
// 		while(current!=0){
// 			sum += ((current%10)*(current%10));
// 			current/=10;
// 		}
// 	it = seen.find(sum);
// 	if(it != seen.end()){
// 		return false;
// 	}
// 	seen.insert(sum);
// 	n=sum;
// 	}
// 	return true;
// }

// int main(){
// 	int n;
// 	cout<<"Enter a number to check if it's happy: ";
// 	cin>>n;
// 	bool isHappy = ishappyNum(n);
// 	if(isHappy) cout<<n<<" is a happy number."<<endl;
// 	else cout<<n<<" is not happy number."<<endl;
// }

// template<typename Map>
// bool key_compare (Map const &lhs, Map const &rhs) {
//     return lhs.size() == rhs.size()
//         && std::equal(lhs.begin(), lhs.end(), rhs.begin(), 
//                       [] (auto a, auto b) { return a.first == b.first; });
// }


// bool checkAnagram(string inputStr1, string inputStr2){
// 	inputStr1.erase(remove_if(inputStr1.begin(), inputStr1.end(),
// 	[](char c){
// 		return isspace(c) || !isalpha(c);
// 	}), inputStr1.end());
// 	transform(inputStr1.begin(), inputStr1.end(), inputStr1.begin(), ::tolower);

// 	inputStr2.erase(remove_if(inputStr2.begin(), inputStr2.end(),
// 	[](char c){
// 		return isspace(c) || !isalpha(c);
// 	}), inputStr2.end());
// 	transform(inputStr2.begin(), inputStr2.end(), inputStr2.begin(), ::tolower);

// 	cout<<inputStr1<<endl;
// 	cout<<inputStr2<<endl;

// 	if(inputStr1.length() != inputStr2.length()) return false;

// 	map<char,int> charMapA;
// 	map<char,int>::iterator itA;
// 	for(char c:inputStr1){
// 		itA = charMapA.find(c);
// 		if(itA!=charMapA.end()){
// 			charMapA[c]+=1;
// 		}else{
// 			charMapA.insert({c,1});
// 		}
// 	}

// 	map<char,int> charMapB;
// 	map<char,int>::iterator itB;
// 	for(char c:inputStr1){
// 		itB = charMapB.find(c);
// 		if(itB!=charMapB.end()){
// 			charMapB[c]+=1;
// 		}else{
// 			charMapB.insert({c,1});
// 		}
// 	}

// 	return key_compare(charMapA, charMapB);
// }

// int main(){
// 	string a = "hello! I am here.";
// 	string b = "olleh, aI m erhew;";
// 	bool res = checkAnagram(a,b);
// 	cout<<res<<endl;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int SOE(int n){
// 	bool arr[n+1];
// 	memset(arr,true,n+1);

// 	for(int i=2;i*i<n;++i){
// 		if(arr[i]==true){
// 			for(int j=i*i;j<n;j+=i){
// 				arr[j] = false;
// 			}
// 		}
// 	}
// 	for(int i=2;i<n;++i){
// 		if(arr[i]) cout<<i<<" ";
// 	}
// 	return 0;
// }

// int main(){
// 	int res = SOE(100);
// }

// #include<bits/stdc++.h>
// using namespace std;

// void countingSort(int arr[], int n){
// 	int max = 0;
// 	for(int i=0;i<n;++i){
// 		if(arr[i]>max) max=arr[i];
// 	}
// 	int countArr[max+1];
// 	memset(countArr, 0, sizeof(countArr)); //Setting all array elements to 0
// 	for(int i=0;i<n;++i){
// 		countArr[arr[i]]+=1;
// 	}
// 	for(int i=1;i<=max;++i){
// 		countArr[i] = countArr[i-1] + countArr[i];
// 	}

// 	int sortedArr[n];
// 	for(int i=n-1; i>=0;--i){
// 		countArr[arr[i]] = countArr[arr[i]] - 1;
// 		sortedArr[countArr[arr[i]]] = arr[i];
// 	}
// 	for(int i=0;i<n;++i){
// 		arr[i] = sortedArr[i];
// 	}
// }

// int main(){
// 	int arr[] = {23,1,7,19,13,5,8,19,1,25};
// 	int n = sizeof(arr)/sizeof(arr[0]);

// 	cout<<"Unsorted array: ";
// 	for(int i:arr) cout<<i<<" ";
// 	cout<<endl;
// 	cout<<"Sorted array: ";
// 	countingSort(arr,n);
// 	for(int i:arr) cout<<i<<" ";
// }


// #include<bits/stdc++.h>
// using namespace std;

// void capitaliseString(string &inputStr){
// 	inputStr[0] = inputStr[0]-32;
// 	for(int i=1;i<inputStr.length();++i){
// 		if(inputStr[i-1] == ' ' || inputStr[i-1] == NULL){
// 			inputStr[i] = inputStr[i]-32;
// 		}
// 	}
// }

// int main(){
// 	string str1 = "hi this is rudra.";
// 	capitaliseString(str1);
// 	cout<<str1;
// }


// #include<bits/stdc++.h>
// using namespace std;

// bool checkSum(int arr1[], int arr2[], int n1, int n2, int sum){
// 	unordered_set<int> calcSet;
// 	for(int i=0;i<n1;++i){
// 		calcSet.insert(calcSet.end(),sum-arr1[i]);
// 	}
// 	for(int i=0;i<n2;++i){
// 		if(!(calcSet.find(arr2[i]) == calcSet.end())) return true;
// 	}
// 	return false;
// }

// int main(){
// 	int arr1[] = {2,4,6,8,-10,-23};
// 	int arr2[] = {32,8,23,10};
// 	int n1 = sizeof(arr1)/sizeof(arr1[0]);
// 	int n2 = sizeof(arr2)/sizeof(arr2[0]);

// 	int sum = 25;

// 	bool res = checkSum(arr1,arr2,n1,n2,sum);
// 	cout<<res<<endl;
// }

// #include<bits/stdc++.h>
// using namespace std;



// string getMostCount(string str, vector<string> banList){
// 	unordered_map<string,int> wordCount;
// 	vector<string> words;
// 	string word="";
// 	for(auto i:str){
// 		if(i == ' ' || ispunct(i)){
// 			if(word!=""){
// 				words.push_back(word);
// 				word="";
// 			}
// 		}else{
// 			word+=tolower(i);
// 		}
// 	}
// 	for(string i:words){
// 		if(wordCount.find(i) == wordCount.end()){
// 			wordCount.insert(make_pair(i,1));
// 		}else{
// 			++wordCount[i];
// 		}
// 	}
// 	int maxCount=0;
// 	string maxKey;
// 	for(auto it=wordCount.cbegin();it!=wordCount.cend();++it){
// 		if(it->second > maxCount && (std::find(banList.begin(), banList.end(),it->first)==banList.end())){
// 				maxCount = it->second;
// 				maxKey = it->first;
			
// 		}
// 	}
// 	return maxKey;

// }


// int main(){
// 	string str = "Hi there, this is me! Who this, man?";
// 	string commonWord = getMostCount(str, {"this"});
// 	cout<<commonWord;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int getMax(int arr[], int n){
// 	int max = 0;
// 	for(int i=0;i<n;++i){
// 		if(arr[i] > max) max = arr[i];
// 	}
// 	return max;
// }

// void countingSort(int arr[], int n, int pos){
// 	int countArray[10] = {0};
// 	for(int i=0;i<n;++i){
// 		++countArray[(arr[i]/pos)%10];
// 	}
// 	for(int i=1;i<10;++i){
// 		countArray[i] = countArray[i] + countArray[i-1];
// 	}
// 	int sortedArr[n];
// 	for(int i=n-1;i>=0;--i){
// 		sortedArr[--countArray[(arr[i]/pos)%10]] = arr[i];
// 	}
// 	for(int i=0;i<n;++i){
// 		arr[i] = sortedArr[i];
// 	}
// }

// void radixSort(int arr[], int n){
// 	int max = getMax(arr,n);
// 	for(int pos=1;max/pos>0;pos*=10){
// 		countingSort(arr, n, pos);
// 	}
// }


// int main(){
// 	int arr[] = {23,15,98,21,203,672};
// 	int n = sizeof(arr)/sizeof(arr[0]);
// 	for(int i:arr) cout<<i<<" ";
// 	cout<<endl;

// 	radixSort(arr,n);

// 	for(int i:arr) cout<<i<<" ";
// 	cout<<endl;
// }

// #include<bits/stdc++.h>
// using namespace std;

// bool checkSumOfArray(vector<int> inputVec, int sum){
// 	unordered_set<int> complement;
// 	for(int i=0;i<inputVec.size();++i){
// 		if(complement.find(inputVec[i]) != complement.end()){
// 			return true;
// 		}else{
// 			complement.insert(sum-inputVec[i]);
// 		}
// 	}
// 	return false;
// }

// int main(){
// 	vector<int> input = {2,6,-4,7,12,6,3};
// 	int sum = 11;
// 	bool isPresent = checkSumOfArray(input,sum);
// 	cout<<isPresent<<endl;
// }


// #include<bits/stdc++.h>
// using namespace std;

// vector<int> getLongestIndex(vector<int> inputVec, int sum){
// 	vector<int> res;
// 	int min_index = 0;
// 	int max_index = 0;
// 	int max_length = 0;
// 	int sum_val = 0;
// 	bool found = false;
// 	for(int right=0, left = 0;right<inputVec.size();++right){
// 		sum_val+=inputVec[right];
// 		while(sum_val > sum && left<inputVec.size()){
// 			sum_val-=inputVec[left];
// 			left++;
// 		}
// 		cout<<sum_val<<endl;
// 		if(sum_val == sum && (right-left)>max_length){
// 			found = true;
// 			max_length = right-left+1;
// 			min_index = left;
// 			max_index = right;
// 		}
// 	}
// 	if(!found) res.push_back(-1);
// 	else{
// 		res.push_back(min_index);
// 		res.push_back(max_index);
// 		res.push_back(max_length);
// 	}
// 	return res;
// }
// int main(){
// 	vector<int> inputVec = {1,2,3,4,5,0,0,0,5,7,3,9,8,7,1,1,1,0,0,0,0,3,2,0};
// 	int sum = 15;
// 	vector<int> res = getLongestIndex(inputVec,sum);
// 	if(res[0]==-1){
// 		cout<<"No sum found in provided list."<<endl;
// 	}else{
// 		cout<<"Largest length of successive values that add up to "<<sum<<" starts from index "<<res[0]<<" till index "<<res[1]<<" and has a length of "<<res[2]<<" units."<<endl;
// 	}

// }


// #include<bits/stdc++.h>
// using namespace std;

// vector<int> getShortestIndex(vector<int> inputVec, int sum){
// 	vector<int> res;
// 	int min_index = 0;
// 	int max_index = 0;
// 	int min_length = inputVec.size();
// 	int sum_val = 0;
// 	bool found = false;
// 	for(int right=0, left = 0;right<inputVec.size();++right){
// 		sum_val+=inputVec[right];
// 		while(sum_val > sum && left<inputVec.size()){
// 			sum_val-=inputVec[left];
// 			left++;
// 		}
// 		cout<<sum_val<<endl;
// 		if(sum_val == sum){
// 			found = true;
// 			if((right-left)<min_length){
// 				min_length = right-left+1;
// 				min_index = left;
// 				max_index = right;
// 			}
// 		}
// 	}
// 	if(!found) res.push_back(-1);
// 	else{
// 		res.push_back(min_index);
// 		res.push_back(max_index);
// 		res.push_back(min_length);
// 	}
// 	return res;
// }
// int main(){
// 	vector<int> inputVec = {1,2,3,4,5,0,0,0,5,7,3,9,8,7,1,1,1,0,0,0,0,3,2,0};
// 	int sum = 15;
// 	vector<int> res = getShortestIndex(inputVec,sum);
// 	if(res[0]==-1){
// 		cout<<"No sum found in provided list."<<endl;
// 	}else{
// 		cout<<"Shortest length of successive values that add up to "<<sum<<" starts from index "<<res[0]<<" till index "<<res[1]<<" and has a length of "<<res[2]<<" units."<<endl;
// 	}

// }


// #include<bits/stdc++.h>
// using namespace std;

//// O(nlogn) due to use of sorting algorith
// int getMaxSum(vector<int> &inputVec){
// 	int size=inputVec.size();
// 	//Sort the vector in ascending order if unsorted
// 	return max(inputVec[0]*inputVec[1]*inputVec[size-1], inputVec[size-3]*inputVec[size-2]*inputVec[size-1]);
// }

//Try above with O(n)












// int main(){
// 	vector<int> inputVec = {-9,-6,-1,0,4,5,8,10};
// 	int maxSum = getMaxSum(inputVec);
// 	cout<<maxSum<<endl;
// }

// #include<bits/stdc++.h>
// using namespace std;

// bool checkIfMatching(string &sentence, string &pattern){
// 	bool flag = false;
// 	for(int i=0,j=0;i<sentence.length();++i){
// 		if(sentence[i] == pattern[j] && j<pattern.length()){
// 			flag = true;
// 			++j;
// 			if(j==pattern.length()) return flag;
// 			continue;
// 		}else{
// 			flag = false;
// 			j=0;
// 		}
// 	}
// 	return flag;
// }

// int main(){
// 	string sentence = "abfsdabcsbabashdabnsabcfabcababcdekfabcskd";
// 	string pattern = "abcd";
// 	bool isMatching = checkIfMatching(sentence,pattern);
// 	cout<<isMatching<<endl;
// }

//KMP algorithm pattern matching

// #include<bits/stdc++.h>
// using namespace std;


//			12345678
//pattern = abcdeabc
//			00000123
//Note on preparing lps
//Index starts from 1 and for each repeating element, it points to the index in which that pattern 1st appeared
//Example: aaaabaacd -> 012301200 (aa after 'b' is 1 and 2 because till index 2, we have aa at the beginning)


// void calculateLPS(vector<int> &lps, string &pattern){
// 	int len = 0; //Length of the previous longest prefix-suffix
// 	lps.push_back(0); //First element will always be 0
// 	int i=1;
// 	while(i<pattern.size()){
// 		if(pattern[i] == pattern[len]){
// 			lps.push_back(++len);
// 			++i;
// 		}else{ //condition - pattern[i] != pattern[len] (E.g. a != b)
// 			if(len!=0){
// 				len = lps[len-1]; //Goes back to check if the element is occuring for the 1st time or not. i is not incremented.
// 			}else{
// 				lps.push_back(0); //Element is coming for the 1st time. Gets assigned 0, i is incremented.
// 				++i;
// 			}
// 		}

// 	}
// }

// vector<int> getMatchKMP(string &sentence, string &pattern){
// 	vector<int> lps;
// 	vector<int> matchedIndex;
// 	calculateLPS(lps, pattern);
// 	int i=0,j=0;
// 	while(i<sentence.length()){
// 		if(sentence[i] == pattern[j]){ //if elements match, increment both pointers to check next elements.
// 			++i;
// 			++j;
// 		}
// 		if(pattern.length() == j){ //if j is equal to pattern size, it is matching
// 			matchedIndex.push_back(i-j);//Make note of matched index and move on
// 			j = lps[j-1];//j is moved back to the previous element in pattern
// 		}else if(sentence[i] != pattern[j] && i<sentence.length()){
// 			if(j!=0){
// 				j = lps[j-1];
// 			}else{
// 				++i;	
// 			}
// 		}
		
// 	}
// 	if(matchedIndex.size()<1) return {-1};
// 	else return matchedIndex;
// }


// int main(){
// 	string sentence = "abfsdabcsbabcabdashdabnsabcfabcababcabcabdab";
// 	string pattern = "abcabd";
// 	vector<int> res  = getMatchKMP(sentence,pattern);
// 	if(res[0] == -1) cout<<"No matches found."<<endl;
// 	else{
// 		for(int i:res) cout<<"Match found at index "<<i<<endl;
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;

// //aabcdaabc
// void createLPS(vector<int> &lps, string pattern){
// 	int len = 0; //size of largest prefix suffix till now
// 	lps.push_back(0); //1st element will always be 0 since one element can't have prefix suffix
// 	int i = 1; //starting from the 2nd index
// 	while(i<pattern.length()){
// 		if(pattern[i] == pattern[len]){//if matching
// 			++len;
// 			lps.push_back(len); //assigns lps value to that element
// 			++i;
// 		}
// 		if(pattern[i] != pattern[len] && i<pattern.length()){//if not matching
// 			if(len!=0){
// 				len=lps[len-1]; //check lps table for which element to fall back to. Not incrementing i.
// 			}else{
// 				lps.push_back(len); //if lenght is 0 and still not getting a match, we assign 0 (len) and increment i, move on to next
// 				++i;
// 			}
// 		}
// 	}
// }

// vector<int> getMatchKMP(string sentence, string pattern){
// 	int i = 0;//setting main iterator to 0 (for sentence)
// 	int j = 0;//setting pattern iterator to 0
// 	vector<int> lps;
// 	vector<int> matchIndex;
// 	createLPS(lps, pattern); //getting lps table for pattern
// 	while(i<sentence.length()){ //main loop
// 		if(sentence[i] == pattern[j]){ //if matching, increment both pointers to check next element
// 			++i;
// 			++j;
// 		}
// 		if(pattern.length() == j){ //if j is matching length of pattern, all elements are matching completely
// 			matchIndex.push_back(i-j);
// 			j = lps[j-1]; // Checks lps table to fall back to last seen prefix (j not resetting to 0)
// 		}else if(sentence[i] != pattern[j] && i<sentence.length()){ //if not matching
// 			if(j!=0){
// 				j=lps[j-1]; //Checks lps to see which element to fall back to
// 			}else{
// 				++i; //Still no matches found and j=0, so increments i and moves on
// 			}
// 		}
// 	}
// 	if(matchIndex.size()<1) return {-1};
// 	else return matchIndex; //returns matched index(es) as vector
// }

// //Driver function
// int main(){
// 	string sentence = "abfsdabcsbabcabdashdabnsabcfabcababcabcabdabcabd";
// 	string pattern = "abcabd";
// 	vector<int> res  = getMatchKMP(sentence,pattern);
// 	if(res[0] == -1) cout<<"No matches found."<<endl;
// 	else{
// 		for(int i:res) cout<<"Match found at index "<<i<<endl;
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;

// //Given a n x n 2D grid with 3 possible values,
// // -1 -> a wall or obstacle
// //  0 -> a gate
// // INF-> an empty room. (We use value 2^31-1 to represent INF. Assume all distances to be less than this.)

// //Fill each room with the distance to its nearest gate. If it is impossible to reach a gate, it should be equal to INF.


// /* 

// Sample input:

// INF   -1      0    INF
// INF   INF    INF   -1
// INF   -1     INF   -1
// 0     -1     INF   INF

// Sample output:

// 3  -1   0   1
// 2   2   1  -1
// 1  -1   2  -1
// 0  -1   3   4

// */


// void bfs(vector<vector<int>> &grid, int i, int j, int count){
// 	if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] < count){
// 		return;
// 	}
// 	grid[i][j] = count;
// 	bfs(grid, i+1, j, count+1);
// 	bfs(grid, i, j+1, count+1);
// 	bfs(grid, i-1, j, count+1);
// 	bfs(grid, i, j-1, count+1);
// }

// void getDistanceFromGate(vector<vector<int>> &grid){
// 	for(int i=0;i<grid.size();++i){
// 		for(int j=0;j<grid[0].size();++j){
// 			if(grid[i][j] == 0)
// 			bfs(grid,i,j,0);
// 		}
// 	}
// }

// int main(){
// 	vector<vector<int>> grid = {{100,   -1,      0,    100},
// 								{100,   100,    100,   -1 },
// 								{100,   -1,     100,   -1 },
// 								{0,     -1,     100,   100}};
	
// 	getDistanceFromGate(grid);

// 	for(int i=0;i<grid.size();++i){
// 		cout<<"{"<<endl;
// 		cout<<"{";
// 		for(int j=0;j<grid[0].size();++j){
// 			cout<<grid[i][j]<<",";
// 		}
// 		cout<<"}"<<endl;
// 	}

// }


// #include<bits/stdc++.h>
// using namespace std;

// struct TrieNode{
// 	unordered_map<char,TrieNode*> children;
// 	bool isLast;
// };

// TrieNode* getNewTrieNode(){
// 	TrieNode* node = new TrieNode;
// 	node->isLast = false;
// 	return node;
// }

// void insert(TrieNode *&head, string word){//passing the reference to a pointer as head (not just reference to a variable)
// 	if(head == nullptr){//if the pointer to the head is null, we create a new head node
// 		head = getNewTrieNode();
// 	}
// 	TrieNode *curr = head;//We set the head node as the current node for the 1st iteration
// 	for(char c:word){//For each char in the word, we check if that node exists in the childrens list.
// 		if(curr->children.find(c) == curr->children.end()){
// 			curr->children[c] = getNewTrieNode();//If the node does not exist, we create a new node
// 		}//If node exists, we set that node as the next one and continue with the iteration
// 		curr = curr->children[c]; //Set curr as the next node with reference of next node corresponding to the char in map
// 	}
// 	curr->isLast = true;//We mark the isLast property of the last character as true, signifying the end of the word
// }

// bool hasChildren(TrieNode const *curr){//reference of the node is provided for checking
// 	for(auto it:curr->children){//checking each entry in the children map of the node
// 		if(it.second!=nullptr) return true;//if any of the chars in the map has an invalid address, we return true
// 	}
// 	return false;
// }

// bool search(TrieNode *head, string word){ //takes head note and starts checking for word from head node
// 	if(head==nullptr) return false; //If trie does not exist, no use checking further
// 	TrieNode *curr = head; //Assigning head node to a TrieNode variable
// 	for(char c: word){
// 		curr=curr->children[c]; //assigning next node to the curr variable. If there is no next node, it will be a null pointer
// 		if(curr==nullptr) return false; //If null pointer, word does not exist. Exit.
// 	}
// 	return curr->isLast; //If last node has isLast set to true, we know it is the end of the word and word exists
// }

// bool deletion(TrieNode *&curr, string word){
// 	if(curr == nullptr) return false; //If curr node is a null pointer, return false
// 	int wordIndex = 0;
// 	for(wordIndex=0;wordIndex<word.length();++wordIndex){ //For the entire word till last (end) char
// 		//cout<<" WORD:"<<word.substr(wordIndex+1,word.length())<<endl;
// 		if(curr!=nullptr && (curr->children.find(word[wordIndex]) != curr->children.end()) && //if current node is not null and if char is present in the children list
// 		   deletion(curr->children[word[wordIndex]], word.substr(wordIndex,word.length())) && curr->isLast==false){//&& if next child is also deleted && it is not the last char
// 			   if(!hasChildren(curr)){//If it has no children (i.e. no dependencies)
// 				   delete curr;//Deleting the node
// 				   curr=nullptr;//Setting node to null
// 				   return true;
// 			   }else{
// 				   return false;
// 			   }
// 		   }
// 	}
// 	//cout<<" Index val:"<<word[wordIndex]<<endl;
// 	if(word[wordIndex] == '\0' && curr->isLast == true){//Handling the last character
// 		if(!hasChildren(curr)){//If it has no children (i.e. no dependencies)
// 				   delete curr;//Deleting the current node
// 				   curr=nullptr;//Setting node to null
// 				   return true;//Deleting non-leaf parent node
// 		}else{//If current node is a leaf node having other dependencies (children) of other words
// 			curr->isLast = false; //Set the isLast status to false to indicate it is no longer the end of a word
// 			return false; //node not deleted
// 		}
// 	}
// 	return false;
// }

//with char of word(working)

// bool deletion(TrieNode *&curr, char *word){
// 	if(curr == nullptr) return false; //If curr node is a null pointer, return false
// 	if(*word){ //For the entire word till last (end) char
// 		if(curr!=nullptr && (curr->children.find(*word)!=(curr->children.end())) && //if current node is not null and if char is present in the children list
// 		   deletion(curr->children[*word], word+1) && curr->isLast==false){//&& if next child is also deleted && it is not the last char
// 			   if(!hasChildren(curr)){//If it has no children (i.e. no dependencies)
// 				   delete curr;//Deleting the node
// 				   curr=nullptr;//Setting node to null
// 				   return true;
// 			   }else{
// 				   return false;
// 			   }
// 		   }
// 	}
// 	if(*word == '\0' && curr->isLast == true){//Handling the last character
// 		if(!hasChildren(curr)){//If it has no children (i.e. no dependencies)
// 				   delete curr;//Deleting the current node
// 				   curr=nullptr;//Setting node to null
// 				   return true;//Deleted non-leaf parent node
// 		}else{//If current node is a leaf node having other dependencies (children) of other words
// 			curr->isLast = false; //Set the isLast status to false to indicate it is no longer the end of a word
// 			return false; //Do not delete this node
// 		}
// 	}
// 	return false;
// }

//Trie implementation in cpp

//node is a pointer to a char node,
//children is a map with a char and the pointer to that char,
//isLeaf is a bool variable to mark if the last node is the end of word

// class TrieNode{
// 	public:
// 		unordered_map<char,TrieNode*> children;
// 		bool isLeaf;
// };

// TrieNode* getNewNode(){
// 	TrieNode* node = new TrieNode;
// 	node->isLeaf = false;
// 	return node;
// }

// void insert(TrieNode *&head, string word){//passing a reference to a pointer
// 	if(head == nullptr){//If the head node does not exist, we create a new head node
// 		head = getNewNode();
// 	}
// 	TrieNode *curr = head; //Setting head node to a pointer curr
// 	for(char c:word){//For each char in the word
// 		if(curr->children.find(c)==curr->children.end()){//If the char is not in the children map of the current node
// 			curr->children[c] = getNewNode();//creates a new node and assigns the pointer to that node to the new char in the children map
// 		}
// 		curr=curr->children[c];//Sets the curr pointer as the pointer to the node of the char
// 	}
// 	curr->isLeaf = true;//After all chars are inserted, the last char of the word is marked as leaf to signify end of word
// }

// bool hasChildren(TrieNode const *head){ //Passing a pointer
// 	for(auto i:head->children){//iterating over the children map of the node
// 		if(i.second != nullptr) return true;//if any valid (not null) pointer is present in the map, it has valid children
// 	}
// 	return false;//Return false if it has no valid children pointers
// }

// bool search(TrieNode *head, string word){//passing head node pointer
// 	if(head == nullptr) return false;//if the head is null, the word is not present in the trie
// 	TrieNode *curr = head;//Setting head pointer to the curr pointer
// 	for(char c:word){//iterating over each char in the word
// 		curr=curr->children[c];
// 		if(curr==nullptr) return false;
// 	}
// 	return curr->isLeaf;//If the last char is a leaf node (end of the word), the word is present in the trie
// }

// bool deletion(TrieNode *&curr, const string word, int depth = 0){//For deletion, we have to delete bottom upwards. Only if all children are deleted or has no dependencies for other words can we delete a head node
// 	if(curr==nullptr) return false; //If curr has no pointer reference, return
// 	if(depth < word.length()){ //Check for recursion to continue till last character
// 		if(curr!=nullptr && (curr->children.find(word.at(depth)) != curr->children.end()) //if curr is not null and if the char exists in the children map
// 		   && deletion(curr->children[word.at(depth)],word,depth+1) && curr->isLeaf==false){//and if all child elements of it are deleted and if it is not a leaf node
// 			if(!hasChildren(curr)){ //if it has no children, delete the node
// 				delete curr;
// 				curr = nullptr;
// 				return true;
// 			}else{ //else don't delete
// 				return false;
// 			}
// 		}
// 	}
// 	if(depth>=word.length() && curr->isLeaf==true){ //For the last node which is at the end of the word and is the leaf
// 		if(!hasChildren(curr)){ //if it has no children, delete the last node
// 			delete curr;
// 			curr = nullptr;
// 			return true;
// 		}else{ //if it has children/dependencies, deleting this node will delete other words as well
// 			curr->isLeaf=false; //set leaf to false instead of deleting, signifying it is not a complete word anymore and won't be returned in a search
// 			return true;
// 		}
// 	}
// 	return false;
// }



// bool deletion(TrieNode *&curr, char *word){
// 	if(curr == nullptr) return false; //If curr node is a null pointer, return false
// 	cout<<" WORD:"<<*word<<" "<<curr->children[*word]<<endl;
// 	if(*word){ //For the entire word till last (end) char
// 		if(curr!=nullptr && (curr->children.find(*word)!=(curr->children.end())) && //if current node is not null and if char is present in the children list
// 		   deletion(curr->children[*word], word+1) && curr->isLeaf==false){//&& if next child is also deleted && it is not the last char
// 			   if(!hasChildren(curr)){//If it has no children (i.e. no dependencies)
// 				   delete curr;//Deleting the node
// 				   curr=nullptr;//Setting node to null
// 				   return true;
// 			   }else{
// 				   return false;
// 			   }
// 		   }
// 	}
// 	if(*word == '\0' && curr->isLeaf == true){//Handling the last character
// 		if(!hasChildren(curr)){//If it has no children (i.e. no dependencies)
// 				   delete curr;//Deleting the current node
// 				   curr=nullptr;//Setting node to null
// 				   return true;//Deleted non-leaf parent node
// 		}else{//If current node is a leaf node having other dependencies (children) of other words
// 			curr->isLeaf = false; //Set the isLast status to false to indicate it is no longer the end of a word
// 			return false; //Do not delete this node
// 		}
// 	}
// 	return false;
// }

// //Driver

// int main()
// {
// 	TrieNode* head = nullptr;

// 	insert(head, "hello");
// 	cout << search(head, "hello") << " ";   	// print 1

// 	insert(head, "helloworld");
// 	cout << search(head, "helloworld") << " ";  // print 1

// 	cout << search(head, "helll") << " ";   	// print 0 (Not present)

// 	insert(head, "hell");
// 	cout << search(head, "hell") << " ";		// print 1

// 	insert(head, "h");
// 	cout << search(head, "h") << endl;  		// print 1 + newline

// 	deletion(head, "hello");
// 	cout << search(head, "hello") << " ";   	// print 0 (hello deleted)
// 	cout << search(head, "helloworld") << " ";  // print 1
// 	cout << search(head, "hell") << endl;   	// print 1 + newline

// 	deletion(head, "h");
// 	cout << search(head, "h") << " ";   		// print 0 (h deleted)
// 	cout << search(head, "hell") << " ";		// print 1
// 	cout << search(head, "helloworld") << endl; // print 1 + newline

// 	deletion(head, "helloworld");
// 	cout << search(head, "helloworld") << " ";  // print 0
// 	cout << search(head, "hell") << " ";		// print 1

// 	deletion(head, "hell");
// 	cout << search(head, "hell") << endl;   	// print 0 + newline

// 	if (head == nullptr)
// 		cout << "Trie empty!!\n";
// 	else
// 		cout<<"Not empty\n";			   		// Trie is empty now

// 	cout << search(head, "hell");   			// print 0

// 	return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;


// class Node{
//     public:
//         int studentID;
//         int studentMarks;
//         Node *nextPtr;
// };

// Node* getNewNode(){
//     Node* node = new Node;
//     node->nextPtr = nullptr;
//     return node;
// }

// typedef Node* studentCollection;


// void addStudent(Node *&head, int id, int marks){
//     while(head->nextPtr!=nullptr){
//         head = head->nextPtr;
//     }
//     Node *curr = getNewNode();
//     curr->studentID = id;
//     curr->studentMarks = marks;
//     head->nextPtr = curr;
// }

// double getAverageMarks(Node *&head){
//     double total = 0;
//     int studentCount = 0;
//     if(head->nextPtr == nullptr) return 0;
//     Node *curr = head;
//     while(curr->nextPtr!= nullptr){
//         curr=curr->nextPtr;
//         total+=curr->studentMarks;
//         studentCount++;
//     }
//     return total/studentCount;
// }

// bool search(Node *&head, int id){
//     if(head == nullptr) return false;
//     Node *curr = head;
//     while(curr != nullptr){
//         if(curr->studentID == id) return true;
//         curr = curr->nextPtr;
//     }
//     return false;
// }

// bool remove(Node *&head, int id){
//     if(head == nullptr) return false;
//     Node *curr = head;
//     Node *prev = head;
//     while(curr!=nullptr){
//         prev = curr;
//         curr=curr->nextPtr;
//         if(curr->studentID == id){
//             prev->nextPtr = curr->nextPtr;
//             delete(curr);
//             curr = NULL;
//             return true;
//         }
//     }
//     return false;
// }

// int main(){
//     studentCollection sc;
//     Node* head = getNewNode();
//     sc=head;
//     addStudent(sc, 1001, 78);
//     addStudent(sc, 1002, 83);
//     addStudent(sc, 1003, 91);
//     addStudent(sc, 1004, 94);
//     addStudent(sc, 1005, 93);

//     // do{
//     //     sc = sc->nextPtr;
//     //     cout<<sc->studentID<<" ";
//     //     cout<<sc->studentMarks<<endl;
//     // }while(sc != nullptr);
//     sc = head;
//     while(sc->nextPtr!=nullptr){
//         sc = sc->nextPtr;
//         cout<<sc->studentID<<" ";
//         cout<<sc->studentMarks<<endl;
//     }

//     sc = head;
//     double avg = getAverageMarks(sc);
//     cout<<"Average marks: "<<avg<<endl;

//     sc = head;
//     bool isPresent = search(head,1006);
//     cout<<"Is present: "<<isPresent<<endl;

//     sc = head;
//     bool isRemoved = remove(head, 1005);
//     cout<<"Is removed: "<<isRemoved<<endl;

//     sc = head;
//     while(sc->nextPtr!=nullptr){
//         sc = sc->nextPtr;
//         cout<<sc->studentID<<" ";
//         cout<<sc->studentMarks<<endl;
//     }
// }
// int main(){
//     cout<<"START"<<endl;
//     studentCollection sc;
//     Node *n1 = new Node;
//     n1->studentID = 1000;
//     n1->studentMarks = 78;

//     Node *n2 = new Node;
//     n2->studentID = 1001;
//     n2->studentMarks = 91;

//     Node *n3 = new Node;
//     n3->studentID = 1002;
//     n3->studentMarks = 83;

//     Node *n4 = new Node;
//     n4->studentID = 1003;
//     n4->studentMarks = 81;

//     sc = n1;
//     n1->nextPtr = n2;
//     n2->nextPtr = n3;
//     n3->nextPtr = n4;
//     n4->nextPtr = nullptr;

//     //n1 = n2 = n3 = n4 = NULL;

//     cout<<n2->nextPtr<<endl;
//     cout<<n4->studentID<<endl;
//     cout<<n1->studentMarks<<endl;
// }

// #include<bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

//Steps:

// int main(){
//     cout<<"Enter the number of steps: "<<endl;
//     int steps;
//     cin>>steps;
//     for(int i=0;i<steps;++i){
//         for(int j=0;j<=i;++j) cout<<"#";
//         for(int k=steps-i;k>1;--k) cout<<" ";
//         cout<<endl;
//     }
// }


//DP
//Given an array of integers (positive and negative), find the largest sum of any non-consecutive integers

//Sample arr = {-5, 3, 4, -1, 2, 6}
//1. Find dp array of 1 element, dp of 2 elements and so on.
//2. Create a dp array of n elements where the value of n elements is stored in the index n of the array

//dp[1] = max(-5,0) = max(arr[0],0)
//dp[2] = max(-5,3) = max(arr[0],arr[1])
//dp[3] = max(-5+4, 3) = max(arr[0]+arr[2], arr[1])
//dp[4] = max(-1, 3)= max(arr[3] + dp[3], dp[n-1]) //Could be with the new element or without it
//dp[n] = arr[n-1] + dp[n-1]

// int getConsecutiveSum(int arr[], int n){
//     int dp[n+1] = {0};
//     dp[1] = max(0,arr[0]);
//     int i = 2;
//     while(i<=n){//To calculate all values of dp from 2 to n and store those values in array to use in the next iteration
//         dp[i] = max(dp[i-1], arr[i-1] + dp[i-2]);
//         ++i;
//     }
//     return dp[n];
// }

// int main(){
//     int inputArr[] = {-5,3,4,-1,2,6};
//     int n = sizeof(inputArr)/sizeof(inputArr[0]);
//     int res = getConsecutiveSum(inputArr, n);
//     cout<<res<<endl;
// }


//ways of climbing stairs -> one at a time, 2 at a time

//dp[1] = 1,
//dp[2] = 2, (2 ways of climbing 2 stairs. 1 at a time x 2, or two at a time x 1)
//dp[3] = 3,  (2,1; 1,1,1; 1,2)
//dp[4] = 5, (2,2; 1,1,1,1; 1,2,1; 2,1,1; 1,1,2)
//dp[5] = 8 , (2,2,1; 1,2,2; 2,1,2; 1,1,1,1,1; 1,1,1,2; 2,1,1,1; 1,1,2,1; 1,2,1,1)
//Results follow fibonacci pattern

//dp[n] = dp[n-1] + dp[n-2];

// int climbingStairs(int n){
//     int dp[n+1] = {0};
//     dp[0] = 1; //zero way of climbing 0 stairs - Dont climb it
//     dp[1] = 1; // 1 way of climbing one stair
//     int i = 2;
//     while(i<=n){
//         dp[i] = dp[i-1] + dp[i-2]; //e.g. dp[4] -> dp[3] + dp[2] -> 3+2 -> 5
//         ++i;
//     }
//     return dp[n];
// }

// int main(){
//     int n = 2; //n stairs
//     int res = climbingStairs(n);//ways of climbing n stairs
//     cout<<res<<endl;
// }


//largest sum of elements from two arrays where elements cannot be consecutive
//i.e if we select element 1 from arr 1, we cannot select element 2 from arr 2

//arr1[] = {5,1,-9,3,2}
//arr2[] = {7,3,1,-3,4}

//dp[1] = max(5,7)
//dp[2] = dp[1] or max(1,3)
//dp[3] = max(dp[1]+max(-9,1)) or dp[2]
//dp[4] = 




// //Traverse array using jumps of 1,2 or 3 steps at a time
// //Find max sum of the jumps

// //arr[] = {2,-3,-5,9,13,24}
// //dp[1] = 1 -> 1
// //dp[2] = 1,1 ; 2 -> 2
// //dp[3] = 1,1,1; 2,1; 1,2 -> 3

// //dp[4] = 9+max(dp[3],dp[2],dp[1])

// int getMaxValue(int a, int b, int c){
//     return max(a,max(b,c));
// }

// int getMaxValue(int a, int b){
//     return max(a,b);
// }

// int getMaxJumpValue(int arr[], int n){
//     int dp[n+1] = {0};
//     dp[0] = 1;
//     dp[1] = arr[0];
//     dp[2] = arr[1] + arr[0];
//     dp[3] = arr[2] + getMaxValue(dp[1], dp[2]);
//     dp[4] = arr[3] + getMaxValue(dp[3], dp[2], dp[1]);
//     //dp[i] = getMaxValue(arr[i-1]+dp[i-1], arr[i-1]+dp[i-2], arr[i-1]+dp[i-3])
//     int i = 5;
//     while(i<=n){
//         dp[i] = arr[i-1] + getMaxValue(dp[i-1], dp[i-2], dp[i-3]);
//         ++i;
//     }
//     return dp[n];
// }

// int main(){
//     // int arr[] = {21,-4,7,3,21,-40,-28,-12,-3,67,12,98};
//     int arr[] = {4,-2,3,5,-4,100};
//     int n = sizeof(arr)/sizeof(arr[0]); //n stairs
//     int res = getMaxJumpValue(arr,n);//ways of climbing n stairs
//     cout<<res<<endl;
// }

// #include<bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

//arr1[] = {2,4,1,9,11}
//arr2[] = {5,-2,7,-1,9}
//dp[1] = max(2,5)
//dp[2] = max(2-2, 4+5)
//dp[4] can either be dp[2]+max(arr1[3],arr2[3]) //if we take 4th element (index 3) we can't take dp[3]
//                 or dp[3] //if we don't take dp[4]

//dp[i] = max(dp[i-2]+max(arr1[i-1], arr2[i-1]), dp[3])

// int getMaxSum(int *arr1, int n1, int *arr2, int n2){
//     int n = (n1>n2?n1:n2);
//     int dp[n+1]={0};
//     dp[1] = max(arr1[0], arr2[0]);
//     dp[2] = max(arr1[1], arr2[2]);
//     int i = 3;
//     while(i<=n){
//         dp[i] = max(dp[i-2] + max(arr1[i-1],arr2[i-1]), dp[i-1]);
//         ++i;
//     }
//     return dp[n];
// }

// int main(){
//     int arr1[] = {2,4,1,9,11};
//     int n1 = sizeof(arr1)/sizeof(arr1[0]);
//     int arr2[] = {5,-2,7,-1,9};
//     int n2 = sizeof(arr2)/sizeof(arr2[0]);
//     int res = getMaxSum(arr1, n1, arr2, n2);
//     cout<<res<<endl;
// }



//GCD

// int getGCD(int arr[], int n){

// }


//LCM

// int GCD(int a, int b){
//     if(a==0) return b;
//     return GCD(b%a,a);
// }

// int getGCD(int arr[], int n){
//     int gcd_res = arr[0];
//     for(int i=1;i<n;++i){
//         gcd_res = GCD(arr[i],gcd_res);
//         if(gcd_res == 1) return 1;
//     }
//     return gcd_res;
// }

// int getLCM(int arr[], int n){
//     int res = arr[0];
//     for(int i=1;i<n;++i){
//         res = res*arr[i]/GCD(arr[i],res);
//     }
//     return res;
// }

// int main(){
//     int arr[] = {8,16,72,32};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int hcf = getGCD(arr, n);
//     int lcm = getLCM(arr,n);
//     cout<<"HCF: "<<hcf<<endl;
//     cout<<"LCM: "<<lcm<<endl;
// }


/*Problem to write program that takes a string and outputs the rearranged string such that
no two same characters in the string are placed next to each other. Outputs empty string if
such an arrangement is not possible.
E.g. aab -> aba; aaab -> ""*/

// #include<bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

// string getRearrangedString(string str){
//     string result = "";
//     unordered_map<char,int> charCount;
//     for(char c:str){
//         if(charCount.find(c) == charCount.end()) charCount.insert({c,1});
//         else(++charCount[c]);
//     }
//     //needs fix
//     priority_queue<char> maxHeap = priority_queue<char>((a, b){charCount[b] - charCount[a]});
//     unordered_map<char,int>::iterator it = charCount.begin();
//     while(it!=charCount.end()){
//         maxHeap.push(it->first);
//         ++it;
//     }
//     while(maxHeap.size()>1){
//         char current = maxHeap.top();
//         maxHeap.pop();
//         char next = maxHeap.top();
//         maxHeap.pop();
//         result+=current;
//         result+=next;
//         --charCount[current];
//         --charCount[next];
//         if(charCount[current]>0) maxHeap.push(current);
//         if(charCount[next]>0) maxHeap.push(next);
//     }
//     if(!maxHeap.empty()){
//         char last = maxHeap.top();
//         maxHeap.pop();
//         if(charCount[last]>0) return "";
//         result+=last;
//     }
//     return result;
// }

// int main(){
//     string inputStr = "aab";
//     string res = getRearrangedString(inputStr);
// }


// #include<bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

/*An alien language uses the same lower case alphabets as us, but in different lexicographical order.
Given a number of words and the lexicographical order, find whether the words are in sorted order. */

// bool checkSortingOrder(vector<string> words, string order){
//     //
//     int orderLen = order.length();

//     //Returns vector of aphabets with their orders in alien language
//     //Example: 5,6,7,4,8, signifying a is the 5th element, b is 6th and so on in alien language
//     vector<int> alphaOrder(orderLen,0);
//     for(int i=0;i<orderLen;++i){
//         alphaOrder[order[i]-'a'] = i;
//     }
    
//     //Iterates through word list and compares words
//     for(int i=0;i<words.size();++i){
//         for(int j=i+1; j<words.size();++j){
//             int min_size = min(words[i].size(),words[j].size());
//             for(int k=0;k<min_size;++k){
//                 char i_char = words[i][k];
//                 char j_char = words[j][k];
//                 if(alphaOrder[i_char-'a'] < alphaOrder[j_char-'a']) break;
//                 else if(alphaOrder[i_char-'a'] > alphaOrder[j_char-'a']) return false;
//                 else if(k+1==min_size && words[i].size()>words[j].size()) return false;
//             }
//         }
//     }
//     return true;
// }

//NEED TO CHECK IF IT IS PASSING ALL TEST CASES
// bool checkSortingOrder(vector<string> words, string order){
//     int orderLen = order.length();
//     vector<int> alphaOrder(orderLen,0);
//     for(int i=0;i<orderLen;++i) alphaOrder[order[i]-'a'] = i;

//     for(int i=1;i<words.size();++i){
//         int minLen = max(words[i-1].size(),words[i].size());
//         for(int k=0;k<minLen;++k){
//             char curr1 = words[i-1][k];
//             char curr2 = words[i][k];
//             if(alphaOrder[curr1-'a']<alphaOrder[curr2-'a']) break;
//             else if(alphaOrder[curr1-'a'] > alphaOrder[curr2-'a']) return false;
//             else if(k+1==minLen && words[i-1].size() > words[i].size()) return false;
//         }
//     }
//     return true;
// }


// int main(){
//     string order = "worldabcefghijkmnpqstuvxyz";
//     vector<string> words = {"word","world","hello","alien","order","or"};
//     //vector<string> words = {"or","order"};
//     bool isSorted = checkSortingOrder(words,order);
//     cout<<isSorted<<endl;
// }

// // //Get max product of each element in array except self (division allowed)
// // #include<bits/stdc++.h>
// // using namespace std;

// // typedef long long int ll;

// // void getMaxProductButSelf(vector<int> inputVec){
// //     int max_product = 1;
// //     for(int i=0;i<inputVec.size();++i){
// //         max_product*=inputVec[i];
// //     }
// //     vector<int> resVec(inputVec.size(),max_product);
// //     for(int i=0;i<inputVec.size();++i){
// //         resVec[i]=resVec[i]/inputVec[i];
// //     }
// //     for(int i:resVec) cout<<i<<endl;
    
// // }

// // int main(){
// //     vector<int> inputVec = {5,4,3,2,1};
// //     getMaxProductButSelf(inputVec);
// // }

// //Get max product of each element in array except self (division NOT allowed)
// #include<bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

// //Without division, the logic is to multiply the product of numbers to
// //the left of the element with the product of numbers to the right of the element
// void getMaxProductButSelf(vector<int> inputVec){
//     //products to the left of each element
//     vector<int> leftVec(inputVec.size());
//     leftVec[0] = 1;
//     for(int i=1;i<inputVec.size();++i){
//         leftVec[i] = inputVec[i-1] * leftVec[i-1];
//     }

//     //products to the left of each element
//     vector<int> rightVec(inputVec.size());
//     rightVec[inputVec.size()-1] = 1;
//     for(int i=inputVec.size()-2; i>=0;--i){
//         rightVec[i] = inputVec[i+1] * rightVec[i+1];
//     }

//     //Product of both vectors
//     vector<int> finalRes(inputVec.size());
//     for(int i=0;i<inputVec.size();++i){
//         finalRes[i] = leftVec[i]*rightVec[i];
//     }
    
//     //Printing result
//     for(int i:finalRes) cout<<i<<endl;
// }

// int main(){
//     vector<int> inputVec = {5,4,3,2,1};
//     getMaxProductButSelf(inputVec);
// }


// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> men;
//     for(int i=1;i<=100;++i){
//         men.push_back(i);
//     }
//     cout<<"Original:"<<endl;
//     for(int i:men) cout<<i<<" ";
//     cout<<endl;
//     int count = 0;
//     vector<int> temp;
//     int men_size = men.size();
//     cout<<men_size;
//     while(men_size>1){
//         cout<<"Step "<<++count<<":"<<endl;
//         for(int i=0;i<men_size;i+=2){
//             temp.push_back(men[i]); 
//         }
//         men = temp;
//         temp.clear();
//         men_size = men.size();
//         for(int i:men) cout<<i<<" ";
//         cout<<endl;
//     }
//     for(int i:men) cout<<"Last man: "<<i<<endl;
// }


// int main(){
//     vector<int> men;
//     for(int i=1;i<=100;++i){
//         men.push_back(i);
//     }
//     vector<int> temp;
//     cout<<"Original:"<<endl;
//     temp = men;
//     for(int i:temp) cout<<i<<" ";
//     men.clear();
//     for(int i:men) cout<<i<<" ";
//     cout<<men.size()<<endl;
// }


// //Increment an int array which stores the digits at each index
// //e.g [1,2,9] -> [1,3,0]

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int inputArr[] = {1,2,9};
//     int n = sizeof(inputArr)/sizeof(inputArr[0]);
//     // int temp = 0;
//     // int carry = 0;
//     for(int i=n;i>0;--i){
//         cout<<n<<endl;
//     }
// }



//KMP

#include <bits/stdc++.h>
using namespace std;

void createLPS(string pat, vector<int> &lps){
    int len = 0;
    int forward = 1;
    while(forward<pat.size()){
        if(pat[len] == pat[forward]){
            ++len;
            lps[forward] = len;
            ++forward;
        }else{
            if(len>0){
                len=lps[len-1];
            }else{
                ++forward;
            }
        }
    }
}


void getMatchesKMP(string str, string pat){
    int str_ptr = 0;
    int pat_ptr = 0;
    bool isPresent = false;
    vector<int> lps(pat.size(),0);
    createLPS(pat,lps);
    while(str_ptr<str.size()){
        if(str[str_ptr] == pat[pat_ptr]){
            ++str_ptr;
            ++pat_ptr;
        }
        if(pat_ptr == pat.size()){
            isPresent = true;
            cout<<"Match found at index: "<<str_ptr-pat_ptr<<endl;
            ++str_ptr;
            pat_ptr=lps[pat_ptr-1];
        }
        if(str[str_ptr] != pat[pat_ptr] && str_ptr<str.size()){
            if(pat_ptr>0){
                pat_ptr=lps[pat_ptr-1];
            }else{
                ++str_ptr;
            }
        }
    }
    if(!isPresent) cout<<"No matches found."<<endl;
}


int main() {
	string str = "ADRSCRUDRUDRASRUSTDRUDAJISTRUARUDRLI";
	string pat = "RUDRA"; //LPS: 00010 (LPS index is assumed to start from 1, so last occurence of the second R is 1)
	getMatchesKMP(str,pat);
	return 0;
}
