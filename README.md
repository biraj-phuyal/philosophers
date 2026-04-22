*This project has been created as part of the 42 curriculum by biphuyal.*

# Philosophers

## Description

`philosophers` is the 42 concurrency project based on the classic Dining Philosophers problem.
The goal is to learn how to manage threads, mutexes, shared state, timing, and race conditions in C.

This repository currently contains the mandatory `philo` part. Each philosopher runs in its own thread, competes for two forks protected by mutexes, and cycles through eating, sleeping, and thinking until one philosopher dies or all philosophers have eaten the required number of meals.

The project focuses on:

- thread creation and synchronization with `pthread`
- avoiding data races on shared state
- handling timing precisely enough for the simulation rules
- preventing deadlocks with a consistent fork acquisition strategy
- monitoring philosopher death and optional meal completion

## Instructions

### Requirements

- `cc`
- `make`
- POSIX threads (`pthread`)

### Compilation

From the repository root:

```bash
cd philo && make
```

This builds the executable `philo/philo`.

Useful make targets:

- `make` : build the program
- `make clean` : remove object files
- `make fclean` : remove object files and the executable
- `make re` : rebuild from scratch
- `make val` : rebuild and run under `valgrind`
- `make test` : run the community tester configured in the Makefile

### Execution

Run the program from the `philo/` directory:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Arguments must be positive integers.

Example:

```bash
./philo 5 800 200 200
./philo 5 800 200 200 7
```

Parameter meaning:

- `number_of_philosophers` : total number of philosophers and forks
- `time_to_die` : max time in ms without eating before a philosopher dies
- `time_to_eat` : time in ms spent eating
- `time_to_sleep` : time in ms spent sleeping
- `number_of_times_each_philosopher_must_eat` : optional stop condition

### Output

The program prints timestamped state changes such as:

- `has taken a fork`
- `is eating`
- `is sleeping`
- `is thinking`
- `died`

## Resources

Classic references people commonly use for this project:

- The Dining Philosophers problem overview:
  `https://en.wikipedia.org/wiki/Dining_philosophers_problem`
- POSIX threads manual pages:
  `https://man7.org/linux/man-pages/man7/pthreads.7.html`
- `pthread_create(3)`:
  `https://man7.org/linux/man-pages/man3/pthread_create.3.html`
- `pthread_mutex_lock(3p)`:
  `https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html`
- `gettimeofday(2)`:
  `https://man7.org/linux/man-pages/man2/gettimeofday.2.html`
- Beej's Guide to C programming and systems basics:
  `https://beej.us/guide/`

### AI Usage

AI was used as a support tool for documentation work in this repository.

- drafting and polishing this `README.md`
- helping organize the project explanation, build instructions, and resource list
- not used to replace understanding of thread synchronization, mutex logic, or project evaluation requirements

## Notes

- The mandatory executable lives in `philo/`.
- The implementation uses `pthread` threads and mutexes for synchronization.
- The simulation stops when a philosopher dies or when every philosopher has reached the optional meal target.
