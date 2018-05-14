/*********************************************************************************
 *      Copyright:  (C) 2012 Guo Wenxue<guowenxue@gmail.com>  
 *                  All rights reserved.
 *
 *       Filename:  cp_proc.c
 *    Description:  This file is the process API
 *                 
 *        Version:  1.0.0(11/06/2012~)
 *         Author:  Guo Wenxue <guowenxue@gmail.com>
 *      ChangeLog:  1, Release initial version on "11/06/2012 09:19:02 PM"
 *                 
 ********************************************************************************/ 
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
 
#include "cp_proc.h"
#include "cp_logger.h"
 
CP_PROC_SIG     g_cp_signal={0};
 
void cp_proc_sighandler(int sig)
{
    switch(sig)
    {
        case SIGINT:
            log_warn("SIGINT - stopping\n");
            g_cp_signal.stop = 1;
            break;
 
        case SIGTERM:
            //log_warn("SIGTERM - stopping\n");
            g_cp_signal.stop = 1;
            break;
#if 0
        case SIGSEGV:
            log_err("SIGSEGV - stopping\n");
            if(g_cp_signal.stop)
                exit(0);
 
            g_cp_signal.stop = 1;
            break;
#endif
 
        case SIGPIPE:
            log_warn("SIGPIPE - warnning\n");
            g_cp_signal.stop = 1;
            break;
    
        default:
            break;
    }
}
 
 
void cp_install_proc_signal(void)
{
    struct sigaction sigact, sigign;
 
    log_nrml("Install default signal handler.\n");
 
    /*  Initialize the catch signal structure. */
    sigemptyset(&sigact.sa_mask);  //将该信号清零
    sigact.sa_flags = 0;
    sigact.sa_handler = cp_proc_sighandler;
 
    /*  Setup the ignore signal. */
    sigemptyset(&sigign.sa_mask);
    sigign.sa_flags = 0;
    sigign.sa_handler = SIG_IGN;
 
    sigaction(SIGTERM, &sigact, 0); /*  catch terminate signal "kill" command */
    sigaction(SIGINT,  &sigact, 0); /*  catch interrupt signal CTRL+C */
    //sigaction(SIGSEGV, &sigact, 0); /*  catch segmentation faults  */
    sigaction(SIGPIPE, &sigact, 0); /*  catch broken pipe */
#if 0
    sigaction(SIGCHLD, &sigact, 0); /*  catch child process return */
    sigaction(SIGUSR2, &sigact, 0); /*  catch USER signal */ 
#endif
}
 
 
/* ****************************************************************************
 * FunctionName: daemonize
 * Description : Set the programe runs as daemon in background
 * Inputs      : nodir: DON'T change the work directory to / :  1:NoChange 0:Change
 *               noclose: close the opened file descrtipion or not 1:Noclose 0:Close
 * Output      : NONE
 * Return      : NONE
 * *****************************************************************************/
void daemonize(int nochdir, int noclose)
{ 
    int retval, fd; 
    int i; 
    
    /*  already a daemon */ 
    if (1 == getppid()) 
        return; 
    
    /*  fork error */
    retval = fork(); 
    if (retval < 0) exit(1); 
    
    /*  parent process exit */
    if (retval > 0)
        exit(0); 
    
    /*  obtain a new process session group */
    setsid(); 
    
    if (!noclose)
    {
        /*  close all descriptors */
        for (i = getdtablesize(); i >= 0; --i)
        {
            //if (i != g_logPtr->fd)
                close(i);
        } 
 
        /*  Redirect Standard input [0] to /dev/null */
        fd = open("/dev/null", O_RDWR); 
 
        /* Redirect Standard output [1] to /dev/null */
        dup(fd);  
 
        /* Redirect Standard error [2] to /dev/null */
        dup(fd);  
    } 
    
    umask(0); 
    
    if (!nochdir)
        chdir("/"); 
    
    return;
}
 
/* ****************************************************************************
 * FunctionName: record_daemon_pid
 * Description : Record the running daemon program PID to the file "pid_file"
 * Inputs      : pid_file:The record PID file path
 * Output      : NONE
 * Return      : 0: Record successfully  Else: Failure
 * *****************************************************************************/
int record_daemon_pid(const char *pid_file)
{ 
    struct stat fStatBuf; 
    int fd = -1; 
    int mode = S_IROTH | S_IXOTH | S_IRGRP | S_IXGRP | S_IRWXU;
    char ipc_dir[64] = { 0 }; 
    
    strncpy(ipc_dir, pid_file, 64); 
 
    /* dirname() will modify ipc_dir and save the result */ 
    dirname(ipc_dir);  
    
    /* If folder pid_file PATH doesnot exist, then we will create it" */
    if (stat(ipc_dir, &fStatBuf) < 0) 
    { 
        if (mkdir(ipc_dir, mode) < 0) 
        { 
            log_fatal("cannot create %s: %s\n", ipc_dir, strerror(errno)); 
            return -1; 
        } 
        
        (void)chmod(ipc_dir, mode); 
    } 
    
    /*  Create the process running PID file */ 
    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    if ((fd = open(pid_file, O_RDWR | O_CREAT | O_TRUNC, mode)) >= 0)
    {
        char pid[PID_ASCII_SIZE]; 
        snprintf(pid, sizeof(pid), "%u\n", (unsigned)getpid()); //把一个整数格式化为一个字符串
        write(fd, pid, strlen(pid)); 
        close(fd); 
 
        log_dbg("Record PID<%u> to file %s.\n", getpid(), pid_file);
    } 
    else 
    {
        log_fatal("cannot create %s: %s\n", pid_file, strerror(errno));
        return -1;
    }
 
    return 0;
}
 
/* ****************************************************************************
 * FunctionName: get_daemon_pid
 * Description : Get the daemon process PID from the PID record file "pid_file"
 * Inputs      : pid_file: the PID record file
 * Output      : NONE
 * Return      : pid_t: The daemon process PID number
 * *****************************************************************************/
pid_t get_daemon_pid(const char *pid_file)
{ 
    FILE *f; 
    pid_t pid; 
    
    if ((f = fopen(pid_file, "rb")) != NULL)
    { 
        char pid_ascii[PID_ASCII_SIZE]; 
        (void)fgets(pid_ascii, PID_ASCII_SIZE, f); 
        (void)fclose(f); 
        pid = atoi(pid_ascii); 
    } 
    else
    {
        log_fatal("Can't open PID record file %s: %s\n", pid_file, strerror(errno));
        return -1;
    } 
    return pid;
}     
 
/* ****************************************************************************
 * FunctionName: check_daemon_running
 * Description : Check the daemon program already running or not
 * Inputs      : pid_file: The record running daemon program PID
 * Output      : NONE
 * Return      : 1: The daemon program alread running   0: Not running
 * *****************************************************************************/
int check_daemon_running(const char *pid_file)
{
    int retVal = -1; 
    struct stat fStatBuf;
 
    retVal = stat(pid_file, &fStatBuf); 
    if (0 == retVal) 
    { 
        pid_t pid = -1; 
        printf("PID record file \"%s\" exist.\n", pid_file);
 
        pid = get_daemon_pid(pid_file);
        if (pid > 0)  /*  Process pid exist */
        { 
            if ((retVal = kill(pid, 0)) == 0) //给pid这个进程发0信号，返回值为0表明该进程正在运行
            { 
                printf("Program with PID[%d] seems running.\n", pid); 
                return 1; 
            } 
            else   /* Send signal to the old process get no reply. */ 
            { 
                printf("Program with PID[%d] seems exit.\n", pid); 
                remove(pid_file); 
                return 0; 
            } 
        } 
        else if (0 == pid) 
        { 
            printf("Can not read program PID form record file.\n"); 
            remove(pid_file); 
            return 0; 
        } 
        else  /* Read pid from file "pid_file" failure */
        { 
            printf("Read record file \"%s\" failure, maybe program still running.\n", pid_file); 
            return 1; 
        } 
    } 
    
    return 0;
}
 
/* ****************************************************************************
 * FunctionName: set_daemon_running
 * Description : Set the programe running as daemon if it's not running and record 
 *               its PID to the pid_file.
 * Inputs      : pid_file: The record running daemon program PID
 * Output      : NONE
 * Return      : 0: Successfully. 1: Failure
 * *****************************************************************************/
int set_daemon_running(const char *pid_file)
{ 
    daemonize(0, 1); 
    log_nrml("Program running as daemon [PID:%d].\n", getpid()); 
    
    if (record_daemon_pid(pid_file) < 0) 
    { 
        log_fatal("Record PID to file \"%s\" failure.\n", pid_file); 
        return -2;
    }
 
    return 0;
}
 
 
int thread_start(pthread_t * thread_id, THREAD_BODY * thread_workbody, void *thread_arg)
{
    int        retval = 0;
 
    pthread_attr_t thread_attr; 
 
    /* Initialize the thread  attribute */
    retval = pthread_attr_init(&thread_attr); 
    if(retval)
        return -1;
 
    /* Set the stack size of the thread */
    retval = pthread_attr_setstacksize(&thread_attr, 120 * 1024); 
    if(retval)
        goto CleanUp;
    
    /* Set thread to detached state:Don`t need pthread_join */
    retval = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED); 
    if(retval)
        goto CleanUp;
    
    /* Create the thread */
    retval = pthread_create(thread_id, &thread_attr, thread_workbody, thread_arg);
    if(retval)
        goto CleanUp;
    
CleanUp:
    /* Destroy the  attributes  of  thread */
    pthread_attr_destroy(&thread_attr); 
    return retval;
}
 
 
void exec_system_cmd(const char *format, ...)
{
    char                cmd[256];
    va_list             args;
    int                 done; 
    
    memset(cmd, 0, sizeof(cmd)); 
    
    va_start(args, format); 
    done = vsnprintf(cmd, sizeof(cmd), format, args);
    va_end(args); 
    
    system(cmd);
}
