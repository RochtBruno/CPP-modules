#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int random = std::rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "A" << std::endl;
			return new A();
		case 1:
			std::cout << "B" << std::endl;
			return new B();
		case 2:
			std::cout << "C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown..." << std::endl;
}


void identify(Base& p) {
	bool identified = false;

	if (!identified) {
		A* a = dynamic_cast<A*>(&p);
		if (a) {
			std::cout << "A" << std::endl;
			identified = true;
		}
	}

	if (!identified) {
		B* b = dynamic_cast<B*>(&p);
		if (b) {
			std::cout << "B" << std::endl;
			identified = true;
		}
	}

	if (!identified) {
		C* c = dynamic_cast<C*>(&p);
		if (c) {
			std::cout << "C" << std::endl;
			identified = true;
		}
	}
}

int	main(void)
{
	std::srand(std::time(0));
	Base *base;
	base = generate();
	std::cout << "Pointer param" << std::endl;
	identify(base);
	std::cout << "Reference param" << std::endl;
	identify(*base);
	delete base;
	return 0;
}
