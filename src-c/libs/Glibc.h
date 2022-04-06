/* automatically created by mc from /home/gaius/GM2/graft-5.2.0/gcc-5.2.0/gcc/gm2/gm2-libs/libc.def.  */


#if !defined (_libc_H)
#   define _libc_H

#   ifdef __cplusplus
extern "C" {
#   endif
#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif

#   include "GSYSTEM.h"

#   if defined (_libc_C)
#      define EXTERN
#   else
#      define EXTERN extern
#   endif

typedef long int libc_time_t;

typedef struct libc_tm_r libc_tm;

typedef struct libc_timeb_r libc_timeb;

typedef libc_tm *libc_ptrToTM;

struct libc_tm_r {
                   int tm_sec;
                   int tm_min;
                   int tm_hour;
                   int tm_mday;
                   int tm_mon;
                   int tm_year;
                   int tm_wday;
                   int tm_yday;
                   int tm_isdst;
                   long int tm_gmtoff;
                   void *tm_zone;
                 };

struct libc_timeb_r {
                      libc_time_t time;
                      short unsigned int millitm;
                      short unsigned int timezone;
                      short unsigned int dstflag;
                    };

EXTERN int libc_write (int d, void * buf, int nbytes);
EXTERN int libc_read (int d, void * buf, int nbytes);
EXTERN int libc_system (void * a);

/*
     abort - generate a fault

     abort() first closes all open files if possible, then sends
     an IOT signal to the process.  This signal usually results
     in termination with a core dump, which may be used for
     debugging.

     It is possible for abort() to return control if is caught or
     ignored, in which case the value returned is that of the
     kill(2V) system call.
*/

EXTERN void libc_abort (void);

/*
     malloc - memory allocator.

     char *malloc(size)
     unsigned size;

     malloc() returns a pointer to a block of at least size
     bytes, which is appropriately aligned.  If size is zero,
     malloc() returns a non-NULL pointer, but this pointer should
     not be dereferenced.
*/

EXTERN void * libc_malloc (unsigned int size);

/*
     free - memory deallocator.

     free(ptr)
     char *ptr;

     free() releases a previously allocated block.  Its argument
     is a pointer to a block previously allocated by malloc,
     calloc, realloc, malloc, or memalign.
*/

EXTERN void libc_free (void * ptr);
EXTERN void * libc_realloc (void * ptr, unsigned int size);

/*
   isatty - does this descriptor refer to a terminal.
*/

EXTERN int libc_isatty (int fd);

/*
   exit - returns control to the invoking process. Result, r, is
          returned.
*/

EXTERN void libc_exit (int r);

/*
   getenv - returns the C string for the equivalent C environment
            variable.
*/

EXTERN void * libc_getenv (void * s);

/*
   getpid - returns the UNIX process identification number.
*/

EXTERN int libc_getpid (void);

/*
   dup - duplicates the file descriptor, d.
*/

EXTERN int libc_dup (int d);

/*
   close - closes the file descriptor, d.
*/

EXTERN int libc_close (int d);

/*
   open - open the file, filename with flag and mode.
*/

EXTERN int libc_open (void * filename, int oflag, ...);

/*
   creat - creates a new file
*/

EXTERN int libc_creat (void * filename, unsigned int mode);

/*
   lseek - calls unix lseek:

           off_t lseek(int fildes, off_t offset, int whence);
*/

EXTERN long int libc_lseek (int fd, long int offset, int whence);

/*
   perror - writes errno and string. (ARRAY OF CHAR is translated onto ADDRESS).
*/

EXTERN void libc_perror (char *string_, unsigned int _string_high);

/*
   readv - reads an io vector of bytes.
*/

EXTERN int libc_readv (int fd, void * v, int n);

/*
   writev - writes an io vector of bytes.
*/

EXTERN int libc_writev (int fd, void * v, int n);

/*
   getcwd - copies the absolute pathname of the
            current working directory to the array pointed to by buf,
            which is of length size.

            If the current absolute path name would require a buffer
            longer than size elements, NULL is returned, and errno is
            set to ERANGE; an application should check for this error,
            and allocate a larger buffer if necessary.
*/

EXTERN void * libc_getcwd (void * buf, int size);

/*
   chown - The  owner  of  the  file  specified  by  path or by fd is
           changed.  Only the super-user may change the  owner  of  a
           file.   The  owner  of  a file may change the group of the
           file to any group of which that owner is  a  member.   The
           super-user may change the group arbitrarily.

           If  the owner or group is specified as -1, then that ID is
           not changed.

           On success, zero is returned.  On error, -1  is  returned,
           and errno is set appropriately.
*/

EXTERN int libc_chown (void * filename, int uid, int gid);

/*
   strlen - returns the length of string, a.
*/

EXTERN int libc_strlen (void * a);

/*
   strcpy - copies string, src, into, dest.
            It returns dest.
*/

EXTERN void * libc_strcpy (void * dest, void * src);

/*
   strncpy - copies string, src, into, dest, copying at most, n, bytes.
             It returns dest.
*/

EXTERN void * libc_strncpy (void * dest, void * src, unsigned int n);

/*
   unlink - removes file and returns 0 if successful.
*/

EXTERN int libc_unlink (void * file);

/*
   memcpy - copy memory area

   SYNOPSIS

   #include <string.h>

   void *memcpy(void *dest, const void *src, size_t n);
   It returns dest.
*/

EXTERN void * libc_memcpy (void * dest, void * src, unsigned int size);

/*
   memset - fill memory with a constant byte

   SYNOPSIS

   #include <string.h>

   void *memset(void *s, int c, size_t n);
*/

EXTERN void * libc_memset (void * s, int c, unsigned int size);

/*
   memmove - copy memory areas which may overlap

   SYNOPSIS

   #include <string.h>

   void *memmove(void *dest, const void *src, size_t n);
   It returns dest.
*/

EXTERN void * libc_memmove (void * dest, void * src, unsigned int size);
EXTERN int libc_printf (char *format_, unsigned int _format_high, ...);

/*
   setenv - sets environment variable, name, to value.
            It will overwrite an existing value if, overwrite,
            is true.  It returns 0 on success and -1 for an error.
*/

EXTERN int libc_setenv (void * name, void * value, int overwrite);

/*
   srand - initialize the random number seed.
*/

EXTERN void libc_srand (int seed);

/*
   rand - return a random integer.
*/

EXTERN int libc_rand (void);

/*
   time - returns a pointer to the time_t value. If, a,
          is not NIL then the libc value is copied into
          memory at address, a.
*/

EXTERN libc_time_t libc_time (void * a);

/*
   localtime - returns a pointer to the libc copy of the tm
               structure.
*/

EXTERN void * libc_localtime (libc_time_t *t);

/*
   ftime - return date and time.
*/

EXTERN int libc_ftime (libc_timeb *t);

/*
   shutdown - shutdown a socket, s.
              if how = 0, then no more reads are allowed.
              if how = 1, then no more writes are allowed.
              if how = 2, then mo more reads or writes are allowed.
*/

EXTERN int libc_shutdown (int s, int how);

/*
   rename - change the name or location of a file
*/

EXTERN int libc_rename (void * oldpath, void * newpath);

/*
   setjmp - returns 0 if returning directly, and non-zero
            when returning from longjmp using the saved
            context.
*/

EXTERN int libc_setjmp (void * env);

/*
   longjmp - restores the environment saved by the last call
             of setjmp with the corresponding env argument.
             After longjmp is completed, program execution
             continues as if the corresponding call of setjmp
             had just returned the value val.  The value of
             val must not be zero.
*/

EXTERN void libc_longjmp (void * env, int val);

/*
   atexit - execute, proc, when the function exit is called.
*/

EXTERN void libc_atexit (PROC proc);

/*
   ttyname - returns a pointer to a string determining the ttyname.
*/

EXTERN void * libc_ttyname (int filedes);

/*
   sleep - calling thread sleeps for seconds.
*/

EXTERN unsigned int libc_sleep (unsigned int seconds);
#   ifdef __cplusplus
}
#   endif

#   undef EXTERN
#endif
