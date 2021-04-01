#include "database.h"

using namespace std;

void Database::Add(const Date& date, const string& event) {
    if (dates.count(date)) {
        const auto insert_it = dates[date].first.insert(event);

        if (insert_it.second) {
            dates[date].second.push_back(insert_it.first);
        }
    } else {
        auto insert_result = dates[date].first.insert(event);
        dates[date].second.push_back(insert_result.first);
    }
}

void Database::Print(ostream& os) const {
    for (const auto& date_it : dates) {
        for (const auto& event_it : date_it.second.second) {
            os << setw(4) << setfill('0') << date_it.first.GetYear() << '-'
            << setw(2) << setfill('0') << date_it.first.GetMonth() << '-' 
            << setw(2) << setfill('0') << date_it.first.GetDay() << " " 
            << *event_it << endl;
        }
    }
}

string Database::Last(const Date& date) const {
    const auto upper_it = dates.upper_bound(date);

    if (upper_it == dates.begin()) {
        throw invalid_argument("No entries");
    }

    return prev(upper_it)->first.DateToString() + " " + *prev(upper_it)->second.second.back();
}

template<typename Functor>
int Database::RemoveIf(const Functor& func) {
    int count = 0;

    for (auto& date_it : dates) {
        auto it = stable_partition(date_it.second.second.begin(), date_it.second.second.end(), 
                                    [&](const auto& event) -> bool {
                                        if (functor(date_it.first, *event)) {
                                            count++;
                                            date_it.second.first.erase(*event);
                                            return false;
                                        }
                                        return true;
                                    });
        date_it.second.second.erase(it, date_it.second.second.end());
    }

    for (auto erase_it = dates.cbegin(), next_it = erase_it;
        erase_it != dates.cend();
        erase_it = next_it) {
            ++next_it;
            if (erase_it->second.first.empty()) {
                dates.erase(erase_it);
            }
        }

    return count;
}

template<typename Functor>
vector<pair<Date, string>> Database::FindIf(const Functor& func) const {
    vector<pair<Date, string>> last_event;

    for (const auto& date_it : dates) {
        auto it = find_if(date_it.second.second.begin(), date_it.second.second.end(),
                         [&](const auto& event) -> {
                             if (functor(date_it.first, *event)) {
                                 last_event.push_back(make_pair(date_it.first, *event));
                             }

                             return false;
                         });
    }

    return last_event;
};