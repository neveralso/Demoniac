//
// Created by Neveralso on 15/3/15.
//

#ifndef _DEMONIAC_IOLOOP_H_
#define _DEMONIAC_IOLOOP_H_

#include <iostream>
#include <vector>

#include "Event.h"
#include "util/noncopyable.h"

#include "poller/GetPoller.h"

namespace dc {

class IOLoop : noncopyable {
private:
    IOLoop *instance_;
    bool quit_;
    Poller *poller_;
    std::vector<Event> events_list_;
    //std::vector<poll_event> events_ready_;

public:
    IOLoop();

    void Loop();

    void AddEvent(const Event& e);

    ~IOLoop();
};

}


#endif //_DEMONIAC_IOLOOP_H_