#include "Common.h"
#include "DoryeongPark.h"

/*
	Constructor
	
	Initializes state, card_table, card_info, monitor.
*/
DoryeongPark::DoryeongPark()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
		for (int j = 0; j < BOARD_SIZE; ++j) {
			state[Point{ i, j }] = UNKNOWN;
			card_table[Point{ i, j }] = UNKNOWN;
		}
		
	for (int i = 1; i <= LAST_CARD_NUMBER; ++i) {
		card_info[i] = SAME_CARD_COUNT;
		monitor[i].resize(0);
	}

}


/*
	inputFirst

	If it has pair of same cards, store one of them in point passer and returns another one.
	If it couldn't find same pair, discover unknown point.

*/
Point DoryeongPark::inputFirst(){

	Point same_p1;

	if (pickSamePair(same_p1)) {
		return same_p1;
	}
	else {
	
		for (auto& p : state) 
			if (p.second == UNKNOWN)
				return p.first;

	}
}

/*
	inputSecond

	If it found same pairs in progress of inputFirst, returns another one in point passer.
	If card number of point picked in progress of inputFirst has same card number with one in monitor,
	returns the point.
*/
Point DoryeongPark::inputSecond()
{
	Point p2;

	if (!point_passer.empty()) {
		p2 = point_passer.front();
		point_passer.clear();
		return p2;
	}
	else {
		for (auto& v : monitor)
			if (v.first == latest_card && v.second.size() >= 2)
				return v.second.front();
	
		return Point{ 0,0 };
	}
}

/*
	checkCardInfo

	Stores new information in monitor.
*/
void DoryeongPark::checkCardInfo(Point point, 
									int card)
{
	card_table[point] = card;

	if (state[point] == UNKNOWN) {
		state[point] = DISCOVERED;
		monitor[card].emplace_back(point);
	}

	updateMonitor();

	latest_card = card;
}

/*
	matchedCard

	If matched card's information exist in monitor, removes it.
	Changes state of the matched points to BLOCKED.
*/
void DoryeongPark::matchedCard(Point p1, Point p2, 
										int card)
{
	if (p1 == p2) {
		state[p1] = DISCOVERED;
		monitor[card].emplace_back(p1);
		return;
	}

	state[p1] = BLOCKED;
	state[p2] = BLOCKED;
	
	monitor[card].erase(remove(monitor[card].begin(), 
		monitor[card].end(), p1), monitor[card].end());

	monitor[card].erase(remove(monitor[card].begin(), 
		monitor[card].end(), p2), monitor[card].end());

	card_info[card] -= 2;
}

/*
	pickSamePair

	If monitor has pair of same cards, 
	it transfers one of them to point passer and another to paramenter
*/
bool DoryeongPark::pickSamePair(Point& p)
{
	vector<int> same_cards_no;

	for (int i = 1; i <= LAST_CARD_NUMBER; ++i)
		if (monitor[i].size() >= 2)
			same_cards_no.emplace_back(i);

	if (same_cards_no.empty()) 
		return false;
	
	random_shuffle(same_cards_no.begin(), same_cards_no.end());

	auto card_selected = same_cards_no.front();

	auto p1 = monitor[card_selected].back();
	auto p2 = monitor[card_selected].front();

	point_passer.emplace_back(p2);
	p = p1;

	return true;
}

void DoryeongPark::updateMonitor() {

	for (auto& s : state)
		if (s.second == DISCOVERED && !existInMonitor(s.first))
			monitor[card_table[s.first]].emplace_back(s.first);

}

bool DoryeongPark::existInMonitor(Point p) {
	
	for (auto& v : monitor) 
		for (auto& vp : v.second) 
			if (vp == p)
				return true;
	
	return false;
}
