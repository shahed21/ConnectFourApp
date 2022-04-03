/**
 * @file env.h
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This function handles the environment settings for the application
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ENV_H
#define ENV_H

//#define _OS (WINDOWS)
//#define _OS (UNIX)
#define _OS (LINUX)
//#define _OS (OLD_MAC)
//#define _OS (OSX)

#define OLD_DEBUG (9)
#define NEW_DEBUG (5)
#define DEBUG (NEW_DEBUG)

#if (_OS==(WINDOWS))
#define _NEWLINE ("\r\n")
#elif ((_OS==(UNIX))||(_OS==(LINUX))||(_OS==(OSX)))
#define _NEWLINE ("\n")
#elif (_OS==(OLD_MAC))
#define _NEWLINE ("\r")
#endif /*_OS*/



#endif /*ENV_H*/