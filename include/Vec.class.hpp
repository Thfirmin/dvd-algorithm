#ifndef VEC_CLASS_HPP
# define VEC_CLASS_HPP

# include <ostream>

class	Vec {
	public:
		Vec(void);
		Vec(const int x, const int y);
		Vec(const Vec& copy);
		~Vec(void);

		Vec&	operator=(const Vec& src);

		const int&	x(void) const;
		const int&	y(void) const;
		
		void	x(const int x);
		void	y(const int y);

	private:
		int	_x;
		int	_y;
};

std::ostream&	operator<<(std::ostream& out, const Vec& src);

#endif
