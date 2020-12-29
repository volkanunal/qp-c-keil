#include "qpc.h"

Q_DEFINE_THIS_FILE

QXThread blinky;  /* QXK extended-thread object */

uint32_t stack_blinky[80]; /* stack for the thread */

void main_blinky(QXThread * const me) { /* thread function */
    while (1) {
        . . .
    }
}

int main() {
    . . .
    /* instantiate and start blinky thread */
    QXThread_ctor(&blinky, &main_blinky, 0); /* <=== ctor */
    QXTHREAD_START(&blinky,
                   5U, /* priority */
                   (void *)0, 0, /* message queue (not used) */
                   stack_blinky, sizeof(stack_blinky), /* stack */
                   (void *)0); /* extra parameter (not used) */
    . . .
    return QF_run(); /* run the application */
}
