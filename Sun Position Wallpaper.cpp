#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

double calculateSolarAngle(double lat, double lon, time_t timestamp) {
    struct tm *timeinfo = gmtime(&timestamp);
    int day_of_year = timeinfo->tm_yday + 1;
    double hour_of_day = timeinfo->tm_hour + timeinfo->tm_min / 60.0 + timeinfo->tm_sec / 3600.0;
    double declination = 23.44 * cos((360.0 / 365.0) * (day_of_year - 81) * M_PI / 180.0);
    double solar_time = hour_of_day + (lon / 15.0);
    double hour_angle = 15.0 * (solar_time - 12.0);
    double altitude_angle = asin(
        sin(lat * M_PI / 180.0) * sin(declination * M_PI / 180.0) +
        cos(lat * M_PI / 180.0) * cos(declination * M_PI / 180.0) * cos(hour_angle * M_PI / 180.0)
    ) * 180.0 / M_PI;
    return altitude_angle;
}

void selectWallpaper(double lat, double lon) {
    time_t now = time(0);
    double altitude_angle = calculateSolarAngle(lat, lon, now);
    
    if (altitude_angle <= 0) {
        cout << "night.png" << endl;
    } else if (altitude_angle < 15) {
        cout << "sunset.png" << endl;
    } else if (altitude_angle < 30) {
        cout << "evenlng.png" << endl;
    } else if (altitude_angle < 60) {
        cout << "noon.png" << endl;
    } else if (altitude_angle < 85) {
        cout << "morntng.png" << endl;
    } else {
        cout << "sunnse.png" << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: ./program <latitude> <longitude>" << endl;
        return 1;
    }
    
    double latitude = atof(argv[1]);
    double longitude = atof(argv[2]);
    selectWallpaper(latitude, longitude);
    return 0;
}