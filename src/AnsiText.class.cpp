#include <AnsiText.class.hpp>
#include <sstream>
#include <unistd.h>

AnsiText::AnsiText(void) {
	this->_absolute = false;
}

AnsiText::AnsiText(const std::string& text) : _text(text) {
	this->_absolute = false;
}

AnsiText::AnsiText(const std::string& text, const Vec& pos): _text(text), _pos(pos) {
	this->_absolute = false;
}

ssize_t	AnsiText::write(const std::string& str, int fd) {
	return (::write(fd, str.c_str(), str.size()));
}

void	AnsiText::clearScreen(void) {
	std::stringstream	stream;

	stream
		<< ANSI_ESCAPE << "3J"
		<< ANSI_ESCAPE << "1J"
		<< ANSI_ESCAPE << "H";
	AnsiText::write(stream.str());
}

void	AnsiText::setLocation(int x, int y) {
	std::stringstream	stream;

	stream << ANSI_ESCAPE << y << ";" << x << "H";
	AnsiText::write(stream.str());
}

void	AnsiText::insert(const AnsiText& txt) {
	std::stringstream	stream;

	if (txt.color().apply) {
		stream << ANSI_ESCAPE << "38;2;" << txt.color().red << ";" << txt.color().green << ";" << txt.color().blue << "m";
	}

	stream << txt.text();

	if (txt.color().apply)
		stream << ANSI_ESCAPE << "0m";
	
	if (txt.absolute())
		AnsiText::setLocation(txt.pos().x(), txt.pos().y());
	AnsiText::write(stream.str());
}

void	AnsiText::applyColor(unsigned short red, unsigned short green, unsigned short blue, bool apply) {
	this->_color.red = red % 256;
	this->_color.green = green % 256;
	this->_color.blue = blue % 256;
	this->_color.apply = apply;
}

const std::string&	AnsiText::text(void) const {
	return (this->_text);
}

const s_color&	AnsiText::color(void) const {
	return (this->_color);
}

const bool&	AnsiText::absolute(void) const {
	return (this->_absolute);
}

const Vec&	AnsiText::pos(void) const {
	return (this->_pos);
}

void	AnsiText::text(const std::string& str) {
	this->_text = str;
}

void	AnsiText::absolute(const bool src) {
	this->_absolute = src;
}

void	AnsiText::pos(const Vec& src) {
	this->_pos = src;
}

void	AnsiText::pos(const int x, const int y) {
	this->_pos = Vec(x, y);
}
