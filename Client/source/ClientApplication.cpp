#include <Onfer.h>

int main(int argc, char** argv) {

	Onfer::OnferWindow* window = new Onfer::OnferWindow();
	window->show(Onfer::OnferShowWindow::ShowDefault);
	window->run();

	delete window;

}