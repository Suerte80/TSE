#include "routineexec.h"

#include "routineclient.h"

void RoutineExec::operator ()(RoutineClient &rc)
{
    rc.routineExec();
}
