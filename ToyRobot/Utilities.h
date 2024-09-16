#pragma once
#include <string>
#include <algorithm>

namespace Util
{
  // From https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
  // trim from start (in place)
  inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
  }

  // trim from end (in place)
  inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
  }

  // trim from both ends (in place)
  inline void trim(std::string &s) {
      rtrim(s);
      ltrim(s);
  }

  // From https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
  inline void toupper(std::string& s){
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return std::toupper(c);});
  }
};

