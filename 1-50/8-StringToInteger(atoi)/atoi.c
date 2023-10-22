#include <limits.h>
#include <stdbool.h>

static bool inBounds(long long int num, bool isPos) {
  if (isPos) {
    return num <= INT_MAX;
  } return -num >= INT_MIN;
}

int myAtoi(char * s) {
  int i, res = 0;
  long long int res_ll = 0;
  bool m_isSpace = true, m_isPos = true, m_inBounds = true;

  for (i = 0; s[i] != '\0'; ++i) {
    if ((s[i] == ' ') && !m_isSpace) {
      break;
    } else if ((s[i] >= '0') && (s[i] <= '9')) {
      m_isSpace = false;
      res_ll = 10 * res_ll + (s[i] - '0');
      if (!inBounds(res_ll, m_isPos)) {
        m_inBounds = false;
        break;
      }
    } else if (m_isSpace && (s[i] == '-')) {
      m_isSpace = false;
      m_isPos = false;
    } else if (m_isSpace && (s[i] == '+')) {
      m_isSpace = false;
    } else if (m_isSpace) {
      if (s[i] != ' ') {
        break;
      }
    } else {
      break;
    }
  }

  if (!m_inBounds) return m_isPos ? INT_MAX : INT_MIN;

  res = m_isPos ? ((int) res_ll) : ((int) -res_ll);
  return res;
}
