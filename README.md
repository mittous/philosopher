
[gif]( https://github.com/mittous/philosopher/blob/master/index.gif)
# -------/-- Philosophers 42 --/-------
# The Dining Philosophers problem

In this project, you will learn the basics of threading a process.
You will see how to create threads and processes and you will discover what Mutexes and Semaphore is.

## Deployment

To deploy this project run :

```bash
    make */ then /*
(./philo */ or /* ./philo_bonus) <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> (``*/ optionall arg is /*``)
<number_of_times_each_philosopher_must_eat>
```
to delete .o files run :
```bash
    make clean */ or /* make fclean */ or /* make re (``to recompile``)
```


## Documentation
take a look to this ressources you may find theme helpfull :

[What’s the Diff: Programs, Processes, and Threads, and how evry one of them really work ??]( https://www.backblaze.com/blog/whats-the-diff-programs-processes-and-threads/) I recommand to take a look on that one especially.

[Fork() in C Programming Language]( https://www.section.io/engineering-education/fork-in-c-programming-language/)

[Multithreaded Programming](https://pages.mtu.edu/~shene/NSF-3/e-Book/index.html) just give it a chance you gonna like it.

And ofc your friend in implementation process is "manuall page".
## About the project
### Overview
#### Here are the things you need to know if you want to succeed this assignment:
`• One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.`

`• The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.`

`• There are also forks on the table. There are as many forks as philosophers.`

`• Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.`

`• When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.`
`• Every philosopher needs to eat and should never starve.`

`• Philosophers don’t speak with each other.`

`• Philosophers don’t know if another philosopher is about to die.`

`•Each philosopher has a number ranging from 1 to number_of_philosophers.`

`•Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.`

`• No need to say that philosophers should avoid dying`

## About the logs of your program:
`•Any state change of a philosopher must be formatted as follows:`

`◦timestamp_in_ms X has taken a fork`

`◦timestamp_in_ms X is eating`

`◦timestamp_in_ms X is sleeping`

`◦timestamp_in_ms X is thinking`

`◦timestamp_in_ms X died`

`Replace timestamp_in_ms with the current timestamp in milliseconds and X with the philosopher number.`

`•A displayed state message should not be mixed up with another message.`

`•A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.`

`•Again, philosophers should avoid dying!`

## road map to follow for your Mandatory Part :


`◦First you need to know what tread is.`

`◦Then you need to know what sharing memory is`

`◦After that, you need to know what mutex is and how they work`

`◦After that, congratulation start building your routine and printing states of your philosopher <take fork> <sleeping> <eating>...`

`◦Then you need to check the death of every philosopher by checking the last time your philosopher has eaten, and that needs to be in parallel with the simulation of course,
and stop the simulation when any philosopher died.`

`◦Finally, you need to add the the last argument and stop the simullation when all philosophers have eaten at least number_of_times_each_philosopher_must_eat
If not specified, the simulation stops when a philosopher dies ofcourse.`

## road map to follow for your bonus Part :


`◦First you need to know what processes is.`

`◦After that, you need to know what Semaphore is and how they work`

`◦After that, congratulation start building your routine and printing states of your philosopher <take fork> <sleeping> <eating>...`

`Thene you need to know what Zombie Process and how that happen.`

`◦Then you need to check the death of every philosopher by checking the last time your philosopher has eaten, and that needs to be in parallel with the simulation of course,
and stop the simulation when any philosopher died.`

`◦Finally, you need to add the the last argument and stop the simullation when all philosophers have eaten at least number_of_times_each_philosopher_must_eat
If not specified, the simulation stops when a philosopher dies ofcourse.`


## functions

| function Name | Authorized                |
| :--------  | :-------------------------   |
| `• memset`              |M |
|`•printf,`               |A|
|`•malloc,`               |N|
|`•free,`                 |D|
|`•write,`                |A|
|`•usleep,`               |T|
|`•gettimeofday,`         |O|
|`•pthread_create,`       |R|
|`•pthread_detach,`       |Y|
|`•pthread_join,`         | |
|`•pthread_mutex_init,`   |P|
|`•pthread_mutex_destroy,`|A|
|`•pthread_mutex_lock,`   |R|
|`•pthread_mutex_unlock`  |T|

| function Name | Authorized                |
| :--------  | :-------------------------   |
|`•memset,`               |B|
|`•printf,`               |O|
|`•malloc,`               |N|
|`•free,`                 |U|
|`•write,`                |S|
|`•fork,`                 | |
|`•kill,`                 | |
|`•exit,`                 | |
|`•pthread_create ,`      | |
|`•pthread_detach,`       | |
|`•pthread_join,`         | |
|`•usleep,`               | |
|`•gettimeofday,`         | |
|`•waitpid,`              | |
|`•sem_open,`             | |
|`•sem_close,`            |P|
|`•sem_post,`             |A|
|`•sem_wait,`             |R|
|`•sem_unlink------------`|T|


#### you can check the man page in your iterm to know more.
