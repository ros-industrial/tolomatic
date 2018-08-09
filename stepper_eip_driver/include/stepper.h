/**
*/

#ifndef EIP_DRIVER_H
#define EIP_DRIVER_H

#include <gtest/gtest_prod.h>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "odva_ethernetip/session.h"
#include "odva_ethernetip/socket/socket.h"

using std::vector;
using boost::shared_ptr;
using eip::Session;
using eip::socket::Socket;

#define DEG2RAD(a) (a * M_PI / 180)
#define RAD2DEG(a) (a * 180 / M_PI)

namespace stepper_eip_driver {


/**
 * Main interface for the Tolomatic stepper controller. 
 * Produces methods to access the
 * laser scanner from a high level, including setting parameters and getting
 * single scans.
 */
class STEPPER : public Session
{
public:
  /**
   * Construct a new OS32C instance.
   * @param socket Socket instance to use for communication with the lidar
   */
  STEPPER(shared_ptr<Socket> socket, shared_ptr<Socket> io_socket)
    : Session(socket, io_socket, 1230, 967628086), connection_num_(1), mrc_sequence_num_(2)
  {
  }


  void startUDPIO();

private:
  // allow unit tests to access the helpers below for direct testing

  // data for sending to stepper controller to keep UDP session alive
  int connection_num_;
  EIP_UDINT mrc_sequence_num_;

};

} // namespace eip_driver

#endif  // EIP_DRIVER_H
