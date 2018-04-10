cmd_util-linux/blkdiscard.o := /opt/xtools/arm920t/bin/arm-linux-gcc -Wp,-MD,util-linux/.blkdiscard.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.27.1)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os     -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(blkdiscard)"  -D"KBUILD_MODNAME=KBUILD_STR(blkdiscard)" -c -o util-linux/blkdiscard.o util-linux/blkdiscard.c

deps_util-linux/blkdiscard.o := \
  util-linux/blkdiscard.c \
    $(wildcard include/config/blkdiscard.h) \
    $(wildcard include/config/feature/clean/up.h) \
  include/libbb.h \
    $(wildcard include/config/feature/shadowpasswds.h) \
    $(wildcard include/config/use/bb/shadow.h) \
    $(wildcard include/config/selinux.h) \
    $(wildcard include/config/feature/utmp.h) \
    $(wildcard include/config/locale/support.h) \
    $(wildcard include/config/use/bb/pwd/grp.h) \
    $(wildcard include/config/lfs.h) \
    $(wildcard include/config/feature/buffers/go/on/stack.h) \
    $(wildcard include/config/feature/buffers/go/in/bss.h) \
    $(wildcard include/config/feature/verbose.h) \
    $(wildcard include/config/feature/ipv6.h) \
    $(wildcard include/config/feature/seamless/xz.h) \
    $(wildcard include/config/feature/seamless/lzma.h) \
    $(wildcard include/config/feature/seamless/bz2.h) \
    $(wildcard include/config/feature/seamless/gz.h) \
    $(wildcard include/config/feature/seamless/z.h) \
    $(wildcard include/config/feature/check/names.h) \
    $(wildcard include/config/feature/prefer/applets.h) \
    $(wildcard include/config/long/opts.h) \
    $(wildcard include/config/feature/getopt/long.h) \
    $(wildcard include/config/feature/pidfile.h) \
    $(wildcard include/config/feature/syslog.h) \
    $(wildcard include/config/feature/individual.h) \
    $(wildcard include/config/echo.h) \
    $(wildcard include/config/printf.h) \
    $(wildcard include/config/test.h) \
    $(wildcard include/config/test1.h) \
    $(wildcard include/config/test2.h) \
    $(wildcard include/config/kill.h) \
    $(wildcard include/config/killall.h) \
    $(wildcard include/config/killall5.h) \
    $(wildcard include/config/chown.h) \
    $(wildcard include/config/ls.h) \
    $(wildcard include/config/xxx.h) \
    $(wildcard include/config/route.h) \
    $(wildcard include/config/feature/hwib.h) \
    $(wildcard include/config/desktop.h) \
    $(wildcard include/config/feature/crond/d.h) \
    $(wildcard include/config/feature/securetty.h) \
    $(wildcard include/config/pam.h) \
    $(wildcard include/config/use/bb/crypt.h) \
    $(wildcard include/config/feature/adduser/to/group.h) \
    $(wildcard include/config/feature/del/user/from/group.h) \
    $(wildcard include/config/ioctl/hex2str/error.h) \
    $(wildcard include/config/feature/editing.h) \
    $(wildcard include/config/feature/editing/history.h) \
    $(wildcard include/config/feature/editing/savehistory.h) \
    $(wildcard include/config/feature/tab/completion.h) \
    $(wildcard include/config/feature/username/completion.h) \
    $(wildcard include/config/feature/editing/vi.h) \
    $(wildcard include/config/feature/editing/save/on/exit.h) \
    $(wildcard include/config/pmap.h) \
    $(wildcard include/config/feature/show/threads.h) \
    $(wildcard include/config/feature/ps/additional/columns.h) \
    $(wildcard include/config/feature/topmem.h) \
    $(wildcard include/config/feature/top/smp/process.h) \
    $(wildcard include/config/pgrep.h) \
    $(wildcard include/config/pkill.h) \
    $(wildcard include/config/pidof.h) \
    $(wildcard include/config/sestatus.h) \
    $(wildcard include/config/unicode/support.h) \
    $(wildcard include/config/feature/mtab/support.h) \
    $(wildcard include/config/feature/devfs.h) \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/nommu.h) \
  /opt/xtools/arm920t/lib/gcc/arm-arm920t-linux-gnueabi/4.4.6/include-fixed/limits.h \
  /opt/xtools/arm920t/lib/gcc/arm-arm920t-linux-gnueabi/4.4.6/include-fixed/syslimits.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/limits.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/features.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/cdefs.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/wordsize.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/gnu/stubs.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/posix1_lim.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/local_lim.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/linux/limits.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/posix2_lim.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/xopen_lim.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/stdio_lim.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/byteswap.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/byteswap.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/endian.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/endian.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/stdint.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/wchar.h \
  /opt/xtools/arm920t/lib/gcc/arm-arm920t-linux-gnueabi/4.4.6/include/stdbool.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/unistd.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/posix_opt.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/environments.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/types.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/typesizes.h \
  /opt/xtools/arm920t/lib/gcc/arm-arm920t-linux-gnueabi/4.4.6/include/stddef.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/confname.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/getopt.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/unistd.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/ctype.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/xlocale.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/dirent.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/dirent.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/errno.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/errno.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/linux/errno.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/errno.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm-generic/errno.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm-generic/errno-base.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/fcntl.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/fcntl.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/types.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/time.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/select.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/select.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/sigset.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/time.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/sysmacros.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/pthreadtypes.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/uio.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/stat.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/stat.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/fcntl2.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/inttypes.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/netdb.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/netinet/in.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/socket.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/uio.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/socket.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/sockaddr.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/socket.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/sockios.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/socket2.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/in.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/rpc/netdb.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/siginfo.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/netdb.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/setjmp.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/setjmp.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/signal.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/signum.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/sigaction.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/sigcontext.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/sigcontext.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/sigstack.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/ucontext.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/procfs.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/time.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/user.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/sigthread.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/paths.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/stdio.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/libio.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/_G_config.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/wchar.h \
  /opt/xtools/arm920t/lib/gcc/arm-arm920t-linux-gnueabi/4.4.6/include/stdarg.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/sys_errlist.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/stdio2.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/stdlib.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/waitflags.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/waitstatus.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/alloca.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/stdlib.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/string.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/string3.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/libgen.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/poll.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/poll.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/poll.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/ioctl.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/ioctls.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/ioctls.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm-generic/ioctls.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/linux/ioctl.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/ioctl.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm-generic/ioctl.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/ioctl-types.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/ttydefaults.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/mman.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/mman.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/wait.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/resource.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/resource.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/termios.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/termios.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/param.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/linux/param.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/param.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/pwd.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/grp.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/mntent.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/sys/statfs.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/statfs.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/utmp.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/utmp.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/utmpx.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/bits/utmpx.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/arpa/inet.h \
  include/pwd_.h \
  include/grp_.h \
  include/shadow_.h \
  include/xatonum.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/linux/fs.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/linux/blk_types.h \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/blk/dev/integrity.h) \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/linux/types.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/types.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm-generic/int-ll64.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/bitsperlong.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/linux/posix_types.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/linux/stddef.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm/posix_types.h \
  /opt/xtools/arm920t/arm-arm920t-linux-gnueabi/sysroot/usr/include/asm-generic/posix_types.h \

util-linux/blkdiscard.o: $(deps_util-linux/blkdiscard.o)

$(deps_util-linux/blkdiscard.o):
