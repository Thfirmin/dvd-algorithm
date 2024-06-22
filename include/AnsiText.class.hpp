#ifndef ANSITEXT_CLASS_HPP
# define ANSITEXT_CLASS_HPP

# define ANSI_ESCAPE "\033["

# include <Vec.class.hpp>
# include <unistd.h>

typedef signed long int ssize_t;

struct s_color {
	unsigned short	red;
	unsigned short	green;
	unsigned short	blue;
	bool			apply;
};

class	AnsiText {
	public:
		AnsiText(void);
		AnsiText(const std::string& text);
		AnsiText(const std::string& text, const Vec& pos);

		static ssize_t	write(const std::string& str, int fd = STDOUT_FILENO);
		static void		clearScreen(void);
		static void		setLocation(int x, int y);
		static void		insert(const AnsiText& txt);

		void	applyColor(unsigned short red, unsigned short green, unsigned short blue, bool aply = true);

		const std::string&	text(void) const;
		const s_color&		color(void) const;
		const bool&			absolute(void) const;
		const Vec&			pos(void) const;

		void	text(const std::string& str);
		void	absolute(const bool src);
		void	pos(const Vec& src);
		void	pos(const int x, const int y);

	private:
		std::string	_text;
		s_color		_color;
		bool		_absolute;
		Vec			_pos;
};

#endif
