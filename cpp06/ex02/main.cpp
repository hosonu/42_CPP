#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void) {
	std::srand(std::time(NULL));
    int choice = rand() % 3;
    switch (choice) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            break;
    }
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
		(void)a;
        std::cout << "A" << std::endl;
    } catch (...) {
        try {
            B& b = dynamic_cast<B&>(p);
			(void)b;
            std::cout << "B" << std::endl;
        } catch (...) {
            try {
                C& c = dynamic_cast<C&>(p);
				(void)c;
                std::cout << "C" << std::endl;
            } catch (...) {
                std::cerr << "Unknown type" << std::endl;
            }
        }
    }
}

int main() {
    Base *ptr = generate();
    identify(ptr);
	identify(*ptr);
    delete ptr;
    return 0;
}
