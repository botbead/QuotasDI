// ---------------------------------------------------------------------------
#ifndef SimpleThreadsH
#define SimpleThreadsH
// ---------------------------------------------------------------------------
#ifdef SIMPLE_THREADS_DLL
#define SIMPLE_THREADS_DLL_PORT __declspec(dllexport)
#else
#define SIMPLE_THREADS_DLL_PORT __declspec(dllimport)
#endif

#ifndef FD_SETSIZE
#define FD_SETSIZE 2048
#endif /* FD_SETSIZE */

#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

typedef unsigned __stdcall(*THREAD_FUNC)(void *);
typedef int __stdcall(*CURDE_TIMER_FUNC)(void *);
typedef void __stdcall(*TIMER_FUNC)(OUT void *, IN void *);
typedef char PORT_TO_LISTEN[8];
typedef char PORT_LISTENED[8];

/*
 struct spin_lock {
 long a;
 };
 */

#define SPIN_LOCK volatile long

struct thread_selecting {
	unsigned long handle;
	SOCKET terminator_beginning, terminator_ending;
};

struct thread_common {
	unsigned long handle;
	void *event_loop, *event_exit;
	// spin_lock exit_lock;
	SPIN_LOCK exit_lock;
	SPIN_LOCK running_flag;
};

enum TIME_UNIT {
	second, millisecond, microsecond, nanosecond
};

struct thread_timer {
	unsigned long handle;
	void *event_exit;
	unsigned long interval;
	// -1 means forever
	long lifetime;
	TIME_UNIT time_unit;
	SPIN_LOCK quit_lock;
	TIMER_FUNC func;
	void * param_in;
	void * value_out;
};

struct terminator_param {
	PORT_TO_LISTEN port;
	SOCKET listener;
	thread_selecting *thread;
};

struct selecting_param {
	int max_fd;
	SOCKET listener;
	unsigned long thread;
	PORT_LISTENED port;
	fd_set master, read_fds;
};

struct thread_selecting2 {
	unsigned long handle;
	SOCKET terminator_beginning, terminator_ending;
	selecting_param sparam;
};

struct crude_timer_s {
	volatile bool exit_flag;
	double interval_s;
	void *timer_func_input;
	unsigned long timer_thread;
	HANDLE start_event;
	CURDE_TIMER_FUNC timer_func;
	LONGLONG freq;
};

#ifdef __cplusplus

extern "C" {
#endif

	// SIMPLE_THREADS_DLL_PORT int __stdcall init_spin_lock(spin_lock * const);
	// SIMPLE_THREADS_DLL_PORT int __stdcall lock(spin_lock * const);
	// SIMPLE_THREADS_DLL_PORT int __stdcall unlock(spin_lock * const);
	SIMPLE_THREADS_DLL_PORT void __stdcall init_spin_lock(SPIN_LOCK * const alock);
	SIMPLE_THREADS_DLL_PORT void __stdcall lock(SPIN_LOCK * const alock);
	SIMPLE_THREADS_DLL_PORT void __stdcall unlock(SPIN_LOCK * const alock);
	SIMPLE_THREADS_DLL_PORT int __stdcall init_thread_selecting(thread_selecting * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall init_thread_common(thread_common * const);
	/*
	 SIMPLE_THREADS_DLL_PORT int __stdcall init_thread_timer
	 (thread_timer * const , const unsigned long = ULONG_MAX, const long =
	 -1, const TIME_UNIT = second);
	 */
	SIMPLE_THREADS_DLL_PORT int __stdcall init_thread_timer(thread_timer * const , const unsigned long, const long,
		const TIME_UNIT);
	SIMPLE_THREADS_DLL_PORT void __stdcall print_dbg_msg_old(const char * const , const int);
	SIMPLE_THREADS_DLL_PORT int __stdcall start_thread_selecting(thread_selecting * const , const THREAD_FUNC,
		const void *);
	SIMPLE_THREADS_DLL_PORT int __stdcall setup_terminator(terminator_param * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall end_thread_selecting(thread_selecting * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall leave_thread_selecting_or_not(bool * const , const int,
		const thread_selecting * const);
	// SIMPLE_THREADS_DLL_PORT int __stdcall start_thread_timer
	// (thread_timer * const , const THREAD_FUNC, const void *);
	SIMPLE_THREADS_DLL_PORT int __stdcall start_thread_timer(thread_timer * const , const TIMER_FUNC, const void *,
		void * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall end_thread_timer(thread_timer * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall leave_thread_timer_or_not(bool * const , thread_timer * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall start_thread_common(thread_common * const , const THREAD_FUNC, const void *);
	SIMPLE_THREADS_DLL_PORT int __stdcall end_thread_common(thread_common * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall active_thread_common(thread_common * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall leave_thread_common_or_not(bool * const , thread_common * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall init_terminator_param(terminator_param * const);
	SIMPLE_THREADS_DLL_PORT bool __stdcall use_winsock_old(const int, const int);
	SIMPLE_THREADS_DLL_PORT void __stdcall drop_winsock_old();
	SIMPLE_THREADS_DLL_PORT int __stdcall tc_logic_running(bool * const , thread_common * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall is_tc_off(thread_common* const);
	SIMPLE_THREADS_DLL_PORT int __stdcall is_tc_busy(thread_common * const);
	SIMPLE_THREADS_DLL_PORT void __stdcall tc_is_ready(thread_common * const);
	SIMPLE_THREADS_DLL_PORT void __stdcall lock0(SPIN_LOCK * const);
	SIMPLE_THREADS_DLL_PORT void __stdcall lock1(SPIN_LOCK * const);
	SIMPLE_THREADS_DLL_PORT bool __stdcall use_winsock(const int, const int);
	SIMPLE_THREADS_DLL_PORT void __stdcall drop_winsock();
	SIMPLE_THREADS_DLL_PORT int __stdcall stderr_to_file(FILE* *, const char *);
	SIMPLE_THREADS_DLL_PORT void __stdcall print_err_msg(const char * const , const int = 0);
	SIMPLE_THREADS_DLL_PORT void __stdcall close_stderr(FILE*);
	SIMPLE_THREADS_DLL_PORT void * __stdcall get_in_addr(sockaddr *);
	SIMPLE_THREADS_DLL_PORT const char * __stdcall inet_ntopx(int, const void *, char *, socklen_t);
	SIMPLE_THREADS_DLL_PORT int __stdcall send_all(SOCKET, char *, int *);
	SIMPLE_THREADS_DLL_PORT int __stdcall init_thread_selecting2(thread_selecting2 * const ts2, char *port);
	SIMPLE_THREADS_DLL_PORT int __stdcall begin_thread_selecting2(thread_selecting2 * const , const THREAD_FUNC);
	SIMPLE_THREADS_DLL_PORT int __stdcall end_thread_selecting2(thread_selecting2 * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall FD_ZEROme(fd_set * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall FD_ISSETme(SOCKET, fd_set * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall FD_CLRme(SOCKET, fd_set * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall FD_SETme(SOCKET, fd_set * const);
	SIMPLE_THREADS_DLL_PORT int __stdcall generate_iocp(HANDLE *);
	SIMPLE_THREADS_DLL_PORT int __stdcall get_cpus_num(int *);
	SIMPLE_THREADS_DLL_PORT int __stdcall listening(SOCKET *, char *, HANDLE);
	SIMPLE_THREADS_DLL_PORT int __stdcall prep_crude_timer_s(crude_timer_s *, double, LONGLONG, CURDE_TIMER_FUNC,
		void *);
	SIMPLE_THREADS_DLL_PORT int __stdcall get_tick_freq(LONGLONG *);
	SIMPLE_THREADS_DLL_PORT int __stdcall get_tick_count(LONGLONG *);
	SIMPLE_THREADS_DLL_PORT int __stdcall end_crude_timer_s(crude_timer_s *);
	SIMPLE_THREADS_DLL_PORT int __stdcall begin_crude_timer_s(crude_timer_s *);
	SIMPLE_THREADS_DLL_PORT int __stdcall follow_listening_s(SOCKET, SOCKET);
	SIMPLE_THREADS_DLL_PORT int __stdcall is_tc_go_on(thread_common* const);
	SIMPLE_THREADS_DLL_PORT int __stdcall get_acptx(LPFN_ACCEPTEX *, SOCKET);
	SIMPLE_THREADS_DLL_PORT int __stdcall get_acptxaddr(LPFN_GETACCEPTEXSOCKADDRS *, SOCKET);
	SIMPLE_THREADS_DLL_PORT int __stdcall listen_in_iocp(SOCKET, HANDLE);
	SIMPLE_THREADS_DLL_PORT int __stdcall get_page_size(unsigned long *);
	SIMPLE_THREADS_DLL_PORT int __stdcall tcp_conn(SOCKET *, char *, char *);
#ifdef __cplusplus
}
#endif

#endif
