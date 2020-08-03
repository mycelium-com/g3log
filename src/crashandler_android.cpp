/** ==========================================================================
 * 2011 by KjellKod.cc. This is PUBLIC DOMAIN to use at your own risk and comes
 * with no warranties. This code is yours to share, use and modify with no
 * strings attached and no restrictions or obligations.
 *
 * For more information see g3log/LICENSE or refer refer to http://unlicense.org
 * ============================================================================*/

#include "g3log/crashhandler.hpp"
#include "g3log/logmessage.hpp"
#include "g3log/logcapture.hpp"
#include "g3log/loglevels.hpp"

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) && !defined(__GNUC__))
#error "crashhandler_android.cpp used but it's a windows system"
#endif


#include <csignal>
#include <cstring>
#include <unistd.h>
#include <cxxabi.h>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <thread>
#include <atomic>
#include <map>
#include <mutex>

namespace g3 {
 
    namespace internal {

      bool shouldBlockForFatalHandling() {
         return true;  // For windows we will after fatal processing change it to false
      }

      std::string stackdump(const char* rawdump) {
        return std::string("");
      }

      std::string exitReasonName(const LEVELS& level, g3::SignalType fatal_id) {
        return std::string("");
      }

      void exitWithDefaultSignalHandler(const LEVELS& level, g3::SignalType fatal_signal_id) {
      }
   } // end g3::internal

   // installs the signal handling for whatever signal set that is currently active
   // If you want to setup your own signal handling then
   // You should instead call overrideSetupSignals()
   void installCrashHandler() {
   }
} // end namespace g3

