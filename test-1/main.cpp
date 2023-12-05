#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <future>
using namespace std;

// 数据结构，用于存储解析的CSV数据
struct TickData
{
    char instrumentId[100];
    char updateTime[100];
    long long lastPrice;
    long long lastSize;
    long long bidVolume1;
    long long bidPrice1;
    long long askPrice1;
    long long askVolume1;
    long long bidVolume2;
    long long bidPrice2;
    long long askPrice2;
    long long askVolume2;
    long long bidVolume3;
    long long bidPrice3;
    long long askPrice3;
    long long askVolume3;
    long long bidVolume4;
    long long bidPrice4;
    long long askPrice4;
    long long askVolume4;
    long long bidVolume5;
    long long bidPrice5;
    long long askPrice5;
    long long askVolume5;
    long long openInterest;
    long long turnover;
    long long totalVolume;
    char serverTime[100];
};

// 解析CSV文件
vector<TickData> parseCSV(const string &filename)
{
    vector<TickData> tickDataList;
    ifstream file(filename);
    string line;

    // 跳过CSV文件的标题行
    getline(file, line);

    while (getline(file, line))
    {
        istringstream iss(line);
        string token;
        TickData tickData;
        try
        {
            getline(iss, token, ',');
            memset(tickData.instrumentId, 0, sizeof(tickData.instrumentId));
            strcpy(tickData.instrumentId, token.c_str());
            tickData.instrumentId[99] = '\0';

            getline(iss, token, ',');
            memset(tickData.updateTime, 0, sizeof(tickData.updateTime));
            strcpy(tickData.updateTime, token.c_str());
            tickData.updateTime[99] = '\0';

            getline(iss, token, ',');
            tickData.lastPrice = stoll(token);

            getline(iss, token, ',');
            tickData.lastSize = stoll(token);

            getline(iss, token, ',');
            tickData.bidVolume1 = stoll(token);

            getline(iss, token, ',');
            tickData.bidPrice1 = stoll(token);

            getline(iss, token, ',');
            tickData.askPrice1 = stoll(token);

            getline(iss, token, ',');
            tickData.askVolume1 = stoll(token);

            getline(iss, token, ',');
            tickData.bidVolume2 = stoll(token);

            getline(iss, token, ',');
            tickData.bidPrice2 = stoll(token);

            getline(iss, token, ',');
            tickData.askPrice2 = stoll(token);

            getline(iss, token, ',');
            tickData.askVolume2 = stoll(token);

            getline(iss, token, ',');
            tickData.bidVolume3 = stoll(token);

            getline(iss, token, ',');
            tickData.bidPrice3 = stoll(token);

            getline(iss, token, ',');
            tickData.askPrice3 = stoll(token);

            getline(iss, token, ',');
            tickData.askVolume3 = stoll(token);

            getline(iss, token, ',');
            tickData.bidVolume4 = stoll(token);

            getline(iss, token, ',');
            tickData.bidPrice4 = stoll(token);

            getline(iss, token, ',');
            tickData.askPrice4 = stoll(token);

            getline(iss, token, ',');
            tickData.askVolume4 = stoll(token);

            getline(iss, token, ',');
            tickData.bidVolume5 = stoll(token);

            getline(iss, token, ',');
            tickData.bidPrice5 = stoll(token);

            getline(iss, token, ',');
            tickData.askPrice5 = stoll(token);

            getline(iss, token, ',');
            tickData.askVolume5 = stoll(token);

            getline(iss, token, ',');
            tickData.openInterest = stoll(token);

            getline(iss, token, ',');
            tickData.turnover = stoll(token);

            getline(iss, token, ',');
            tickData.totalVolume = stoll(token);

            getline(iss, token, ',');
            memset(tickData.serverTime, 0, sizeof(tickData.serverTime));
            strcpy(tickData.serverTime, token.c_str());
            tickData.serverTime[99] = '\0';

            tickDataList.push_back(tickData);
        }
        catch (const std::invalid_argument &e)
        {
            // cout << "Invalid argument exception caught: " << e.what() << endl;
            // cout << "Value causing the exception: " << token << endl;
            continue;
        }
    }

    return tickDataList;
}

// 将TickData数据写入TD文件
void writeTickDataToTDFile(const string &filename, const vector<TickData> &tickDataList)
{
    ofstream file(filename, ios::binary);

    for (const auto &tickData : tickDataList)
    {
        // 将TickData数据转换为二进制格式，并写入TD文件
        file.write(reinterpret_cast<const char *>(&tickData.instrumentId), sizeof(tickData.instrumentId));
        file.write(reinterpret_cast<const char *>(&tickData.updateTime), sizeof(tickData.updateTime));
        file.write(reinterpret_cast<const char *>(&tickData.lastPrice), sizeof(tickData.lastPrice));
        file.write(reinterpret_cast<const char *>(&tickData.lastSize), sizeof(tickData.lastSize));
        file.write(reinterpret_cast<const char *>(&tickData.bidVolume1), sizeof(tickData.bidVolume1));
        file.write(reinterpret_cast<const char *>(&tickData.bidPrice1), sizeof(tickData.bidPrice1));
        file.write(reinterpret_cast<const char *>(&tickData.askPrice1), sizeof(tickData.askPrice1));
        file.write(reinterpret_cast<const char *>(&tickData.askVolume1), sizeof(tickData.askVolume1));
        file.write(reinterpret_cast<const char *>(&tickData.bidVolume2), sizeof(tickData.bidVolume2));
        file.write(reinterpret_cast<const char *>(&tickData.bidPrice2), sizeof(tickData.bidPrice2));
        file.write(reinterpret_cast<const char *>(&tickData.askPrice2), sizeof(tickData.askPrice2));
        file.write(reinterpret_cast<const char *>(&tickData.askVolume2), sizeof(tickData.askVolume2));
        file.write(reinterpret_cast<const char *>(&tickData.bidVolume3), sizeof(tickData.bidVolume3));
        file.write(reinterpret_cast<const char *>(&tickData.bidPrice3), sizeof(tickData.bidPrice3));
        file.write(reinterpret_cast<const char *>(&tickData.askPrice3), sizeof(tickData.askPrice3));
        file.write(reinterpret_cast<const char *>(&tickData.askVolume3), sizeof(tickData.askVolume3));
        file.write(reinterpret_cast<const char *>(&tickData.bidVolume4), sizeof(tickData.bidVolume4));
        file.write(reinterpret_cast<const char *>(&tickData.bidPrice4), sizeof(tickData.bidPrice4));
        file.write(reinterpret_cast<const char *>(&tickData.askPrice4), sizeof(tickData.askPrice4));
        file.write(reinterpret_cast<const char *>(&tickData.askVolume4), sizeof(tickData.askVolume4));
        file.write(reinterpret_cast<const char *>(&tickData.bidVolume5), sizeof(tickData.bidVolume5));
        file.write(reinterpret_cast<const char *>(&tickData.bidPrice5), sizeof(tickData.bidPrice5));
        file.write(reinterpret_cast<const char *>(&tickData.askPrice5), sizeof(tickData.askPrice5));
        file.write(reinterpret_cast<const char *>(&tickData.askVolume5), sizeof(tickData.askVolume5));
        file.write(reinterpret_cast<const char *>(&tickData.openInterest), sizeof(tickData.openInterest));
        file.write(reinterpret_cast<const char *>(&tickData.turnover), sizeof(tickData.turnover));
        file.write(reinterpret_cast<const char *>(&tickData.totalVolume), sizeof(tickData.totalVolume));
        file.write(reinterpret_cast<const char *>(&tickData.serverTime), sizeof(tickData.serverTime));
    }

    file.close();
}

void convertToCSV(const string &inputFilename, const string &outputFilename)
{
    ifstream tdFile(inputFilename, ios::binary);

    // 检查文件是否成功打开
    if (!tdFile.is_open())
    {
        cout << "Failed to open .td file." << endl;
        return;
    }

    // 获取文件大小
    tdFile.seekg(0, tdFile.end);
    int fileSize = tdFile.tellg();
    tdFile.seekg(0, tdFile.beg);

    // 计算TickData对象个数
    int numTickData = fileSize / sizeof(TickData);

    // 读取TickData数据
    vector<TickData> tickDataList(numTickData);
    for (auto &tickData : tickDataList)
    {
        tdFile.read(reinterpret_cast<char *>(&tickData.instrumentId), sizeof(tickData.instrumentId));
        tdFile.read(reinterpret_cast<char *>(&tickData.updateTime), sizeof(tickData.updateTime));
        tdFile.read(reinterpret_cast<char *>(&tickData.lastPrice), sizeof(tickData.lastPrice));
        tdFile.read(reinterpret_cast<char *>(&tickData.lastSize), sizeof(tickData.lastSize));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidVolume1), sizeof(tickData.bidVolume1));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidPrice1), sizeof(tickData.bidPrice1));
        tdFile.read(reinterpret_cast<char *>(&tickData.askPrice1), sizeof(tickData.askPrice1));
        tdFile.read(reinterpret_cast<char *>(&tickData.askVolume1), sizeof(tickData.askVolume1));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidVolume2), sizeof(tickData.bidVolume2));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidPrice2), sizeof(tickData.bidPrice2));
        tdFile.read(reinterpret_cast<char *>(&tickData.askPrice2), sizeof(tickData.askPrice2));
        tdFile.read(reinterpret_cast<char *>(&tickData.askVolume2), sizeof(tickData.askVolume2));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidVolume3), sizeof(tickData.bidVolume3));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidPrice3), sizeof(tickData.bidPrice3));
        tdFile.read(reinterpret_cast<char *>(&tickData.askPrice3), sizeof(tickData.askPrice3));
        tdFile.read(reinterpret_cast<char *>(&tickData.askVolume3), sizeof(tickData.askVolume3));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidVolume4), sizeof(tickData.bidVolume4));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidPrice4), sizeof(tickData.bidPrice4));
        tdFile.read(reinterpret_cast<char *>(&tickData.askPrice4), sizeof(tickData.askPrice4));
        tdFile.read(reinterpret_cast<char *>(&tickData.askVolume4), sizeof(tickData.askVolume4));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidVolume5), sizeof(tickData.bidVolume5));
        tdFile.read(reinterpret_cast<char *>(&tickData.bidPrice5), sizeof(tickData.bidPrice5));
        tdFile.read(reinterpret_cast<char *>(&tickData.askPrice5), sizeof(tickData.askPrice5));
        tdFile.read(reinterpret_cast<char *>(&tickData.askVolume5), sizeof(tickData.askVolume5));
        tdFile.read(reinterpret_cast<char *>(&tickData.openInterest), sizeof(tickData.openInterest));
        tdFile.read(reinterpret_cast<char *>(&tickData.turnover), sizeof(tickData.turnover));
        tdFile.read(reinterpret_cast<char *>(&tickData.totalVolume), sizeof(tickData.totalVolume));
        tdFile.read(reinterpret_cast<char *>(&tickData.serverTime), sizeof(tickData.serverTime));
    }

    tdFile.close();

    std::ofstream csvFile(outputFilename);

    // Write the header
    csvFile << "InstrumentId,UpdateTime,LastPrice,LastSize,BidVolume1,BidPrice1,AskPrice1,AskVolume1,BidVolume2,BidPrice2,AskPrice2,AskVolume2,BidVolume3,BidPrice3,AskPrice3,AskVolume3,BidVolume4,BidPrice4,AskPrice4,AskVolume4,BidVolume5,BidPrice5,AskPrice5,AskVolume5,OpenInterest,Turnover,TotalVolume,ServerTime\n";

    // Write the data
    for (auto &tickData : tickDataList)
    {

        csvFile << tickData.instrumentId << ","
                << tickData.updateTime << ","
                << tickData.lastPrice << ","
                << tickData.lastSize << ","
                << tickData.bidVolume1 << ","
                << tickData.bidPrice1 << ","
                << tickData.askPrice1 << ","
                << tickData.askVolume1 << ","
                << tickData.bidVolume2 << ","
                << tickData.bidPrice2 << ","
                << tickData.askPrice2 << ","
                << tickData.askVolume2 << ","
                << tickData.bidVolume3 << ","
                << tickData.bidPrice3 << ","
                << tickData.askPrice3 << ","
                << tickData.askVolume3 << ","
                << tickData.bidVolume4 << ","
                << tickData.bidPrice4 << ","
                << tickData.askPrice4 << ","
                << tickData.askVolume4 << ","
                << tickData.bidVolume5 << ","
                << tickData.bidPrice5 << ","
                << tickData.askPrice5 << ","
                << tickData.askVolume5 << ","
                << tickData.openInterest << ","
                << tickData.turnover << ","
                << tickData.totalVolume << ","
                << tickData.serverTime << "\n";
    }

    csvFile.close();
}

time_t parseTime(const std::string &timeStr)
{
    std::istringstream ss(timeStr);
    std::tm tm;
    std::memset(&tm, 0, sizeof(tm));
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    return std::mktime(&tm);
}

std::vector<TickData> extractDataMultiThreaded(const std::string &inputFilename, time_t fromTime, time_t toTime)
{
    std::ifstream tdFile(inputFilename, ios::binary);
    if (!tdFile.is_open())
    {
        std::cout << "Failed to open .td file." << std::endl;
        return {};
    }

    tdFile.seekg(0, tdFile.end);
    int fileSize = tdFile.tellg();
    tdFile.seekg(0, tdFile.beg);
    int numTickData = fileSize / 500;
    int dataPerThread = numTickData / 10;
    vector<TickData> tickDataList;
    TickData tickData;

std::vector<std::future<std::vector<TickData>>> futures;
for (int i = 0; i < 10; ++i)
{
    futures.push_back(std::async(std::launch::async, [fromTime, toTime, dataPerThread, i,inputFilename]() {
        std::ifstream tdFile(inputFilename, std::ios::binary); // 为每个线程创建一个新的 ifstream 对象
        TickData tickData;
        std::vector<TickData> tickDataList;
        tdFile.seekg(i * dataPerThread * 500, std::ios::beg); // 设置读取的起始位置
        for (int j = 0; j < dataPerThread; ++j)
        {
            tdFile.read(reinterpret_cast<char *>(&tickData), 500);
            std::istringstream ss(tickData.updateTime);
            std::tm tm = {};
            std::memset(&tm, 0, sizeof(tm));
            ss >> std::get_time(&tm, "%Y%m%d %H:%M:%S");
            time_t tickTime = std::mktime(&tm);
            //std::cout << tickData.updateTime << std::endl;
            //std::streampos currentPos = tdFile.tellg(); // 获取当前文件指针位置
            //std::cout << i <<"  Current file pointer position: " << currentPos << std::endl;
            if (tickTime >= fromTime && tickTime <= toTime)
            {
                tickDataList.push_back(tickData);
            }
            if (tickTime > toTime)
            {
                break;
            }
        }
        return tickDataList;
    }));

        // while (tdFile.read(reinterpret_cast<char *>(&tickData), 500))
        // {
        //     // 确保字符串被正确终止
        //     // tickData.updateTime[sizeof(tickData.updateTime) - 1] = '\0';

        //     std::istringstream ss(tickData.updateTime);
        //     std::memset(&tm, 0, sizeof(tm));
        //     ss >> std::get_time(&tm, "%Y%m%d %H:%M:%S");
        //     time_t tickTime = std::mktime(&tm);
        //     // time_t tickTime = parseTime(tickData.updateTime);
        //     std::cout << tickData.updateTime << std::endl;
        //     if (tickTime >= fromTime && tickTime <= toTime)
        //     {
        //         tickDataList.push_back(tickData);
        //     }
        //     if (tickTime > toTime)
        //     {
        //         break;
        //     }
        // }
    }

    std::vector<TickData> result;
    for (auto &f : futures)
    {
        auto tickDataList = f.get();
        result.insert(result.end(), tickDataList.begin(), tickDataList.end());
    }
    tdFile.close();
    return result;
}

vector<TickData> extractData(const std::string &inputFilename, time_t fromTime, time_t toTime)
{
    vector<TickData> tickDataList;
    ifstream tdFile(inputFilename, ios::binary);

    // 检查文件是否成功打开
    if (!tdFile.is_open())
    {
        cout << "Failed to open .td file." << endl;
        return tickDataList;
    }
    tdFile.seekg(0, tdFile.end);
    int fileSize = tdFile.tellg();
    tdFile.seekg(0, tdFile.beg);
    int numTickData = fileSize / sizeof(TickData);
    TickData tickData;
    std::tm tm = {};
    while (tdFile.read(reinterpret_cast<char *>(&tickData), 500))
    {
        // 确保字符串被正确终止
        // tickData.updateTime[sizeof(tickData.updateTime) - 1] = '\0';

        std::istringstream ss(tickData.updateTime);
        std::memset(&tm, 0, sizeof(tm));
        ss >> std::get_time(&tm, "%Y%m%d %H:%M:%S");
        time_t tickTime = std::mktime(&tm);
        // time_t tickTime = parseTime(tickData.updateTime);
        //std::cout << tickData.updateTime << std::endl;
        if (tickTime >= fromTime && tickTime <= toTime)
        {
            tickDataList.push_back(tickData);
        }
        if (tickTime > toTime)
        {
            break;
        }
    }

    tdFile.close();
    return tickDataList;
}

int main(int argc, char *argv[])
{
    if (argc != 5 && argc != 7) {
        //cout<<argc<<endl;
        cout << "Usage: ./tdb -c -o <output_file> <input_file>" << endl;
        cout << "Usage: ./tdb -d -o <output_file> <input_file>" << endl;
        cout << "Usage: ./tdb -s -f <from_time> -t <to_time> <input_file>" << endl;
        return 1;
    }

    // string option = argv[1];
    // string outputFilename = argv[3];
    // string inputFilename = argv[4];
    string option = "";
    string outputFilename = "";
    string inputFilename = "";
    string fromTimeStr = "";
    string toTimeStr = "";
    if(argc ==5){
        option = argv[1];
        outputFilename = argv[3];
        inputFilename = argv[4];
    }
    else{
        option = argv[1];
        fromTimeStr = argv[3];
        toTimeStr = argv[5];
        inputFilename = argv[6];
    }
    // option = "-c";
    // outputFilename = "example.tb";
    // inputFilename = "ni2207.csv";

    // option = "-d";
    // inputFilename = "example.tb";
    // outputFilename = "example.csv";

    // string option = argv[1];
    // string fromTimeStr = argv[3];
    // string toTimeStr = argv[5];
    // string inputFilename = argv[6];
    // option = "-s";
    // fromTimeStr = "2022-06-01 09:00:00";
    // toTimeStr = "2022-06-01 10:05:21";
    // inputFilename = "example.tb";
    // outputFilename = "example.csv";
    if (option == "-c")
    {
        vector<TickData> tickDataList = parseCSV(inputFilename);
        writeTickDataToTDFile(outputFilename, tickDataList);
        cout << "Conversion completed successfully." << endl;
    }
    else if (option == "-d")
    {
        convertToCSV(inputFilename, outputFilename);
        // tdFile.read(reinterpret_cast<char *>(tickDataList.data()), fileSize);
        // tdFile.close();

        // // 将TickData数据写入CSV文件
        // writeTickDataToCSVFile(outputFilename, tickDataList);

        cout << "Conversion completed successfully." << endl;
    }
    else if (option == "-s")
    {
        time_t fromTime = parseTime(fromTimeStr);
        time_t toTime = parseTime(toTimeStr);

        // 从td文件中提取数据
        //vector<TickData> tickDataList = extractData(inputFilename, fromTime, toTime);
        vector<TickData> tickDataList = extractDataMultiThreaded(inputFilename, fromTime, toTime);
        cout << tickDataList.size() << endl;
    }
    else
    {

        cout << "Invalid option. Use -c to convert CSV to TD." << endl;
        return 1;
    }

    return 0;
}