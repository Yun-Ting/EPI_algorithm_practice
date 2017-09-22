// 6.4_replace-and-remove.cpp
// 9/21 : 弄了好久才弄懂
#include <iostream>
#include <string>
using namespace std;

int ReplaceAndRemove(int size, char s[]) { // char s[] means it's a character arr
	// <a,c,a,a,_,_,_>
	// forward iteration: remove "b"s and 
	// count the number of "a"s
	int write_idx = 0; // the next where we're going to write to
	int a_count = 0;
	for (int i = 0; i < size; ++i) {
		if (s[i] != 'b') {
			s[write_idx++] = s[i]; // becasue write_idx increases after assignment
		}
		if (s[i] == 'a') {
			++a_count;
		}
	}
	// backward iteration: 
	// replace 'a's with 'd's starting from the end
	int cur_idx = write_idx - 1; // the cur_idx is for logok up
	write_idx = write_idx + a_count - 1; // write_idx is for writing
	const int final_size = write_idx + 1; // because write_idx will change as
										  // we starts writing,
										  // we need to create another const
										  // to store it
										  // why "+1", because the idx starts from 0, so the size from 0 ~ write_idx 
										  // is write_idx + 1
	while (cur_idx >= 0) {
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

int main() {
	char charArr[] = {'a', 'c', 'a', 'a', 's', 'w', 'h'};
	int final_size = ReplaceAndRemove(4, charArr);
	for (int i = 0; i < final_size; ++i) {
		cout << charArr[i] << endl;
	}
} 
