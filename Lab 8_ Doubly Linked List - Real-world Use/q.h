#ifndef Q_H
#define Q_H

#include <fstream>
#include <string>
#include "dllist.h"

namespace hlp2
{
class finder
{
public:

    using size_type = size_t;
    using container_type = dllist<size_type>;

    finder(std::string const&);

    void find(std::string const&);
    void print();

private:

    std::string search_space_filename;
    std::ifstream search_space_stream;
    std::string search_space_txt;
    std::string search_str;
    container_type pos_ls;
};
}
#endif