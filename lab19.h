#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Unit{
		string name;
		string type;		
		int hp;
		int hpmax;
		int atk;
		int def;
		bool guard_on;		
	public:			
		void create(string);
		void showStatus();
		void newTurn();
		int attack(Unit &);
		int beAttacked(int);
		int heal();	
		void guard();
		bool isDead();	
};

void Unit::create(string t){ 
	if(t == "Hero"){
		type = "Hero";
		cout << "Please input your name: ";
		getline(cin,name);
		hpmax = rand()%20+90;
		atk = rand()%5+14;
		def = rand()%3+9;
	}else if(t == "Monster"){
		type = "Monster";
		name = "Kraken";
		hpmax = rand()%20+200;
		atk = rand()%5+25;
		def = rand()%3+5;
	}
	hp = hpmax;
	guard_on = false;
}

void Unit::showStatus(){
	if(type == "Hero"){
		cout << "---------------------------------------\n"; 
		cout << name << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def;		
		cout << "\n---------------------------------------\n";
	}	
	else if(type == "Monster"){
		cout << "\t\t\t\t---------------------------------------\n"; 
		cout << "\t\t\t\t" << name << "\n"; 
		cout << "\t\t\t\tHP: " << hp << "\t\tATK: "<< atk << "\t\tDEF: "<< def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
}

void Unit::newTurn(){
	guard_on = false;
}



/////////////////////////////////////////////////////////////////////////////////////
//Write function members isDead(), guard(), heal(), beAttacked(), and attack() here//
/////////////////////////////////////////////////////////////////////////////////////
bool Unit::isDead(){
    if(hp <= 0 ) return true;
    else return false;
}
void Unit::guard(){
    guard_on = true ;
}
int Unit::beAttacked(int oppatk){
    int dmg = oppatk-def;
    if(guard_on == true) {
    hp -= dmg/3;
    return dmg/3;
    }
    else{
    hp -= dmg;
    return dmg;
    }
}
int Unit::attack(Unit &target){
	return target.beAttacked(atk);
}
int Unit::heal(){
    int aid = rand()%21+10;
    hp += aid;
    if(hp>hpmax){
    aid = hpmax+aid-hp;
    hp = hpmax;
    }
    return aid;
}

void drawScene(char p_action,int p,char m_action,int m){
	cout << "                                                       \n";
	if(p_action == 'A'){
	cout << "                                       "<< -p <<"\n";
	}else{
	cout << "                                                       \n";	
	}	
	cout << "                                *               *      \n";
	cout << "                                **  *********  **      \n";
	cout << "                                ****         ****      \n";
	if(m_action == 'A'){
	cout << "                 " << setw(5) << -m << "           *** **   ** ***       Attack!\n";
	}else if(m_action == 'G'){
	cout << "                                 *** **   ** ***       Guard!\n";
	}else{
	cout << "                                 *** **   ** ***       \n";	
	}
	cout << "                                  ** **   ** **        \n";
	cout << "                   ***             *         *         \n";
	if(p_action == 'A'){
	cout << "        Attack!    ***  *           *********          \n";		
	}else if(p_action == 'H'){
	cout << "      Heal! +" << setw(2) << p << "    ***  *           *********          \n";
	}else if(p_action == 'G'){
	cout << "         Guard!    ***  *           *********          \n";
	}else{
	cout << "                   ***  *           *********          \n";	
	}
	cout << "                    *  *       ***  *  *  *            \n";
	cout << "                  *****           **   *   *           \n";
	cout << "                    *                  *    ***        \n";
	cout << "                   * *               **        *       \n";
	cout << "                  *   *                                \n";
	cout << "                                                       \n";
};


void playerWin(){	
	cout << "*******************************************************\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*                   YOU WIN!!!                        *\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};


void playerLose(){
	cout << "*******************************************************\n";
	cout << "*                                                     *\n";
	cout << "*                   YOU LOSE!!!                       *\n";
	cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};
