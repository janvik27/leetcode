class UndergroundSystem {
    unordered_map<int,pair<string,int>> checkin;  // id : {stationName, time}
    unordered_map<string,pair<int,int>> routes;   // startStation-endStation : {sumOfTime, count}
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start_to_end = checkin[id].first + '-' +  stationName;
        routes[start_to_end] = {routes[start_to_end].first + (t- checkin[id].second), routes[start_to_end].second +1};
        checkin.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s = startStation + '-' + endStation;
        pair<int,int> p = routes[s];
        
        return (double)p.first/p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */