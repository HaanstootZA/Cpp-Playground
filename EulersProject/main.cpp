#include <cstdlib>
#include <iostream>
#include <list>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

#pragma region Project1
typedef unsigned long long ULONG;
typedef list<ULONG> FLIST,*PFLIST;
//Get the sum of the value between min and max
ULONG GetSumOfBetween(int min, int max){
     return (max *(max+min))/2;
}

//Get the sum of all the natural number that are divisible by
//divisor, and between min and max
ULONG GetSumForMultiplesBetween(int min, int divisor, int max){
     int i = min + 1;           //bottom
     int n = (max - i)/divisor; //top
     return divisor*(GetSumOfBetween(i, n));
}

void Project1(){
    ULONG answer = GetSumForMultiplesBetween(0, 3, 1000)//sum of values divisible by 3 smaller than 1000
               + GetSumForMultiplesBetween(0, 5, 1000)//sum of all values divisilbe by 5 smaller than 1000
               - GetSumForMultiplesBetween(0, 15, 1000); //sum of all values divisible by 15(3*5) smaller than 1000;
    cout << "Find the sum of all the multiples of 3 or 5 below 1000." << endl;
    cout << answer << endl;
}
#pragma endregion

#pragma region Project2
void GetNextEvenFibonacci(ULONG& current, ULONG& previous){
    previous = 2*current + previous ;
    current = 2*previous - current;
}

ULONG SumEvenFibonacci(ULONG max){
    ULONG current = 2;
    ULONG previous = 1;
    ULONG ret = 0;
    while(current < max){
        ret += current;
        GetNextEvenFibonacci(current, previous);
    }
    return ret;
}

void Project2(){
    ULONG answer = SumEvenFibonacci(4000000);
    cout << "Find the sum of all the even Fibonacci values smaller than 4M." << endl;
    cout << answer << endl;
    return ;
}
#pragma endregion

#pragma region Project 3
bool IsDecimal(double val){
    if((int)val == val)
        return false;
    return true;
}

PFLIST FindPrimeFactors(ULONG val){
    PFLIST Factors = new FLIST();
    int r = sqrt(val);
    int c = 0;
    while(r > 1 && c == 0){
        if(val % r == 0){
            PFLIST tr = FindPrimeFactors(val/r);
            Factors->merge(*tr);
            tr = FindPrimeFactors(r);
            Factors->merge(*tr);
            
            c++;
            delete tr;
        }
        r--;
    }
    if(c == 0)
        Factors->push_back(val);
    return Factors;
}

void Project3(){
    PFLIST answer = FindPrimeFactors(600851475143);
    cout << "The prime factors of 600851475143 are:" << endl;
    for(FLIST::iterator iter = answer->begin(); iter != answer->end(); ++iter){
        cout << *iter << " ; ";
    }
    cout << endl;
}
#pragma endregion

#pragma region Project 4
//long ReverseLong(long val){
//    long ret = 0;
//    while(val > 0){
//        ret = ret*10 + val%10;
//        val = val/10;
//    }
//    return ret;
//}
//
//bool IsPalindrome(long val){
//    int newval = ReverseLong(val);
//    return (newval == val);
//}

int FindLargestDivider(int min, int max){
    min -= 1;
    max += 1;
    return (max/11 - 1)*11;
}

int LargestPalindromeWithFactorsBetween(int mfactor1range, int mfactor2range){
    //All Palindromes that have an even number of digits, is divisble by 11
    //Largest number divisble by 11, thats larger than 100 and smaller than 1000
    int divisor = FindLargestDivider(mfactor1range, mfactor2range);
    //find the largest value for x, where 990x = a(10^5 + 1) + b(10^3 + 1) + c(10^1 + 1)
    //and x is a positive integer
    int maxpal = 0;
    long result =0;
    double test;
    while(divisor > 99){
        for(int a = 9; a >= 0; a--){
            for(int b = 9; b >= 0; b--)
            {
                for(int c = 9; c > 0; c--){
                    result = a*(100001) + 10*b*(1001) + 100*c*(11);
                    test = ((double)result)/((double)divisor);
                    if(!IsDecimal(test) && result > maxpal
                    && (99 < test && test < 1000)){
                        maxpal = result;
                    }
                }
            }
        }
        divisor -= 11;
    }
    return maxpal;
}

void Project4(){
    cout << "Largest is " << LargestPalindromeWithFactorsBetween(100, 1000) << endl;
}
#pragma endregion

#pragma region Project5
class PrimeExponent{
    public:
        int PrimeBase;
        int Exponent;
        bool operator==(const PrimeExponent &rhs) const {
            return PrimeBase == rhs.PrimeBase;
        }
        bool operator<(const PrimeExponent &rhs) const{
            return PrimeBase < rhs.PrimeBase;
        }
        bool operator>(const PrimeExponent &rhs) const{
            return PrimeBase > rhs.PrimeBase;
        }
        int Pow(){return pow(PrimeBase, Exponent);}
};
typedef list<int> ILIST, *PILIST;
typedef list<PrimeExponent> ELIST, *PELIST;

void MergePrimeValues(PELIST lhs, PELIST &rhs){
    bool contains = false;
    for(ELIST::iterator riter = rhs->begin(); riter != rhs->end(); ++riter){
        for(ELIST::iterator liter = lhs->begin(); liter != lhs->end(); ++liter){
            if(*riter == *liter){
                (*liter).Exponent += (*riter).Exponent;
                contains = true;
            }
        }
        if(!contains)
            lhs->push_back(*riter);
        contains = false;
    }
}

PELIST FindPrimeFactors_2(int val){
    PELIST Factors = new ELIST();
    int r = sqrt(val);
    int c = 0;
    while(r > 1 && c == 0){
        if(val % r == 0){
            PELIST tr = FindPrimeFactors_2(val/r);
            MergePrimeValues(Factors, tr);
            tr = FindPrimeFactors_2(r);
            MergePrimeValues(Factors, tr);
            c++;
            delete tr;
        }
        r--;
    }
    if(c == 0){
        PrimeExponent temp;
        temp.Exponent = 1;
        temp.PrimeBase = val;
        Factors->push_back(temp);
    }
    return Factors;
}

void AddPrimeValuesToCommomValues(PELIST lhs, PELIST &rhs){
    bool contains = false;
    for(ELIST::iterator riter = rhs->begin(); riter != rhs->end(); ++riter){
        for(ELIST::iterator liter = lhs->begin(); liter != lhs->end(); ++liter){
            if(*riter == *liter){
                if((*riter).Exponent > (*liter).Exponent)
                        (*liter).Exponent = (*riter).Exponent;
                contains = true;
            }
        }
        if(!contains)
            lhs->push_back(*riter);
        contains = false;
    }
}

PELIST GetCommonPrimeValues(PILIST Values){
    Values->sort();
    PELIST flist;
    PELIST PrimeList = new ELIST();
    for(ILIST::iterator iter = --Values->end(); iter != Values->end(); --iter){
        flist = FindPrimeFactors_2(*iter);
        AddPrimeValuesToCommomValues(PrimeList, flist);
    }
    return PrimeList;
}

ULONG FindSmallestCommonDenominator(PILIST Values){
    PELIST numlist = GetCommonPrimeValues(Values);
    ULONG ret = 1;
    cout << "Common Prime values with exponents are:";
    numlist->sort();
    for(ELIST::iterator iter = numlist->begin(); iter != numlist->end(); ++iter){
        ret *= (*iter).Pow();
    }
    cout << endl;
    delete numlist;
    return ret;
}

void Project5(){
    PILIST values = new ILIST();
    for(int i = 1; i <= 30; i++){
        values->push_back(i);
    }
    ULONG value = FindSmallestCommonDenominator(values);
    delete values;
    cout << "The Smallest Common Denominator for all the values from 1 to 20 is" << endl;
    cout << value << endl;
}
#pragma endregion Project Euler project 5

#pragma region Project6
int GetSumOfPowers(int n){
    return (n*(n+1)*(2*n + 1))/6;
}

void Project6(){
    long value = pow(GetSumForMultiplesBetween(0, 1, 101), 2) - GetSumOfPowers(100);
    cout.setf(ios::fixed);
    cout << value;
    cout << endl;
}
#pragma endregion

#pragma region Project7
//Just can't see how this is ever quicker!!!
//http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
long SieveOfEratosthenes(int n){
    return 0;
}

long FindNthPrime(int n){
    long upperlimit = n*log(n)+n*log(log(n))+2*n;
    long nthPrime;
    PFLIST factors = NULL;
    for(int i = 2; i <= upperlimit && n > 0; i++){
        PFLIST factors = FindPrimeFactors(i);
        int temp = factors->size();
        if(temp == 1)
            n--;
        if(n == 0)
            nthPrime = i;
        delete factors;
        factors = NULL;
    }
    return nthPrime;
}

void Project7(){
    long value = FindNthPrime(10001);
    cout.setf(ios::fixed);
    cout << value;
    cout << endl;
}
#pragma endregion

#pragma region Project8
int CharToInt(char){
    
}

int ProductStringValues(string value){
    int val = 1;
    for(int i = 0; i < value.size(); i++){
        char temp = value[i];
        val *= atoi(&temp);
    }
    return val;
}

int MoveBar(string &current, char next, int range){
    current = current.substr(1, range-1) + next;
    return ProductStringValues(current);
}

int FindLargestProductOf(string number, int range){
    string current = number.substr(0, range);
    string end = number.substr(number.size()-(range));
    int index = range;
    int max = ProductStringValues(current);
    int temp = 0;
    do{
        temp = MoveBar(current, number.substr(index, 1)[0], range);
        if(temp > max)
            max = temp;
        index++;
    }while(current != end);
    return max;
}

void Project8(){
    int value = FindLargestProductOf(
            "73167176531330624919225119674426574742355349194934"
            "96983520312774506326239578318016984801869478851843"
            "85861560789112949495459501737958331952853208805511"
            "12540698747158523863050715693290963295227443043557"
            "66896648950445244523161731856403098711121722383113"
            "62229893423380308135336276614282806444486645238749"
            "30358907296290491560440772390713810515859307960866"
            "70172427121883998797908792274921901699720888093776"
            "65727333001053367881220235421809751254540594752243"
            "52584907711670556013604839586446706324415722155397"
            "53697817977846174064955149290862569321978468622482"
            "83972241375657056057490261407972968652414535100474"
            "82166370484403199890008895243450658541227588666881"
            "16427171479924442928230863465674813919123162824586"
            "17866458359124566529476545682848912883142607690042"
            "24219022671055626321111109370544217506941658960408"
            "07198403850962455444362981230987879927244284909188"
            "84580156166097919133875499200524063689912560717606"
            "05886116467109405077541002256983155200055935729725"
            "71636269561882670428252483600823257530420752963450", 5);
    //long value = FindNthPrime(10001);
    cout.setf(ios::fixed);
    cout << value;
    cout << endl;
}
#pragma endregion

int main(int argc, char *argv[]){
    Project5();
    system("PAUSE");
    return EXIT_SUCCESS;
}
