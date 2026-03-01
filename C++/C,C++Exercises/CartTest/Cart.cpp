// 购物系统:
/*
实现功能:
1.菜单
2.展示所有商品信息
3.增删商品
4.购物车功能,包括查看购物车和清空购物车
5.结算
6.退出
*/
#include <iostream>
#include <string>
#include <fstream>

class Goods
{
public:
    std::string m_Id;
    std::string m_Name;
    int m_Price;
    int m_Quantity;
};

class ShoppingSystem
{
public:
    void update_goods_quantity(const std::string &id, int quantity_change)
    {
        std::ifstream ifs("goods.txt");
        std::ofstream ofs("temp.txt");
        std::string line;
        bool found = false;

        while (std::getline(ifs, line))
        {
            size_t pos = 0;
            std::string current_id = line.substr(0, line.find(',', pos));

            if (current_id == id)
            {
                found = true;
                pos = current_id.length() + 1;

                std::string name = line.substr(pos, line.find(',', pos) - pos);
                pos += name.length() + 1;

                std::string priceStr = line.substr(pos, line.find(',', pos) - pos);
                int price = std::stoi(priceStr);
                pos += priceStr.length() + 1;

                std::string quantityStr = line.substr(pos);
                int quantity = std::stoi(quantityStr);

                quantity += quantity_change;
                if (quantity < 0)
                    quantity = 0;

                ofs << current_id << "," << name << "," << price << "," << quantity << "\n";
            }
            else
            {
                ofs << line << "\n";
            }
        }

        ifs.close();
        ofs.close();

        if (found)
        {
            std::remove("goods.txt");
            std::rename("temp.txt", "goods.txt");
        }
    }

    void clearScreen()
    {
        std::cout << "\n请按任意键继续..." << std::endl;
        system("pause");
        system("cls");
    }
    void showMenu()
    {
        std::cout << "\n===== 购物系统菜单 =====" << std::endl;
        std::cout << "1. 展示所有商品信息" << std::endl;
        std::cout << "2. 增加商品" << std::endl;
        std::cout << "3. 添加到购物车" << std::endl;
        std::cout << "4. 查看购物车" << std::endl;
        std::cout << "5. 清空购物车" << std::endl;
        std::cout << "6. 结算" << std::endl;
        std::cout << "7. 退出" << std::endl;
        std::cout << "========================" << std::endl;
    }

    void display_goods()
    {
        std::ifstream ifs("goods.txt");
        if (!ifs.is_open())
        {
            std::cerr << "商品文件不存在或无法打开!" << std::endl;
            return;
        }

        std::cout << "\n===== 商品信息 =====" << std::endl;
        std::cout << "ID\t名称\t价格\t库存" << std::endl;

        std::string line;
        while (std::getline(ifs, line))
        {
            size_t pos = 0;
            std::string id = line.substr(0, line.find(',', pos));
            pos = id.length() + 1;

            std::string name = line.substr(pos, line.find(',', pos) - pos);
            pos += name.length() + 1;

            std::string priceStr = line.substr(pos, line.find(',', pos) - pos);
            pos += priceStr.length() + 1;

            std::string quantityStr = line.substr(pos);

            std::cout << id << "\t" << name << "\t" << priceStr << "\t" << quantityStr << std::endl;
        }
        std::cout << "========================" << std::endl;
        ifs.close();
    }

    void add_goods()
    {
        std::ofstream ofs("goods.txt", std::ios::app);
        if (!ofs.is_open())
        {
            std::cerr << "无法打开商品文件!" << std::endl;
            return;
        }

        std::string id, name;
        int price, quantity;
        std::cout << "请输入商品ID: ";
        std::cin >> id;
        std::cout << "请输入商品名称: ";
        std::cin >> name;
        std::cout << "请输入商品价格: ";
        std::cin >> price;
        std::cout << "请输入商品数量: ";
        std::cin >> quantity;

        ofs << id << "," << name << "," << price << "," << quantity << "\n";
        ofs.close();
        std::cout << "商品添加成功!" << std::endl;
    }

    void add_cart()
    {
        std::string id;
        int quantity;

        std::ifstream ifs("goods.txt");
        if (!ifs.is_open())
        {
            std::cerr << "无法打开商品文件!" << std::endl;
            return;
        }

        std::cout << "请输入要添加到购物车的商品ID: ";
        std::cin >> id;

        std::string line;
        Goods good;

        while (std::getline(ifs, line))
        {
            size_t pos = 0;
            good.m_Id = line.substr(0, line.find(',', pos));

            if (good.m_Id == id)
            {
                std::cout << "请输入购买数量: ";
                std::cin >> quantity;
                pos = good.m_Id.length() + 1;

                good.m_Name = line.substr(pos, line.find(',', pos) - pos);
                pos += good.m_Name.length() + 1;

                std::string priceStr = line.substr(pos, line.find(',', pos) - pos);
                good.m_Price = std::stoi(priceStr);
                pos += priceStr.length() + 1;

                std::string quantityStr = line.substr(pos);
                good.m_Quantity = std::stoi(quantityStr);
                break;
            }
            else
            {
                std::cout << "未找到商品!" << std::endl;
                return;
            }
        }
        ifs.close();

        if (good.m_Quantity < quantity)
        {
            std::cout << "库存不足! 当前库存: " << good.m_Quantity << std::endl;
            return;
        }

        // 更新商品库存
        update_goods_quantity(id, -quantity);

        // 添加到购物车
        std::ofstream cartOfs("cart.txt", std::ios::app);
        cartOfs << id << "," << good.m_Name << "," << good.m_Price << "," << quantity << "\n";
        cartOfs.close();

        std::cout << "商品已添加到购物车!" << std::endl;
    }

    void view_cart()
    {
        std::ifstream ifs("cart.txt");
        if (!ifs.is_open())
        {
            std::cerr << "购物车为空!" << std::endl;
            return;
        }

        std::cout << "\n===== 购物车信息 =====" << std::endl;
        std::cout << "ID\t名称\t单价\t数量\t小计" << std::endl;

        std::string line;
        int total = 0;

        while (std::getline(ifs, line))
        {
            size_t pos = 0;
            std::string id = line.substr(0, line.find(',', pos));
            pos = id.length() + 1;

            std::string name = line.substr(pos, line.find(',', pos) - pos);
            pos += name.length() + 1;

            std::string priceStr = line.substr(pos, line.find(',', pos) - pos);
            int price = std::stoi(priceStr);
            pos += priceStr.length() + 1;

            std::string quantityStr = line.substr(pos);
            int quantity = std::stoi(quantityStr);

            int subtotal = price * quantity;
            total += subtotal;

            std::cout << id << "\t" << name << "\t" << price << "\t" << quantity << "\t" << subtotal << std::endl;
        }

        std::cout << "-----------------------" << std::endl;
        std::cout << "总计: " << total << std::endl;
        std::cout << "=======================" << std::endl;
        ifs.close();
    }

    void clearCart()
    {
        std::ofstream ofs("cart.txt", std::ios::trunc);
        if (!ofs.is_open())
        {
            std::cerr << "无法清空购物车!" << std::endl;
            return;
        }
        ofs.close();
        std::cout << "购物车已清空!" << std::endl;
    }

    void checkout()
    {
        std::ifstream ifs("cart.txt");
        if (!ifs.is_open() || ifs.peek() == std::ifstream::traits_type::eof())
        {
            std::cerr << "购物车为空，无法结算!" << std::endl;
            return;
        }

        // 显示购物车内容
        view_cart();

        // 确认结算
        std::string confirm;
        std::cout << "确认结算吗? (y/n): ";
        std::cin >> confirm;

        if (confirm != "y" && confirm != "Y")
        {
            std::cout << "取消结算!" << std::endl;
            return;
        }

        // 清空购物车
        clearCart();
        std::cout << "结算成功! 感谢您的购买!" << std::endl;
    }
};

int main()
{
    ShoppingSystem shoppingsystem;
    int choice;

    while (true)
    {
        shoppingsystem.showMenu();
        std::cout << "请输入您的选择: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            shoppingsystem.display_goods();
            shoppingsystem.clearScreen();
            break;
        case 2:
            shoppingsystem.add_goods();
            shoppingsystem.clearScreen();
            break;
        case 3:
            shoppingsystem.add_cart();
            shoppingsystem.clearScreen();
            break;
        case 4:
            shoppingsystem.view_cart();
            shoppingsystem.clearScreen();
            break;
        case 5:
            shoppingsystem.clearCart();
            shoppingsystem.clearScreen();
            break;
        case 6:
            shoppingsystem.checkout();
            shoppingsystem.clearScreen();
            break;
        case 7:
            std::cout << "感谢使用购物系统，再见!" << std::endl;
            system("pause");
            return 0;

        default:
            std::cout << "无效选择，请重新输入!" << std::endl;
            shoppingsystem.clearScreen();
        }
    }
    return 0;
}
