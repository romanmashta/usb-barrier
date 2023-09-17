#pragma once

#include <arch/IArchMultithread.h>
#include <arch/IArchLog.h>
#include <arch/IArchNetwork.h>

#define ARCH_NETWORK NetworkStub
#define ARCH_SYSTEM SystemStub
#define ARCH_TASKBAR TaskbarStub
#define ARCH_INTERNET InternetStub

class NetworkStub{
    public:
        void init() { }
        virtual void  unblockPollSocket(ArchThread thread) {};
        int pollSocket(IArchNetwork::PollEntry pe[], int num, double timeout){ return 0;}
};

class SystemStub{
};

class TaskbarStub{
};

class InternetStub{
};