/*         Copyright © 2002, Rob Tougher.
Copying license http://www.linuxgazette.com/copying.html
  Published in Issue 74 of Linux Gazette, January 2002
*/

// SocketException class


#ifndef SocketException_class
#define SocketException_class

#include <string>

class SocketException
{
 public:
  SocketException ( std::string s ) : m_s ( s ) {};
  ~SocketException (){};

  std::string description() { return m_s; }

 private:

  std::string m_s;

};

#endif
