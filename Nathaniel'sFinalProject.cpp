#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void weapon (int &MP, int &SP, int &MF, std::string &C);
int randNum (int min, int max);
void PlayerTurn(int &PlayerHP, int PlayerHPMAX, int PlayerDEF, int PlayerATK, int PlayerSPD, int &EnemyHP, int EnemyHPMAX, int EnemyDEF, int EnemyATK, int EnemySPD, int damage, int &d, int &n, string name, int &A, int &x, int &p, int &f, int MF, string C);
void EnemyTurn(int &PlayerHP, int PlayerHPMAX, int PlayerDEF, int PlayerATK, int PlayerSPD, int &EnemyHP, int EnemyHPMAX, int EnemyDEF, int EnemyATK, int EnemySPD, int damage, int &d, string name, int &A, int &n, int &p, int &f);
void encounter(int MF, int MP, std::string &C, ifstream &inEncounter);

int main() {
	ifstream inEncounter;
	ifstream inText;
	ofstream Stats;
	string text = " ";
	string descion = " ";
	string ignore = " ";
	string name = " ";
	string choice = " ";
	string C = " ";
	int MP = 1;
	int SP = 0;
	int MF = 0;
	int x = 0;
	int y = 0;
	int z = 0;

	inText.open("Intro.txt");

	getline(inText, text, '&');
	cout << text;
	cin >> ignore;
	cout << "-------------------------------------------------------" << endl;
	getline(inText, text, '&');
	cout << text << endl;
	cout << "-------------------------------------------------------" << endl;
	cin.ignore();
	getline(cin, name);
	cout << "-------------------------------------------------------";
	getline(inText, text, '&');
	cout << text << name;
	getline(inText, text, '&');
	cout << text << endl;
	cout << "-------------------------------------------------------" << endl;
	cin >> choice;
	cout << "-------------------------------------------------------" << endl;
	while (choice != "1" && choice != "2"){
		cout << "Ummmmm... there is no option " << choice << ". Please enter either a 1 or 2 which are valid options." << endl;
		cin >> choice;
		cout << "-------------------------------------------------------" << endl;
	}
	getline(inText, descion, '#');
	if (choice == "1"){
		getline(inText, text);
		cout << text << endl;
		getline(inText, ignore);
	}
	else{
		getline(inText, ignore);
		getline(inText, descion, '#');
	}
	if (choice == descion){
		getline(inText, text);
		cout << text << endl;
	}
	getline(inText, text);
	cout << text << endl;
	while (x != 1) {
		cout << "-------------------------------------------------------" << endl;
		inText.close();
		inText.open("Inn1.txt");
		getline(inText, text, '&');
		cout << text;
		getline(inText, text, '&');
		cout << text << endl;
		cout << "-------------------------------------------------------" << endl;
		cin >> choice;
		cout << "-------------------------------------------------------" << endl;
		while (choice != "1" && choice != "2" && choice != "3"){
			cout << "Ummmmm... there is no option " << choice << ". Please enter a valid option." << endl;
			cin >> choice;
			cout << "-------------------------------------------------------" << endl;
		}
		getline(inText, descion, '#');
		if (choice == "1") {
			getline(inText, text);
			cout << text << endl;
			weapon(MP, SP, MF, C);
			getline(inText, ignore);
			getline(inText, ignore);
			x += 1;
		}
		else{
			getline(inText, ignore);
			getline(inText, descion, '#');
		}
		if (choice == descion){
			if (y == 1) {
				cout << "You decide that there is no point in searching the bookshelf again." << endl;
				choice = " ";
			}
			else {
				getline(inText, text);
				cout << text << endl;
				getline(inText, ignore);
				MP += 1;
				SP += 1;
				y = 1;
				choice = " ";
			}
		}
		else{
			getline(inText, ignore);
			getline(inText, descion, '#');
		}
		if (choice == descion){
			if (z == 1) {
				cout << "You decide searching the desk wood have no point." << endl;
				choice = " ";
			}
			else{
				getline(inText, text);
				cout << text << endl;
				z = 1;
			}
		}
	}
	x = 0;
	while (x != 1) {
		cout << "-------------------------------------------------------" << endl;
		inText.close();
		inText.open("Inn2.txt");
		getline(inText, text, '&');
		cout << text << endl;
		cout << "-------------------------------------------------------" << endl;
		cin >> choice;
		cout << "-------------------------------------------------------" << endl;
		getline(inText, descion, '#');
		while (choice != "1" && choice != "2" && choice != "3"){
			cout << "Ummmmm... there is no option " << choice << ". Please enter an actual choice." << endl;
			cin >> choice;
			cout << "-------------------------------------------------------" << endl;
		}
		if (choice == "1"){
			if (y == 1) {
				cout << "You decide that there is no point in searching the bookshelf again." << endl;
				choice = " ";
			}
			else {
				getline(inText, text);
				cout << text << endl;
				getline(inText, ignore);
				getline(inText, ignore);
				MP += 1;
				SP += 1;
				y = 1;
				choice = " ";
			}
		}
		else{
			getline(inText, ignore);
			getline(inText, descion, '#');
		}
		if (choice == descion){
			if (z == 1) {
				cout << "You decide searching the desk wood have no point." << endl;
				choice = " ";
			}
			else{
				getline(inText, text);
				cout << text << endl;
				getline(inText, ignore);
				z = 1;
				choice = " ";
			}
		}
		else{
			getline(inText, ignore);
			getline(inText, descion, '#');
		}
		if (choice == descion){
			getline(inText, text);
			cout << text << endl;
			x = 1;
			choice = " ";
		}
	}
	inText.close();
	inText.open("InnCommon1.txt");
	getline(inText, text, '&');
	cout << text << name;
	getline(inText, text, '&');
	cout << text << endl;
	cout << "--------------------------------------------------" << endl;
	cin >> choice;
	cout << "--------------------------------------------------" << endl;
	while (choice != "1" && choice != "2"){
		cout << "Ummmmm... there is no option " << choice << ". Please enter either a 1 or 2 which are valid options." << endl;
		cin >> choice;
		cout << "-------------------------------------------------------" << endl;
	}
	if (choice == "1"){
		getline(inText, text, '&');
		cout << text << endl;
		cout << "--------------------------------------------------" << endl;
	}
	if (choice == "2"){
		getline(inText, text, '&');
		cout << text << endl;
		cout << "--------------------------------------------------" << endl;
	}
	encounter(MF, MP, C, inEncounter);
	getline(inText, text, '&');
	cout << text << endl;
	cout << "--------------------------------------------------" << endl;
}
void weapon (int &MP, int &SP, int &MF, std::string &C){
	ifstream inText;
	string text = " ";
	string ignore = " ";
	string descion = " ";
	string choice = " ";
	int x = 0;
	inText.open("Weapons1.txt");
	getline(inText, text, '&');
	cout << text;
	cout << "-------------------------------------------------------" << endl;
	cin >> choice;
	cout << "-------------------------------------------------------" << endl;
	while (choice != "1" && choice != "2" && choice != "3" && choice != "14"){
		cout << "Ummmmm... there is no option " << choice << ". Please enter a valid option." << endl;
		cin >> choice;
		cout << "-------------------------------------------------------" << endl;
	}
	getline(inText, descion, '#');
	if (choice == "1"){
		getline(inText, text);
		cout << text << endl;
		C = "Knight";
		getline(inText, ignore);
		getline(inText, ignore);
		getline(inText, ignore);
		choice = " ";
	}
	else{
		getline(inText, ignore);
		getline(inText, descion, '#');
	}
	if (choice == descion){
		getline(inText, text);
		cout << text << endl;
		C = "Assassin";
		getline(inText, ignore);
		getline(inText, ignore);
		choice = " ";
	}
	else{
		getline(inText, ignore);
		getline(inText, descion, '#');
	}
	if (choice == descion){
		getline(inText, text);
		cout << text << endl;
		C = "Archer";
		getline(inText, ignore);
		choice = " ";
	}
	else{
		getline(inText, ignore);
		getline(inText, descion, '#');
	}
	if (choice == descion){
		getline(inText, text);
		cout << text << endl;
		MF = 1;
		while (x == 0){
			inText.close();
			inText.open("Weapons2.txt");
			getline(inText, text, '&');
			cout << text << endl;
			cout << "-------------------------------------------------------" << endl;
			cin >> choice;
			cout << "-------------------------------------------------------" << endl;
			getline(inText, descion, '#');
			while (choice != "1" && choice != "2" && choice != "3" && choice != "14"){
				cout << "Ummmmm... there is no option " << choice << ". Please enter a valid option." << endl;
				cin >> choice;
				cout << "-------------------------------------------------------" << endl;
			}
			if (choice == "1"){
				getline(inText, text);
				cout << text << endl;
				C = "Knight";
				getline(inText, ignore);
				getline(inText, ignore);
				getline(inText, ignore);
				x += 1;
				choice = " ";
			}
			else{
				getline(inText, ignore);
				getline(inText, descion, '#');
			}
			if (choice == descion){
				getline(inText, text);
				cout << text << endl;
				C = "Assassin";
				getline(inText, ignore);
				getline(inText, ignore);
				x += 1;
				choice = " ";
			}
			else{
				getline(inText, ignore);
				getline(inText, descion, '#');
			}
			if (choice == descion){
				getline(inText, text);
				cout << text << endl;
			 	C = "Archer";
				getline(inText, ignore);
				x += 1;
				choice = " ";
			}
			else{
				getline(inText, ignore);
				getline(inText, descion, '#');
			}
			if (choice == descion){
				getline(inText, text);
				cout << text << endl;
			}
		}
	}
	inText.close();
}
void encounter(int MF, int MP, std::string &C, ifstream &inEncounter) {
	srand(static_cast<int> (time(0)));
	string text = " ";
	int p = 0;
	int f = 0;
	int n = 0;
	int A = 0;
	int x = 0;
	int z = 0;
	int g = 0;
	int damage = 0;
	int PlayerHP = 100;
	int PlayerHPMAX = PlayerHP;
	int PlayerATK = 5;
	int PlayerDEF = 5;
	int d = PlayerDEF;
	int PlayerSPD = 5;
	int EnemyHP = 0;
	int EnemyATK = 0;
	int EnemyDEF = 0;
	int EnemySPD = 0;
	string name = " ";
	inEncounter.open("Encounter1.txt");
	getline(inEncounter, name);
	inEncounter >> EnemyHP;
	int EnemyHPMAX = EnemyHP;
	inEncounter >> EnemyATK;
	inEncounter >> EnemyDEF;
	inEncounter >> EnemySPD;
	if (C == "Knight") {
		PlayerDEF *= 1.6;
	}
	if (C == "Assassin") {
		PlayerSPD *= 1.6;
	}
	if (C == "Archer") {
		PlayerATK *= 1.6;
	}
	getline(inEncounter, text);
	getline(inEncounter, text);
	cout << text << endl;
	cout << "--------------------------------------------------" << endl;
	getline(inEncounter, text);
	while (EnemyHP > 0 && PlayerHP > 0) {
		cout << "Your Current HP: " << PlayerHP << "/" << PlayerHPMAX << ". Your Class: " << C << ". Your Attack Power: " << PlayerATK << ". Your Defense Value: " << PlayerDEF << ". Your Speed Value: " << PlayerSPD << "."<< endl; 
		cout << "--------------------------------------------------" << endl;
		cout << name << " wants to fight. What do you do?"<< endl;
		cout << "1. Check" << endl;
		cout << "2. Attack" << endl;
		cout << "3. Defend" << endl; 
		cout << "4. Magic" <<endl;
		cout << "--------------------------------------------------" << endl;
		cin >> x;
		cout << "--------------------------------------------------" << endl;
		while (1 > x || x > 4) {
			switch (g) {
				case 0: 
					cout << "You have to do something. Now Chose." << endl;
					cin >> x;
					g+=1;
					cout << "--------------------------------------------------" << endl;
					break;
				case 1: 
					cout << "You HAVE to DO something. CHOSE NOW." << endl;
					cin >> x;
					g+=1;
					cout << "--------------------------------------------------" << endl;
					break;
				case 2:
					cout << "CHOSE NOW!" << endl;
					cin >> x;
					cout << "--------------------------------------------------" << endl;
					g+=1;
					break;
				case 3: 
					cout << "What are you doing?" << endl;
					cin >> x;
					cout << "--------------------------------------------------" << endl;
					g+=1;
					break;
				case 4:
					cout << "Welp, this is going nowhere." << endl;
					cout << "--------------------------------------------------" << endl;
					cin >> x;  
					break;
			}
		}
		if (PlayerSPD >= EnemySPD) {
			PlayerTurn(PlayerHP, PlayerHPMAX, PlayerDEF, PlayerATK, PlayerSPD, EnemyHP, EnemyHPMAX, EnemyDEF, EnemyATK, EnemySPD, damage, d, n, name, A, x, p, f, MF, C);			
			if (EnemyHP > 0) {
			EnemyTurn(PlayerHP, PlayerHPMAX, PlayerDEF, PlayerATK, PlayerSPD, EnemyHP, EnemyHPMAX, EnemyDEF, EnemyATK, EnemySPD, damage, d, name, A, n, p, f);
			}
		}	
		else if (EnemySPD > PlayerSPD) {
			EnemyTurn (PlayerHP, PlayerHPMAX, PlayerDEF, PlayerATK, PlayerSPD, EnemyHP, EnemyHPMAX, EnemyDEF, EnemyATK, EnemySPD, damage, d, name, A, n, p, f);
			if (PlayerHP > 0){
			PlayerTurn (PlayerHP, PlayerHPMAX, PlayerDEF, PlayerATK, PlayerSPD, EnemyHP, EnemyHPMAX, EnemyDEF, EnemyATK, EnemySPD, damage, d, n, name, A, x, p, f, MF, C);
			}
		}
		cout << text << endl;
		cout << "--------------------------------------------------" << endl;
		if (PlayerHP > 0 && EnemyHP > 0) {
			if (C == "Knight") {
				cout << "You twirl your sword in a fancy manner." << endl;
			}
			if (C == "Assassin") {
				cout << "You casually throw one of your knives into the air and catch it." << endl;
			}
			if (C == "Archer") {
				cout << "You withdraw another arrow from your quiver and aim carefully." << endl;
			}
			cout << "--------------------------------------------------" << endl;
			cout << "The battle continues." << endl;
			cout << "--------------------------------------------------" << endl;
		}
	}
	inEncounter.close();
}
int randNum (int min, int max){
	return min + rand()%(max - min + 1);
}
void PlayerTurn(int &PlayerHP, int PlayerHPMAX, int PlayerDEF, int PlayerATK, int PlayerSPD, int &EnemyHP, int EnemyHPMAX, int EnemyDEF, int EnemyATK, int EnemySPD, int damage, int &d, int &n, string name, int &A, int &x, int &p, int &f, int MF, string C){
	int z = 0;
	int spellOneEffect [4][4]= {{1,2,3,4},{2,3,4,1},{3,4,1,2},{4,1,2,3}};
	switch (x) {
		case 1:
			cout <<"You checked the enemy. Name: "  << name << " HP: "<< EnemyHP << "/" << EnemyHPMAX << " ATK: " << EnemyATK << " DEF: " << EnemyDEF << " SPD: " << EnemySPD << endl;
			cout << "You feel so informed." << endl;
			cout << "--------------------------------------------------" << endl;
			break;
		case 2:	
			if (C == "Knight") {
				cout << "You rush foward and slash with your sword." << endl;
			}
			if (C == "Assassin") {
				cout << "You dash forward and strike carefully with your knives." << endl;
			}
			if (C == "Archer") {
				cout << "You quickly realease the arrow you were aiming directly into your enemy." << endl;
			}
			z = EnemyHP;
			EnemyHP -= (PlayerATK + randNum(1, 25)) / EnemyDEF;
			damage = z - EnemyHP;
			if (damage == 0) {
				damage += 1;
				EnemyHP -= damage;
			}
			cout << "You did " << damage << " damage. Good Job." << endl;
			cout << "--------------------------------------------------" << endl;
			break;
		case 3:
			cout << "You Prepare for " << name << "'s Attack. You're defense doubled. Awesome!" << endl;
			cout << "--------------------------------------------------" << endl;
			d = PlayerDEF * 2;
			break;
		case 4:
			cout << "You prepare a magic spell. Spells available:" << endl;
			cout << "1. Effect Spell" << endl;
			if (MF != 0){
				cout << "2. Energy Ball" << endl;
			}
			cout << "--------------------------------------------------" << endl;
			cout << "Which would you like to use?" << endl;
			cout << "--------------------------------------------------" << endl;
			int S = 0;
			int h = 0;
			cin >> S;
			cout << "--------------------------------------------------" << endl;
			switch (S) {
				case 1:
					cout << "You cast an Effect Spell." << endl;
					h = spellOneEffect[randNum(0, 3)][randNum(0, 3)];
					switch (h) {
						case 1:
							cout << "You cast Effect Fire." << endl;
							cout << name << " was burned." << endl;
							cout << "--------------------------------------------------" << endl;
							A = 3;
							break;
						case 2:
							cout << "You cast Effect Toxin." << endl;
							cout << name << " was poisoned." << endl;
							cout << "--------------------------------------------------" << endl;
							n = 3;
							break;
						case 3:
							cout << "You cast Effect Thunder." << endl;
							cout << name << " was paralyzed." << endl;
							cout << "--------------------------------------------------" << endl;
							p = 2;
							break;
						case 4:
							cout << "You cast Effect Ice." << endl;
							cout << name << " was frozen." << endl;
							cout << "--------------------------------------------------" << endl;
							f = 5;
							break;
					}
					break;
				case 2:
					if (MF != 0){
					cout << "You cast an Energy Sphere." << endl;
					int j = randNum(10, 20);
					EnemyHP -= j;
					cout << "You did " << j << " damage." << endl; 
					cout << "--------------------------------------------------" << endl;
					}
					else {
						cout << "You cannot cast this spell." << endl;
						cout << "--------------------------------------------------" << endl;
					}
					break;
			}
	}
}
void EnemyTurn(int &PlayerHP, int PlayerHPMAX, int PlayerDEF, int PlayerATK, int PlayerSPD, int &EnemyHP, int EnemyHPMAX, int EnemyDEF, int EnemyATK, int EnemySPD, int damage, int &d, string name, int &A, int &n, int &p, int &f){
	if (EnemyHP > 0) {
		if (p == 0 && f == 0) {
			int z = 0;
			cout << name << " attacks. Ouch." << endl;
			z = PlayerHP;
			PlayerHP -= ((EnemyATK + randNum(1, 25)) / d);
			damage = z - PlayerHP;
			if (damage == 0) {
				damage += 1;
				PlayerHP -= damage;
			}
			cout << "You took " << damage << " damage." << endl;
			cout << "--------------------------------------------------" << endl;
			d = PlayerDEF;
		}
		else if (p > 0) {
			p -= 1;
			cout << name << " is Paralyzed. They cannot move. " << p << " turns left." << endl;
			cout << "--------------------------------------------------" << endl;
		}
		else {
			f -= 1;
			cout << name << " is Frozen. They cannot move. " << f << " turns left." << endl;
			cout << "--------------------------------------------------" << endl;
		}
		if (A > 0) {
			A -= 1;
			cout << name << " is Burned. They took 5 damage. " << A << " turns left." << endl;
			EnemyHP -= 5;
			cout << "--------------------------------------------------" << endl;
		}
		if (n > 0) {
			n -= 1;
			cout << name << " is Poisoned. They took 10 damage. " << n << " turns left." << endl;
			EnemyHP -= 10;
			cout << "--------------------------------------------------" << endl;
		}
	}
}