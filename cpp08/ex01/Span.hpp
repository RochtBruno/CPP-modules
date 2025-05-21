# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>

class Span{
	private:
		// unsigned int		_n;
		std::vector<int>	_vec;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void			displayElements(void);
		void			addNumber(unsigned int number);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();


		class OutOfLimit : public std::exception{
			public:
				virtual const char *what() const throw(){
					return("Error: It's not possible to add any value into Span anymore");
				};
		};

		class NoSpan : public std::exception{
			public:
				virtual const char *what() const throw(){
					return("Error: There is no span to calculate");
				};
		};

};


