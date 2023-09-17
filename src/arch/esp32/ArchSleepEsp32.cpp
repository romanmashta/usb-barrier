/*
 * barrier -- mouse and keyboard sharing utility
 * Copyright (C) 2012-2016 Symless Ltd.
 * Copyright (C) 2002 Chris Schoeneman
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "arch/esp32/ArchSleepEsp32.h"

#include "arch/Arch.h"
#include <Arduino.h>

#if TIME_WITH_SYS_TIME
#    include <sys/time.h>
#    include <time.h>
#else
#    if HAVE_SYS_TIME_H
#        include <sys/time.h>
#    else
#        include <time.h>
#    endif
#endif
#if !HAVE_NANOSLEEP
#    if HAVE_SYS_SELECT_H
#        include <sys/select.h>
#    endif
#    if HAVE_SYS_TYPES_H
#        include <sys/types.h>
#    endif
#    if HAVE_UNISTD_H
#        include <unistd.h>
#    endif
#endif

//
// ArchSleepUnix
//

ArchSleepEsp32::ArchSleepEsp32()
{
    // do nothing
}

ArchSleepEsp32::~ArchSleepEsp32()
{
    // do nothing
}

void
ArchSleepEsp32::sleep(double timeout)
{
    ARCH->testCancelThread();
    if (timeout < 0.0) {
        return;
    }

    vTaskDelay(timeout * 1000 / portTICK_PERIOD_MS);
}
