// Name: FGX
// Date: 2018/3/19
// Last Update: 2018/3/20
// Problem statement: This program solves the scheduling problem, or more specifically, the round-robin scheduling.
#include <iostream>
#include <deque> // double-ended queue
#include <algorithm>
#include <string>
#include "FakeRand.h"
using namespace std;

struct Player {
	string name; // player name
	int level; // player level
	int start; // start time to wait
	int leftTime; // (left battles - 1) * 5 < left time before leave <= left battles * 5
	int timer = 25; // RR limit: when it counts from 25 to 0, the player loses
};

// Intent: To simulate if target player defeats his opponent.
// Pre: Pass target's level and opponent's level.
// Post: Return true if target wins, false if his opponent wins.
bool Win(const int &targetLv, const int &opponentLv) {
	double rate = pow(2, targetLv - opponentLv);
	return rand() / (RAND_MAX + 1.0) < rate / (rate + 1);
}

int main() {
	Player *all; // all players for input
	int n; // number of all players
	while (cin >> n) {
		deque<Player *> queue; // players in current list
		Player *pa = nullptr, *pb = nullptr; // the 2 players in battle

		all = new Player[n];
		for (int i = 0; i < n; i++)
			cin >> all[i].name >> all[i].level >> all[i].start >> all[i].leftTime;
		sort(all, all + n, [](const Player &a, const Player &b) {return a.start <= b.start;}); // sort players by start time

		int nextJoinIdx = 0; // next player to join the queue
		int time = 0; // current time
		int battleEndCountDown = -1; // time until current battle ends, -1 means no current battle
		while (true) { // event loop
			// skip time to where an event happens (a player joins queue or a battle ends)
			int nextTime = min(nextJoinIdx < n ? all[nextJoinIdx].start : INT_MAX, battleEndCountDown == -1 ? INT_MAX : time + battleEndCountDown);
			if (nextTime == INT_MAX) // no more event
				break;
			if (battleEndCountDown != -1) // if there's a battle
				battleEndCountDown -= nextTime - time; // battleEndCountDown -= delta time
			time = nextTime;
			// event: player join
			while (nextJoinIdx < n && all[nextJoinIdx].start == time) {
				if (!pa) // seat A is empty
					pa = all + nextJoinIdx++;
				else if (!pb) // seat B is empty
					pb = all + nextJoinIdx++;
				else // neither is empty
					queue.push_back(all + nextJoinIdx++);
			}
			if (battleEndCountDown == 0) { // battle ends, player leaves
				battleEndCountDown = -1; // no currrent battle
				pa->leftTime -= 5;
				pb->leftTime -= 5;
				pa->timer -= 5;
				pb->timer -= 5;
				Player *winner = pa->timer > 0 && Win(pa->level - 1, pb->level) ? pa : pb; // simulate
				Player *loser = winner == pa ? pb : pa;

				if (loser->leftTime > 0) // if loser still want to play
					queue.push_back(loser); // push loser to the end

				pb = nullptr;
				if (!queue.empty()) { // pop the next player to seat B
					pb = queue.front();
					queue.pop_front();
					pb->timer = 25; // reset Pb's timer
				}

				pa = winner; // timer remains
				if (pa->leftTime <= 0) { // if winner leaves
					pa = nullptr;
					if (!queue.empty()) { // pop the next player to seat A
						pa = queue.front();
						queue.pop_front();
						pa->timer = 25; // reset Pa's timer
					}
				}
			}
			if (battleEndCountDown == -1 && pa && pb) // no currrent battle, 2 players in seat
				battleEndCountDown = 5; // new battle starts

			cout << time << ": " << (pa ? pa->name + " lv" + to_string(pa->level) : "none") << " vs. " << (pb ? pb->name + " lv" + to_string(pb->level) : "none") << " |";
			for (int i = 0; i < queue.size(); i++)
				cout << " " << queue[i]->name;
			cout << endl;
		}
		delete[] all;
	}
}