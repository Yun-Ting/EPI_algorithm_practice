#include <iostream>
using namespace std;

int ReplaceAndRemove(int size, char s[]) {
    
    int write_idx = 0;
    int a_count = 0;
    
    // forward iteration: remove the 'b's and count the 'a's
    for (int i = 0; i < size; ++i) {
        if (s[i] != 'b') {
            s[write_idx++] = s[i];
        }
        if (s[i] == 'a') {
            ++a_count;
        }
    }
    
    // backward iteration: replace 'a's with 'dd's starting from the end
    int cur_idx = write_idx - 1;
    write_idx = write_idx + a_count - 1;
    const int final_size = write_idx + 1;
    
    while(cur_idx >= 0) {
        if (s[cur_idx] == 'a') {
            s[write_idx--] = 'd';
            s[write_idx--] = 'd';
        } else {
            s[write_idx--] = s[cur_idx];
        }
        --cur_idx;
    }
    return final_size;
}


int main(int argc, const char * argv[]) {
    char myword[] = "acdbbca";
    cout << ReplaceAndRemove(7, myword) << endl;
    
    char *ptr = myword;
    while (*ptr != '\0') {
        cout << *ptr << endl;
        ++ptr;
    }
}
