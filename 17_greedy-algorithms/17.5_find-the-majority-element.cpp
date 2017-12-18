// 17.5_find-the-majority-element.cpp

string Majority(vector<string>::const_iterator input_stream_begin, 
			    const vector<string>::const_iterator input_stream_end) {

	string candidate;
	int candidate_count = 0;
	while(input_stream_begin != input_stream_end) {
	    string it = *input_stream_begin++;
	    if(candidate_count == 0) {
	    	candidate = it;
	    	candidate_count = 1;
	    }
	    else if(candidate == it) {
	    	++candidate_count;
	    }
	    else {
	    	--candidate_count;
	    }
	}
	return candidate;
}