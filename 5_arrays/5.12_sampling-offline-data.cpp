//
//  main.cpp
//  sampling-offline
//
//  Created by Lin, Yun-Ting on 7/5/17.
//  Copyright © 2017 Lin, Yun-Ting. All rights reserved.
//

// Example program
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

void RandomSampling( int k, vector<int>* A_ptr ){
    vector<int>& A = *A_ptr;
    default_random_engine seed( (random_device()) () );
    
    for ( int i = 0; i < k; ++i ) {
        // generate a random index in [i, A.size() - 1]
        swap( A[i],  A[uniform_int_distribution<int>{i, static_cast<int>(A.size()) - 1}(seed)] );
    }
    for ( int i = 0; i < A.size(); ++i) {
        cout << A[i] << endl;
    }
}

int main()
{
    vector<int> myVector = { 3,7,5,11 };
    RandomSampling( 3, &myVector );
    return 0;
}
