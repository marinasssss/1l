#include "exceptions.h"

exceptions::exceptions() : mesg(nullptr) {
	std::cout << TAB << "exceptions()\n";
}
exceptions::exceptions(const char* s) {
	std::cout << TAB << "exceptions(...)\n";
	int	n = strlen(s) + 1;
	mesg = nullptr;
	if (n) {
		mesg = new char[n];
		memcpy(mesg, s, sizeof(char) * n);
	}
}
exceptions::exceptions(exceptions& e) {
	std::cout << TAB << "exceptions(exceptions&)\n";
	int	n = strlen(e.mesg) + 1;
	mesg = new char[n];
	memcpy(mesg, e.mesg, sizeof(char) * n);
}
exceptions::exceptions(exceptions&& e) {
	std::cout << TAB << "exceptions(exceptions&&)\n";
	mesg = e.mesg;
	e.mesg = nullptr;
}
exceptions::~exceptions() {
	std::cout << TAB << "~exceptions()\n";
	delete[] mesg;
}
const char* exceptions::what() {
	return mesg;
}