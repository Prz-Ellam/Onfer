#include <Onfer.h>

int main(int argc, char** argv) {

	Onfer::Log::trace("Estamos investigando: %d", 3);
	Onfer::Application* application = new Onfer::Application();
	application->run();
	delete application;

}