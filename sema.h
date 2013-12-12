/* Implementing P(s) and V(s) using UNIX semaphores.
 *
 * exit (1):	error calling fork ()
 * exit (2):	error calling semget ()
 * exit (3):	error calling semctl ()
 * exit (4):	error calling semop ()
 *
 * "union semun" isn't declared using SunOS or Linux 2.2.x and above.
 * Starting with Linux 2.2.x the macro _SEM_SEMUN_UNDEFINED must be
 * checked to determine if Linux knows about the union. Up to Linux
 * 2.0.x "semctl" needs all four paramters (even then when the last
 * parameter isn't used, e.g. using IPC_RMID).
 *
 * gcc [-DSunOS] [-DLinux] -o sema_pv sema_pv.c
 *
 * File: sema_pv.c			Author: S. Gross
 * Date: 18.01.2001
 *
 */

/* starting with Linux 2.2.x the macro "_SVID_SOURCE" must be defined
 * for "System V IPC"
 */
#ifdef Linux
  #define _SVID_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define SEM_KEY	      IPC_PRIVATE	/* create private semaphore	*/
#define SEM_PERM      0600		/* access permissions		*/

typedef int	semaphore;		/* semaphore (handle) type	*/
#if (_SEM_SEMUN_UNDEFINED == 1) || defined(SunOS)
  typedef union semun
    {
      int		val;		/* cmd: SETVAL			*/
      struct semid_ds	*buf;		/* cmd: IPC_STAT, IPC_SET	*/
      ushort		*array;		/* cmd: GETALL, SETALL		*/
    } semunion;
#endif

/* Create and initialize a semaphore set with one semphore. The
 * semaphore has index 0.
 *
 * input parameter:	value		initial value for semaphore
 * output parameter:	none
 * return value:	semaphore handle
 * side effects:	none
 *
 */
semaphore init_sem (int value)
{
  union semun arg;			/* parameter for semctl		*/
  int	      semid;			/* semaphore handle		*/

  semid = semget (SEM_KEY, 1, IPC_CREAT | SEM_PERM);
  if (semid == -1)
  {
    perror ("init_sem: semget failed");
    exit (2);
  };
  arg.val = value;
  if (semctl (semid, 0, SETVAL, arg) == -1)
  {
    perror ("init_sem: semctl failed");
    exit (3);
  };
  return semid;
}


/* Release a semaphore set.
 *
 * input parameter:	sem	semaphore handle
 * output parameter:	none
 * return value:	none
 * side effects:	none
 *
 */
void rel_sem (semaphore sem)
{
  union semun tmp;			/* for Linux up to 2.0.x	*/

  if (semctl (sem, 0, IPC_RMID, tmp) == -1)
  {
    perror ("rel_sem: semctl failed");
    exit (3);
  };  
}


/* P() operation for a semaphore set with one semaphore.
 *
 * input parameter:	sem	semaphore handle
 * output parameter:	none
 * return value:	none
 * side effects:	none
 *
 */
void P (semaphore sem)
{
  struct sembuf tmp;

  tmp.sem_num = 0;
  tmp.sem_op  = -1;
  tmp.sem_flg = 0;
  if (semop (sem, &tmp,  (size_t) 1) == -1)
  {
    perror ("P: semop failed");
    exit (4);
  };
}


/* V() operation for a semaphore set with one semaphore.
 *
 * input parameter:	sem	semaphore handle
 * output parameter:	none
 * return value:	none
 * side effects:	none
 *
 */
void V (semaphore sem)
{
  struct sembuf tmp;

  tmp.sem_num = 0;
  tmp.sem_op  = 1;
  tmp.sem_flg = 0;
  if (semop (sem, &tmp,  (size_t) 1) == -1)
  {
    perror ("V: semop failed");
    exit (4);
  };
}
