/*********************************************************************************
 *      Copyright:  (C) 2018 Wang Tao
 *                  All rights reserved.
 *
 *       Filename:  system.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2018年05月12日)
 *         Author:  wang tao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "2018年05月12日 21时09分21秒"
 *                 
 ********************************************************************************/
#include <stdlib.h>

/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
    /* fork+exec */
    system("ifconfig eth0");
    return 0;
} /* ----- End of main() ----- */

