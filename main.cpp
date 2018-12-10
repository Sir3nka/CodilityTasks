#include <iostream>
#include <vector>
#include <bitset>
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