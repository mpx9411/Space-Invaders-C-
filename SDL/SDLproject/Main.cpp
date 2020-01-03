#include "Engine.h"
#include "SDL.h"
#include "Player.h"
#include "Session.h"
using namespace std;
#include <SDL.h>

int main(int argc, char* argv[])
{
    //TODO Don't forget to choose your ABSOLUTE path in these classes: Bullet, player (IN TWO PLACES), Session, Invader

	player = Player::getInstance(0,0,50,50,"");
	ses.add(player);
	ses.run();
	return 0;


}