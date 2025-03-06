#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream> 
#include <string>
#include <ctime>   


class Logger {
public:
    virtual ~Logger() {} 
    virtual void log(const std::string& message) { 
        //
    };
};


class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override { // Добавлено override и const std::string&
        std::cout << getCurrentTimestamp() << " [CONSOLE] " << message << std::endl;
    }

private:
    std::string getCurrentTimestamp() {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &ltm);

        return buffer;
    }
};
    
    
class FileLogger : public Logger {
public:
    FileLogger(const std::string& filename) : filename_(filename) {
        logFile_.open(filename_, std::ios::app); 
        if (!logFile_.is_open()) {
            std::cerr << "Error opening log file: " << filename_ << std::endl;
        }
    }

    ~FileLogger() override { 
        if (logFile_.is_open()) {
            logFile_.close();
        }
    }

    void log(const std::string& message) override { 
        if (logFile_.is_open()) {
            logFile_ << getCurrentTimestamp() << " [FILE] " << message << std::endl;
            logFile_.flush(); 
        }
    }

private:
    std::string filename_;
    std::ofstream logFile_;

    std::string getCurrentTimestamp() {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &ltm);

        return buffer;
    }
};

class LoggerFactory {
    public:
        Logger* CreateLogger(int type, const std::string& filename = "") {
            switch (type) {
                case 1:
                    return new ConsoleLogger();
                case 2:
                    return new FileLogger(filename);
                default:
                    std::cerr << "Unknown logger type: " << type << std::endl;
                    return nullptr; 
            }
        }
    };
#endif