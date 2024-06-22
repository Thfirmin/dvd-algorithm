#include <Body.class.hpp>
#include <fstream>

Body::Body(void) {}

Body::Body(const std::string& src, const bool isFile) {
	if (isFile)
		this->openTextureFile(src);
	else
		this->openTextureStr(src);
}

void	Body::openTextureFile(const std::string& filepath) {
	size_t			szx = 0, szy = 0;
	std::ifstream	file(filepath.c_str());
	std::string		line;

	if (!file.is_open())
		return ;

	this->_body.clear();
	while (std::getline(file, line)) {
		if (szx < line.size())
			szx = line.size();
		szy++;
		this->_body.push_back(line);
	}
	file.close();
}

void	Body::openTextureStr(const std::string& str) {
	this->_body.clear();
	this->_body.push_back(str);
	this->_size = Vec(str.size(), 1);
}

std::string	Body::bodyStringfy(void) const {
	std::string	str("");

	for (std::vector<std::string>::const_iterator it = this->_body.begin(); it != this->_body.end(); it++) {
		str += *it;
		if ((it + 1) != this->_body.end())
			str += "\n";
	}
	return (str);
}

const std::vector<std::string>&	Body::body(void) const {
	return (this->_body);
}

const Vec&	Body::size(void) const {
	return (this->_size);
}

const Vec&	Body::pos(void) const {
	return (this->_pos);
}

void	Body::pos(const Vec& vec) {
	this->_pos = vec;
}

std::ostream&	operator<<(std::ostream& out, const Body& src) {
	out << std::endl << src.bodyStringfy() << std::endl;
	return (out);
}
