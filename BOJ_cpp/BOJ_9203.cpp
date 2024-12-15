#include<bits/stdc++.h>
using namespace std;

int DAYS[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int convert(int year, int month, int day, int hour, int min)
{
	int days = 0;
	days = 365 * (year - 2013);	// 2016년이 윤년
	for (int m = 1; m < month; m++)
		days += DAYS[m];

	days += (day - 1);

	if (year >= 2016)
	{
		if (month >= 3)
			days++;
	}

	int minutes = days * 24 * 60;
	minutes += 60 * hour;
	minutes += min;
	return minutes;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	short T;
	cin >> T;
	while (T-- > 0)
	{
		short B, C;
		cin >> B >> C;

		vector< pair<int, int> > timeline;//<입실시간, 퇴실시간> 배열
		for (int i = 0; i < B; i++)
		{
			string code;
			char hyphen;
			int year, month, day, hour, min;
			cin >> code >> year >> hyphen >> month >> hyphen >> day >> hour >> hyphen >> min;
			int checkIn = convert(year, month, day, hour, min);
			cin >> year >> hyphen >> month >> hyphen >> day >> hour >> hyphen >> min;
			int checkOut = convert(year, month, day, hour, min);
			checkOut += C;
			timeline.push_back(make_pair(checkIn, checkOut));
		}
		sort(timeline.begin(), timeline.end());//입실시간 기준

		multiset<int> rooms;
		for (pair<int, int>& data : timeline)
		{
			int begin = data.first;
			int end = data.second;

			bool stay = false;
			if (rooms.size() > 0)
			{
				if (*rooms.begin() <= begin)
					stay = true;
			}
			if (stay)
			{
				rooms.erase(rooms.begin());
				rooms.insert(end);
			}
			else
				rooms.insert(end);
		}
		cout << rooms.size() << "\n";
	}
}