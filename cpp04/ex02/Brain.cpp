#include "Brain.hpp"

std::string fillIdeas(size_t i)
{
	if (i % 2 == 0)
		return ("{@_Corgi_Cat_@}");
	else
		return ("!German-Shepard__CAT!");
	return ("Crash Brain");
}
std::string Brain::getIdeas(void) const
{
	std::string allIdeas;
	for(int i = 0; i < 100; i++)
		allIdeas += this->ideas[i] + "\n";
	return allIdeas;

}

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = fillIdeas(i);
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return *this;
}


