// 13.5_render-a-calendar.cpp

struct Event {
	int start, finish;
};

struct EndPoint {
	bool operator<(const EndPoint& e) const {
		// if times are equal, an endpoint that starts
		// an interval comes first.
		return time != e.time ? time < e.time : (is_start && !e.is_start);
	}
	int time;
	bool is_start;
};

int FindMaxSimultaneousEvents(const vector<Event>& A) {
	// Builds an array of all endpoints
	vector<EndPoint> E;
	for (const Event& event : E) {
		E.emplace_back(EndPoint{event.start, true});
		E.emplace_back(EndPoint{event.end, false});
	}
	sort(E.begin(), E.end());

	int max_num_simultaneous_events = 0;
	int num_of_simultaneous_events = 0;

	for (const EndPoint& endpoint : E) {
		if (endpoint.is_start) {
			++num_of_simultaneous_events;
			max_num_simultaneous_events = max(num_of_simultaneous_events, max_num_simultaneous_events);
		} else {
			--num_of_simultaneous_events;
		}
	}
	return max_num_simultaneous_events;
}




