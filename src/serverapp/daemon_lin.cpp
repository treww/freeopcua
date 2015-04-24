/// @author Alexander Rykovanov 2013
/// @email rykovanov.as@gmail.com
/// @brief Daemon class.
/// @license GNU GPL
///
/// Distributed under the GNU GPL License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/gpl.html)
///

#include "daemon.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

#include <mutex>
#include <condition_variable>
#include <iostream>
#include <signal.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

namespace
{

  OpcUa::Daemon* DaemonInstance = 0;

  void TerminateSignal(int signum)
  {
    std::cout << "terminating.." << std::endl;
    if (DaemonInstance)
    {
      DaemonInstance->Terminate();
      DaemonInstance = nullptr;
    }
  }

}

namespace OpcUa
{
  void Daemon::SetTerminateHandlers()
  {
    std::cout << "Setting terminal handlers." << std::endl;
    if (signal(SIGTERM, TerminateSignal) == SIG_ERR)
    {
      perror("unable to set SIGTERM handler");
    }
    if (signal(SIGINT, TerminateSignal) == SIG_ERR)
    {
      perror("unable to set SIGINT handler");
    }
    if (signal(SIGSTOP, TerminateSignal) == SIG_ERR)
    {
      perror("unable to set SIGSTOP handler");
    }
    DaemonInstance = this;
  }

  void Daemon::CreatePidFile(const char* file)
  {
    if (!file || !file[0])
      return;

    std::cout << "PidFile '" << file << "'" << std::endl;
    Pidfd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0666);
    if (Pidfd < 0)
    {
      perror("Failed to create pid file");
      exit(EXIT_FAILURE);
    }
    char buf[32] = {0};
    sprintf(buf, "%d", getpid());
    if (write(Pidfd, buf, strlen(buf)) < 0)
    {
      perror("Failed to write process id to file");
      exit(EXIT_FAILURE);
    }
  }

  void Daemon::CreateLogFile(const char* file)
  {
    if (!file || !file[0])
      return;

    std::cout << "LogFile '" << file << "'" << std::endl;
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    Logfd = open(file, O_WRONLY | O_CREAT, 0666);
    if (Logfd < 0)
      exit(EXIT_FAILURE);

    dup2(Logfd, STDOUT_FILENO);
    dup2(Logfd, STDERR_FILENO);
  }

  void Daemon::Daemonize()
  {
    pid_t pid, sid;
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    SetTerminateHandlers();

    std::cout << "Daemonize..." << std::endl;
    pid = fork();
    if (pid < 0)
      exit(EXIT_FAILURE);
    if (pid > 0)
      exit(EXIT_SUCCESS);

    sid = setsid();
    if (sid < 0)
      exit(EXIT_FAILURE);

    pid = fork();
    if (pid < 0)
      exit(EXIT_FAILURE);
    if (pid > 0)
      exit(EXIT_SUCCESS);
    
    if (chdir("/") < 0)
      exit(EXIT_FAILURE);
  }
}

