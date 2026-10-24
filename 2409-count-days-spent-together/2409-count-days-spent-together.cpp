class Solution {
public:
    int convertToDayOfYear(string date) {
        int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        int totalDays = day;
        for(int i = 1; i < month; i++){
            totalDays += daysInMonths[i];
        }
        return totalDays;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrival = convertToDayOfYear(arriveAlice);
        int aliceLeave = convertToDayOfYear(leaveAlice);
        int bobArrival = convertToDayOfYear(arriveBob);
        int bobLeave = convertToDayOfYear(leaveBob);
        int startDay = max(aliceArrival, bobArrival);
        int endDay = min(aliceLeave, bobLeave);
        if(startDay > endDay){
            return 0;
        }
        return endDay - startDay + 1;
    }
};