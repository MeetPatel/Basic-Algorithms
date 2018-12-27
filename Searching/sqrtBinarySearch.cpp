//Find sqrt with binary search upto given precision
#include<iostream>
#define presicion 15   //sqrt upto 15 digits after decimal point //NOTE: don't go beyond 15 presicion.
using namespace std;    //don't go beyond 6 presicion when answer dataType is float (not double).

double sqrtBinary(int x){
    if(x==0 || x==1){
        return x;
    }

    int start = 1, end = x;
    double ans;

    while(start <=end){         //calculate integral part of sqrt
        int mid = start + (end-start)/2;

        if(mid*mid == x){ 
            ans = mid;
            break;
        }
        if(mid*mid < x){
            start = mid+1;
            ans = mid;
        }
        else {
            end = mid- 1;
        }
    }                         //end of calculating integral part
    
    float increment = 0.1;      //calculate fractional part
    for(int i=0; i<presicion; i++){
        while(ans*ans <= x){
            ans += increment;
        }
        ans = ans - increment;
        increment /= 10;
    }                           //end of calculating fractional part
    return ans;
    
}
int main(){
    int a = 17;
    cout<< "Sqrt of " << a<< " is "<< sqrtBinary(a)<< endl;
    return 0;
}
