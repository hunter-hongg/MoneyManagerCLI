#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::string money = getenv("HOME")+std::string("/.moneymanager");

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
}
int main() {
    std::cout << "\033[34m欢迎来到记账程序！\033[0m" << std::endl;
    while(1){
        std::cout << "\033[35m选择如下: \n1. 查看零花钱  2. 增加零花钱\n3. 消费零花钱  4.\n5. 退出程序\033[0m" << std::endl;
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
            case 5:
                break;
            default:
                std::cout << "\033[31m未知选项\033[0m" << std::endl;
        }
        if(choice == 5) break;
        std::cout << std::endl;
    }
}
