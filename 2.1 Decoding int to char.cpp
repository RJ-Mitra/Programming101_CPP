//Code to decode char code from int list


#include<iostream>

using std::cin;
using std::cout;



char getNewModulo(char prevModulo){
    char newModulo;
    switch(prevModulo){
        case 'U':
            newModulo = 'L';
            break;
        case 'L':
            newModulo = 'P';
            break;
        case 'P':
            newModulo = 'U';
            break;
    }
    return newModulo;
}

char getCalculatedValue(char property, int inputNum){
    int opNum;
    char outputChar;

    char punctuationDecoder[] = {'!','?',',','.',' ',';','"','\''};
    
    switch(property){
        case 'U':
            opNum = (inputNum%27);
            if (opNum!=0){
                outputChar = static_cast<char>(opNum+64);
            }else{
                outputChar = '0';
            }
            break;
        
        case 'L':
            opNum = (inputNum%27);
            if (opNum!=0){
            outputChar = static_cast<char>(opNum+96);
            }else{
                outputChar = '0';
            }
            break;

        case 'P':
            opNum = (inputNum%9);
            if (opNum!=0){
            outputChar = punctuationDecoder[opNum-1];
            }else{
                outputChar = '0';
            }
            break;
    }
    return outputChar;
}



int main(){
    int inputString[] = {18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10};
    //char digit;
    //int index = 0;
    //int inputString[] = {};
    char modulo = 'U';
    char calcResult;
    
    //cout<<"Enter your digits. Press enter twice once done: ";
    //digit = cin.get();

    // while(sizeof(digit) > 0){
    //     inputString[index] = int(digit);
    //     digit = cin.get();
    //     index++;
    // }



    for(int i : inputString){
        calcResult = getCalculatedValue(modulo, i);
        if(calcResult == '0'){
            modulo = getNewModulo(modulo);
        }else{
        cout<<calcResult;
        }
    }
}