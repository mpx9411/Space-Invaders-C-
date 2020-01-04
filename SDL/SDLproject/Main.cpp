#include "Player.h"
#include "Session.h"
#include "GameObject.h"
#include "Engine.h"
using namespace std;

int main(int argc, char* argv[])
{
    //TODO Don't forget to choose your ABSOLUTE path in these classes: Bullet, player (IN TWO PLACES), Session, Invader
	vector<GameObject*> preLoad;
	player = Player::getInstance(0,0,50,50,"");
	eng.add(player);
	eng.start("/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/background.png", 500, preLoad);
	return 0;


}