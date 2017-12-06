#include <iostream>
#include <string>

class SalesItem {
public:
    std::string Isbn() const {
        return isbn_;
    }

friend std::istream& operator>>(std::istream& in, SalesItem& item) {
    double price;
    in >> item.isbn_ >> item.sold_number_ >> price;

    if (in) {
        item.total_revenue_ = price * item.sold_number_;
    } else {
        item.isbn_ = "";
        item.total_revenue_ = 0;
        item.sold_number_ = 0;
    }
    return in;
}

friend std::ostream& operator<<(std::ostream& out, const SalesItem& item) {
    double average_price = item.total_revenue_ / std::max(item.sold_number_ , 1);
    out << item.isbn_ 
        << " " << item.sold_number_ 
        << " " << item.total_revenue_
        << " " << average_price;
    return out;
}

private:
    std::string isbn_;
    // total revenue
    double total_revenue_; 
    // number of copies sold
    int sold_number_;
};
int main() {

    SalesItem book;
    std::cin >> book;

    std::cout << book << std::endl;

    return 0;
}
