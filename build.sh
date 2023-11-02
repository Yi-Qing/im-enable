#!/bin/sh

g++ im-select-mspy.cpp -O3 -Wl,-Bstatic -lstdc++ -lgcc_eh -lpthread -Wl,-Bdynamic -lole32 -loleaut32 -luuid
