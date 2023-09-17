#include "common/version.h"
#include "barrier/ClientApp.h"
#include "arch/Arch.h"
#include "base/Log.h"
#include "base/EventQueue.h"
#include "init.h"

Arch arch;
Log log;
EventQueue events;


void setup() {
  initSystem();

  arch.init();

  log.setFilter(ELevel::kDEBUG5);
  LOG((CLOG_DEBUG1 "Hello %s. %s", "world", kVersion));

}

void loop() {
  while (true)
  {
    ClientApp app(&events, NULL);
    int argc = 2;
    char* argv[] = {"barrier", "--help", NULL};
    int result = app.run(argc, argv);
  }
}
