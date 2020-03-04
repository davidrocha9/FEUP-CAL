/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>
#include <vector>

string calcSum(int* sequence, int size){
    string result = "";

    int sum[size];
    int min, idx;

    for(int m=1; m <= size; m++){
        min = INT_MAX;
        for(int i=0; i <= size-m ; i++){
            switch(m){
                case 1:
                    sum[i]= sequence[i];
                    break;
                default:
                    sum[i]=sum[i]+sequence[i+m-1];
                    break;
            }
            if(sum[i]<min){
                min=sum[i];
                idx=i;
            }
        }
        result += to_string(sum[idx])+ ","+ to_string(idx)+";";
    }
    return result;
}

