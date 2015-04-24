/// @author Alexander Rykovanov 2013
/// @email rykovanov.as@gmail.com
/// @brief Daemon class.
/// @license GNU GPL
///
/// Distributed under the GNU GPL License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/gpl.html)
///

#include <opc/common/class_pointers.h>
#include <mutex>
#include <condition_variable>

namespace OpcUa
{

  class Daemon
  {
  public:
    DEFINE_CLASS_POINTERS(Daemon);

  public:
    Daemon();
    ~Daemon();


    /// Set log file should be used to trace messages.
    /// If this file is specified this tile will replace stdou and stderr
    void CreateLogFile(const char* file);
   

    /// @param pidFile file with pid of current process.
    /// if empty it will not be created.
    void CreatePidFile(const char* file);

    void Daemonize();
    void WaitForTerminate();

    void Terminate();

    void SetTerminateHandlers();

  private:
    int Pidfd = -1;
    int Logfd = -1;
    std::mutex Mutex;
    std::condition_variable ExitEvent;
    volatile bool Terminating = false;
  };

} // namespace OpcUa

