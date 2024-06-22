#include <iostream>
#include <Vec.class.hpp>
#include <Body.class.hpp>
#include <AnsiText.class.hpp>

static Body	getBody(int argc, char **argv);

int	main(int argc, char **argv)
{
	Body		body = getBody(argc, argv);
	
	std::cout << "Hello, World! " << body << std::endl;
	
	AnsiText	text("Pablo");

	text.applyColor(255, 0, 0);
	text.pos(50, 10);
	text.absolute(true);

	AnsiText::clearScreen();
	AnsiText::insert(text);
	return (0);
}

static Body	getBody(int argc, char **argv)
{
	bool		file;
	std::string	src;
	Body		res;

	file = argc > 1;
	src = file ? argv[1] : "DVD";
	res = Body(src, file);

	return (res);
}
