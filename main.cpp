#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>

std::string money = getenv("HOME")+std::string("/.moneymanager");
std::string moneylog = money+".log";

int get() {
    std::ifstream a(money);
    if(!a.is_open()){ std::ofstream b(money); b << 0; b.close(); }
    a.close();
    std::ifstream c(money);
    std::string d;
    c >> d;
    c.close();
    return atoi(d.c_str());
}
void addm(int a){
    int x = get();
    std::ofstream o(money);
    o << ( x + a );
    std::fstream lgo(moneylog, std::ios::app);
    if ( a > 0 ) {
        lgo << time(0) << " " << "a+" << " " << a << std::endl;
    } else {
        lgo << time(0) << " " << "i-" << " " << -a << std::endl;
    }
    lgo.close();
}
void getlog(int logs) {
    int xx = 0;
    std::vector<std::string> lines;
    std::string tmpline;
    std::cout << std::endl;
    std::ifstream istr(moneylog);
    if(!istr.is_open()) { istr.close(); return; }
    while(getline(istr, tmpline)) { lines.push_back(tmpline); }
    std::vector<std::string> linesr;
    for(auto i = lines.rbegin(); i != lines.rend();++i) { linesr.push_back(*i); }
    for(const auto& i: linesr){
        std::stringstream xxx(i);
        std::string time_a;
        xxx >> time_a;
        long int time_aa = atol(time_a.c_str());
        struct tm* time_b = localtime(&time_aa);
        std::cout << 1900 + time_b -> tm_year << "年 " << 1 + time_b -> tm_mon << "月 " << time_b -> tm_mday << "日 ";
        std::string rdt;
        xxx >> rdt;
        if ( rdt == "a+" ) { std::cout << "
    }
}
int main() {
    std::cout << "\033[34m欢迎来到记账程序！\033[0m" << std::endl;
    while(1){
        std::cout << "\033[35m选择如下: \n1. 查看零花钱  2. 增加零花钱\n3. 消费零花钱  4. 查看明细\n5. 退出程序\033[0m" << std::endl;
        std::cout << "输入选项: ";
        std::string a;
        std::cin >> a;
        int choice = atoi(a.c_str());
        switch(choice){
            case 1:
                std::cout << "\033[36m零花钱为: " << get() << "元\033[0m" << std::endl;
                break;
            case 2: 
                std::cout << "\033[36m增加零花钱(元): \033[0m";
                int add2; std::cin >> add2;
                addm(add2);
                std::cout << "\033[36m增加成功\033[0m" << std::endl;
                break;
            case 3: 
                std::cout << "\033[36m消费零花钱(元): \033[0m";
                int add; std::cin >> add;
                if(add > get()) { std::cout << "\033[31m零花钱不足\033[0m" << std::endl; break; }
                addm(-add);
                std::cout << "\033[36m消费成功\033[0m" << std::endl;
                break;
            case 4:
                std::cout << "\033[36m查看近几条明细: \033[0m";
                int logs; std::cin >> logs;
                getlog(logs);
                break;
            case 5:
                break;
            default:
                std::cout << "\033[31m未知选项\033[0m" << std::endl;
        }
        if(choice == 5) break;
        std::cout << std::endl;
    }
}
