#include "Common.h"
#include "DoryeongPark.h"
#include "Point.h"

/*
	Constructor

	Initiates monitor/probablilty table/flag table.
*/
DoryeongPark::DoryeongPark()
{
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = BOARD_SIZE - 1; j >= 0; --j) {

			monitor[Point{ i, j }] = UNKNOWN;
			prob_table[Point{ i, j }] = UNKNOWN;
			visited[Point{ i, j }] = false;

		}
	}

	reduce_reservation.reserve(BOARD_SIZE * BOARD_SIZE);
}

/*
	input

	Returns the highest probability point.
*/
Point DoryeongPark::input() noexcept {

	auto p = get_highest();

	//cout << "Player 1 - " << p << endl;

	return p;
}

/*
	checkMineInfo

	Gets information of mine point.
	Updates probability table with the point.
*/
void DoryeongPark::checkMineInfo(const Point p) noexcept
{
	monitor[p] = -1;
	prob_table[p] = 0;
	visited[p] = true;

	mine_reduce_effect(p);

	update_prob_table();

}

/*
	checkBoardInfo

	Gets information of exposed point.
	Updates probability table with the point.
*/
void DoryeongPark::checkBoardInfo(const Point& p, const int value) noexcept
{
	monitor[p] = value;

	for (auto it = reduce_reservation.begin(); it != reduce_reservation.end(); ++it) {
		if (*it == p)
			--monitor[p];
	}

	prob_table[p] = 0;
	visited[p] = true;

	update_prob_table();
}

/*
	update_prob_table

	Updates probability table as monitor changes.
*/
void DoryeongPark::update_prob_table() noexcept {

	for (auto p : monitor) {
		if (p.second != -1 && p.second != UNKNOWN)
			distribute_prob(p.first);

		if (monitor[p.first] == 0)
			expand_zero(p.first);
	}

}

/*
	distribute_prob

	Distributes probability from one point to 8 points around.
*/
void DoryeongPark::distribute_prob(Point p) noexcept {

	vector<Point> points;
	double prob;

	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {

			auto&& current_p = Point{ p.getX() + i, p.getY() + j };

			if (i == 0 && j == 0) {
				prob_table[current_p] = 0;
				continue;
			}

			if (current_p.checkBoardRange() && visited[current_p] == false)
				points.emplace_back(current_p);

		}
	}

	if (!points.empty())
		prob = static_cast<double>(monitor[p]) / points.size();

	for_each(points.begin(), points.end(), [&](Point q) {
		if (prob_table[q] < prob) {

			if (prob_table[q] > 0) {
				auto weight = prob_table[q] * 0.3;

				if (prob + weight > 1)
					prob_table[q] = 1;
				else
					prob_table[q] = prob + weight;
			}
			else
				prob_table[q] = prob;

		}
		else if (prob_table[q] == 0)
			prob_table[q] = 0;

		else if (prob == 0)
			prob_table[q] = 0;

	});
}

/*
	expand_zero

	Locks every point around one point.
*/
void DoryeongPark::expand_zero(Point p) noexcept {

	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			auto current_p = Point{ p.getX() + i, p.getY() + j };

			if (current_p.checkBoardRange() && visited[current_p] == false) {
				visited[current_p] = true;
				prob_table[current_p] = 0;
			}
		}
	}
}

/*
	get_highest

	Gets the highest probability point of the table.
*/
Point DoryeongPark::get_highest() noexcept {

	Point highest;
	double highest_value = 0;
	vector<Point> highest_points;
	vector<Point> random_points;

	for (auto p : prob_table) {
		if (p.second > highest_value && visited[p.first] == false)
			highest_value = p.second;

	}

	if (highest_value <= 0) {

		for (auto p : visited)
			if (p.second == false)
				random_points.emplace_back(p.first);

		random_shuffle(random_points.begin(), random_points.end());

		return random_points.back();
	}
	else {
		for (auto p : prob_table)
			if (p.second == highest_value && visited[p.first] == false)
				highest_points.emplace_back(p.first);
	}

	random_shuffle(highest_points.begin(), highest_points.end());

	if (highest_points.empty()) {

		for (auto p : visited)
			if (p.second == false)
				return p.first;

	}
	else {

		highest = highest_points.back();
	}

	highest_points.clear();

	//cout << "Max Probability Point : " << highest << " Probability : " << prob_table[highest] << endl;

	prob_table[highest] = 0;

	return highest;
}

/*
	mine_reduce_effect

	If mine's uncovered, updates information of 8 points around mine.
*/

void DoryeongPark::mine_reduce_effect(Point p) noexcept {

	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {

			auto current_p = Point{ p.getX() + i, p.getY() + j };

			if (current_p.checkBoardRange() && monitor[current_p] > 0)
				--monitor[current_p];

			if (current_p.checkBoardRange() &&
				visited[current_p] == false &&
				monitor[current_p] == UNKNOWN)
				reduce_reservation.emplace_back(current_p);

		}
	}
}


