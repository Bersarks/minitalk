#include "./ft_printf/ft_printf.h"

struct sigaction	g_act;

void	bit(int sig, char a)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((a >> i) & 1)
			kill (sig, SIGUSR1);
		else
			kill (sig, SIGUSR2);
		sigaction(SIGUSR2, &g_act, NULL);
		usleep(100);
		i--;
	}
}

void	receive(int num, siginfo_t *info, void *x)
{
	if (num == SIGUSR2)
		ft_printf("Signal received / Sender pid -> %d\n", info->si_pid);
	x = 0;
}

int	main(int ac, char **av)
{
	int	i;

	g_act.sa_flags = SA_SIGINFO;
	g_act.sa_sigaction = &receive;
	i = 0;
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			bit(ft_atoi(av[1]), av[2][i]);
			i++;
		}
	}
}
