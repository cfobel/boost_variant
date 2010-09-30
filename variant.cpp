#include <string>
#include <list>
#include <iostream>
#include <boost/variant.hpp>
#include <boost/foreach.hpp>

using namespace std;
using namespace boost;

typedef variant<string, int, bool> object;

struct vis : public static_visitor<>
{
    void operator() (string s) const { 
        cout << "This is a string: " << s << endl;
    }
    void operator() (int i) const { 
        cout << "This is an int: " << i << endl;
    }

    void operator() (bool b) const {
        cout << "This is a bool: ";
        if(b) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
};

int main() 
{
    list<object> List;

    List.push_back((string)("Hello World!"));
    List.push_back(7);
    List.push_back(true);
    List.push_back(10);
    List.push_back(false);
    List.push_back(true);
    List.push_back((string)("This is another string!"));

    BOOST_FOREACH (object& o, List) {
        apply_visitor(vis(), o);
    }

    return 0;
}
