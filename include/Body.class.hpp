#ifndef BODY_CLASS_HPP
# define BODY_CLASS_HPP

# include <Vec.class.hpp>
# include <AnsiText.class.hpp>
# include <vector>
# include <ostream>
# include <string>

class	Body {
	public:
		Body(void);
		Body(const std::string& src,bool isFile);

		std::string	bodyStringfy(void) const;

		void	apllyAbsolute(void);

		void	openTextureFile(const std::string& filepath);
		void	openTextureStr(const std::string& str);

		const std::vector<std::string>&	body(void) const;
		const Vec&						size(void) const;
		const Vec&						pos(void) const;

		void	pos(const Vec& vec);

	private:
		std::vector<AnsiText>	_body;
		Vec						_size;
		Vec						_pos;
};

std::ostream&	operator<<(std::ostream& out, const Body& src);

#endif
