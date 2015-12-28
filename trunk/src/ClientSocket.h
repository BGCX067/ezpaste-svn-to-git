/*         Copyright © 2002, Rob Tougher.
Copying license http://www.linuxgazette.com/copying.html
  Published in Issue 74 of Linux Gazette, January 2002
*/

// Definition of the ClientSocket class

#ifndef ClientSocket_class
#define ClientSocket_class

#include "Socket.h"


class ClientSocket : private Socket
{
 public:

  ClientSocket ( std::string host, int port );
  virtual ~ClientSocket(){};

  const ClientSocket& operator << ( const std::string& ) const;
  const ClientSocket& operator >> ( std::string& ) const;

};


#endif
