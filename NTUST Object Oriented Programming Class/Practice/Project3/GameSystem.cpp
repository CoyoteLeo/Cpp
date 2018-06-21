#include "GameSystem.h"
#include <sstream>
#include <iomanip> 
#include <utility>

GameSystem::GameSystem() {
	running = false;
	timer = 0;
	teamA.name = "TeamA";
	teamB.name = "TeamB";
}

void GameSystem::pause() {
	running = false;
}

void GameSystem::start() {
	running = true;
	executeCommand(teamA);
	executeCommand(teamB);
}


bool comp(const Shell&a, const Shell&b) {
	return a.explosionTime < b.explosionTime;
}

void GameSystem::updateFrame() {

	if (!running) {
		printf("Unable update while pause\n");
		return;
	}

	std::stringstream ss;
	std::vector<Shell>explosion;//紀錄爆炸點
	std::map<std::string, Shell*>::iterator shellIter;
	for (shellIter = shells.begin(); shellIter != shells.end(); ) {//對砲彈作遍歷
		double dist = shellIter->second->target - shellIter->second->position;//目前位置到爆炸點的位置
		if (dist <= shellIter->second->speed * 15) {//determin explosion 
			shellIter->second->explosionTime = dist / shellIter->second->speed;
			shellIter->second->position = shellIter->second->target;
			explosion.push_back(*(shellIter->second));
			delete shellIter->second;
			shellIter = shells.erase(shellIter);
		}
		else {
			shellIter->second->move();
			shellIter++;
		}
	}
	std::sort(explosion.begin(), explosion.end(), comp);//依照爆炸時間做排序


	std::map<std::string, Vessel*>::iterator vesselsIter;//update position of vessels
	for (int i = 0; i < explosion.size(); ++i) {//對爆炸點作遍歷
		for (vesselsIter = teamA.vessels.begin(); vesselsIter != teamA.vessels.end(); ) {//對船艦作遍歷
			Position pos = vesselsIter->second->computePosition(explosion[i].explosionTime);
			long long dist = explosion[i].position - pos;
			if (explosion[i].position - vesselsIter->second->computePosition(explosion[i].explosionTime)<explosion[i].range) {
				explosion[i].hitRecord.push_back("TeamA" + vesselsIter->second->name);
				if (vesselsIter->second->beFired(&explosion[i])) {
					long long tempTimer = timer - 15;
					tempTimer += explosion[i].explosionTime;
					int m = tempTimer / 60, s = tempTimer % 60;
					ss.str("");
					ss.clear();
					ss << '[' << std::setw(2) << std::setfill('0') << m << ':' << std::setw(2) << std::setfill('0') << s << "] TeamA " << vesselsIter->second->name << " destroyed";
					logs.push_back(ss.str());
					delete vesselsIter->second;
					vesselsIter = teamA.vessels.erase(vesselsIter);
				}
				else
					vesselsIter++;
			}
			else
				vesselsIter++;
		}
		for (vesselsIter = teamB.vessels.begin(); vesselsIter != teamB.vessels.end(); ) {//對船艦作遍歷
			Position pos = vesselsIter->second->computePosition(explosion[i].explosionTime);
			long long dist = explosion[i].position - pos;
			if (explosion[i].position - vesselsIter->second->computePosition(explosion[i].explosionTime)<explosion[i].range) {
				explosion[i].hitRecord.push_back("TeamB" + vesselsIter->second->name);
				if (vesselsIter->second->beFired(&explosion[i])) {
					long long tempTimer = timer - 15;
					tempTimer += explosion[i].explosionTime;
					int m = tempTimer / 60, s = tempTimer % 60;
					ss.str("");
					ss.clear();
					ss << '[' << std::setw(2) << std::setfill('0') << m << ':' << std::setw(2) << std::setfill('0') << s << "] TeamB " << vesselsIter->second->name << " destroyed";
					logs.push_back(ss.str());
					delete vesselsIter->second;
					vesselsIter = teamB.vessels.erase(vesselsIter);
				}
				else
					vesselsIter++;
			}
			else
				vesselsIter++;
		}
		if (explosion[i].hitRecord.size() == 0) {
			long long tempTimer = timer - 15;
			tempTimer += explosion[i].explosionTime;
			int m = tempTimer / 60, s = tempTimer % 60;
			ss.str("");
			ss.clear();
			ss << '[' << std::setw(2) << std::setfill('0') << m << ':' << std::setw(2) << std::setfill('0') << s << ']' <<" "<< explosion[i].name << " arrived (" << explosion[i].target.x << "," << explosion[i].target.y << ") -> miss";
			logs.push_back(ss.str());
		}
		else {
			long long tempTimer = timer - 15;
			tempTimer += explosion[i].explosionTime;
			int m = tempTimer / 60, s = tempTimer % 60;
			ss.str("");
			ss.clear();
			ss << '[' << std::setw(2) << std::setfill('0') << m << ':' << std::setw(2) << std::setfill('0') << s << ']' <<" "<< explosion[i].name << " arrived (" << explosion[i].target.x << "," << explosion[i].target.y << ") -> hit {";
			for (int j = 0; j < explosion[i].hitRecord.size(); j++){
				ss << explosion[i].hitRecord[j];
				if (j != explosion[i].hitRecord.size() - 1)
					ss << ',';
			}
			ss << "}";
			logs.push_back(ss.str());
		}
	}

	for (vesselsIter = teamA.vessels.begin(); vesselsIter != teamA.vessels.end(); vesselsIter++) {//對船艦作遍歷
		vesselsIter->second->move();
	}
	for (vesselsIter = teamB.vessels.begin(); vesselsIter != teamB.vessels.end(); vesselsIter++ ) {//對船艦作遍歷
		vesselsIter->second->move();
	}
}

void GameSystem::cleanBrokenVessel(long long timestamp, Position position) {

}

void GameSystem::executeCommand(Team& team) {
	std::string command;
	std::stringstream ss;
	int m = timer / 60, s = timer % 60;  std::string M, S, posX, posY, posZ;
	ss.clear();
	ss << std::setw(2) << std::setfill('0') << m;
	ss >> M;
	ss.clear();
	ss << std::setw(2) << std::setfill('0') << s;
	ss >> S;
	for (int i = 0; i < team.commands.size(); i++) {
		ss.clear();
		ss << team.commands[i];
		ss >> command;

		if (command == "SET") {
			std::string name, type, position;
			ss >> name;
			ss >> type;
			ss >> position;
			double x, y;
			std::string tempPos;
			tempPos = tempPos.assign(position, 1, position.find(","));
			std::stringstream tempPos1(tempPos);
			tempPos1 >> x;
			tempPos = tempPos.assign(position, position.find(",") + 1, position.find(")"));
			std::stringstream tempPos2(tempPos);
			tempPos2 >> y;
			ss.clear(); ss << x; ss >> posX; ss.clear(); ss << y; ss >> posY;

			if (team.vessels.count(name) || x>20 || y>20) {	// vessel already exists or position out of range{	//fail
				logs.push_back("[" + M + ":" + S + "] " + team.name + " Set " + name + " with " + type + " at (" + posX + "," + posY + ") -> Fail");
			}
			else { // vessel can be created {
				if (type == "BB") {
					team.vessels[name] = new BB(name, x, y);
					logs.push_back("[" + M + ":" + S + "] " + team.name + " Set " + name + " with BB at (" + posX + "," + posY + ") -> Success");
				}
				else if (type == "CG") {
					team.vessels[name] = new CG(name, x, y);
					logs.push_back("[" + M + ":" + S + "] " + team.name + " Set " + name + " with CG at (" + posX + "," + posY + ") -> Success");
				}
				else if (type == "CV") {
					team.vessels[name] = new CV(name, x, y);
					logs.push_back("[" + M + ":" + S + "] " + team.name + " Set " + name + " with CV at (" + posX + "," + posY + ") -> Success");
				}
				else if (type == "DD") {
					team.vessels[name] = new DD(name, x, y);
					logs.push_back("[" + M + ":" + S + "] " + team.name + " Set " + name + " with DD at (" + posX + "," + posY + ") -> Success");
				}
				else if (type == "F") {
					team.vessels[name] = new Fisher(name, x, y);
					logs.push_back("[" + M + ":" + S + "] " + team.name + " Set " + name + " with DD at (" + posX + "," + posY + ") -> Success");
				}
				else {
					logs.push_back("[" + M + ":" + S + "] " + team.name + " Set " + name + " with " + type + " at (" + posX + "," + posY + ") -> Fail");
					//std::cout << "Command Error!" << std::endl;
				}
			}

		}
		else if (command == "FIRE") {
			std::string vessel, position, shellName;
			ss >> vessel >> position;
			double x, y;
			std::string tempPos;
			tempPos = tempPos.assign(position, 1, position.find(","));
			std::stringstream tempPos1(tempPos);
			tempPos1 >> x;
			tempPos = tempPos.assign(position, position.find(",") + 1, position.find(")"));
			std::stringstream tempPos2(tempPos);
			tempPos2 >> y;
			ss.clear();
			ss << x; ss >> posX;
			ss.clear();
			ss << y; ss >> posY;

			if (team.vessels.count(vessel) && x <= 20 && y <= 20 && timer - team.vessels[vessel]->lastAttack >= team.vessels[vessel]->attackCD && team.vessels[vessel]->position-Position(x,y)<team.vessels[vessel]->attackRange) {	// vessel found{
				team.numOfShells++;

				if (team.name == "TeamA")
					shellName = "Shell_A" + std::to_string(team.numOfShells);
				else
					shellName = "Shell_B" + std::to_string(team.numOfShells);



				shells[shellName] = team.vessels[vessel]->fire(x, y, shellName);
				team.vessels[vessel]->setLastAttack(timer);
				logs.push_back("[" + M + ":" + S + "] " + team.name + " " + vessel + " FIRE to " + "(" + posX + "," + posY + ") -> " + shellName);
			}
			else {
				logs.push_back("[" + M + ":" + S + "] " + team.name + " " + vessel + " FIRE to " + "(" + posX + "," + posY + ") -> Fail");
			}
		}
		else if (command == "DEFENSE") {
			std::string vessel, shell;
			ss >> vessel >> shell;
			if (team.vessels.count(vessel) && shells.count(shell) && timer - team.vessels[vessel]->lastDefense >= team.vessels[vessel]->defenseCD) {
				if (team.vessels[vessel]->defense(shells[shell])){
				logs.push_back("[" + M + ":" + S + "] " + vessel + " Defense " + shell + " -> Hit");
				delete shells[shell];
				shells.erase(shell);
				}
					team.vessels[vessel]->lastDefense = timer;
			}
			else {
				logs.push_back("[" + M + ":" + S + "] " + vessel + " Defense " + shell + " -> Fail");
			}
		}
		// [mm:ss] [team] RENAME [Vessel_Name] to [New_Name] -> Success
		else if (command == "TAG") {
			std::string name1, name2;
			ss >> name1 >> name2;
			if (name1 == name2 && team.vessels.count(name1))
			{
				logs.push_back("[" + M + ":" + S + "] " + team.name + " RENAME " + name1 + " to " + name2 + " -> Success");
			}
			else if (team.vessels.count(name1) && !team.vessels.count(name2)) {
				team.vessels[name1]->setName(name2);
				team.vessels[name2] = team.vessels[name1];
				team.vessels.erase(name1);
				logs.push_back("[" + M + ":" + S + "] " + team.name + " RENAME " + name1 + " to " + name2 + " -> Success");
			}
			else {
				logs.push_back("[" + M + ":" + S + "] " + team.name + " RENAME " + name1 + " to " + name2 + " -> Fail");
			}
		}
		//[mm:ss] [team] [Vessel_NameA] MOVE to [Angle] as [Speed] -> Success
		else if (command == "MOVE") {
			std::string name;
			double speed, angle;
			bool TorF;
			ss >> name >> speed >> angle;

			if (team.vessels.count(name)) {
				TorF = team.vessels[name]->setMovement(speed / 60, angle);
				if(team.vessels[name]->setMovement(speed / 60, angle))
					logs.push_back("[" + M + ":" + S + "] " + team.name + " " + name + " Move to " + std::to_string(angle) + " as " + std::to_string(speed) + " -> Success");
				else
					logs.push_back("[" + M + ":" + S + "] " + team.name + " " + name + " Move to " + std::to_string(angle) + " as " + std::to_string(speed) + " -> Fail");
			}
			else {
				logs.push_back("[" + M + ":" + S + "] " + team.name + " " + name + " Move to " + std::to_string(angle) + " as " + std::to_string(speed) + " -> Fail");
			}

		}
	}
	team.commands.clear();
}
