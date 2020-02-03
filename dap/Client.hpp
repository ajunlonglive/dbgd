#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "SocketBase.hpp"
namespace dap
{
class Client
{
    SocketBase::Ptr_t m_socket = nullptr;

public:
    Client();
    virtual ~Client();

    /**
     * @brief Wait until connection is established
     */
    void Connect(int timeoutSeconds);
};

};     // namespace dap
#endif // CLIENT_HPP