#include "Player.h"
#include "Session.h"
#include "GameObject.h"
#include "Engine.h"
#include "Invader.h"
using namespace std;

int main(int argc, char* argv[])
{
    //TODO Don't forget to choose your ABSOLUTE path in these classes: Bullet, player (IN TWO PLACES), Session, Invader
	vector<GameObject*> preLoad;
	player = Player::getInstance(0,0,50,50,"");
	for (int i = 0; i <= 30; i++) {
			if (i % 3 == 0) {
				Invader* inv(Invader::getInstance(10 + (i * 50), 0, 30, 30, 1));
				eng.add(inv);

			}if (i % 3 == 1) {
				Invader* inv(Invader::getInstance((i * 50), 31, 30, 30, 2));
				eng.add(inv);
			}if (i % 3 == 2) {
				Invader* inv(Invader::getInstance((i * 50), 62, 30, 30, 3));
				eng.add(inv);
			}
		}
		Invader* inv3(Invader::getInstance(10, 62, 30, 30, 3));
		eng.add(inv3);
	eng.add(player);
	eng.start("/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/background.png", 500, preLoad);
	return 0;


}