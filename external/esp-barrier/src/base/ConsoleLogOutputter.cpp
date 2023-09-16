#include "ConsoleLogOutputter.h"
#include <iostream>

ConsoleLogOutputter::ConsoleLogOutputter()
{
}

ConsoleLogOutputter::~ConsoleLogOutputter()
{

}

void
ConsoleLogOutputter::open(const char* title)
{

}

void
ConsoleLogOutputter::close()
{

}

void
ConsoleLogOutputter::show(bool showIfEmpty)
{

}

bool
ConsoleLogOutputter::write(ELevel level, const char* msg)
{
    std::cout << msg << std::endl;
    return true;
}

void
ConsoleLogOutputter::flush()
{

}
