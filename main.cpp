#include <iostream>
#include <vector>
#include <bitset>
//A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
//
//For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.
//
//Write a function:
//
//int solution(int N);
//
//that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
//
//For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.
//
//Write an efficient algorithm for the following assumptions:
//
//N is an integer within the range [1..2,147,483,647].
//Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
using namespace std;


int findGap(string solution ) {
    //Gap is abs(X - Y )
    vector<int> holdCoord;
    int length = 0;
    for ( int i(0) ; i <=solution.length() ; i++)
        //We're looking for ones in code and we need to save their indexes to check gaps
        if(solution[i]=='1')
            holdCoord.push_back(i);

    if( holdCoord.size()==1) return 0 ;
     vector<int>::iterator it;
     for( it = holdCoord.begin() ; it!=holdCoord.end(); it++ ){
         //if we're checking last element and we call next nothing with happend but it'll gimp our gap so we need to ignore this one
         if( next(it)==holdCoord.end()) continue;
         int tmp = abs(*it - ( *next(it) ));
         if(tmp > length) length = tmp;
     }
    return length - 1 ;
}
int solution(int &A) {
    string hold = bitset<32>(A).to_string();
    //Lazy solution is to assume that imput is not bigger than 32 bites, then we need to cut off it's head
    for (int i(0); i <= hold.length(); i++)
        //Erase the range of 0 to I without the I ;
        if( hold[i] == '1') {
            hold.erase(0, i);
            break;
        }
    cout<<hold <<"\n";
    return findGap(hold);
}


int main (){

    int a = 561892;
    std:: cout << bitset<32>(a).to_string() << "\n";
    std::cout<<solution(a);
}