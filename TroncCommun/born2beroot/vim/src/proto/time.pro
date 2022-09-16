/* time.c */
time_T vim_time(void);
char *get_ctime(time_t thetime, int add_newline);
void f_localtime(typval_T *argvars, typval_T *rettv);
void f_reltime(typval_T *argvars, typval_T *rettv);
void f_reltimefloat(typval_T *argvars, typval_T *rettv);
void f_reltimestr(typval_T *argvars, typval_T *rettv);
void f_strftime(typval_T *argvars, typval_T *rettv);
void f_strptime(typval_T *argvars, typval_T *rettv);
long proftime_time_left(proftime_T *due, proftime_T *now);
timer_T *create_timer(long msec, int repeat);
void timer_start(timer_T *timer);
long check_due_timer(void);
void stop_timer(timer_T *timer);
int set_ref_in_timer(int copyID);
void timer_free_all(void);
void f_timer_info(typval_T *argvars, typval_T *rettv);
void f_timer_pause(typval_T *argvars, typval_T *rettv);
void f_timer_start(typval_T *argvars, typval_T *rettv);
void f_timer_stop(typval_T *argvars, typval_T *rettv);
void f_timer_stopall(typval_T *argvars, typval_T *rettv);
void time_push(void *tv_rel, void *tv_start);
void time_pop(void *tp);
void time_msg(char *mesg, void *tv_start);
time_T get8ctime(FILE *fd);
int put_time(FILE *fd, time_T the_time);
void time_to_bytes(time_T the_time, char_u *buf);
void add_time(char_u *buf, size_t buflen, time_t tt);
/* vim: set ft=c : */