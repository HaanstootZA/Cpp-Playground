#include <cstdlib>
#include <ctime>
#include "Stringcleaner.h"

using namespace std;

int main(int argc, char** argv) {
    const string original = "A Very Long string\n"
    "By Hendrik Jacobs\n"
    "This is a very long string, and this very long string has a very long story\n"
    "attached to it.\n"
    "I created this string because I needed a string from which I can remove\n"
    "certain character, by removing these characters I can test the differences\n"
    "in my character removal algorithms, the fastest of these will be used within\n"
    "my music file renaming program.\n";
    int n_runs = 1000000;
    double diff1 = 0;
    double diff2 = 0;
    Stringcleaner t_Stringcleaner;
    
    string cpy = original;
    std::clock_t start;
    for ( int i = 0; i < n_runs; i++ ){
        start = std::clock();
        cpy = t_Stringcleaner.RemoveChar(cpy, 'a');
        diff1 += ( std::clock() - start ) / (double)CLOCKS_PER_SEC;
        int s = cpy.size();
        cpy = original;
    }
    //361
    //358
    for ( int i = 0; i < n_runs; i++ ){
        start = std::clock();
        cpy = RemoveChar(cpy, 'a');
        diff2 += ( std::clock() - start ) / (double)CLOCKS_PER_SEC;
        int s = cpy.size();
        cpy = original;
    }
    cout << "Stringcleaner current\n"
         << ((int)(diff1/60)) << "m "
         << diff1 << "s"  <<endl;
    
    cout << "Stringcleaner new\n"
         << ((int)(diff2/60)) << "m "
         << diff2 << "s" <<endl;
    
    system("pause");
    return 0;
}