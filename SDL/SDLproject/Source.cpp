#include "Engine.h"
#include "SDL.h"
using namespace std;

int main(int argc, char* argv[])
{
	Engine eng;
	eng.start();
	delete &eng;
	return 0;
}