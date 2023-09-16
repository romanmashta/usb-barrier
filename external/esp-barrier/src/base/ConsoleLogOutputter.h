#pragma once

#include "base/ILogOutputter.h"


class ConsoleLogOutputter : public ILogOutputter {
public:
    ConsoleLogOutputter();
    virtual ~ConsoleLogOutputter();

    // ILogOutputter overrides
    virtual void        open(const char* title);
    virtual void        close();
    virtual void        show(bool showIfEmpty);
    virtual bool        write(ELevel level, const char* message);
    virtual void        flush();
};

