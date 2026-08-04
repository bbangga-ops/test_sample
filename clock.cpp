#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>

int main() {
    const char* days[] = {"일", "월", "화", "수", "목", "금", "토"};

    std::cout << "디지털 시계 (Ctrl+C를 눌러 종료하세요)\n";

    while (true) {
        // 현재 시간 가져오기
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* parts = std::localtime(&now_c);

        // 터미널에 날짜와 시간 출력 (\r을 사용하여 같은 줄에 계속 덮어씀)
        std::cout << "\r"
                  << parts->tm_year + 1900 << "년 "
                  << std::setfill('0') << std::setw(2) << parts->tm_mon + 1 << "월 "
                  << std::setfill('0') << std::setw(2) << parts->tm_mday << "일 "
                  << "(" << days[parts->tm_wday] << ") "
                  << std::setfill('0') << std::setw(2) << parts->tm_hour << ":"
                  << std::setfill('0') << std::setw(2) << parts->tm_min << ":"
                  << std::setfill('0') << std::setw(2) << parts->tm_sec
                  << std::flush;

        // 1초 대기
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}