#include "Engine.h"
#include "SDL.h"
using namespace std;

int main(int argc, char* argv[])
{
	Engine eng;
	eng.start();
	eng.play();
	eng.terminate();
	return 0;
}