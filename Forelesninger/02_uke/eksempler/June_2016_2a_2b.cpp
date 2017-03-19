//
// 2a)
//
int checkAlarm(const double value, const double threshold)
{
	if (value > threshold && value <= MAX_WIND)
		return 1;
	else if (value < 0 || value > MAX_WIND)
		return -1;
	else
		return 0;
}

//
// 2b)
//
void printAlarm(const int id, const double wind, const int dir)
{
	cout << "ALARM " << id << ": ";
	cout << fixed << setprecision(2) << wind << " fra ";
	if (dir >= 45 && dir < 135)
		cout << "Øst";
	else if (dir >= 135 && dir < 225)
		cout << "Syd";
	else if (dir >= 225 && dir < 315)
		cout << "Vest";
	else
		cout << "Nord";
	cout << endl;
}