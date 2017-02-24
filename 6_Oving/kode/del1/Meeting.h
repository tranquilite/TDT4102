#include<string>
#include<vector>
#include<iostream>

using std::string;
using std::vector;

#include"Person.h"
#include"Car.h"

using namespace del1;

namespace del1 {
enum Campus {TRH, GJO, AAL};

const std::ostream& operator<<(std::ostream& stream, Campus& camp);

class Meeting {
    private:
        int day;
        int startTime, endTime;
        Campus location;
        string subject;
        const Person* leader;
        vector<const Person*> participant;
        static vector<const Meeting*> meetings;

    public:
        Meeting();

        int getDay();
        int getStart();
        int getEnd();
        Campus getLocation();
        string getSubject();
        Person getLeader();

}; 
} // Namespace del1 slut
