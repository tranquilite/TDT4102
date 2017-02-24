#include<string>
#include<vector>
#include<iostream>

#include"Meeting.h"

using namespace del1;

namespace del1 {
const std::ostream& operator<<(std::ostream& stream, Campus& camp) {
    string str[3] = {"TRH", "GJO", "AAL"};
    return stream << str[camp];
}

Meeting::Meeting() { startTime = 12; }

int Meeting::getDay()   { return day; }
int Meeting::getStart() { return startTime; }
int Meeting::getEnd()   { return endTime; }
string Meeting::getSubject()    { return subject; }
//Person Meeting::getLeader()     { return leader; }
Campus Meeting::getLocation()   { return location; }

} //Namespace del1 slut
