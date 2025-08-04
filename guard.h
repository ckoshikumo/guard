#ifndef INCLUDE_GUARD_H
#define INCLUDE_GUARD_H

#include <errno.h>
#include <stdlib.h>

#define guard(a, msg, ...)                                                     \
	if (!(a)) {                                                                \
		rec_error(msg __VA_OPT__(, ) __VA_ARGS__);                             \
		errno = 0;                                                             \
		goto error;                                                            \
	}

#define guard_debug(a, msg, ...)                                               \
	if (!(a)) {                                                                \
		rec_debug(msg __VA_OPT__(, ) __VA_ARGS__);                             \
		errno = 0;                                                             \
		goto error;                                                            \
	}

#define guard_log(a, msg, ...)                                                 \
	if (!(a)) {                                                                \
		rec_log(msg __VA_OPT__(, ) __VA_ARGS__);                               \
		errno = 0;                                                             \
	}

#define guard_log_err(a, msg, ...)                                             \
	if (!(a)) {                                                                \
		rec_log(msg __VA_OPT__(, ) __VA_ARGS__);                               \
		errno = 0;                                                             \
		goto error;                                                            \
	}

#define guard_mem(a)                                                           \
	if (!(a)) {                                                                \
		rec_error("Memory error");                                             \
		exit(EXIT_FAILURE);                                                    \
	}

#define guard_exit(a, msg, ...)                                                \
	if (!(a)) {                                                                \
		rec_error(msg __VA_OPT__(, ) __VA_ARGS__);                             \
		exit(EXIT_FAILURE);                                                    \
	}

#define guard_sentinel(msg, ...)                                               \
	{                                                                          \
		rec_error(msg __VA_OPT__(, ) __VA_ARGS__);                             \
		errno = 0;                                                             \
		goto error;                                                            \
	}

#endif // INCLUDE_GUARD_H
