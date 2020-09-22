#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <exception>
#include <sstream>
#include <stdexcept>

using namespace std;

// Êëàññ äàòà - îòâå÷àåò çà ïðàâèëüíîñü ôîðìèðîâàíèÿ äàòû ñîáûòèÿ
class Date {
public:
	explicit Date() { // êîíñòðóêòîð äàòû ïî óìîë÷àíèþ
		year = 0;
		month = 0;
		day = 0;
	};
	// Êîíñòðóêòîð äàòû
	explicit Date(const int& year_, const int& month_, const int& day_) {
		year = year_;
		if (month_ < 1 || month_ > 12) { // ïðîâåðêà äèàïàçîíà ìåñÿöà
			string string_error;
			string_error = "Month value is invalid: " + to_string(month_);
			throw runtime_error(string_error);   // ëîâèò èñêëþ÷åíèå
		}
		else if (day_ < 1 || day_ > 31) { // ïðîâåðêà äèàïàçîíà äíåé
			string string_error;
			string_error = "Day value is invalid: " + to_string(day_);
			throw runtime_error(string_error);   // ëîâèò èñêëþ÷åíèå
		}
		else {
			month = month_;
			day = day_;
		}
	};
	// Ìåòîäû âûçîâà äàííûõ äàòû
	int GetYear() const { return year; }
	int GetMonth() const { return month; }
	int GetDay() const { return day; }

private:
	int year;
	int month;
	int day;
};

// ïåðåçàãðóçêà îïåðàòîðà < äëÿ äàòû
bool operator < (const Date& lhs, const Date& rhs) {
	if ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth())) {
		return lhs.GetDay() < rhs.GetDay();
	}
	else if ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() != rhs.GetMonth())) {
		return lhs.GetMonth() < rhs.GetMonth();
	}
	else {
		return lhs.GetYear() < rhs.GetYear();
	}
}

// ïåðåçàãðóçêà îïåðàòîðà << âûâîäà â ïîòîê
ostream& operator << (ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() << '-'
		<< setw(2) << setfill('0') << date.GetMonth() << '-'
		<< setw(2) << setfill('0') << date.GetDay();
	return stream;
}
// ôóíêöèÿ ïðîâåðêè êîððåêòíîñòè ðàçäåëèòåëÿ '-' çíà÷åíèé äàòû
void EnsureNextSymbolAndSkip(stringstream& stream, const string& data_str) {
	if (stream.peek() != '-') {  // ÷òî íóæíî íàéòè
		stringstream ss;
		ss << "Wrong date format: " + data_str;
		throw runtime_error(ss.str());   // ëîâèò èñêëþ÷åíèå
	}                                    // str() - ïðèâîäèò äàííûå ê ñòðîêå
	stream.ignore(1);
}
// ïåðåçàãðóçêà îïåðàòîðà >> ââîäà èç ïîòîêà
istream& operator >> (istream& stream, Date& date) {
	int year = 10000;
	int month = 10000;
	int day = 10000;

	string data_str; // äàòà ñòðîêîé
	string endError = ""; // ëîâèì ëèøíèé ñèìâîë â êîíöå äàòû
	if (stream >> data_str) {
		stringstream d(data_str); // ïàðñèì äàòó íà çíà÷åíèÿ ãîä, ìåñ, äåíü
		d >> year;
		EnsureNextSymbolAndSkip(d, data_str);
		d >> month;
		EnsureNextSymbolAndSkip(d, data_str);
		d >> day;
		d >> endError;
		// ïðîâåðÿåì è ïåðåäàåì êîððåêòíóþ äàòó äëÿ ðàáîòû
		if (year > -1 && year < 10000 && month < 10000 && day < 10000 && endError == "") {
			date = Date(year, month, day);
			return stream;
		}
		else {
			// åñëè ïîëüçîâàòåëü ââåë íå êîððåêòíóþ äàòó âûáðàñûâàåì èñêëþ÷åíèå
			stringstream string_error;
			string_error << "Wrong date format: " + data_str;
			throw runtime_error(string_error.str());   // ëîâèò èñêëþ÷åíèå
		}
	}
	else {
		// åñëè ïîëüçîâàòåëü íå ââåë äàòó âûáðàñûâàåì èñêëþ÷åíèå
		stringstream string_error;
		string_error << "Wrong date format: " + data_str;
		throw runtime_error(string_error.str());   // ëîâèò èñêëþ÷åíèå
	}

}
// Êëàññ áàçà äàííûõ ñ ïàðàìè âèäà: êëþ÷ - äàòà, çíà÷åíèå - ñîáûòèå
class Database {
public:
	// ìåòîä äîáàâëåíèÿ ñîáûòèÿ â ÁÄ
	void AddEvent(const Date& date, const string& event) {
		DB[date].insert(event);
	}
	// Óäàëåíèå ñîáûòèÿ
	bool DeleteEvent(const Date& date, const string& event) {
		if (DB.count(date)) {
			if (DB[date].count(event)) {
				DB[date].erase(event);
				return true;
			}
		}
		return false;
	}
	// Óäàëåíèå äàòû âìåñòå ñ ñîáûòèÿìè
	int  DeleteDate(const Date& date) {
		if (DB.count(date)) {
			int c = DB[date].size();
			DB.erase(date);
			return c;
		}
		return 0;
	}
	// Ïîèñê ñîáûòèÿ
	void Find(const Date& date) const {
		if (DB.count(date)) {
			for (auto& find : DB.at(date)) {
				cout << find << endl;
			}
		}
	}
	// Âûâîä âñåé áàçû
	void Print() const {
		for (auto& p : DB) {
			for (auto& s : p.second) {
				cout << p.first << ' ' << s << endl;
			}
		}
	}

private:
	map<Date, set<string>> DB;
};
// Ïàðñèì êîìàíäû - äàòû - ñîáûòèÿ
void ParseCommands(const string& command, Database& db) {
	stringstream stream(command);
	string com = "";
	Date date;
	string event = "";
	// Ïåðåêëþ÷àåìñÿ ïî êîìàíäàì
	if (stream >> com) {
		if (com == "Add") {
			if (stream >> date) {
				if (stream >> event) {
					db.AddEvent(date, event);
				}
				else {
					stringstream ss; // Åñëè íåò ñîáûòèÿ òî èñêëþ÷åíèå
					ss << "Wrong date format: " << date;
					throw runtime_error(ss.str());
				}
			}
		}
		else if (com == "Find") {
			if (stream >> date) {
				db.Find(date);
			}
		}
		else if (com == "Print") {
			db.Print();
		}
		else if (com == "Del") {
			if (stream >> date) {
				if (stream >> event) {
					if (db.DeleteEvent(date, event)) {
						// Óäàëåíèå ñîáûòèÿ ïðîøëî íîðìàëüíî
						cout << "Deleted successfully" << endl;
					}
					else {
						// Óäàëåíèå ñîáûòèÿ íå ïðîøëî - íåò ñîáûòèÿ
						cout << "Event not found" << endl;
					}
				}
				else {
					// Óäàëåíèå äàòû c âûâîäîì åå â ñîáùåíèè
					cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
				}
			}
		}
		else {
			// Âûáðàñûâàåì èñêëþ÷åíèå ñ ñîîáùåíèåì ÷òî íåò âåðíîé êîìàíäû
			stringstream ss;
			ss << "Unknown command: " << com;
			throw runtime_error(ss.str());
		}
	}
}


int main() {
	Database db;
	string command;

	try { // â try ïîìåùàåì îïàñíûé êîä	
		while (getline(cin, command)) {
			// Ñ÷èòûâàåì êîìàíäû ñ ïîòîêà ââîäà è îáðàáàòûâàåì êàæäóþ ïàðñåðîì
			ParseCommands(command, db);
		}
	}
	//ëîâèì âñå èñêëþ÷åíèÿ è âûâîäèì íà êîíñîëü
	catch (exception& ex) {
		cout << ex.what();
	}

	return 0;
}