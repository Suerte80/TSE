#ifndef ROUTINEEXEC_H
#define ROUTINEEXEC_H

using namespace std;

class RoutineClient;

class RoutineExec{
public:
    void operator()(RoutineClient &rc);
};

#endif // ROUTINEEXEC_H
