//时间居然击败了100%，剪枝果然有用
 class Solution {
 public:
     bool wordPatternMatch(string pattern, string s) {
         if (pattern.size() > s.size()) return false;
         return match(pattern, s, 0, 0);
     }
     bool match(string pattern, string s, int cidx, int stridx)
     {
         if (cidx == pattern.size())
         {
             return stridx == s.size();
         }
         if (cstr.find(pattern[cidx]) != cstr.end())
         {
             string p = cstr[pattern[cidx]];
             int n = p.size();
             if (p == s.substr(stridx, n)) return match(pattern, s, cidx + 1, stridx + n);
             else return false;
         }
         else
         {
             //保证剩余的字符串一对一足以匹配pattern剩余的字符
             // 由于size是无符号数，如果会减到-1一定要转换成int来比较，否则会变成一个很大的数字！
             for (int len = 1; (int)s.size() - (len + stridx) >= (int)pattern.size() - cidx - 1; len++)
             {
                 string str = s.substr(stridx, len);
                 if (strc.find(str) == strc.end())
                 {
                     cstr[pattern[cidx]] = str;
                     strc[str] = pattern[cidx];
                     if (match(pattern, s, cidx + 1, stridx + len)) return true;
                     cstr.erase(pattern[cidx]);
                     strc.erase(str);
                 }           
             }
         }
         return false;
     }
 private:
     unordered_map<char, string> cstr;
     unordered_map<string, char> strc;
 };